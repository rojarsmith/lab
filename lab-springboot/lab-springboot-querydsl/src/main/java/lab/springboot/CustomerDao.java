package lab.springboot;

import java.util.List;

import org.apache.commons.lang3.StringUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.querydsl.core.BooleanBuilder;
import com.querydsl.jpa.impl.JPAQueryFactory;

@Service
public class CustomerDao {
	@Autowired
	private JPAQueryFactory queryFactory;
	
	public List<Customer> findCustomer(String firstName, String lastName) {
		QCustomer qcustomer = QCustomer.customer;
		
		BooleanBuilder condition = new BooleanBuilder();
		if(StringUtils.isBlank(firstName) || StringUtils.isBlank(lastName)) {
			condition.and(qcustomer.firstName.eq(firstName))
			.or(qcustomer.lastName.eq(lastName));
		} else {
			condition.and(qcustomer.firstName.eq(firstName))
			.and(qcustomer.lastName.eq(lastName));
		}
		
		return queryFactory.selectFrom(qcustomer)
				.where(condition)
				.fetch();
	}
}
