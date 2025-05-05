package com.example.mapper;

import com.example.entity.Datas;
import org.apache.ibatis.annotations.Delete;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;

import java.util.List;

public interface DatasMapper {

    List<Datas> selectAll(Datas datas);

    void insert(Datas datas);

    void insertNoRepo(Datas datas);

    @Select("select  * from  `datas` where studentid = #{studentid}")
    Datas selectByStudentid(String studentid);

    @Select("select  * from  `datas` where studentid = #{studentid}")
    List<Datas> selectAllA01Codes();

    @Select("SELECT MAX(id) FROM datas")
    Integer findMaxId();

    @Select("SELECT id FROM datas WHERE id BETWEEN #{start} AND #{end}")
    List<Integer> findExistIds(@Param("start") int start, @Param("end") int end);

    void updateById(Datas datas);

    void updateByStudentId(Datas datas);

    void updateByStudentIdNoRepo(Datas datas);

    @Delete("delete from `datas` where id = #{id}")
    void deleteById(Integer id);

    @Select("select  * from  `datas` where id = #{id}")
    Datas selectById(Integer id);
}
