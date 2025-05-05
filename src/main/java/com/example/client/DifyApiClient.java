package com.example.client;


import org.apache.http.HttpEntity;
import org.apache.http.client.methods.CloseableHttpResponse;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.entity.StringEntity;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.impl.client.HttpClients;
import org.apache.http.util.EntityUtils;

public class DifyApiClient {
    private static final String API_BASE_URL = "http://localhost/v1";
    private final String apiKey;

    public DifyApiClient(String apiKey) {
        this.apiKey = apiKey;
    }

    public String post(String endpoint, String requestBody) throws Exception {
        try (CloseableHttpClient httpClient = HttpClients.createDefault()) {
            HttpPost httpPost = new HttpPost(API_BASE_URL + endpoint);

            // 设置请求头
            httpPost.setHeader("Authorization", "Bearer " + apiKey);
            httpPost.setHeader("Content-Type", "application/json");

            // 设置请求体
            httpPost.setEntity(new StringEntity(requestBody));

            // 执行请求
            try (CloseableHttpResponse response = httpClient.execute(httpPost)) {
                HttpEntity entity = response.getEntity();
                return EntityUtils.toString(entity);
            }
        }
    }
}
