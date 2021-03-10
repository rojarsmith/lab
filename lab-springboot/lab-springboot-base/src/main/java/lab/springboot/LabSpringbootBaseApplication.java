package lab.springboot;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

import lab.springboot.basic.Library;

@SpringBootApplication
public class LabSpringbootBaseApplication {

	public static void main(String[] args) {
		Library.someLibraryMethod();
		SpringApplication.run(LabSpringbootBaseApplication.class, args);
	}

}
