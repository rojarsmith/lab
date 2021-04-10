package lab.springboot;

import com.fasterxml.jackson.annotation.JsonProperty;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@NoArgsConstructor
@AllArgsConstructor
public class DetailDto {

	@JsonProperty("ORDER_ID")
	private String orderId;

	@JsonProperty("MEMBER_ID")
	private String memberId;

	@JsonProperty("PET_ID")
	private String petId;

	@JsonProperty("FIRST_NAME")
	private String firstName;

	@JsonProperty("LAST_NAME")
	private String lastName;

	@JsonProperty("PET_NAME")
	private String petName;

	@JsonProperty("SPECIES")
	private String species;

	@JsonProperty("AGE")
	private Integer age;
}