package com.lwf.example.net;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
    public static void main(String[] args) {
        Product product = new Product("手机",500,10);
        System.out.println("Waiting...");
        ServerSocket serverSocket=null;
        try {
            serverSocket=new ServerSocket(6666);
            while (true){
                Socket socket=serverSocket.accept();
                new ServerThread(socket,product);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }finally {
            try {
                serverSocket.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
