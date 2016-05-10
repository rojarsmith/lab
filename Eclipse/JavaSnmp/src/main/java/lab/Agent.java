package lab;

import lab.MibValueTable;
import org.snmp4j.*;
import org.snmp4j.smi.*;

/**
 *
 * @author root
 */
public class Agent {

	public static class Handler implements org.snmp4j.CommandResponder {
		protected String mAddress = null;
		protected int mPort = 0;
		protected String mMyCommunityName = null;
		@SuppressWarnings("rawtypes")
		protected org.snmp4j.TransportMapping mServerSocket = null;
		protected org.snmp4j.Snmp mSNMP = null;

		public Handler() {
		}

		public void configure() {
			mAddress = "127.0.0.1";
			mPort = 161;
			mMyCommunityName = "public";
		}

		public void start() {
			try {
				mServerSocket = new org.snmp4j.transport.DefaultUdpTransportMapping(
						new org.snmp4j.smi.UdpAddress(java.net.InetAddress
								.getByName(mAddress), mPort));
				mSNMP = new org.snmp4j.Snmp(mServerSocket);
				mSNMP.addCommandResponder(this);
				mServerSocket.listen();
			} catch (java.net.UnknownHostException vException) {
				System.out.println(vException);
			} catch (java.io.IOException vException) {
				System.out.println(vException);
			}
		}

		public synchronized void processPdu(
				org.snmp4j.CommandResponderEvent aEvent) {
			String vCommunityName = new String(aEvent.getSecurityName());
			System.out.println("Community name " + vCommunityName);
			org.snmp4j.PDU vPDU = aEvent.getPDU();
			MibValueTable config = new MibValueTable();
			if (vPDU == null) {
				System.out.println("Null pdu");
			} else {
				System.out.println("(rcv) " + vPDU.toString());
				switch (vPDU.getType()) {
				case org.snmp4j.PDU.GET:
				case org.snmp4j.PDU.GETNEXT:
					break;
				case org.snmp4j.PDU.SET:
					System.out.println("------SET----------");
					String reciv = vPDU.get(0).getVariable().getSyntaxString();
					System.out.println("SyntaxString=" + reciv);
					System.out
							.println("----set------" + vPDU.get(0).toString());
					String setoid = vPDU.get(0).toString();
					System.out.println("-----set-----"
							+ setoid.substring(0, setoid.indexOf("=") - 1));
					System.out.println("-----set-----"
							+ setoid.substring(setoid.indexOf("=") + 1));
					config.setValueByOID(
							setoid.substring(0, setoid.indexOf("=") - 1).trim(),
							setoid.substring(setoid.indexOf("=") + 1).trim());
				}
				org.snmp4j.mp.StatusInformation statusInformation = new org.snmp4j.mp.StatusInformation();
				org.snmp4j.mp.StateReference ref = aEvent.getStateReference();
				try {
					System.out.println("Sending response");
					vPDU.setType(PDU.RESPONSE);

					OID oid = vPDU.get(0).getOid();
					String setoid = vPDU.get(0).toString();
					System.out.println("----get------"
							+ setoid.substring(0, setoid.indexOf("=") - 1));
					System.out.println("-----get-----"
							+ setoid.substring(setoid.indexOf("=") + 1));
					vPDU.set(
							0,
							new VariableBinding(oid, new OctetString(config
									.getValueByOID(setoid.substring(0,
											setoid.indexOf("=") - 1).trim()))));
					aEvent.getMessageDispatcher().returnResponsePdu(
							aEvent.getMessageProcessingModel(),
							aEvent.getSecurityModel(),
							aEvent.getSecurityName(),
							aEvent.getSecurityLevel(), vPDU,
							aEvent.getMaxSizeResponsePDU(), ref,
							statusInformation);
				} catch (org.snmp4j.MessageException vException) {
					System.out.println(vException);
				}
			}
		}
	}

	public static void main(String argv[]) {
		Handler h = new Handler();
		// Initial parameter
		h.configure();
		h.start();
		// Do nothing loop
		while (true) {
			System.out.println("----------loop-------------");
			synchronized (Agent.class) {
				try {
					Agent.class.wait();
				} catch (Exception e) {
				}
			}
		}
	}
}
