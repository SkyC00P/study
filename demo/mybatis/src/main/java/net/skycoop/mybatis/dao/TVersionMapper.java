package net.skycoop.mybatis.dao;

import net.skycoop.mybatis.domain.TVersion;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;
import tk.mybatis.mapper.common.Mapper;

import java.util.List;

public interface TVersionMapper extends Mapper<TVersion> {

    List<TVersion> select_filter(@Param("filter") String filter);

    @Select("SELECT * FROM t_version WHERE version = #{version}")
    List<TVersion> select_one(String version);

    void deleteByList(@Param("ids")List<Long> ids);
}
