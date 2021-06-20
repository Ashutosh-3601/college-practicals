import java.util.Random;
class SquareThread implements Runnable {
	int num;
	SquareThread(int x) {
		this.num = x;
	}
	
	public void run() { 
		System.out.println("Thread Name:Square Thread and Square of " + this.num + " is: " + this.num 
				* this.num);
	}
}

class CubeThread implements Runnable {
	int num;
	CubeThread(int x) {
		this.num = x;
	}
	
	public void run() { 
		System.out.println("Thread Name:Cube Thread and Square of " + this.num + " is: " + this.num 
				* this.num * this.num);
	}
}

class RandomThread implements Runnable {
	public void run() {
		int num;
		Random r = new Random();
		
		try {
				// Generating random number [1..100]
				num = r.nextInt(100);
				
				System.out.println("Main Thread and Generated Number is " + num);
				
				Thread thread2 = new Thread(new SquareThread(num));
				thread2.start();
				
				Thread thread3 = new Thread(new CubeThread(num));
				thread3.start();
				
				// no idea why but okay shrug
				Thread.sleep(1000);
				System.out.println("__________________________________________");
		} catch(InterruptedException e) {
			System.out.println("Interrupted Exception"); 
		}
	}
}

/**
 * Main Class
 */

class MainThread {
	public static void main(String[] args) { 
		Thread t1 = new Thread(new RandomThread()); 
		t1.start();
	}
}
