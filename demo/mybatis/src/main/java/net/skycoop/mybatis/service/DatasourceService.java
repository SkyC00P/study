package net.skycoop.mybatis.service;

import net.skycoop.mybatis.dao.TVersionMapper;
import net.skycoop.mybatis.domain.TVersion;
import net.skycoop.mybatis.pojo.JsonPage;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

@Service
public class DatasourceService {

    private static final Logger log = LoggerFactory.getLogger(DatasourceService.class);

    @Resource
    private TVersionMapper versionMapper;

    public Object selectAll() {
        return versionMapper.selectAll();
    }

    public Object select_filter(String filter) {
        return versionMapper.select_filter(filter);
    }

    public Object select_one(String id) {
        return versionMapper.selectByPrimaryKey(id);
    }

    public Object select_version(String version) {
        return versionMapper.select_one(version);
    }

    public void add(TVersion version) {
        versionMapper.insert(version);
    }

    public void add_when_no_null(TVersion version) {
        versionMapper.insertSelective(version);
    }

    public void update(TVersion version) {
        versionMapper.updateByPrimaryKey(version);
    }

    public void update_when_no_null(TVersion version) {
        versionMapper.updateByPrimaryKeySelective(version);
    }

    public Object select_page(JsonPage jsonPage) {
        return JsonPage.wrapper(jsonPage, () -> versionMapper.selectAll());
    }

    public void delete(TVersion version) {
        versionMapper.delete(version);
    }

    public void delete_id(Object id) {
        versionMapper.deleteByPrimaryKey(id);
    }

    public void delete_list(List<Long> ids) {
        versionMapper.deleteByList(ids);
    }

}
