package lab.springboot;

import javax.persistence.Entity;
import javax.persistence.Id;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@NoArgsConstructor
@AllArgsConstructor
@Entity
public class Pet {
	@Id
	private String seq;
	private String petId;
	private String petName;
	private String species;
	private Integer age;
}