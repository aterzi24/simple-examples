import java.util.ArrayList;
import java.util.List;

public class ListExample {
	public static final List<Human> list = new ArrayList<>();
	public static final List<List<Human>> brokenList = new ArrayList<>();

	static final int times = 100;

	public static void main(String[] args) {
		int i;

		for (i = 0; i < 20; i++)
			list.add(new Human(0, 0, 0));

		for (i = 0; i < 20; i += 2) {
			List<Human> temp = new ArrayList<>();
			temp.add(list.get(i));
			brokenList.add(temp);
		}

		Thread t1 = new Thread(new Run1());
		List<Thread> threads = new ArrayList<>();

		for (i = 0; i < 10; i++)
			threads.add(new Thread(new Run2(i)));

		threads.forEach(Thread::start);
		t1.start();

		try {
			t1.join();
			for (Thread thread : threads) {
				thread.join();
			}
		} catch (InterruptedException e) {
			e.printStackTrace();
		}

		list.forEach(System.out::println);
	}
}

class Human {
	int arm;
	int head;
	int leg;

	Human(int arm, int head, int leg) {
		this.arm = arm;
		this.head = head;
		this.leg = leg;
	}

	@Override
	public String toString() {
		return "Human{" +
				"arm=" + arm +
				", head=" + head +
				", leg=" + leg +
				'}';
	}
}

class Run1 implements Runnable {

	@Override
	public void run() {
		synchronized (ListExample.list) {
			List<Human> list = ListExample.list;
			for (Human human : list) {
				//synchronized (human) {
				for (int i = 0; i < ListExample.times; i++) {
					human.arm++;
				}
				//}
			}
		}
	}
}

class Run2 implements Runnable {

	int index = 0;

	Run2(int index) {
		this.index = index;
	}

	@Override
	public void run() {
		synchronized (ListExample.brokenList.get(index)) {
			List<Human> list = ListExample.brokenList.get(index);
			for (int i = 0; i < ListExample.times; i++) {
				//synchronized (list.get(0)) {
					int temp = list.get(0).arm;
					try {
						Thread.sleep(10);
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
					list.get(0).arm = temp - 1;
				//}
			}
		}
	}
}