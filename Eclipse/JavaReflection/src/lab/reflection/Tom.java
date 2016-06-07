package lab.reflection;

public class Tom extends Persion {

	public Tom(String name, int age) {
		super(name, age);
	}

	public void sayHello() {
		System.out.println("Yes, " + getName() + " say hello, age=" + getAge());
	}

}
