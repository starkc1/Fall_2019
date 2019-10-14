import java.lang.Thread;
import java.util.Random;

/*
Course: CS 420
Assignment: Homework 3
Problem: Problem 1
Made By: Cameron Stark
Function: A Program to show how the sleep of thread either before or after a function and value change can cause race hazards but 
    with the addition of the functions being used are synchronized
Instructions: 
    Step 1: javac race3.java
    Step 2: java race3.java
    or
    Load file into eclipse and run
*/

public class race3 {
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
                        int value = sharedResource.getValue();
                        System.out.println(value);
                        sharedResource.setValue(value + 1);
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
                        int value = sharedResource.getValue();
                        System.out.println(value);
                        sharedResource.setValue(value - 1);
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