package com.homework;

import com.homework.view.ChangeFrame;

import java.io.*;
import java.util.Scanner;

public class WriteFile {

    public static void main(String[] args) {
        new ChangeFrame().setVisible(true);
        while (true) {
            Scanner scanner = new Scanner(System.in);
            System.out.println("\n文件路径：");
            String path = scanner.next();
            if (!checkExists(path)) {
                continue;
            }
            File file = new File(path);
            System.out.println("\n插入内容：");
            String message = scanner.next();
            System.out.println("\n插入行数：");
            int number = scanner.nextInt();
            insertText(message, file, number - 1);
            System.out.println("\n\n是否退出(Y/N)");
            String con = scanner.next();
            if(con.equals("Y")||con.equals("y")){
                System.out.println("欢迎再次使用！");
                break;
            }
        }
    }


    public static void insertText(String message, File file, int number){
        String strTemp;
        int index = 0;
        try{
            //创建一个退出虚拟机时删除的临时文件;
            File temp = File.createTempFile("temp",null);
            temp.deleteOnExit();
            //创建一个RandomAccessFile型
            RandomAccessFile raf = new RandomAccessFile(file,"rw");
            //创建temp的输入输出流;
            FileInputStream tempIn = new FileInputStream(temp);
            FileOutputStream tempOut = new FileOutputStream(temp);
            //创建读取RandomAccessFile,try内会自动close
            try (RandomAccessFile randomAccessFile = new RandomAccessFile(file, "rw")) {
                //循环读取
                while ((strTemp = randomAccessFile.readLine()) != null) {
                    //System.out.println("index = " + index + "  number = " + number + "  text = " + strTemp);

                    if(index == number){
                        //行数达到指定数，先将欲写数据写入临时文件
                        tempOut.write(message.getBytes());
                        //再将原本数据写入
                        tempOut.write((strTemp+"\r\n").getBytes());
                    }else if (index > number) {
                        //行数大于指定数，写入原数据
                        tempOut.write((strTemp+"\r\n").getBytes());
                    }else{
                        //行数小于指定数，写光标后移
                        raf.readLine();
                    }
                    index++;
                }
                if(index <= number){
                    //遍历结束，指针小于指定行数
                    System.out.println("文件行数不足，自动添加到末尾");
                    //移动光标到文件尾
                    raf.seek(raf.length());
                    //写入数据
                    raf.write(message.getBytes());
                    return;
                }
                //临时文件数据数组
                byte[] fileContent = new byte[(int) temp.length()];
                //读取临时文件数据并存放至数组
                tempIn.read(fileContent);
                //将数组数据写入文件
                raf.write(fileContent);
                //关闭流
                tempIn.close();
                raf.close();
                tempOut.close();
            } catch (IOException e) {
                e.printStackTrace();
            }


        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    private static boolean checkExists(String path) {
        File file = new File(path);
        File fileParent = file.getParentFile();
        boolean flag = true;
        try {
            if (fileParent!=null && !fileParent.exists()) {
                fileParent.mkdirs();
                System.out.println("指定路径不存在，已创建\n");
                return false;
            }
            if (!file.exists()) {
                file.createNewFile();
                System.out.println("文件不存在，已创建\n");
                return false;
            }
        } catch (IOException e) {
            System.out.println("输入异常");
            e.printStackTrace();
        }
        return true;
    }

}
