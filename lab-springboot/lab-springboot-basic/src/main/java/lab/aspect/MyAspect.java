package lab.aspect;

import org.aspectj.lang.annotation.After;
import org.aspectj.lang.annotation.AfterReturning;
import org.aspectj.lang.annotation.AfterThrowing;
import org.aspectj.lang.annotation.Around;
import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Before;
import org.aspectj.lang.annotation.DeclareParents;
import org.aspectj.lang.annotation.Pointcut;
import org.springframework.stereotype.Component;
import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.ProceedingJoinPoint;

import lab.aspect.validator.UserValidator;
import lab.aspect.validator.impl.UserValidatorImpl;
import lab.pojo.User;

@Aspect
public class MyAspect {
	@Pointcut("execution (* lab.service.impl.UserServiceImpl.printUser(..))")
	public void pointCut() {
	}
	
	@Before("pointCut() && args(user)")
	public void before(JoinPoint jp, User user) {
		Object[] args = jp.getArgs();
		System.out.println("before ....");
	}
	
	@DeclareParents(value = "lab.service.impl.UserServiceImpl", defaultImpl = UserValidatorImpl.class)
	public UserValidator userValidator;
	
	
	@Around("pointCut()")
	public Object around(ProceedingJoinPoint jp) throws Throwable{
		Object[] argsObjects = jp.getArgs();
		System.out.println("around before....");
		Object proceed = jp.proceed();
		System.out.println("around after....");
		return proceed;
	}
	
	@After("pointCut()")
	public void after() {
		System.out.println("after ....");
	}
	
	@AfterReturning("pointCut()")
	public void afterReturningbefore() {
		System.out.println("afterReturning ....");
	}
	
	@AfterThrowing("pointCut()")
	public void afterThrowing() {
		System.out.println("afterThrowing ....");
	}
}
