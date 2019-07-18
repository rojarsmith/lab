package lab.pojo;

import org.springframework.stereotype.Component;

import lab.pojo.definition.Animal;

@Component
public class Dog implements Animal{

	@Override
	public void use() {
		System.out.println(Dog.class.getSimpleName() + "is used for the gate.");
	}
	
}
