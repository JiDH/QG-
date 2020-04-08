package com.homework.util;

import java.text.SimpleDateFormat;
import java.util.Date;

public class SetSql {
    public static String beSql(String message,String path,int line){
        SimpleDateFormat sdf =new SimpleDateFormat("yyyy-MM-dd HH:mm:ss" );
        Date d= new Date();
        line++;
        String date = sdf.format(d);
        return "insert into history values(null,'"+path+"','"+ message +"',"+line+",'"+date+"')";
    }

}
