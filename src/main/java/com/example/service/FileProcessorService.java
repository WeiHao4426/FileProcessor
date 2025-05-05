package com.example.service;

import com.example.entity.Datas;
import com.example.entity.Topic;
import com.example.mapper.DatasMapper;
import com.example.mapper.TopicMapper;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Service;

import java.io.*;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

@Service
public class FileProcessorService {
    @Autowired
    private DatasMapper datasMapper;

    @Autowired
    private TopicMapper topicMapper;

    // 批次大小可配置
    @Value("${batch.size:1000}")
    private int BATCH_SIZE;


    private static String studentId;
    private static String name;
    private static String report;
    private static int Aid;
    private static int Bid;
    private static int Cid;
    Datas datas;
    Topic topic = new Topic();




    private void processAllLoop(){
        // 获取最大ID
        Integer maxId = datasMapper.findMaxId();
        if (maxId == null || maxId < 1) {
            return;
        }

        // 分批次处理
        for (int currentBatch = 1; currentBatch <= maxId; currentBatch += BATCH_SIZE) {
            int batchStart = currentBatch;
            int batchEnd = Math.min(currentBatch + BATCH_SIZE - 1, maxId);

            // 获取本批次实际存在的ID
            List<Integer> existIds = datasMapper.findExistIds(batchStart, batchEnd);

            // 处理每个存在的ID
            existIds.forEach(this::processSingleRecord);
        }
    }

