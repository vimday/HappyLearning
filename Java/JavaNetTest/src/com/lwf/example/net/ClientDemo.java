package com.lwf.example.net;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.util.Scanner;

public class ClientDemo {
    public static void main(String[] args) {
        try {
            Socket socket = new Socket("127.0.0.1",6565);
            DataOutputStream out=new DataOutputStream(socket.getOutputStream());
            DataInputStream in=new DataInputStream(socket.getInputStream());
            String str;
            while (true){
                System.out.println("请输入要发送的信息：");
                Scanner sc=new Scanner(System.in);
                str=sc.next();
                out.writeUTF(str);
                str=in.readUTF();
                System.out.println("服务器："+str);
            }
        } catch (IOException e) {
            System.out.println("网路连接出现异常！");
            e.printStackTrace();
        }
    }
}
