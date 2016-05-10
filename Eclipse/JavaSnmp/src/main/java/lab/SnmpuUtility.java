package lab;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import org.apache.commons.lang3.exception.ExceptionUtils;
import org.snmp4j.CommunityTarget;
import org.snmp4j.PDU;
import org.snmp4j.TransportMapping;
import org.snmp4j.event.ResponseEvent;
import org.snmp4j.mp.SnmpConstants;
import org.snmp4j.smi.Address;
import org.snmp4j.smi.GenericAddress;
import org.snmp4j.smi.OID;
import org.snmp4j.smi.OctetString;
import org.snmp4j.smi.VariableBinding;
import org.snmp4j.transport.DefaultTcpTransportMapping;
import org.snmp4j.transport.DefaultUdpTransportMapping;

/**
 *
 * @author Rojar.Wu
 */
public class SnmpuUtility {

	public String _communityRead = "public";
	public String _communityWrite = "private";
	public int _retryTimes = 2;
	public int _communicationTimeout = 2000;
	static final org.slf4j.Logger _logger = org.slf4j.LoggerFactory
			.getLogger(SnmpuUtility.class);
	Address _targetAddress = null;
	CommunicationProtocol _protocol = null;
	org.snmp4j.Snmp _snmp = null;

	public SnmpuUtility(CommunicationProtocol protocol, String agentIp,
			Integer port) {
		this._protocol = protocol;
		this._targetAddress = GenericAddress.parse(protocol.toString() + ":"
				+ agentIp + "/" + port);
	}

	public boolean initialCommunication() {
		boolean isAllPass = true;

		try {
			TransportMapping<?> transport;

			switch (_protocol) {
			case TCP:
				transport = new DefaultTcpTransportMapping();
				break;
			default:
				transport = new DefaultUdpTransportMapping();
				break;
			}

			_snmp = new org.snmp4j.Snmp(transport);
			transport.listen();
		} catch (Exception e) {
			isAllPass = false;
			_logger.error(ExceptionUtils.getStackTrace(e));
		}

		return isAllPass;
	}

	public boolean closeCommunication() {
		boolean isAllPass = true;

		try {
			if (null != _snmp) {
				_snmp.close();
			}
		} catch (Exception e) {
			isAllPass = false;
			_logger.error(ExceptionUtils.getStackTrace(e));
		}

		return isAllPass;
	}

	public String getPduForString(OID oid) {
		String result = null;

		ResponseEvent revent = getPdu(oid);
		result = parseResponseToString(revent);

		return result;
	}

	public List<String> getPduForListString(OID oid) {
		List<String> result = null;

		ResponseEvent revent = getPdu(oid);
		result = parseResponseToListString(revent);

		return result;
	}

	public List<String> getPduForListString(OID oid, int suffixIndexStart,
			int suffixIndexEnd) {
		List<String> result = null;

		ResponseEvent revent = getPdu(oid, suffixIndexStart, suffixIndexEnd);
		result = parseResponseToListString(revent);

		return result;
	}

	public Boolean setPdu(OID oid, String value) {
		Boolean result = true;
		try {
			PDU pdu = new PDU();
			pdu.add(new VariableBinding(oid, new OctetString(value)));
			pdu.setType(PDU.SET);
			sendPDU(pdu, true);

			String tryGetValueAgain = getPduForString(oid);
			if (!tryGetValueAgain.equals(value)) {
				result = false;
			}
		} catch (Exception e) {
			result = false;
			_logger.error(ExceptionUtils.getStackTrace(e));
		}

		return result;
	}

	ResponseEvent getPdu(OID oid) {
		ResponseEvent result = null;

		PDU pdu = new PDU();
		pdu.add(new VariableBinding(oid));
		pdu.setType(PDU.GET);

		try {
			result = sendPDU(pdu, false);
		} catch (Exception e) {
			_logger.error(ExceptionUtils.getStackTrace(e));
		}

		return result;
	}

	ResponseEvent getPdu(OID oid, int suffixIndexStart, int suffixIndexEnd) {
		ResponseEvent result = null;

		PDU pdu = new PDU();
		for (int i = suffixIndexStart; i <= suffixIndexEnd; i++) {
			OID oidItem = new OID(oid + "." + i);
			pdu.add(new VariableBinding(oidItem));
		}
		pdu.setType(PDU.GET);

		try {
			result = sendPDU(pdu, false);
		} catch (Exception e) {
			_logger.error(ExceptionUtils.getStackTrace(e));
		}

		return result;
	}

	ResponseEvent sendPDU(PDU pdu, Boolean isWrite) throws IOException {
		ResponseEvent result = null;

		// set target
		CommunityTarget target = new CommunityTarget();
		if (isWrite) {
			target.setCommunity(new OctetString(_communityWrite));
		} else {
			target.setCommunity(new OctetString(_communityRead));
		}
		target.setAddress(_targetAddress);
		// retry communicate, N+1 time
		target.setRetries(_retryTimes);
		// time of time out
		target.setTimeout(_communicationTimeout);
		// snmp version
		target.setVersion(SnmpConstants.version2c);
		// send pdu to target

		try {
			result = _snmp.send(pdu, target);
		} catch (Exception e) {
			_logger.error(ExceptionUtils.getStackTrace(e));
		}
		return result;
	}

	String parseResponseToString(ResponseEvent respEvnt) {
		String result = null;

		if (respEvnt != null && respEvnt.getResponse() != null) {
			@SuppressWarnings("unchecked")
			List<VariableBinding> recVBs = (List<VariableBinding>) respEvnt
					.getResponse().getVariableBindings();

			if (recVBs.size() >= 1) {
				VariableBinding recVB = recVBs.get(0);
				result = recVB.getVariable().toString();
				result = convertSpecialResponse(result);
			}
		}

		return result;
	}

	List<String> parseResponseToListString(ResponseEvent respEvnt) {
		List<String> result = null;

		if (respEvnt != null && respEvnt.getResponse() != null) {
			@SuppressWarnings("unchecked")
			List<VariableBinding> recVBs = (List<VariableBinding>) respEvnt
					.getResponse().getVariableBindings();

			if (recVBs.size() >= 1) {
				result = new ArrayList<String>();

				for (int i = 0; i < recVBs.size(); i++) {
					VariableBinding recVB = recVBs.get(i);
					String v1 = recVB.getVariable().toString();
					v1 = convertSpecialResponse(v1);
					result.add(v1);
				}
			}
		}

		return result;
	}

	String convertSpecialResponse(String value) {
		String result = value;

		if (result.equalsIgnoreCase("noSuchInstance")) {
			result = null;
		}

		return result;
	}
}
