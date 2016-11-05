package lab.java.springbasic;

import org.springframework.beans.factory.config.ConfigurableBeanFactory;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.Scope;
import org.springframework.context.annotation.ScopedProxyMode;

import lab.java.springbasic.dependencyinjection.MessagePrinterA;
import lab.java.springbasic.dependencyinjection.MessagePrinterB;
import lab.java.springbasic.dependencyinjection.MessageService;
import lab.java.springbasic.proxydependencyinjection.MyPrototypeBean;
import lab.java.springbasic.proxydependencyinjection.MySingletonBean;

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

	@Bean
	@Scope(value = ConfigurableBeanFactory.SCOPE_PROTOTYPE, proxyMode = ScopedProxyMode.TARGET_CLASS)
	public MyPrototypeBean prototypeBean() {
		return new MyPrototypeBean();
	}

	@Bean
	public MySingletonBean singletonBean() {
		return new MySingletonBean();
	}

	public static void main(String[] args) throws InterruptedException{
		context = new AnnotationConfigApplicationContext(App.class);
		MessagePrinterA printerA = context.getBean(MessagePrinterA.class);
		MessagePrinterB printerB = context.getBean(MessagePrinterB.class);
		printerA.printMessage();
		printerB.printMessage();

		// This is another way to solve injecting a narrower scoped bean into
		// wider scoped bean problem.
		context = new AnnotationConfigApplicationContext(App.class);
		MySingletonBean bean = context.getBean(MySingletonBean.class);
		bean.showMessage();
		Thread.sleep(1000);

		bean.showMessage();
	}
}
