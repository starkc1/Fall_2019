import java.lang.Thread;
import java.util.concurrent.TimeUnit;

/*
Course: CS 420
Assignment: Homework 2
Problem: Problem 3
Made By: Cameron Stark

Function: Program to have each thread join, therefore causing the program to wait until the previous thread closes.
Instructions: 
    Step 1: javac Problem3.java
    Step 2: java Problem3.java

    or

    Load file into eclipse and run
*/

public class Problem3 {

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
        try {
            threadA.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        threadB.start();
        try {
            threadB.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        threadC.start();
        try {
            threadC.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        long mainEnd = System.nanoTime();

        long mainDuration = TimeUnit.NANOSECONDS.toMillis(mainEnd - mainStart);

        System.out.println("Main Duration: " + mainDuration);
    }
}