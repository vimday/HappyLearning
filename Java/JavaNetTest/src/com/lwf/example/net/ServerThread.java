package com.lwf.example.net;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;

public class ServerThread extends Thread {


    private Socket clientSocket;
    private DataInputStream clientInput;
    private DataOutputStream clientOutput;
    private Product product;

    public ServerThread(Socket clientSocket, Product product) throws IOException {
        this.clientSocket = clientSocket;
        this.clientInput = new DataInputStream(this.clientSocket.getInputStream());
        this.clientOutput = new DataOutputStream(this.clientSocket.getOutputStream());
        this.product = product;
        this.start();
    }

    @Override
    public void run() {
        try {
            int num = this.clientInput.readInt();
            System.out.println("收到订购" + num + "件商品的请求");
            synchronized (this.product) {
                if (this.product.getNum() >= num) {
                    try {
                        Thread.sleep(5000);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }

                    this.product.setNum(this.product.getNum() - num);

                    this.clientOutput.writeUTF("订购成功！商品库存剩余" + this.product.getNum());
                } else {
                    this.clientOutput.writeUTF("订购失败！商品库存剩余" + this.product.getNum());
                }
            }
        } catch (IOException e) {
            try {
                this.clientOutput.writeUTF("系统异常，操作失败！");
            } catch (IOException ex) {
                ex.printStackTrace();
            }
            e.printStackTrace();
        } finally {
            try {
                this.clientOutput.close();
                this.clientInput.close();
                this.clientSocket.close();
            } catch (IOException e) {
                e.printStackTrace();
            }

        }
    }
}
