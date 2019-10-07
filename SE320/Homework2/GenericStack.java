import java.util.Arrays;

/*
Convert the provied Generic Stack with an ArrayList implementation to an Array implementation.
Assumptions
    - Array Stack format will be the top of stack will be the last non null value
    - Peeks will reveal the top of stack/last of array
    - Push will insert to top of stack/first null index

Assignment: Assignment 2
Problem: Problem 1
Made By: Cameron Stark
*/

public class GenericStack<E> {

    private E[] list;
    
    //Default constructor with a size of 10
    public GenericStack() {
        list = (E[])new Object[10];
    }

    //Constructor of specificed size
    public GenericStack(int size) {
        list = (E[])new Object[size];
    }

    //Function to get the size of the array
    public int getSize() {
        return list.length;
    }

    //Function to get the most recent pushed item
    public E peek() {
        if (getSize() <= 0) {
            return null;
        } else {
            for (int i = 0; i < getSize(); i++) {
                if (list[i] == null) {
                    return (E)list[i-1];
                } 
            }
        }
        return null;
    }

    //Function to push an item to the first null location of the array
    public void push(E item) {
        E[] newList;
        if (list[getSize() - 1] != null) {
            newList = (E[])new Object[getSize() * 2];

            for (int i = 0; i < getSize(); i++) {
                newList[i] = list[i];
            }

            newList[getSize()] = item;
            list = newList;
        } else {
            for (int i = 0; i < getSize(); i++) {
                if (list[i] == null) {
                    list[i] = item;
                    break;
                } 
            }
        }
    }

    //Function that removes the most recently inserted item and returns that item
    public E pop() {
        E poppedItem = null;

        if (getSize() <= 0) {
            return null;
        } else {
            for (int i = 0; i < getSize(); i++) {
                if (list[i] == null) {
                    poppedItem = (E)list[i - 1];
                    list[i - 1] = null;
                    break;   
                }
            }
        }

        return poppedItem;
    }

    //Function that checks if array has any value that is not a null
    public boolean isEmpty() {
        boolean empty = true;

        for (int i = 0; i < getSize(); i++) {
            if (list[i] != null) {
                empty = false;
            }
        }

        return empty;
    }

    //Function that overrides the default toString method to print the array
    @Override
    public String toString() {
        String arrayString = "";
        for(int i = 0; i < list.length; i++) {
            arrayString = arrayString + list[i] + " ";
        }
        return arrayString;
    }

    
    public static void main(String[] args) {
        GenericStack<String> stack = new GenericStack();

        System.out.println("Empty Default Stack: \n" + stack.toString()); 

        stack.push("First");
        stack.push("Second");
        stack.push("Third");
        stack.push("Fourth");
        stack.push("Fifth");
        stack.push("Sixtth");
        stack.push("Seventh");
        stack.push("Eighth");
        stack.push("Ninth");
        stack.push("Tenth");

        System.out.println("\nFull Stack: \n" + stack.toString());

        stack.push("Eleventh");

        System.out.println("\nSize Expanded Stack: \n" + stack.toString());

        String peekedItem = stack.peek();
        System.out.println("\nPeeked Item Of Stack: \n" + peekedItem);

        String poppedItem = stack.pop();
        System.out.println("\nPopped Item Of Stack: \n" + poppedItem);
        System.out.println("\nStack After Pop: \n" + stack.toString());


        boolean isEmpty = stack.isEmpty();
        System.out.println("\nIs Stack Empty: \n" + isEmpty);
   
    }
}