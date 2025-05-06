package com.example.mapper;

import com.example.entity.Points;
import org.apache.ibatis.annotations.Delete;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;

import java.util.List;

public interface PointsMapper {


    void insert(Points points);


    @Select("select  * from  `points` where studentid = #{studentid}")
    Points selectByStudentid(String studentid);

    @Select("select  * from  `points` where studentid = #{studentid} and topic = #{topic}")
    Points selectByStudentidAndTopic(String studentid, String topic);


    void updateByStudentIdAndTopic(Points points);


    @Delete("delete from `points` where id = #{id}")
    void deleteById(Integer id);

}
