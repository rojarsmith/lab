package lab.pojo;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Component;

import lab.pojo.definition.Animal;
import lab.pojo.definition.Person;

@Component
public class BussinessPerson implements Person {
	
	private Animal animal = null;
	
	public BussinessPerson(@Autowired @Qualifier("dog") Animal animal) {
		this.animal = animal;
	}
	
	@Override
	public void service() {
		this.animal.use();
	}

	@Override	
	public void setAnimal(Animal animal) {
		this.animal = animal;
	}
	
}
