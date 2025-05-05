package com.example.mapper;

import com.example.entity.Topic;
import org.apache.ibatis.annotations.Select;


public interface TopicMapper {

    @Select("select  * from  `topic` where name = #{name}")
    Topic getIncludeByName(String name);

    void insert(Topic topic);

    @Select("select  * from  `topic` where id = #{id}")
    Topic getIncludeById(Integer id);
}
