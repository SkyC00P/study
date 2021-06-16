package net.skycoop.mybatis.domain;

import com.fasterxml.jackson.annotation.JsonFormat;

import java.io.Serializable;
import java.util.Date;
import javax.persistence.*;

@Table(name = "t_version")
public class TVersion implements Serializable {
    @Id
    private Long id;

    /**
     * 版本号
     */
    private Integer version;

    /**
     * 备注
     */
    private String notes;

    /**
     * 创建时间
     */
    @JsonFormat(timezone = "GMT+8", pattern = "yyyy-MM-dd HH:mm:ss")
    private Date cretime;

    private static final long serialVersionUID = 1L;

    /**
     * @return id
     */
    public Long getId() {
        return id;
    }

    /**
     * @param id
     */
    public void setId(Long id) {
        this.id = id;
    }

    /**
     * 获取版本号
     *
     * @return version - 版本号
     */
    public Integer getVersion() {
        return version;
    }

    /**
     * 设置版本号
     *
     * @param version 版本号
     */
    public void setVersion(Integer version) {
        this.version = version;
    }

    /**
     * 获取备注
     *
     * @return notes - 备注
     */
    public String getNotes() {
        return notes;
    }

    /**
     * 设置备注
     *
     * @param notes 备注
     */
    public void setNotes(String notes) {
        this.notes = notes == null ? null : notes.trim();
    }

    /**
     * 获取创建时间
     *
     * @return cretime - 创建时间
     */
    public Date getCretime() {
        return cretime;
    }

    /**
     * 设置创建时间
     *
     * @param cretime 创建时间
     */
    public void setCretime(Date cretime) {
        this.cretime = cretime;
    }
}
