public class SyncExample {
	public static void main(String[] args) {
		new Thread(new Thread2()).start();
		new Thread(new Thread1()).start();

	}
}

class First {
	synchronized void method() {
		try {
			Thread.sleep(5);
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		synchronized (System.out) {
			System.out.println("a");
			int num = 100000;
			int temp = 0;
			for (int i = 0; i < num; i++) {
				for (int j = 0; j < num; j++) {
					temp = i * j;
				}
			}
			temp++;
			System.out.println("a");
		}
	}
}

class Second {
	synchronized void method() {
		System.out.println("b");
		int num = 100000;
		int temp = 0;
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num; j++) {
				temp = i * j;
			}
		}
		temp++;
		System.out.println("b");
	}
}

class Thread1 implements Runnable {

	@Override
	public void run() {
		new First().method();
	}
}

class Thread2 implements Runnable {

	@Override
	public void run() {
		new Second().method();
	}
}