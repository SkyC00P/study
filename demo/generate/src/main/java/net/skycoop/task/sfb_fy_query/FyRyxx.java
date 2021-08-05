package net.skycoop.task.sfb_fy_query;

import javax.xml.bind.annotation.XmlRootElement;

@XmlRootElement(name = "resource")
public class FyRyxx {
    // 身份证号
    private String c_zjhm;
    // 姓名
    private String c_mc;
    // 出生日期
    private String d_csrq;
    // 性别
    private int n_xb;
    // 民族
    private int n_mz;
    // 婚姻状况
    private int n_hyzk;
    // 文化程度
    private int n_whcd;
    // 现住址
    private String c_xzz;
    // 案号
    private String c_ah;
    // 经办法院
    private int n_bh_jbfy;
    // 定罪罪名
    private int n_dzzm;
    // 是否共同犯罪
    private int n_gtfz;
    // 判处结果
    private int n_pcjg;
    // 适用主刑种类
    private int n_syzxzl;
    // 适用附加刑种类
    private String c_syfjxzl;
    // 自由刑刑期年
    private int n_zyxxqn;
    // 自由刑刑期月
    private int n_zyxxqy;
    // 自由刑刑期日
    private int n_zyxxqr;
    // 共同犯罪地位
    private int n_gtfzdw;
    // 附加刑适用方式
    private int n_fjxsyfs;
    // 罪犯类型
    private int n_zflx;
    // 判决日期
    private String d_pjrq;

    public String getC_zjhm() {
        return c_zjhm;
    }

    public void setC_zjhm(String c_zjhm) {
        this.c_zjhm = c_zjhm;
    }

    public String getC_mc() {
        return c_mc;
    }

    public void setC_mc(String c_mc) {
        this.c_mc = c_mc;
    }

    public String getD_csrq() {
        return d_csrq;
    }

    public void setD_csrq(String d_csrq) {
        this.d_csrq = d_csrq;
    }

    public int getN_xb() {
        return n_xb;
    }

    public void setN_xb(int n_xb) {
        this.n_xb = n_xb;
    }

    public int getN_mz() {
        return n_mz;
    }

    public void setN_mz(int n_mz) {
        this.n_mz = n_mz;
    }

    public int getN_hyzk() {
        return n_hyzk;
    }

    public void setN_hyzk(int n_hyzk) {
        this.n_hyzk = n_hyzk;
    }

    public int getN_whcd() {
        return n_whcd;
    }

    public void setN_whcd(int n_whcd) {
        this.n_whcd = n_whcd;
    }

    public String getC_xzz() {
        return c_xzz;
    }

    public void setC_xzz(String c_xzz) {
        this.c_xzz = c_xzz;
    }

    public String getC_ah() {
        return c_ah;
    }

    public void setC_ah(String c_ah) {
        this.c_ah = c_ah;
    }

    public int getN_bh_jbfy() {
        return n_bh_jbfy;
    }

    public void setN_bh_jbfy(int n_bh_jbfy) {
        this.n_bh_jbfy = n_bh_jbfy;
    }

    public int getN_dzzm() {
        return n_dzzm;
    }

    public void setN_dzzm(int n_dzzm) {
        this.n_dzzm = n_dzzm;
    }

    public int getN_gtfz() {
        return n_gtfz;
    }

    public void setN_gtfz(int n_gtfz) {
        this.n_gtfz = n_gtfz;
    }

    public int getN_pcjg() {
        return n_pcjg;
    }

    public void setN_pcjg(int n_pcjg) {
        this.n_pcjg = n_pcjg;
    }

    public int getN_syzxzl() {
        return n_syzxzl;
    }

    public void setN_syzxzl(int n_syzxzl) {
        this.n_syzxzl = n_syzxzl;
    }

    public String getC_syfjxzl() {
        return c_syfjxzl;
    }

    public void setC_syfjxzl(String c_syfjxzl) {
        this.c_syfjxzl = c_syfjxzl;
    }

    public int getN_zyxxqn() {
        return n_zyxxqn;
    }

    public void setN_zyxxqn(int n_zyxxqn) {
        this.n_zyxxqn = n_zyxxqn;
    }

    public int getN_zyxxqy() {
        return n_zyxxqy;
    }

    public void setN_zyxxqy(int n_zyxxqy) {
        this.n_zyxxqy = n_zyxxqy;
    }

    public int getN_zyxxqr() {
        return n_zyxxqr;
    }

    public void setN_zyxxqr(int n_zyxxqr) {
        this.n_zyxxqr = n_zyxxqr;
    }

    public int getN_gtfzdw() {
        return n_gtfzdw;
    }

    public void setN_gtfzdw(int n_gtfzdw) {
        this.n_gtfzdw = n_gtfzdw;
    }

    public int getN_fjxsyfs() {
        return n_fjxsyfs;
    }

    public void setN_fjxsyfs(int n_fjxsyfs) {
        this.n_fjxsyfs = n_fjxsyfs;
    }

    public int getN_zflx() {
        return n_zflx;
    }

    public void setN_zflx(int n_zflx) {
        this.n_zflx = n_zflx;
    }

    public String getD_pjrq() {
        return d_pjrq;
    }

    public void setD_pjrq(String d_pjrq) {
        this.d_pjrq = d_pjrq;
    }

    @Override
    public String toString() {
        final StringBuffer sb = new StringBuffer("FyRyxx{");
        sb.append("c_zjhm='").append(c_zjhm).append('\'');
        sb.append(", c_mc='").append(c_mc).append('\'');
        sb.append(", d_csrq='").append(d_csrq).append('\'');
        sb.append(", n_xb=").append(n_xb);
        sb.append(", n_mz=").append(n_mz);
        sb.append(", n_hyzk=").append(n_hyzk);
        sb.append(", n_whcd=").append(n_whcd);
        sb.append(", c_xzz='").append(c_xzz).append('\'');
        sb.append(", c_ah='").append(c_ah).append('\'');
        sb.append(", n_bh_jbfy=").append(n_bh_jbfy);
        sb.append(", n_dzzm=").append(n_dzzm);
        sb.append(", n_gtfz=").append(n_gtfz);
        sb.append(", n_pcjg=").append(n_pcjg);
        sb.append(", n_syzxzl=").append(n_syzxzl);
        sb.append(", c_syfjxzl='").append(c_syfjxzl).append('\'');
        sb.append(", n_zyxxqn=").append(n_zyxxqn);
        sb.append(", n_zyxxqy=").append(n_zyxxqy);
        sb.append(", n_zyxxqr=").append(n_zyxxqr);
        sb.append(", n_gtfzdw=").append(n_gtfzdw);
        sb.append(", n_fjxsyfs=").append(n_fjxsyfs);
        sb.append(", n_zflx=").append(n_zflx);
        sb.append(", d_pjrq='").append(d_pjrq).append('\'');
        sb.append('}');
        return sb.toString();
    }
}
