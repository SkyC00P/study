package net.skycoop.multidatasource.oracle.domain;

import com.fasterxml.jackson.annotation.JsonIgnoreProperties;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.Table;

/**
 * @author thj
 * @Date 2020/11/2/002
 * @Description 应用上传实体类
 */

@Entity
@Table(name = "YIDAOAPPSC", schema = "MSYIDAOAPP")
@JsonIgnoreProperties(ignoreUnknown = true)
public class Yidaoappsc {

    /**
     * APP名称
     */
    @Column(name = "TITLE", length = 1000)
    private String title;

    /**
     * APP描述
     *
     * @return
     */
    @Column(name = "APPMS", length = 4000)
    private String appms;

    /**
     * APP所属年份外键
     *
     */
    @Column(name = "APPNF", length = 32)
    private String appnf;

    /**
     * 发布状态(Y:已发布，N:未发布，C:已作废)
     */
    @Column(name = "FBZT", length = 32, nullable = false)
    private String fbzt;

    /**
     * 图片路径（截取路径存到这个字段）
     */
    @Column(name = "TPLJ", length = 400)
    private String tplj;

    @Id
    @Column(name = "ID")
    private String id;

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getAppms() {
        return appms;
    }

    public void setAppms(String appms) {
        this.appms = appms;
    }

    public String getAppnf() {
        return appnf;
    }

    public void setAppnf(String appnf) {
        this.appnf = appnf;
    }

    public String getFbzt() {
        return fbzt;
    }

    public void setFbzt(String fbzt) {
        this.fbzt = fbzt;
    }

    public String getTplj() {
        return tplj;
    }

    public void setTplj(String tplj) {
        this.tplj = tplj;
    }


    public void setId(String id) {
        this.id = id;
    }

    public String getId() {
        return id;
    }
}
