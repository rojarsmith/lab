package lab.pattern.singleton;

public class ThreadSafeSingleton {

	private volatile static ThreadSafeSingleton instance;

	private volatile static boolean isRunning;

	{
		setIsRunning(false);
	}

	private ThreadSafeSingleton() {
	}

	public static ThreadSafeSingleton getInstanceUsingDoubleLocking() {
		if (instance == null) {
			synchronized (ThreadSafeSingleton.class) {
				if (instance == null) {
					instance = new ThreadSafeSingleton();
				}
			}
		}
		return instance;
	}

	public void run(String name) {
		if (isIsRunning()) {
			System.out.println("Singleton Lock! ThreadSafeSingleton="
					+ this.hashCode() + " Name=" + name);
			return;
		}

		setIsRunning(true);

		for (int i = 0; i < 3; i++) {
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			System.out.println("Run! ThreadSafeSingleton=" + this.hashCode()
					+ " Name=" + name);
		}

		setIsRunning(false);
	}

	public boolean isIsRunning() {
		return isRunning;
	}

	public void setIsRunning(boolean isRunning) {
		ThreadSafeSingleton.isRunning = isRunning;
	}

}