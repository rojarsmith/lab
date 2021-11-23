package lab.pojo;

import org.springframework.context.annotation.Primary;
import org.springframework.stereotype.Component;

import lab.pojo.definition.Animal;

@Component
@Primary
public class Cat implements Animal{

	@Override
	public void use() {
		System.out.println(Cat.class.getSimpleName() + "is catch mouse.");
	}
	
}
