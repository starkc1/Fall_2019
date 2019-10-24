import java.lang.Thread;

/*
Course: CS 420
Assignment: Homework 3
Problem: Problem 2
Made By: Cameron Stark
Function: A Program to show how the jvm handles and organizes treads that are changing the same value
Instructions: 
    Step 1: javac race2.java
    Step 2: java race2.java
    or
    Load file into eclipse and run
*/

public class race2 {
    static Resource sharedResource = new Resource();

    public static void main(String[] args) {

        final Thread thread1 = new Thread() {
            @Override
            public void run() {
                int i = 0;
                while(true) {
                    int value = sharedResource.getValue();
                    System.out.println(value);
                    sharedResource.setValue(value + 1);
                }
            }
        };

        final Thread thread2 = new Thread() {
            @Override
            public void run() {
                int i = 0; 
                while(true) {
                    int value = sharedResource.getValue();
                    System.out.println(value);
                    sharedResource.setValue(value - 1);
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
