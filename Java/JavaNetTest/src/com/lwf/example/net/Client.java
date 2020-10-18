package com.lwf.example.net;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;

public class Client {
    public static void main(String[] args) {
        try {
            Scanner sc=new Scanner(System.in);
            System.out.println("请输入订购数量:");
            int num=sc.nextInt();
            Socket socket=new Socket("127.0.0.1",6666);
            DataOutputStream out=new DataOutputStream(socket.getOutputStream());
            out.writeInt(num);
            DataInputStream in=new DataInputStream(socket.getInputStream());
            String result=in.readUTF();
            System.out.println(result);
            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
