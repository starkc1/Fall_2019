import java.util.Scanner;
import java.util.Random;

/*
Write a Java program that meets the following requirements:
- Creates an array with 100 randomly chosen integers.
- Prompts the user to enter the index of the array, then displays the corresponding element value. 
    If the specified index is out of bounds, display the message Out of Bounds

Assignment: Assignment 1
Problem: Problem 2
Made By: Cameron Stark

*/

public class Problem2 {

    public static void main(String[] args) {
        
        Problem2 problem2 = new Problem2();

        int randomArray[] = problem2.createArray();
        int userIndex = problem2.getUserInput();
        int arrayValue = problem2.getValueAtIndex(randomArray, userIndex);
        if (arrayValue != 0) {
            System.out.println("Value at index of " + userIndex + " is " + arrayValue);
        }
    }

    //create the array of size 100 with random values
    public int[] createArray() {
        int array[] = new int[100];
        Random rand = new Random();

        for (int i = 0; i < 99; i++) {
            array[i] = (rand.nextInt(100) + 1);
        }
        
        return array;
    }

    //requests for user input
    public int getUserInput() {
        Scanner scanner = new Scanner(System.in);
        int index = 0;

        System.out.println("Enter An integer value for the index of the array");
        index = scanner.nextInt();

        scanner.close();
        return index;
    }

    //takes the random array and the user input and checks for value at index if no index, throws exception
    public int getValueAtIndex(int array[], int index) {
        int value = 0;

        try {
            value = array[index];
        } catch (IndexOutOfBoundsException e) {
            System.out.println("Out Of Bounds");
        }

        return value;
    }




}