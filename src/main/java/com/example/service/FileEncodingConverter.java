package com.example.service;

import org.springframework.stereotype.Component;

import org.mozilla.universalchardet.UniversalDetector;
import java.io.*;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;

public class FileEncodingConverter {
    
    public static String[] convertCFileToUTF8(String filePath) throws IOException {
        // 检查文件是否为 .c 文件
        if (!filePath.toLowerCase().endsWith(".c")) {
            throw new IllegalArgumentException("仅支持 .c 文件");
        }

        // 读取文件字节
        Path path = Paths.get(filePath);
        byte[] fileContent = Files.readAllBytes(path);
        
        // 检测编码
        String encoding = detectEncoding(fileContent);
        if (encoding == null) {
            encoding = "UTF-8"; // 默认回退
        }

        // 转换编码并读取内容
        String fileText = new String(fileContent, Charset.forName(encoding))
                .replaceAll("﻿", ""); // 移除BOM

        // 按行分割
        return fileText.split("\n");
    }

    private static String detectEncoding(byte[] bytes) {
        UniversalDetector detector = new UniversalDetector(null);
        detector.handleData(bytes, 0, bytes.length);
        detector.dataEnd();
        return detector.getDetectedCharset();
    }
}