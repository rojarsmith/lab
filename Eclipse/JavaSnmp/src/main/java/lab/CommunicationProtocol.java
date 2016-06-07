/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package lab;

/**
 *
 * @author Rojar.Wu
 */
public enum CommunicationProtocol {

    TCP("tcp"),
    UDP("udp");
    private final String _protocol;

    private CommunicationProtocol(String protocol) {
        this._protocol = protocol;
    }

    @Override
    public String toString() {
        return _protocol;
    }

    public static CommunicationProtocol getEnum(String str) {        
        for (CommunicationProtocol e : CommunicationProtocol.values()) {
            if (e._protocol.equalsIgnoreCase(str)) {
                return e;
            }
        }
        return CommunicationProtocol.TCP;
        //return null;
    }
}
