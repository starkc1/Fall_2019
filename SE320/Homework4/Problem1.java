import java.util;
import java.util.GregorianCalendar;

public class Problem1 {

    public Problem1() {

    }

    public static void main(String args[]) {
        //System.out.println("Hello World");
        Problem1 problem1 = new Problem1();
        GregorianCalendar gCalendar = new GregorianCalendar();
        long dateToConvert = 1234567898765L;
        
        problem1.displayCurrentDate(gCalendar);
        problem1.displayDateFromMillis(dateToConvert, gCalendar);
    }

    public void displayCurrentDate(GregorianCalendar gCalendar) {
        
        int year = getYear(gCalendar);
        int month = getMonth(gCalendar);
        int day = getDayOfMonth(gCalendar);
        
        printResult("Current Day", month, day, year);
    }

    public void displayDateFromMillis(long date, GregorianCalendar gCalendar) {
        gCalendar.setTimeInMillis(date);

        int year = getYear(gCalendar);
        int month = getMonth(gCalendar);
        int day = getDayOfMonth(gCalendar);

        printResult("Converted Day", month, day, year);
    }

    public static int getYear(GregorianCalendar gCalendar) {
        return gCalendar.get(GregorianCalendar.YEAR);
    }

    public static int getMonth(GregorianCalendar gCalendar) {
        return gCalendar.get(GregorianCalendar.MONTH);
    }

    public static int getDayOfMonth(GregorianCalendar gCalendar) {
        return gCalendar.get(GregorianCalendar.DAY_OF_MONTH);
    }
 
    public static void printResult(String label, int month, int day, int year) {
        System.out.println(label + ": " + month + "/" + day + "/" + year);
    }
}