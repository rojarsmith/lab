package lab.java.springbasic.dependencyinjection;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

@Component
public class MessagePrinterA {
    final private MessageService service;

    @Autowired
    public MessagePrinterA(MessageService service) {
        this.service = service;
    }

    public void printMessage() {
        System.out.println("PrinterA:" + this.service.getMessage());
    }
}
