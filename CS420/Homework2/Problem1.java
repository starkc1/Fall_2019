import java.lang.Thread;
import java.time.Duration;
import java.util.concurrent.TimeUnit;
/*
Course: CS 420
Assignment: Homework 2
Problem: Problem1
Made By: Cameron Stark

Function: 
Instructions: 
    Step 1: javac Problem1.java
    Step 2: java Problem1.java

    or

    Load file into eclipse and run
*/

public class Problem1 {

    public static void main(String[] args) {


        final Thread threadA = new Thread("threadA") {
            @Override
            public void run() {
                long threadStart = System.nanoTime();
                try {
                    Thread.sleep(500);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                long threadEnd = System.nanoTime();

                long threadDuration = TimeUnit.NANOSECONDS.toMillis(threadEnd - threadStart);
                System.out.println("ThreadA Duration: " + threadDuration);
            }
        };

        final Thread threadB = new Thread("threadB") {
            @Override
            public void run() {
                long threadStart = System.nanoTime();

                try {
                    Thread.sleep(500);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }

                long threadEnd = System.nanoTime();

                long threadDuration = TimeUnit.NANOSECONDS.toMillis(threadEnd - threadStart);

                System.out.println("ThreadB Duration: " + threadDuration);
            }
        };

        final Thread threadC = new Thread("threadC") {
            @Override
            public void run() {
                long threadStart = System.nanoTime();

                try {
                    Thread.sleep(1300);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }

                long threadEnd = System.nanoTime();

                long threadDuration = TimeUnit.NANOSECONDS.toMillis(threadEnd - threadStart);

                System.out.println("ThreadC Duration: " + threadDuration);
            }
        };

        long mainStart = System.nanoTime();
        threadA.start();
        threadB.start();
        threadC.start();
        long mainEnd = System.nanoTime();

        long mainDuration = TimeUnit.NANOSECONDS.toMillis(mainEnd - mainStart);

        System.out.println("Main Duration: " + mainDuration);
    }
}
