package lab.java.springbasic.dependencyinjection;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

@Component
public class MessagePrinterB {
    final private MessageService service;

    @Autowired
    public MessagePrinterB(MessageService service) {
        this.service = service;
    }

    public void printMessage() {
        System.out.println("PrinterB:" + this.service.getMessage());        
    }
}
