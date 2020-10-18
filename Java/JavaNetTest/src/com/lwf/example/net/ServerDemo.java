package com.lwf.example.net;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

public class ServerDemo {
    public static void main(String[] args) {
        try {
            ServerSocket serverSocktet = new ServerSocket(6565);
            while (true){
                Socket socket=serverSocktet.accept();
                DataInputStream in=new DataInputStream(socket.getInputStream());
                DataOutputStream out=new DataOutputStream(socket.getOutputStream());
                String str;
                while(true){
                    str=in.readUTF();
                    System.out.println("来自"+socket.getInetAddress().getHostName()+"的信息:"+str);
                    System.out.println("请回答:");
                    Scanner sc=new Scanner(System.in);
                    str=sc.next();
                    out.writeUTF(str);
                }
            }
        } catch (IOException e) {
            System.out.println("网路连接出现异常！");
            e.printStackTrace();
        }
    }
}
