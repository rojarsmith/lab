package lab.springboot;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.querydsl.jpa.impl.JPAQueryFactory;

@Service
public class CustomerDao {
	@Autowired
	private JPAQueryFactory queryFactory;
	
	public List<Customer> findCustomer(String firstName, String lastName) {
		QCustomer qcustomer = QCustomer.customer;
		
		return queryFactory.selectFrom(qcustomer)
				.where(qcustomer.firstName.eq(firstName)
						.or(qcustomer.lastName.eq(lastName)))
				.fetch();
	}
}
