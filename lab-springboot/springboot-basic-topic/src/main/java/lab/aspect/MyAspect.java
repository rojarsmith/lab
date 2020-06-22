package lab.aspect;

import org.aspectj.lang.annotation.After;
import org.aspectj.lang.annotation.AfterReturning;
import org.aspectj.lang.annotation.AfterThrowing;
import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Before;
import org.aspectj.lang.annotation.Pointcut;

@Aspect
public class MyAspect {
	@Pointcut("execution (* lab.service.impl.UserServiceImpl.printUser(..))")
	public void pointCut() {
	}
	
	@Before("pointCut()")
	public void before() {
		System.out.println("before ....");
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
