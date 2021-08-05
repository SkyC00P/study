package net.skycoop.task.sfb_fy_query;

import java.sql.*;
import java.util.HashMap;
import java.util.Map;

public class DBHelp {

    private static final String JDBC_DRIVER = "com.mysql.cj.jdbc.Driver";
    private static final String DB_URL = "jdbc:mysql://${url}:3306/${name}?useSSL=false&allowPublicKeyRetrieval=true&serverTimezone=UTC";

    private String url;
    private String name;
    private String user;
    private String password;
    private String countSql = "select count(1) from ljxx_all order by sfzh,xm";
    private String querySql = "select xm,sfzh from ljxx_all order by sfzh,xm limit ?,?;";
    private String insertSql = "insert into fy_ryxx_bak_1(c_zjhm,c_mc,d_csrq,n_xb,n_mz,n_hyzk,n_whcd,c_xzz,c_ah,n_bh_jbfy,n_dzzm,n_gtfz,n_pcjg,n_syzxzl,c_syfjxzl,n_zyxxqn,n_zyxxqy,n_zyxxqr,n_gtfzdw,n_fjxsyfs,n_fzlx,d_pjrq) " +
            "values(?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)";

    private Connection conn = null;
    private boolean isConn = false;
    private static Map<String, Throwable> ERR = new HashMap<>();

    public DBHelp(String url, String name, String user, String password) {
        init(url, name, user, password);
    }

    private void init(String url, String name, String user, String password) {
        this.url = url;
        this.name = name;
        this.user = user;
        this.password = password;
    }

    public DBHelp() {
        init("localhost", "test", "root", "IMCsoft.12345");
    }

    public DBHelp connect() {
        try {
            Class.forName(JDBC_DRIVER);
            final String uri = DB_URL
                    .replace("${url}", url)
                    .replace("${name}", name);

            conn = DriverManager.getConnection(uri, user, password);
            isConn = true;
        } catch (Throwable e) {
            isConn = false;
            ERR.put("connect", e);
        }
        return this;
    }

    public boolean isConn() {
        try {
            return conn != null && isConn && !conn.isClosed();
        } catch (SQLException e) {
            return false;
        }
    }

    public Throwable getErr(String k) {
        return ERR.get(k);
    }

    public long count() throws SQLException {
        PreparedStatement stmt = conn.prepareStatement(countSql);
        ResultSet resultSet = stmt.executeQuery();
        long count = resultSet.getLong(1);
        stmt.close();
        return count;
    }

    public void close() {
        if (conn != null) {
            try {
                conn.close();
            } catch (SQLException e) {
                // ignore
            }
        }
        isConn = false;
    }

    public void insert(FyRyxx fyxx) throws SQLException {
        PreparedStatement ps = conn.prepareStatement(insertSql);
        ps.setString(1, fyxx.getC_zjhm());
        ps.setString(2, fyxx.getC_mc());
        ps.setString(3, fyxx.getD_csrq());
        ps.setInt(4, fyxx.getN_xb());
        ps.setInt(5, fyxx.getN_mz());
        ps.setInt(6, fyxx.getN_hyzk());
        ps.setInt(7, fyxx.getN_whcd());
        ps.setString(8, fyxx.getC_xzz());
        ps.setString(9, fyxx.getC_ah());
        ps.setInt(10, fyxx.getN_bh_jbfy());
        ps.setInt(11, fyxx.getN_dzzm());
        ps.setInt(12, fyxx.getN_gtfz());
        ps.setInt(13, fyxx.getN_pcjg());
        ps.setInt(14, fyxx.getN_syzxzl());
        ps.setString(15, fyxx.getC_syfjxzl());
        ps.setInt(16, fyxx.getN_zyxxqn());
        ps.setInt(17, fyxx.getN_zyxxqy());
        ps.setInt(18, fyxx.getN_zyxxqr());
        ps.setInt(19, fyxx.getN_gtfzdw());
        ps.setInt(20, fyxx.getN_fjxsyfs());
        ps.setInt(21, fyxx.getN_zflx());
        ps.setString(22, fyxx.getD_pjrq());
        ps.executeUpdate();
        ps.close();
    }

    public static final class QueryResult {
        public long count = 0;
        public String condition;
    }

    public QueryResult query(int pageNum, int pageSize) {
        try {
            QueryResult result = new QueryResult();
            StringBuilder sb = new StringBuilder("<condition>\n");
            PreparedStatement stmt = conn.prepareStatement(querySql);
            stmt.setInt(1, pageNum * pageSize);
            stmt.setInt(2, pageSize);
            ResultSet rs = stmt.executeQuery();
            while (rs.next()) {
                String xm = rs.getString("xm");
                String sfzh = rs.getString("sfzh");
                sb.append(String.format("<c_mczjhm><![CDATA[%s#%s]]></c_mczjhm>", xm, sfzh));
                sb.append("\n");
                result.count++;
            }
            sb.append("</condition>\n");
            result.condition = sb.toString();
            return result;
        } catch (SQLException e) {
            ERR.put("query", e);
            return null;
        }
    }
}
