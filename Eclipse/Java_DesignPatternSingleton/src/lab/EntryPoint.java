package lab;

public class EntryPoint {

	public static void main(String[] args) {
		TaskParameter taskParameter1 = new TaskParameter();
		taskParameter1.setLoopCount(11);
		TaskParameter taskParameter2 = new TaskParameter();
		taskParameter2.setLoopCount(12);
		Task t1 = new Task("T1", taskParameter1);
		Task t2 = new Task("T2", taskParameter2);
		t1.start();
		t2.start();

		System.out.println("Thread.activeCount=" + Thread.activeCount());
	}

}
