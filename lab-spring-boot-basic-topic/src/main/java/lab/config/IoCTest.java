package lab.config;

import org.jboss.logging.Logger;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;

import lab.pojo.BussinessPerson;
import lab.pojo.User;
import lab.pojo.definition.Person;

public class IoCTest {
	private static Logger log = Logger.getLogger(IoCTest.class);

	public static void main(String[] args) {
		AnnotationConfigApplicationContext ctx = new AnnotationConfigApplicationContext(AppConfig.class);
		User user = ctx.getBean(User.class);
		log.info(user.getId());		
		
		Person person = ctx.getBean(BussinessPerson.class);
		person.service();
		ctx.close();
	}
}
