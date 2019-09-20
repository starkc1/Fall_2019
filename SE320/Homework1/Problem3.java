import java.util.Scanner;

/*
Write a Java program that prompts the user to enter a number between 0 and 10 and displays the entered number. 
Use an "assert statement" to determine whether the user entered a number within the valid range. 
If the user entered a number that is out of range, 
    the program must reports an error with assertion error message "The entered number is out of range"


Assignment: Assignment 1
Problem: Problem 3
Made By: Cameron Stark
*/

public class Problem3 {

    
    public static void main(String[] args) {
        Problem3 problem3 = new Problem3();

        int userValue = problem3.getUserValue();
        
        problem3.checkIfLessThan0(userValue);
        problem3.checkIfGreaterThan10(userValue);
    }

    //requests user for integer between 0 and 10
    public int getUserValue() {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter an integer between 0 and 10");
        int value = scanner.nextInt();
        System.out.println("Value Entered: " + value);
        scanner.close();
        return value;
    }

    //uses an assertion to check if value is less than 0
    public void checkIfLessThan0(int value) {
        assert (value < 0) : "The Entered Number is out of range";
    }

    //uses an assertion to check if value is greater than 10
    public void checkIfGreaterThan10(int value) {
        assert (value > 10) : "The Entered Number is out of range";
    }
}
