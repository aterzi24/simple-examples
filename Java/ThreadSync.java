import java.util.ArrayList;
import java.util.List;

public class ThreadSync {
	int money = 0;
	List<Thread> threads = new ArrayList<>();

	ThreadSync(int time) {
		int i;
		Runnable runnable1 = new AddMoney(this);
		Runnable runnable2 = new SubMoney(this);
		for (i = 0; i < time; i++)
			threads.add(new Thread(runnable2));
		for (i = 0; i < time; i++)
			threads.add(new Thread(runnable1));

	}

	synchronized void increment() {
		System.out.println("UG");
		int money = this.money + 1;
		try {
			Thread.sleep(1);
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		this.money = money;
		System.out.println("U");
		notify();
	}

	synchronized void decrement() {
		System.out.println("DG");
		try {
			while (this.money == 0) {
				wait();
				//Thread.sleep(2);
			}
		    int money = this.money - 1;
			Thread.sleep(1);
			this.money = money;
			System.out.println("D");
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
	}

	void start() {
		for (Thread thread: threads)
			thread.start();
	}

	void waitFinish() {
		for (Thread thread: threads) {
			try {
				thread.join();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}

	public static void main(String[] args) {
		ThreadSync threadSync = new ThreadSync(10);

		threadSync.start();
		threadSync.waitFinish();

		System.out.println(threadSync.money);
	}
}


class AddMoney implements Runnable {
	ThreadSync threadSync;
	AddMoney(ThreadSync te) {
		threadSync = te;
	}
	@Override
	public void run() {
		threadSync.increment();
	}
}

class SubMoney implements Runnable {
	ThreadSync threadSync;
	SubMoney(ThreadSync te) {
		threadSync = te;
	}
	@Override
	public void run() {
		threadSync.decrement();
	}
}