package lab;

import java.io.IOException;
import java.util.Vector;

import org.snmp4j.CommunityTarget;
import org.snmp4j.PDU;
import org.snmp4j.Snmp;
import org.snmp4j.TransportMapping;
import org.snmp4j.event.ResponseEvent;
import org.snmp4j.mp.SnmpConstants;
import org.snmp4j.smi.Address;
import org.snmp4j.smi.GenericAddress;
import org.snmp4j.smi.OID;
import org.snmp4j.smi.OctetString;
import org.snmp4j.smi.VariableBinding;
import org.snmp4j.transport.DefaultUdpTransportMapping;

public class SnmpNms {
	private Snmp snmp = null;
	private Address targetAddress = null;

	public static void main(String[] args) {
		try {
			SnmpNms util = new SnmpNms();
			util.initComm();
			util.getPDU();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	/**
	 * 初始化
	 */
	public void initComm() throws IOException {
		// 地址是本機 端口一般都是161
		targetAddress = GenericAddress.parse("udp:127.0.0.1/161");
		TransportMapping<?> transport = new DefaultUdpTransportMapping();
		snmp = new Snmp(transport);
		transport.listen();
	}

	/**
	 * 執行發送
	 */
	public void getPDU() throws IOException {
		// PDU 對象
		PDU pdu = new PDU();
		pdu.add(new VariableBinding(new OID("1.3.6.1.2.1.1.5.0")));
		// 操作類型
		pdu.setType(PDU.GET);
		ResponseEvent revent = sendPDU(pdu);
		if (null != revent) {
			readResponse(revent);
		}
	}

	/**
	 * 發送一個PDU
	 */
	public ResponseEvent sendPDU(PDU pdu) throws IOException {
		// 設置 目標
		CommunityTarget target = new CommunityTarget();
		target.setCommunity(new OctetString("public"));
		target.setAddress(targetAddress);
		// 通信不成功時的重試次數 N+1次
		target.setRetries(2);
		// 超時時間
		target.setTimeout(2 * 1000);
		// SNMP 版本
		target.setVersion(SnmpConstants.version2c);
		// 向Agent發送PDU，並返回Response
		return snmp.send(pdu, target);
	}

	/**
	 * 解析返回的值
	 */
	@SuppressWarnings("unchecked")
	public void readResponse(ResponseEvent respEvnt) {
		// 解析Response
		System.out.println("------------>解析Response<-------------");
		if (respEvnt != null && respEvnt.getResponse() != null) {
			Vector<VariableBinding> recVBs = (Vector<VariableBinding>) respEvnt
					.getResponse().getVariableBindings();
			for (int i = 0; i < recVBs.size(); i++) {
				VariableBinding recVB = recVBs.elementAt(i);
				System.out.println(recVB.getOid() + " : "
						+ recVB.getVariable().toString());
			}
		}
	}
}
