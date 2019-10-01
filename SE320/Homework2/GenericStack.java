import java.util.Arrays;

public class GenericStack<E> {

    private Object[] list;
    
    //Default constructor with a size of 10
    public GenericStack() {
        list = new Object[10];
    }

    //Constructor 
    public GenericStack(int size) {
        list = new Object[size];
    }

    public int getSize() {
        return list.length;
    }

    public E peek() {
        if (list.length <= 0) {
            return null;
        } else {
            return list[0];
        }
    }

    // public E push() {
        
    // }

    // public E pop() {

    // }

    // public boolean isEmpty() {

    // }

    public static void main(String[] args) {
        GenericStack<String> stack = new GenericStack();

        System.out.println(stack);
    }
}