import java.lang.Thread;
import java.util.concurrent.TimeUnit;

/*
Course: CS 420
Assignment: Homework 2
Problem: Problem 2
Made By: Cameron Stark

Function: Program to display the time elapsed and thread priority, when a different priority is given to each thread
Instructions: 
    Step 1: javac Problem2.java
    Step 2: java Problem2.java

    or

    Load file into eclipse and run
*/

public class Problem2 {

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

        threadA.setPriority(Thread.NORM_PRIORITY);
        threadB.setPriority(Thread.MIN_PRIORITY);
        threadC.setPriority(Thread.MAX_PRIORITY);


        long mainStart = System.nanoTime();
        threadA.start();
        threadB.start();
        threadC.start();
        System.out.println("ThreadA Priority: " + threadA.getPriority());
        System.out.println("ThreadB Priority: " + threadB.getPriority());
        System.out.println("ThreadC Priority: " + threadC.getPriority());
        long mainEnd = System.nanoTime();

        long mainDuration = TimeUnit.NANOSECONDS.toMillis(mainEnd - mainStart);

        System.out.println("Main Duration: " + mainDuration);
    }
}