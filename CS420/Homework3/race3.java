import java.lang.Thread;

public class race3 {

    public static void main(String[] args) {

        final Thread thread1 = new Thread() {
            @Override
            public void run() {
                 
            }
        };

        final Thread thread2 = new Thread() {
            @Override
            public void run() {

            }
        };
    }
}

class Resource {
    private volatile int value;

    public synchronized int getValue() {
        return value;
    }

    public synchronized void setValue(int v) {
        if (Math.abs(value - v) != 1) {
            System.out.println("Mismatch: " + value + " " + v);
        }
        value = v;
    }
}