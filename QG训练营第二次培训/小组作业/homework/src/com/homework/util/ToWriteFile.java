package com.homework.util;

import com.homework.model.History;
import com.homework.model.Msg;
import com.homework.util.DBUtil;
import com.homework.util.SetSql;

import java.io.*;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class ToWriteFile {
    private static Connection connection;
    private static PreparedStatement preparedStatement;

    public static Msg write(String path, String message, int line) {
        if (!checkExists(path).isFlag()) {
            return new Msg("文件不存在", false);
        }
        File file = new File(path);
        return insertText(message, file, line - 1, path);
    }


    public static Msg insertText(String message, File file, int number, String path) {
        Connection connection = null;
        PreparedStatement preparedStatement = null;
        String strTemp;
        int index = 0;
        try {
            //创建一个退出虚拟机时删除的临时文件;
            File temp = File.createTempFile("temp", null);
            temp.deleteOnExit();
            //创建一个RandomAccessFile型
            RandomAccessFile raf = new RandomAccessFile(file, "rw");
            //创建temp的输入输出流;
            FileInputStream tempIn = new FileInputStream(temp);
            FileOutputStream tempOut = new FileOutputStream(temp);
            //创建读取RandomAccessFile,try内会自动close
            try (RandomAccessFile randomAccessFile = new RandomAccessFile(file, "rw")) {
                //循环读取
                while ((strTemp = randomAccessFile.readLine()) != null) {
                    if (index == number) {
                        //行数达到指定数，先将欲写数据写入临时文件
                        tempOut.write(message.getBytes());
                        //再将原本数据写入
                        tempOut.write((strTemp + "\r\n").getBytes());
                    } else if (index > number) {
                        //行数大于指定数，写入原数据
                        tempOut.write((strTemp + "\r\n").getBytes());
                    } else {
                        //行数小于指定数，写光标后移
                        raf.readLine();
                    }
                    index++;
                }
                if (index <= number) {
                    //遍历结束，指针小于指定行数
                    //移动光标到文件尾
                    raf.seek(raf.length());
                    //写入数据
                    raf.write(message.getBytes());
                    try {
                        connection = DBUtil.dbConnection();
                        String sql = SetSql.beSql(message, path, number);
                        preparedStatement = connection.prepareStatement(sql);
                        preparedStatement.executeUpdate(sql);
                    } catch (SQLException e) {
                        e.printStackTrace();
                    } catch (ClassNotFoundException e) {
                        e.printStackTrace();
                    } finally {
                        try {
                            DBUtil.connectionClose(connection, preparedStatement);
                        } catch (SQLException e) {
                            e.printStackTrace();
                        }
                    }
                    return new Msg("文件行数不足，自动添加到末尾", true);
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
        try {
            connection = DBUtil.dbConnection();
            String sql = SetSql.beSql(message, path, number);
            preparedStatement = connection.prepareStatement(sql);
            preparedStatement.executeUpdate(sql);
        } catch (SQLException e) {
            e.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        } finally {
            try {
                DBUtil.connectionClose(connection, preparedStatement);
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        return new Msg("修改成功", true);
    }


    private static Msg checkExists(String path) {
        File file = new File(path);
        File fileParent = file.getParentFile();
        boolean flag = true;
        try {
            if (fileParent != null && !fileParent.exists()) {
                fileParent.mkdirs();
                System.out.println("指定路径不存在，已创建\n");
                return new Msg("创建路径", false);
            }
            if (!file.exists()) {
                file.createNewFile();
                System.out.println("文件不存在，已创建\n");
                return new Msg("创建文件", false);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return new Msg("成功", true);
    }


    public static List<History> Find() {
        List<History> historyList = new ArrayList<History>();
        try {
            //连接数据库
            connection = DBUtil.dbConnection();
            //UserSetSql.FindUserSqlByName(seat);
            //接口赋值
            preparedStatement = connection.prepareStatement("select * from history");
            //结果集赋值
            ResultSet rs = preparedStatement.executeQuery();
            //结果集下一个才是第一个结果
            while (rs.next()) {
                int id = rs.getInt("id");
                String path = rs.getString("path");
                String history = rs.getString("history");
                int number = rs.getInt("line_number");
                String date = rs.getString("date");
                historyList.add(new History(id, path, history, number, date));
            }
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            try {
                DBUtil.connectionClose(connection, preparedStatement);
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        return historyList;
    }
}
