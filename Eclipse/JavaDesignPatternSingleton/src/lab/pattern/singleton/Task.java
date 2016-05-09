package lab.pattern.singleton;

public class Task extends Thread {

	private TaskParameter taskParameter;

	public Task(String taskName, TaskParameter taskParameter) {
		this.taskParameter = taskParameter;
		super.setName(taskName);
	}

	public void run() {
		int runCount = 0;
		String tName = Thread.currentThread().getName();
		int hashCode = Thread.currentThread().hashCode();

		for (int i = 1; i <= taskParameter.getLoopCount(); i++) {
			try {
				Thread.sleep(10);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}

			System.out.println(tName + ":" + i);

			ThreadSafeSingleton tss = ThreadSafeSingleton
					.getInstanceUsingDoubleLocking();

			if (!tss.isIsRunning()) {
				tss.run(tName);
				runCount++;
			} else {
				System.out.println("Task Locked!" + " Name=" + tName + " Task="
						+ hashCode + " ThreadSafeSingleton=" + tss.hashCode());
				i--;				
			}			
		}

		System.out.println("End! Name=" + tName + " runCount=" + runCount);
	}
}
