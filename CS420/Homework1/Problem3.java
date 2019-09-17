import java.lang.Thread;
import java.lang.Runnable;

/*
Course: CS 420
Assignment: Homework 1
Problem: Problem3
Made By: Cameron Stark

Function: 
Instructions: 
*/

public class Problem3 implements Runnable {

    public String Id;
    public Problem3(String letter) {
        this.Id = letter;
    }

    @Override
    public void run() {
        for (int i = 1; i <= 4000; i++) {
            if (i % 10 == 0) {
                Thread.yield();
            }
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
