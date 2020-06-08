package lab.java.language;

public interface IBehavior {
	public void sayHello();
	
	default public void sayGoodbye() {
		System.out.println("Goodbye!");
	}
}
