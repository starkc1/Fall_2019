import java.util.ArrayList;

public class Problem2 {

    //Function that removes and checks if duplicates exist
    public static <E> ArrayList<E> removeDuplicates(ArrayList<E> list) {
        ArrayList<E> duplicatedItems = new ArrayList<E>();
        ArrayList<E> secondList = new ArrayList<E>();

        for (E item : list) {
            if (secondList.contains(item)) {
                duplicatedItems.add(item);
            } else {
                secondList.add(item);
            }
        }

        return duplicatedItems;
    }

    public static void main(String[] args) {
        ArrayList<Integer> list = new ArrayList<Integer>();

        list.add(14);
        list.add(24);
        list.add(14);
        list.add(42);
        list.add(25);
        

        ArrayList<Integer> newList = removeDuplicates(list);

        System.out.print(newList);
    }
}