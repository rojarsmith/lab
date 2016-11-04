package lab.java.springbasic;

import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;

import lab.java.springbasic.dependencyinjection.MessagePrinterA;
import lab.java.springbasic.dependencyinjection.MessagePrinterB;
import lab.java.springbasic.dependencyinjection.MessageService;

@Configuration
@ComponentScan
public class App {
	private static ApplicationContext context;

	@Bean
	MessageService mockMessageService() {
		return new MessageService() {
			public String getMessage() {
				return "Hello World!";
			}
		};
	}

	public static void main(String[] args) {
		context = new AnnotationConfigApplicationContext(App.class);
		MessagePrinterA printerA = context.getBean(MessagePrinterA.class);
		MessagePrinterB printerB = context.getBean(MessagePrinterB.class);
		printerA.printMessage();
		printerB.printMessage();
	}
}
