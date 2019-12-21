import java.io.*;
import java.net.*;
import java.util.Scanner;
import java.awt.*;
import java.awt.event.*;

public class Multi_ServerBMI {
    public static void main(String[] args) {
        new Multi_ServerBMI();
    }

    private DataOutputStream outputStream;
    private DataInputStream inputStream;
    private int i = 0;
    public Multi_ServerBMI() {
        try {
            ServerSocket server = new ServerSocket(8000);
            System.out.println("Server started\n");

            while (true) {
                Socket socket = server.accept();
                i++;
                Thread thread = new Thread(new Runnable() {
                    @Override
                    public void run() {
                        System.out.println("Client " + i + " Connected");
                        try {
                            DataInputStream inputStream = new DataInputStream(socket.getInputStream());
                            DataOutputStream outputStream = new DataOutputStream(socket.getOutputStream());
            
                        
                            String value = inputStream.readUTF();
                            //System.out.println(value);
                            String[] values = value.split(" ");
                            System.out.println("Weight: " + values[0] + "\nHeight: " + values[1]);
            
                            double bmi = (Double.parseDouble(values[0]) / (Double.parseDouble(values[1]) * Double.parseDouble(values[1]))) * 703;
            
                            outputStream.writeDouble(bmi);
            
                        } catch (IOException e) {
                
                        }
                        
                    }
                });
                thread.start();

            }
        } catch (IOException e) {

        }
            
            

           
        

    }
}