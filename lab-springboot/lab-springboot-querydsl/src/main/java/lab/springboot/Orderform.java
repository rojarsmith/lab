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
public class Orderform {
	@Id
	private String seq;
	private String orderId;
	private String memberId;
	private String petId;
}
