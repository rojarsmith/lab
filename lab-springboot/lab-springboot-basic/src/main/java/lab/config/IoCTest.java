package lab.config;


import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;

import lab.other.pojo.Squirrel;
import lab.pojo.BussinessPerson;
import lab.pojo.DataBaseProperties;
import lab.pojo.User;
import lab.pojo.definition.Person;
import lab.scope.pojo.ScopeBean;

public class IoCTest {
	private static Logger log = LoggerFactory.getLogger(IoCTest.class);

	public static void main(String[] args) {
		AnnotationConfigApplicationContext ctx = new AnnotationConfigApplicationContext(AppConfig.class);
		User user = ctx.getBean(User.class);
		log.info(user.getId().toString());		
		
		DataBaseProperties db = ctx.getBean(DataBaseProperties.class);
				
		Person person = ctx.getBean(BussinessPerson.class);
		person.service();
		
		ScopeBean scopeBean1 = ctx.getBean(ScopeBean.class);
		ScopeBean scopeBean2 = ctx.getBean(ScopeBean.class);
		System.out.println(scopeBean1 == scopeBean2);
		
		Squirrel scopeBean3 = ctx.getBean(Squirrel.class);
		scopeBean3.use();
		
		ctx.close();		
	}
}
