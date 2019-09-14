import java.util.Scanner;

import com.sun.org.apache.xalan.internal.xsltc.compiler.util.TypeCheckError;

/*
Write a Java program that prompts the user to enter two integers and displays their sum. 
Use exception handling to prompt the user for reading the number again if the input is incorrect

Assignment: Assignment 1
Problem: Problem 1
Made By: Cameron Stark
*/

public class Problem1 {

    public static void main(String[] args) {
        
        Problem1 problem1 = new Problem1();
        int numbers[] = problem1.getUserInput();

        //System.out.println(numbers[0] + " " + numbers[1]);
        int result = problem1.addNumbers(numbers);
        System.out.println(numbers[0] + " + " + numbers[1] + " = " + result);
    }

    public int[] getUserInput() {
        int nums[] = new int[2];
        int num1;
        int num2;

        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the first integer");
        num1 = parseInt(scanner.nextLine(), scanner);
        System.out.println("Enter the second integer");
        num2 = parseInt(scanner.nextLine(), scanner);

        nums[0] = num1;
        nums[1] = num2;
        scanner.close();
        return nums;
    }

    public static int parseInt(String num, Scanner scanner) {
        boolean correct = false;
        int number = 0;
        while(!correct) {
            try {
                number = Integer.parseInt(num);
                correct = true;
            } catch (NumberFormatException e) {
                System.out.println("ERROR: Please re-enter an Integer value");
                num = scanner.nextLine();
            }
        }

        return number;
    }

    public int addNumbers(int[] nums) {
        int result;

        if (nums.length < 2) {
            result = 0;
        } else {
            result = nums[0] + nums[1];
        }
        return result;
    }
}