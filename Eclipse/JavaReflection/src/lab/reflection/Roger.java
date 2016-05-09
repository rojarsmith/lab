package lab.reflection;

public class Roger extends Persion {

	public Roger(String name, int age) {
		super(name, age);
	}

	@Override
	public void sayHello() {
		System.out.println(getName() + " say hello, age=" + getAge());
	}

}
