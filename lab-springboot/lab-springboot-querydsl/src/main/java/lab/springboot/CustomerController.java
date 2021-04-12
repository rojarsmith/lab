package lab.springboot;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping(value = "/customer")
public class CustomerController {
	@Autowired
	private CustomerDao customerDao;

	@GetMapping(value = "/getCustomer")
	public List<Customer> getCustomer(@RequestParam String firstName, @RequestParam String lastName) {
		List<Customer> list = customerDao.findCustomer(firstName, lastName);
		return list;
	}

	@GetMapping(value = "/getOrder")
	public List<DetailDto> getOrder(@RequestParam String firstName, @RequestParam String lastName) {
		List<DetailDto> dtos = customerDao.findOrder(firstName, lastName);
		return dtos;
	}
}
