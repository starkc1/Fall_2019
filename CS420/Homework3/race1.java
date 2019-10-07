import java.lang.Thread;
import java.util.Random;

public class race1 {
    static Resource sharedResource = new Resource();

    public static void main(String[] args) {
                
        Random rand = new Random();
        
        
        final Thread thread1 = new Thread() {
            @Override
            public void run() {
                try {
                    int i = 0;
                    while(true) {
                        Thread.sleep(rand.nextInt(200 - 10) + 10);
                        i++;
                        System.out.println(sharedResource.getValue());
                        sharedResource.setValue(i);
                    }
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        };

        final Thread thread2 = new Thread() {
            @Override
            public void run() {
                try {
                    int i = 0;
                    while(true) {
                        System.out.println(sharedResource.getValue());
                        i--;
                        sharedResource.setValue(i);
                        Thread.sleep(rand.nextInt(200 - 10) + 10);
                    }
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        };

        thread1.start();
        thread2.start();
    }    
}

class Resource {
    private volatile int value;

    public int getValue() {
        return value;
    }

    public void setValue(int v) {
        if (Math.abs(value - v) != 1) {
            System.out.println("Mismatch: " + value  + " " + v);
        }
        value = v;
    }
}
