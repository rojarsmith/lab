package lab.java.basic.topic.annotation;

public class NoBug {

	@NoBugAnnotation	
	public void fun1(){
		System.out.println("1234567890");
	}
	
	@NoBugAnnotation
	public void fun2(){
		System.out.println("1+1="+1+1);
	}
	
	@NoBugAnnotation
	public void fun3(){
		System.out.println("1-1="+(1-1));
	}
	
	@NoBugAnnotation
	public void fun4(){
		System.out.println("3 x 5="+ 3*5);
	}
	
	@NoBugAnnotation
	public void fun5(){
		System.out.println("6 / 0="+ 6 / 0);
	}
	
	public void fun6(){
		System.out.println("My program is no bug!");
	}
}
