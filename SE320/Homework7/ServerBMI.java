import java.io.*;
import java.net.*;
import java.util.Scanner;
import java.awt.*;
import java.awt.event.*;

public class ServerBMI {
    public static void main(String[] args) {
        new ServerBMI();
    }

    private DataOutputStream outputStream;
    private DataInputStream inputStream;
    public ServerBMI() {
        try {
            ServerSocket server = new ServerSocket(8000);
            System.out.println("Server started\n");

            while (true) {
                Socket socket = server.accept();

                DataInputStream inputStream = new DataInputStream(socket.getInputStream());
                DataOutputStream outputStream = new DataOutputStream(socket.getOutputStream());

            
                String value = inputStream.readUTF();
                //System.out.println(value);
                String[] values = value.split(" ");
                System.out.println("Weight: " + values[0] + "\nHeight: " + values[1]);

                double bmi = (Double.parseDouble(values[0]) / (Double.parseDouble(values[1]) * Double.parseDouble(values[1]))) * 703;

                outputStream.writeDouble(bmi);
            }
        } catch (IOException e) {

        }
    }
}