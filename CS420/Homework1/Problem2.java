import java.lang.Thread;
import java.lang.Runnable;

/*
Course: CS 420
Assignment: Homework 1
Problem: Problem2
Made By: Cameron Stark

Function: Start Three Threads but implement as runnables and have them print from 1 to 4000 with a letter at the from A, B, or C
Instructions: 
    Step 1: javac Problem2.java
    Step 2: java Problem2.java

    or

    Load file into eclipse and run
*/

public class Problem2 implements Runnable {

    public String Id;
    public Problem2(String letter) {
        this.Id = letter;
    }

    @Override
    public void run() {
        for (int i = 1; i <= 4000; i++) {
            System.out.println(this.Id + i);
        }
    }

    public static void main(String[] args) {
        Thread threadA = new Thread(new Problem2("A"));
        threadA.start();

        Thread threadB = new Thread(new Problem2("B"));
        threadB.start();

        Thread threadC = new Thread(new Problem2("C"));
        threadC.start();
    }
}