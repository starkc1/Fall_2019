import java.util.Scanner;

import com.sun.org.apache.xalan.internal.xsltc.compiler.util.TypeCheckError;

/*
Write a Java program that prompts the user to enter two integers and displays their sum. 
Use exception handling to prompt the user for reading the number again if the input is incorrect

Assignment: Assignment 1
Made By: Cameron Stark
*/

public class Problem1 {

    public static void main(String[] args) {
        
        Problem1 problem1 = new Problem1();
        int numbers[] = problem1.getUserInput();
    }

    public int[] getUserInput() {
        int nums[] = new int[2];
        int num1;
        int num2;

        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter two integers seperated by a space");
        String[] numString = scanner.nextLine().split(" ");
        num1 = parseInt(numString[0], scanner);

        return nums;
    }

    public static int parseInt(String num, Scanner scanner) {
        boolean correct = false;
        int number;
        while(!correct) {
            try {
                number = Integer.parseInt(numString[0]);
                correct = true;
            } catch (TypeCheckError e) {
                System.out.println("Please re-enter an Integer value");
                numString[0] = scanner.nextLine();
            }
        }

        return number;
    }
}