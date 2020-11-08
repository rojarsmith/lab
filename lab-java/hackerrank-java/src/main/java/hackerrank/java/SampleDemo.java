package hackerrank.java;

public class SampleDemo implements Runnable {
    private Thread t;
    private String threadName;

    SampleDemo(String threadName) {
        this.threadName = threadName;
    }

    public void run() {
        while (true) {
            System.out.print(threadName);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public void start() {
        if (t == null) {
            t = new Thread(this, threadName);
            t.start();
        }
    }
    
    public static void lab1() {
        SampleDemo A = new SampleDemo("A");
        SampleDemo B = new SampleDemo("B");
        B.start();
        A.start();
    }
}
