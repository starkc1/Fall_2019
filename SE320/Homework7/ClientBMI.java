import java.io.*;
import java.net.*;
import java.util.Scanner;
import java.awt.*;
import java.awt.event.*;

public class ClientBMI {
    public static void main(String[] args) {
        new ClientBMI();
    }

    private DataOutputStream outputStream;
    private DataInputStream inputStream;
    public ClientBMI() {


        try {
            Socket socket = new Socket("localhost", 8000);

            inputStream = new DataInputStream(socket.getInputStream());

            outputStream = new DataOutputStream(socket.getOutputStream());
            
            System.out.println("Enter Weight in Kilograms: ");
            Scanner scanner = new Scanner(System.in);
            double weight = scanner.nextDouble();
    
            System.out.println("\nEnter Height in Inches: ");
            double height = scanner.nextDouble();
    
            scanner.close();


            String info = weight + " " + height;
            outputStream.writeUTF(info);;
            outputStream.flush();
    
            double bmiValue = inputStream.readDouble();
            System.out.println("\n\nWeight: " + weight);
            System.out.println("\nHeight: " + height);
            String status = "";
            if (bmiValue < 18.5) {
                status = "underweight";
            } else if (18.5 < bmiValue && bmiValue < 24.9) {
                status = "normal";
            } else if (25.0 < bmiValue && bmiValue < 29.9) {
                status = "overweight";
            } else if (bmiValue > 30.0) {
                status = "obese";
            }
            System.out.println("\nBMI: " + bmiValue + " " + status);
            
            socket.close();
        } catch (IOException e) {

        }

    }
}