package com.example.entity;


public class Points {
    private Integer id;
    private Integer total;
    private Integer typesettingScore;
    private String studentid;
    private Integer namingScore;
    private Integer requirement1;
    private Integer requirement2;
    private Integer requirement3;
    private Integer otherScore;
    private String evaluation;
    private String topic;

    public String getTopic() {
        return topic;
    }

    public void setTopic(String topic) {
        this.topic = topic;
    }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public Integer getTotal() {
        return total;
    }

    public void setTotal(Integer total) {
        this.total = total;
    }

    public Integer getTypesettingScore() {
        return typesettingScore;
    }

    public void setTypesettingScore(Integer typesettingScore) {
        this.typesettingScore = typesettingScore;
    }

    public String getStudentid() {
        return studentid;
    }

    public void setStudentid(String studentid) {
        this.studentid = studentid;
    }

    public Integer getNamingScore() {
        return namingScore;
    }

    public void setNamingScore(Integer namingScore) {
        this.namingScore = namingScore;
    }

    public Integer getRequirement1() {
        return requirement1;
    }

    public void setRequirement1(Integer requirement1) {
        this.requirement1 = requirement1;
    }

    public Integer getRequirement2() {
        return requirement2;
    }

    public void setRequirement2(Integer requirement2) {
        this.requirement2 = requirement2;
    }

    public Integer getRequirement3() {
        return requirement3;
    }

    public void setRequirement3(Integer requirement3) {
        this.requirement3 = requirement3;
    }

    public Integer getOtherScore() {
        return otherScore;
    }

    public void setOtherScore(Integer otherScore) {
        this.otherScore = otherScore;
    }

    public String getEvaluation() {
        return evaluation;
    }

    public void setEvaluation(String evaluation) {
        this.evaluation = evaluation;
    }
}
