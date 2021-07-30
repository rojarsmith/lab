package lab.aspect;

import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.annotation.After;
import org.aspectj.lang.annotation.AfterReturning;
import org.aspectj.lang.annotation.AfterThrowing;
import org.aspectj.lang.annotation.Around;
import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Before;
import org.aspectj.lang.annotation.DeclareParents;
import org.aspectj.lang.annotation.Pointcut;
import org.springframework.core.annotation.Order;

import lab.aspect.validator.UserValidator;
import lab.aspect.validator.impl.UserValidatorImpl;
import lab.pojo.User;

/**
 * @author Rojar Smith
 *
 * @date 2021-07-30
 */
@Order(2)
@Aspect
public class MyAspect2 {
	@Pointcut("execution (* lab.service.impl.UserServiceImpl.printUser(..))")
	public void pointCut() {
	}

	@Before("pointCut() && args(user)")
	public void before(JoinPoint jp, User user) {
		@SuppressWarnings("unused")
		Object[] args = jp.getArgs();
		System.out.println("2 before ....");
	}

	@DeclareParents(value = "lab.service.impl.UserServiceImpl", defaultImpl = UserValidatorImpl.class)
	public UserValidator userValidator;

	@Around("pointCut()")
	public Object around(ProceedingJoinPoint jp) throws Throwable {
		@SuppressWarnings("unused")
		Object[] argsObjects = jp.getArgs();
		System.out.println("2 around before....");
		Object proceed = jp.proceed();
		System.out.println("2 around after....");
		return proceed;
	}

	@After("pointCut()")
	public void after() {
		System.out.println("2 after ....");
	}

	@AfterReturning("pointCut()")
	public void afterReturningbefore() {
		System.out.println("2 afterReturning ....");
	}

	@AfterThrowing("pointCut()")
	public void afterThrowing() {
		System.out.println("2 afterThrowing ....");
	}
}
