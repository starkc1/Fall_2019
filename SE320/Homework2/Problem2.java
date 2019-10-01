import java.util.ArrayList;

public class problem2 {

    public static <E> ArrayList<E> removeDuplicates(ArrayList<E> list) {
        
    }

    public static void main(String[] args) {
        ArrayList<Integer> list = new ArrayList<Integer>();

        list.add(14);
        list.add(24);
        list.add(14);
        list.add(42);
        list.add(25);

        ArrayList<Integer> newList = new removeDuplicates(list);

        System.out.print(newList);
    }
}