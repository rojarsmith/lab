package lab.springboot.jackson;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import org.springframework.boot.CommandLineRunner;
import org.springframework.stereotype.Component;

import com.fasterxml.jackson.core.type.TypeReference;
import com.fasterxml.jackson.databind.ObjectMapper;

@Component
public class Demo implements CommandLineRunner{

	@SuppressWarnings("unused")
	@Override
	public void run(String... args) throws Exception {
		String jsonGetAddressesByLabel = "{\n"
				+ "  \"te1qg4s7pe4awjn97qcfpgm54ts9tk6zna53decf0a\": {\n"
				+ "    \"purpose\": \"receive\",\n"
				+ "    \"purpose2\": \"receive2\"\n"
				+ "  },\n"
				+ "  \"te1qgmecypy5z7zuusumn8aeuv0svjm5em3vdcg6rf\": {\n"
				+ "    \"purpose\": \"receive\"\n"
				+ "  },\n"
				+ "  \"te1qd82jmlmsuj75vxyxl47unhyef37nzny5k69a6u\": {\n"
				+ "    \"purpose\": \"receive\"\n"
				+ "  },\n"
				+ "  \"te1q72q3rxhcmwz0cky8q59rtg5y64f469r6cuu0cy\": {\n"
				+ "    \"purpose\": \"receive\"\n"
				+ "  }\n"
				+ "}";
		
		ObjectMapper objectMapper = new ObjectMapper();
		
		// Deserialize
		Map<String, Map<String, String>> addrs = objectMapper.readValue(jsonGetAddressesByLabel, new TypeReference<Map<String, Map<String, String>>>(){});
		System.out.println(addrs);
		String v1 = addrs.get("te1qd82jmlmsuj75vxyxl47unhyef37nzny5k69a6u")
		.get("purpose");
		
		
		List<User> users = new ArrayList<>();
		User user1 = new User(1, "Rojar");
		User user2 = new User(1, "Smith");
	    users.add(user1);
	    users.add(user2);
	    // Error : No serializer found for class 
	    // and no properties discovered to create BeanSerializer.
	    // Lack get/set method in the class.
	    String ujson = objectMapper.writeValueAsString(user1);
		
		int dbg = 0;
	}

}
