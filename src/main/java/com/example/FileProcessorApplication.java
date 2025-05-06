package com.example;

import com.example.service.ApiService;
import com.example.service.FileEncodingConverter;
import com.example.service.FileProcessorService;
import com.example.service.UnicodeUtils;
import org.mybatis.spring.annotation.MapperScan;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ConfigurableApplicationContext;

@SpringBootApplication
@MapperScan("com.example.mapper")
public class FileProcessorApplication {

    public static void main(String[] args) {
        ConfigurableApplicationContext context = SpringApplication.run(FileProcessorApplication.class, args);

        // 获取 FileProcessorService bean
        FileProcessorService fileProcessorService = context.getBean(FileProcessorService.class);

        // 获取文件处理器实例
        FileProcessorService processor = context.getBean(FileProcessorService.class);

        // 执行处理流程
        processor.process();

        context.close();
    }
}


