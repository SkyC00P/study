package net.skycoop.mybatis.controller;

import net.skycoop.mybatis.domain.TVersion;
import net.skycoop.mybatis.pojo.JsonData;
import net.skycoop.mybatis.pojo.JsonPage;
import net.skycoop.mybatis.pojo.JsonRespond;
import net.skycoop.mybatis.service.DatasourceService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
public class DatasourceController {

    @Autowired
    private DatasourceService datasourceService;

    /**
     * 查询全部
     */
    @GetMapping("/select_all")
    public ResponseEntity<JsonRespond> select_all(@RequestParam(required = false, name = "filter") String filter) {
        Object result = datasourceService.selectAll();
        return ResponseEntity.ok(JsonRespond.Suc(result));
    }

    /**
     * 通过ID查询一个
     */
    @GetMapping("/select_one")
    public ResponseEntity<JsonRespond> select_one(@RequestParam(name = "version") String version) {
        Object result = datasourceService.select_one(version);
        return ResponseEntity.ok(JsonRespond.Suc(result));
    }

    /**
     * 通过version等值查询一个
     */
    @GetMapping("/select_version")
    public ResponseEntity<JsonRespond> select_version(@RequestParam(name = "version") String version) {
        Object result = datasourceService.select_version(version);
        return ResponseEntity.ok(JsonRespond.Suc(result));
    }

    /**
     * 分页查询无分页参数则默认查询全部
     */
    @PostMapping("/select_page")
    public ResponseEntity<JsonRespond> select_page(@RequestBody JsonData data) {
        JsonPage jsonPage = data.PageInfo();
        Object result = datasourceService.select_page(jsonPage);
        return ResponseEntity.ok(JsonRespond.Suc(result));
    }

    /**
     * 动态查询
     */
    @GetMapping("/select_filter")
    public ResponseEntity<JsonRespond> select_filter(@RequestParam(required = false, name = "filter") String filter) {
        Object result = datasourceService.select_filter(filter);
        return ResponseEntity.ok(JsonRespond.Suc(result));
    }


    /**
     * 新增
     * 当存在相同记录时，不会变成更新，会因主键冲突而报错
     */
    @PostMapping("/add")
    public ResponseEntity<JsonRespond> add(@RequestBody JsonData data) {
        TVersion version = data.cast(TVersion.class);
        datasourceService.add(version);
        return ResponseEntity.ok(JsonRespond.Suc());
    }

    /**
     * 非空新增
     * 属性为null的属性会以数据库默认值填充
     */
    @PostMapping("/add_when_no_null")
    public ResponseEntity<JsonRespond> add_when_no_null(@RequestBody JsonData data) {
        TVersion version = data.cast(TVersion.class);
        datasourceService.add_when_no_null(version);
        return ResponseEntity.ok(JsonRespond.Suc());
    }

    /**
     * 覆盖更新
     */
    @PostMapping("/update")
    public ResponseEntity<JsonRespond> update(@RequestBody JsonData data) {
        TVersion version = data.cast(TVersion.class);
        datasourceService.update(version);
        return ResponseEntity.ok(JsonRespond.Suc());
    }

    /**
     * 非空更新
     */
    @PostMapping("/update_when_no_null")
    public ResponseEntity<JsonRespond> update_when_no_null(@RequestBody JsonData data) {
        TVersion version = data.cast(TVersion.class);
        datasourceService.update_when_no_null(version);
        return ResponseEntity.ok(JsonRespond.Suc());
    }

    /**
     * 全匹配删除单个记录
     */
    @DeleteMapping("/delete")
    public ResponseEntity<JsonRespond> delete(@RequestBody JsonData data) {
        TVersion version = data.cast(TVersion.class);
        datasourceService.delete(version);
        return ResponseEntity.ok(JsonRespond.Suc());
    }

    /**
     * 主键删除单个记录
     */
    @DeleteMapping("/delete_id")
    public ResponseEntity<JsonRespond> delete_id(@RequestBody JsonData data) {
        Object id = data.Data().get("id");
        datasourceService.delete_id(id);
        return ResponseEntity.ok(JsonRespond.Suc());
    }

    /**
     * 批量删除
     */
    @DeleteMapping("/delete_list")
    public ResponseEntity<JsonRespond> delete_list(@RequestBody JsonData data) {
        List<Long> ids = data.dataList("ids", Long.class);
        datasourceService.delete_list(ids);
        return ResponseEntity.ok(JsonRespond.Suc());
    }
}
