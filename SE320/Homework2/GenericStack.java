import java.util.Arrays;

public class GenericStack<E> {

    private E[] list;
    
    //Default constructor with a size of 10
    public GenericStack() {
        list = new E[10];
    }

    //Constructor of specificed size
    public GenericStack(int size) {
        list = new E[size];
    }

    public int getSize() {
        return list.length;
    }

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

    public void push(E item) {
        Object[] newList;
        if (list[getSize() - 1] != null) {
            newList = new Object[getSize() * 2];

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

    public boolean isEmpty() {
        boolean empty = true;

        for (int i = 0; i < getSize(); i++) {
            if (list[i] != null) {
                empty = false;
            }
        }

        return empty;
    }

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