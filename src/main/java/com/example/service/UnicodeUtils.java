package com.example.service;


import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class UnicodeUtils {
    /**
     * 转换Unicode转义序列
     * 示例："\u4f60\u597d" -> "你好"
     */
    public static String unicodeToString(String unicodeStr) {
        Pattern pattern = Pattern.compile("(\\\\u[0-9a-fA-F]{4})");
        Matcher matcher = pattern.matcher(unicodeStr);
        StringBuffer sb = new StringBuffer();

        while (matcher.find()) {
            String group = matcher.group(1);
            char ch = (char) Integer.parseInt(group.substring(2), 16);
            matcher.appendReplacement(sb, String.valueOf(ch));
        }
        matcher.appendTail(sb);

        return sb.toString();
    }
}