package App;

public class App implements Runnable {
	public static void main(String[] args) {
		App me = new App();
		me.method_A();
	}
	
	private void method_A() {
		Thread t = new Thread(this);
		t.setName("Secondary Thread");
		t.start();
		t.join();
		method_C();
	}
	
	private void method_C() {
		System.out.println("method c executng");
	}
	
	public void run() {
		method_C();
	}
}
