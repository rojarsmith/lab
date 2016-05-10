/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package lab;

import java.io.IOException;
import org.snmp4j.smi.OID;

/**
 *
 * @author Rojar.Wu
 */
public class Test {

	static long _time1, _time2, _time3;

	public static void main(String[] args) throws IOException {

		try {
			_time1 = System.currentTimeMillis();

			Test_OLD();

			_time2 = System.currentTimeMillis();

			System.out.println("time :" + (_time2 - _time1) / 1000.0
					+ " Seconds.");
		} catch (Exception e) {
			e.toString();
		}
	}

	static void Test_OLD() {

		SnmpuUtility s1 = new SnmpuUtility(CommunicationProtocol.UDP, "192.168.14.216", 161);
		// Snmp s3 = new Snmp(CommunicationProtocol.UDP, "192.168.14.216", 161);
		// Snmp s2 = new Snmp(CommunicationProtocol.UDP, "192.168.14.215", 161);

		System.out.println(s1.initialCommunication());
		// boolean b2 = s2.initialCommunication();
		// boolean b3 = s3.initialCommunication();

		// Object o1 = s1.getPdu(new OID(".1.3.6.1.4.1.42331.1.1002.3.2.0"));
		// Object o3 = s1.getPduForString(new
		// OID(".1.3.6.1.4.1.42331.1.1002.3.2.0"));
		// Object o2 = s1.getPduForString(new
		// OID(".1.3.6.1.4.1.42331.1.1002.3.2.0"));
		// Object o4 = s2.getPduForString(new
		// OID(".1.3.6.1.4.1.42331.1.1002.3.2.99"));
		// Object o5 = s1.getPduForListString(new
		// OID(".1.3.6.1.4.1.42331.1.1002.1.1.1.2"), 4, 25);

		long time1, time2;

		time1 = System.currentTimeMillis();
		s1.getPdu(new OID(".1.3.6.1.4.1.42331.1.1002.3.2.0"));
		// Boolean b4 = s1.setPdu(new
		// OID(".1.3.6.1.4.1.42331.1.1002.1.1.1.5.3"), "AAA");
		time2 = System.currentTimeMillis();
		System.out.println("time :" + (time2 - time1) / 1000.0 + " Seconds.");
		// s1.getPDUforString(".1.3.6.1.4.1.42331.1.1002.1.1.1.5.24");
		// s2.getPDUforString(".1.3.6.1.4.1.42331.1.1002.3.2.0");
	}
}
