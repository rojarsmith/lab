package lab.springboot;

import java.util.List;

import org.apache.commons.lang3.StringUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.querydsl.core.BooleanBuilder;
import com.querydsl.core.types.Projections;
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

	public List<DetailDto> findOrder(String firstName, String lastName) {
		QCustomer qcustomer = QCustomer.customer;
		QPet qpet = QPet.pet;
		QOrderform qorderform = QOrderform.orderform;
		
		return queryFactory.select(
				Projections.bean(DetailDto.class, 
						qorderform.orderId,
						qorderform.memberId,
						qorderform.petId,
						qcustomer.firstName,
						qcustomer.lastName,
						qpet.petName,
						qpet.species,
						qpet.age))
				.from(qorderform)
				.leftJoin(qpet).on(qpet.petId.eq(qorderform.petId))
				.leftJoin(qcustomer).on(qcustomer.memberId.eq(qorderform.memberId))
				.where(qcustomer.firstName.eq(firstName)
						.or(qcustomer.lastName.eq(lastName)))
				.fetch();
	}
}
