package com.example.service;

import com.example.client.DifyApiClient;
import com.fasterxml.jackson.databind.JsonNode;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.databind.node.ObjectNode;

import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class ApiService {

    public static String ApiPoster(String dynamicQuery) {
        String apiKey = "app-HdDir9lLF2cGLkLJ6NZWPpgm";
        DifyApiClient client = new DifyApiClient(apiKey);

        String answer = null;

        ObjectMapper mapper = new ObjectMapper();
        ObjectNode requestBody = mapper.createObjectNode();

        // 根据新要求构建请求体
        requestBody.set("inputs", mapper.createObjectNode());  // 空对象
        requestBody.put("query", dynamicQuery);
        requestBody.put("response_mode", "blocking");
        requestBody.put("conversation_id", "");
        requestBody.put("user", "abc-123");

        try {
            String response = client.post("/chat-messages", requestBody.toString());
            try {
                JsonNode rootNode = mapper.readTree(response);
                answer = rootNode.get("answer").asText();

                answer = unicodeDecode(answer);

                System.out.println("提取的 answer 内容：");
                System.out.println(answer);
            } catch (Exception e) {
                e.printStackTrace();
            }

            System.out.println("API响应: " + response);
        } catch (Exception e) {
            e.printStackTrace();
        }

        return answer;
    }

    public static String unicodeDecode(String string) {
        Pattern pattern = Pattern.compile("(\\\\u(\\p{XDigit}{4}))");
        Matcher matcher = pattern.matcher(string);
        char ch;
        while (matcher.find()) {
            ch = (char) Integer.parseInt(matcher.group(2), 16);
            string = string.replace(matcher.group(1), ch + "");
        }
        return string;
    }
}

