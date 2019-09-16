import java.lang.Thread;

/*
Course: CS 420
Assignment: Homework 1
Problem: Problem1
Made By: Cameron Stark

Function: 
Instructions: 
*/

public class Problem1 {

    public static void main(String[] args) {
        
        final Thread threadA = new Thread("threadA") {
            @Override
            public void run() {
                for (int i=1; i <= 4000; i++) {
                    System.out.println("A" + i);
                }
            }
        };

        final Thread threadB = new Thread("threadB") {
            @Override
            public void run() {
                for (int i = 1; i <= 4000; i++) {
                    System.out.println("B" + i);
                }
            }
        };

        final Thread threadC = new Thread("threadC") {
            @Override
            public void run() {
                for (int i = 1; i <= 4000; i++) {
                    System.out.println("C" + i);
                }
            }
        };

        threadA.start();
        threadB.start();
        threadC.start();
    }
}