    private void processSingleRecord(Integer id) {
        try {
            Datas data = datasMapper.selectById(id);
            if (data != null) {
                // 这里添加具体业务逻辑
                if(data.getA01() == 1)
                {
                    // 读取 A01 代码文件
                    String[] codeLines = FileEncodingConverter.convertCFileToUTF8(data.getA01code());
                    String code = String.join("\n", codeLines);

                    // 读取对应的实验题目
                    topic = topicMapper.getIncludeById(1);

                    // 拼接并输出
                    if (topic != null) {
                        String fullContent = "### 实验题目：\n" + topic.getInclude() + "\n### 学生代码：\n" + code;
                        System.out.println("学生ID：" + data.getStudentid());
                        System.out.println(fullContent);
                        System.out.println("---------成功----------\n 答案:");

                        System.out.println(ApiService.ApiPoster(fullContent));
                    }
                   else System.out.println("---------失败----------");

                }
                if(data.getA02() == 1)
                {
                    // 读取 A01 代码文件
                    String[] codeLines = FileEncodingConverter.convertCFileToUTF8(data.getA02code());
                    String code = String.join("\n", codeLines);

                    // 读取对应的实验题目
                    topic = topicMapper.getIncludeByName("A02");

                    // 拼接并输出
                    String fullContent = "### 实验题目：\n" + topic.getInclude() + "\n### 学生代码：\n" + code;
                    System.out.println("学生ID：" + data.getStudentid());
                    System.out.println(fullContent);
                    System.out.println("-------------------");
                }
                if(data.getA03() == 1)
                {
                    // 读取 A01 代码文件
                    String[] codeLines = FileEncodingConverter.convertCFileToUTF8(data.getA03code());
                    String code = String.join("\n", codeLines);

                    // 读取对应的实验题目
                    topic = topicMapper.getIncludeByName("A03");

                    // 拼接并输出
                    String fullContent = "### 实验题目：\n" + topic.getInclude() + "\n### 学生代码：\n" + code;
                    System.out.println("学生ID：" + data.getStudentid());
                    System.out.println(fullContent);
                    System.out.println("-------------------");
                }
                if(data.getA04() == 1)
                {
                    // 读取 A01 代码文件
                    String[] codeLines = FileEncodingConverter.convertCFileToUTF8(data.getA04code());
                    String code = String.join("\n", codeLines);

                    // 读取对应的实验题目
                    topic = topicMapper.getIncludeByName("A04");

                    // 拼接并输出
                    String fullContent = "### 实验题目：\n" + topic.getInclude() + "\n### 学生代码：\n" + code;
                    System.out.println("学生ID：" + data.getStudentid());
                    System.out.println(fullContent);
                    System.out.println("-------------------");
                }
                if(data.getB01() == 1)
                {
                    // 读取 A01 代码文件
                    String[] codeLines = FileEncodingConverter.convertCFileToUTF8(data.getB01code());
                    String code = String.join("\n", codeLines);

                    // 读取对应的实验题目
                    topic = topicMapper.getIncludeByName("B01");

                    // 拼接并输出
                    String fullContent = "### 实验题目：\n" + topic.getInclude() + "\n### 学生代码：\n" + code;
                    System.out.println("学生ID：" + data.getStudentid());
                    System.out.println(fullContent);
                    System.out.println("-------------------");
                }
                if(data.getB02() == 1)
                {
                    // 读取 A01 代码文件
                    String[] codeLines = FileEncodingConverter.convertCFileToUTF8(data.getB02code());
                    String code = String.join("\n", codeLines);

                    // 读取对应的实验题目
                    topic = topicMapper.getIncludeByName("B02");

                    // 拼接并输出
                    String fullContent = "### 实验题目：\n" + topic.getInclude() + "\n### 学生代码：\n" + code;
                    System.out.println("学生ID：" + data.getStudentid());
                    System.out.println(fullContent);
                    System.out.println("-------------------");
                }
                if(data.getB03() == 1)
                {
                    // 读取 A01 代码文件
                    String[] codeLines = FileEncodingConverter.convertCFileToUTF8(data.getB03code());
                    String code = String.join("\n", codeLines);

                    // 读取对应的实验题目
                    topic = topicMapper.getIncludeByName("B03");

                    // 拼接并输出
                    String fullContent = "### 实验题目：\n" + topic.getInclude() + "\n### 学生代码：\n" + code;
                    System.out.println("学生ID：" + data.getStudentid());
                    System.out.println(fullContent);
                    System.out.println("-------------------");
                }
                if(data.getB04() == 1)
                {
                    // 读取 A01 代码文件
                    String[] codeLines = FileEncodingConverter.convertCFileToUTF8(data.getB04code());
                    String code = String.join("\n", codeLines);

                    // 读取对应的实验题目
                    topic = topicMapper.getIncludeByName("B04");

                    // 拼接并输出
                    String fullContent = "### 实验题目：\n" + topic.getInclude() + "\n### 学生代码：\n" + code;
                    System.out.println("学生ID：" + data.getStudentid());
                    System.out.println(fullContent);
                    System.out.println("-------------------");
                }
                if(data.getC01() == 1)
                {
                    // 读取 A01 代码文件
                    String[] codeLines = FileEncodingConverter.convertCFileToUTF8(data.getC01code());
                    String code = String.join("\n", codeLines);

                    // 读取对应的实验题目
                    topic = topicMapper.getIncludeByName("C01");

                    // 拼接并输出
                    String fullContent = "### 实验题目：\n" + topic.getInclude() + "\n### 学生代码：\n" + code;
                    System.out.println("学生ID：" + data.getStudentid());
                    System.out.println(fullContent);
                    System.out.println("-------------------");
                }
                if(data.getC02() == 1)
                {
                    // 读取 A01 代码文件
                    String[] codeLines = FileEncodingConverter.convertCFileToUTF8(data.getC02code());
                    String code = String.join("\n", codeLines);

                    // 读取对应的实验题目
                    topic = topicMapper.getIncludeByName("C02");

                    // 拼接并输出
                    String fullContent = "### 实验题目：\n" + topic.getInclude() + "\n### 学生代码：\n" + code;
                    System.out.println("学生ID：" + data.getStudentid());
                    System.out.println(fullContent);
                    System.out.println("-------------------");
                }
                if(data.getC03() == 1)
                {
                    // 读取 A01 代码文件
                    String[] codeLines = FileEncodingConverter.convertCFileToUTF8(data.getC03code());
                    String code = String.join("\n", codeLines);

                    // 读取对应的实验题目
                    topic = topicMapper.getIncludeByName("C03");

                    // 拼接并输出
                    String fullContent = "### 实验题目：\n" + topic.getInclude() + "\n### 学生代码：\n" + code;
                    System.out.println("学生ID：" + data.getStudentid());
                    System.out.println(fullContent);
                    System.out.println("-------------------");
                }
                if(data.getC04() == 1)
                {
                    // 读取 A01 代码文件
                    String[] codeLines = FileEncodingConverter.convertCFileToUTF8(data.getC04code());
                    String code = String.join("\n", codeLines);

                    // 读取对应的实验题目
                    topic = topicMapper.getIncludeByName("C04");

                    // 拼接并输出
                    String fullContent = "### 实验题目：\n" + topic.getInclude() + "\n### 学生代码：\n" + code;
                    System.out.println("学生ID：" + data.getStudentid());
                    System.out.println(fullContent);
                    System.out.println("-------------------");
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    //垃圾

    public void process() {
        //processExperimentReports();
        //processComputerExam();
        processAllLoop();
    }


//        datas.setA01(1);//修改datas数据
//        datas.getA02();//获取datas当前数据
//        datasMapper.insert(datas);//插入当前datas到数据库新行
//        datasMapper.updateByStudentId(datas);//根据studentid学号，查找并更新datas到该行
//    }

    private void processExperimentReports() {
        File reportRoot = new File("src/main/数据/实验报告");
        File[] studentDirs = reportRoot.listFiles(File::isDirectory);

        if (studentDirs != null) {
            for (File dir : studentDirs) {
                // 解析学号和姓名
                String[] parts = dir.getName().split("-");
                if (parts.length != 2) continue;

                studentId = parts[0];
                name = parts[1];

                datas.setStudentid(studentId);
                datas.setName(name);

                // 查找并重命名报告文件
                // 使用逻辑或运算符组合条件
                File[] docs = dir.listFiles((d, name) ->
                        name.endsWith(".docx") || name.endsWith(".doc"));

                if (docs != null && docs.length == 1) {
                    File oldFile = docs[0];
                    report = oldFile.getAbsolutePath();
                }

                datas.setStudentid(studentId);
                datas.setName(name);
                datas.setReport(report);

                Datas dbDatas = datasMapper.selectByStudentid(datas.getStudentid());
                //看数据库里是否有这个学生的数据
                if (dbDatas != null) {
                    datasMapper.updateByStudentId(datas);
                }
                else {
                    datasMapper.insert(datas);
                }
                resetDatas(datas);
            }
        }
    }

    private void processComputerExam() {
        File examRoot = new File("src/main/数据/机考");
        File[] studentDirs = examRoot.listFiles(File::isDirectory);

        if (studentDirs != null) {
            for (File studentDir : studentDirs) {
                // 解析学号姓名（无连字符）
                Matcher matcher = Pattern.compile("^([A-Za-z0-9]+)([\u4E00-\u9FA5]+)$")
                        .matcher(studentDir.getName());
                if (!matcher.find()) continue;

                studentId = matcher.group(1);
                name = matcher.group(2);

                datas.setStudentid(studentId);
                datas.setName(name);

                // 初始化机考相关变量
                resetExamVariables();

                // 处理题目目录
                File[] problemDirs = studentDir.listFiles(File::isDirectory);
                if (problemDirs != null) {
                    for (File problemDir : problemDirs) {
                        processProblemDir(problemDir);
                    }
                    Datas dbDatas = datasMapper.selectByStudentid(datas.getStudentid());
                    //看数据库里是否有这个学生的数据
                    if (dbDatas != null) {
                        datasMapper.updateByStudentIdNoRepo(datas);
                    }
                    else {
                        datasMapper.insertNoRepo(datas);
                    }
                    resetDatas(datas);
                }
            }
        }
    }

    private static void resetExamVariables() {
        Aid = 0;
        Bid = 0;
        Cid = 0;
    }

    private static void resetDatas(Datas datas) {
        datas.setStudentid("");
        datas.setName("");
        datas.setReport("");
        datas.setA01(0);
        datas.setA02(0);
        datas.setA03(0);
        datas.setA04(0);
        datas.setB01(0);
        datas.setB02(0);
        datas.setB03(0);
        datas.setB04(0);
        datas.setC01(0);
        datas.setC02(0);
        datas.setC03(0);
        datas.setC04(0);
        datas.setA01code("");
        datas.setA02code("");
        datas.setA03code("");
        datas.setA04code("");
        datas.setB01code("");
        datas.setB02code("");
        datas.setB03code("");
        datas.setB04code("");
        datas.setC01code("");
        datas.setC02code("");
        datas.setC03code("");
        datas.setC04code("");
        datas.setA01report("");
        datas.setA02report("");
        datas.setA03report("");
        datas.setA04report("");
        datas.setB01report("");
        datas.setB02report("");
        datas.setB03report("");
        datas.setB04report("");
        datas.setC01report("");
        datas.setC02report("");
        datas.setC03report("");
        datas.setC04report("");
    }

    private static void processProblemDir(File problemDir) {
        Datas datas = new Datas();
        String dirName = problemDir.getName();
        if (!dirName.matches("^[A-C][0-9]{2}$")) return;

        char type = dirName.charAt(0);
        int id = Integer.parseInt(dirName.substring(1));

        String reportPath = null;
        String codePath = null;

        try {
            // 处理代码文件
            // 使用逻辑或运算符组合条件
            File[] report = problemDir.listFiles((d, name) ->
                    name.endsWith(".docx") || name.endsWith(".doc"));
            if (report != null && report.length == 1) {
                File  reportFile= report[0];
                reportPath = reportFile.getAbsolutePath();
            }
            // 使用逻辑或运算符组合条件
            File[] code = problemDir.listFiles((d, name) ->
                    name.endsWith(".c"));
            if (code != null && code.length == 1) {
                File  codeFile= code[0];
                codePath = codeFile.getAbsolutePath();
            }

            switch (type) {
                case 'A': Aid = id; break;
                case 'B': Bid = id; break;
                case 'C': Cid = id; break;
            }

            switch (Aid){
                case 0: break;
                case 1: datas.setA01(1);datas.setA01code(codePath);datas.setA01report(reportPath); break;
                case 2: datas.setA02(1);datas.setA02code(codePath);datas.setA02report(reportPath); break;
                case 3: datas.setA03(1);datas.setA03code(codePath);datas.setA03report(reportPath); break;
                case 4: datas.setA04(1);datas.setA04code(codePath);datas.setA04report(reportPath); break;
            }
            switch (Bid){
                case 0: break;
                case 1: datas.setB01(1);datas.setB01code(codePath);datas.setB01report(reportPath); break;
                case 2: datas.setB02(1);datas.setB02code(codePath);datas.setB02report(reportPath); break;
                case 3: datas.setB03(1);datas.setB03code(codePath);datas.setB03report(reportPath); break;
                case 4: datas.setB04(1);datas.setB04code(codePath);datas.setB04report(reportPath); break;
            }
            switch (Cid){
                case 0: break;
                case 1: datas.setC01(1);datas.setC01code(codePath);datas.setC01report(reportPath); break;
                case 2: datas.setC02(1);datas.setC02code(codePath);datas.setC02report(reportPath); break;
                case 3: datas.setC03(1);datas.setC03code(codePath);datas.setC03report(reportPath); break;
                case 4: datas.setC04(1);datas.setC04code(codePath);datas.setC04report(reportPath); break;
            }
            reportPath = null;
            codePath = null;
            resetExamVariables();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
