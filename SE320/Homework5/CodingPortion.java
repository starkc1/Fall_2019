/**
 * SE 320
 * Assigment 5
 * Problem 2
 * Cameron Stark
 */
class Person {
    private String firstName;
    private String lastName;

    public boolean equals(Object obj) {
        if (!(obj instanceof Person)) return false;
        
        Person that = (Person) obj;

        return this.lastName.toUpperCase().equals(that.lastName.toUpperCase());
    }

    public int hashCode() {
        return this.lastName.toUpperCase().hashCode();
    }
}

/**
 * SE 320
 * Assigment 5
 * Problem 3
 * Cameron Stark
 */
public interface PrintPredicate {
    String makeString(Apple apple);
}

public class PrintAppleWeight implements PrintPredicate {
    String makeString(Apple apple) {
        return apple.weight.toString();
    }
}

public class FormattedPrintAppleWeight implements PrintPredicate {
    String makeString(Apple apple) {
        return "Weight of " + apple.name + ": " + apple.weight.toString();
    }
}

class Printing {
    public static  void prettyPrintApple(List<Apple> inventory, PrintPredicate print) {
        for (Apple apple : inventory) {
            String output = print.makeString(apple);

            System.out.println(output);
        }
    } 
}