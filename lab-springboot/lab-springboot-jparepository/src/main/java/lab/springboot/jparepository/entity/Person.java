package lab.springboot.jparepository.entity;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;

import lombok.Data;
import lombok.NonNull;

@Entity
@Data
public class Person {
	@Id
	@GeneratedValue(strategy = GenerationType.AUTO)
	private Long id;
	
	@NonNull private String name;
	
	@NonNull private Integer age;
	
	public Person() {
		
	}
	
//	public Person(String name, Integer age) {
//		this.name = name;
//		this.age = age;
//	}
}
