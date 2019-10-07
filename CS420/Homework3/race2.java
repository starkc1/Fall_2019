import java.lang.Thread;

public class race2 {
    static Resource sharedResource = new Resource();

    public static void main(String[] args) {

        final Thread thread1 = new Thread() {
            @Override
            public void run() {
                int i = 0;
                while(true) {
                    i++;
                    System.out.println(sharedResource.getValue());
                    sharedResource.setValue(i);
                }
            }
        };

        final Thread thread2 = new Thread() {
            @Override
            public void run() {
                int i = 0; 
                while(true) {
                    i--;
                    System.out.println(sharedResource.getValue());
                    sharedResource.setValue(i);
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
