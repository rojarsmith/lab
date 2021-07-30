package lab;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.annotation.Bean;

import lab.aspect.MyAspect;
import lab.aspect.MyAspect2;

@SpringBootApplication // (scanBasePackages = {"lab.aspect"})
public class SpringBootBasicTopicApplication {

	@Bean(name = "myAspect")
	public MyAspect initMyAspect() {
		return new MyAspect();
	}

	@Bean(name = "myAspect2")
	public MyAspect2 initMyAspect2() {
		return new MyAspect2();
	}

	public static void main(String[] args) {
		SpringApplication.run(SpringBootBasicTopicApplication.class, args);
	}

}
