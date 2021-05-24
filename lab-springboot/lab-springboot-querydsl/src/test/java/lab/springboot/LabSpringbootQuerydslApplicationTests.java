package lab.springboot;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;

import javax.annotation.PostConstruct;

import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.http.MediaType;
import org.springframework.test.web.servlet.MockMvc;
import org.springframework.test.web.servlet.MvcResult;
import org.springframework.test.web.servlet.request.MockMvcRequestBuilders;
import org.springframework.test.web.servlet.setup.MockMvcBuilders;
import org.springframework.web.context.WebApplicationContext;

@SpringBootTest
class LabSpringbootQuerydslApplicationTests {

	protected MockMvc mvc;
	
	@Autowired
	WebApplicationContext webApplicationContext;
	
	@PostConstruct
	void init() {
		mvc = MockMvcBuilders.webAppContextSetup(webApplicationContext).build();
	}
	
	@Test
	void contextLoads() {
	}
	
	@Test
	public void getCustomer() throws Exception {
	   String uri = "/customer/getCustomer?firstName=Rojar&lastName=Smith";
	   MvcResult mvcResult = mvc.perform(MockMvcRequestBuilders.get(uri).accept(MediaType.APPLICATION_JSON_VALUE)).andReturn();
	   int status = mvcResult.getResponse().getStatus();
	   assertEquals(200, status);
	   // [{"seq":"1","memberId":"M0001","firstName":"Rojar","lastName":"Smith"}]
	   String content = mvcResult.getResponse().getContentAsString();
	   assertTrue(content.contains("[{\"seq\":\""));
	}
}
