package lab;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.annotation.Bean;

import lab.aspect.MyAspect;

@SpringBootApplication//(scanBasePackages = {"lab.aspect"})
public class SpringBootBasicTopicApplication {

	@Bean(name="myAspect")
	public MyAspect initMyAspect() {
		return new MyAspect();
	}
	
	public static void main(String[] args) {
		SpringApplication.run(SpringBootBasicTopicApplication.class, args);
	}

}
