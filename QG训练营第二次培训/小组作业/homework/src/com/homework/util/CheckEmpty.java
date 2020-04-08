package com.homework.util;

public class CheckEmpty {
    /**
     * 验证文本是否为空
     *
     * @param theText 待验证文本
     * @return
     */
    public static boolean isEmpty(String theText) {
        if (theText == null || theText.equals("")) {
            return true;
        }
        return false;
    }

}
