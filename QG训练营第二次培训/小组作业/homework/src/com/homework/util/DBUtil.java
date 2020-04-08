package com.homework.util;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

/**
 * 数据库相关工具类
 * 执行连接和关闭功能
 */

public class DBUtil {
    //数据库驱动
    public static String theDriver = "com.mysql.jdbc.Driver";
    //数据库用户名
    public static String dbUserName = "root";
    //数据库密码
    public static String dbPassword = "admin";
    //数据库地址
    public static String dbUrl = "jdbc:mysql://127.0.0.1:3306/file_history?characterEncoding=UTF-8";


    /**
     * 获取数据库连接
     *
     * @return 连接
     * @throws ClassNotFoundException 未找到Drive,可能未设置依赖
     * @throws SQLException           未找到数据库,可能是数据库密码或账号错误
     */
    public static Connection dbConnection() throws ClassNotFoundException, SQLException {
        Class.forName(theDriver);
        Connection connection = DriverManager.getConnection(dbUrl, dbUserName, dbPassword);
        return connection;
    }

    /**
     * 关闭数据库连接
     *
     * @param connection 待关闭连接
     * @throws SQLException 关闭异常,可能是没有连接或已关闭。
     */
    public static void connectionClose(Connection connection) throws SQLException {
        if (connection != null) {
            connection.close();
        }
    }

    public static void connectionClose(Connection connection, PreparedStatement preparedStatement) throws SQLException {
        if (preparedStatement != null) {
            preparedStatement.close();
            if (connection != null) {
                connection.close();
            }
        }
    }
}
