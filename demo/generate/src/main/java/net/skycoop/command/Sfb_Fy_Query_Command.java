package net.skycoop.command;

import net.skycoop.Tool;
import net.skycoop.task.sfb_fy_query.DBHelp;
import net.skycoop.task.sfb_fy_query.FyRyxx;
import net.skycoop.task.sfb_fy_query.Handler;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;
import java.io.OutputStreamWriter;
import java.net.HttpURLConnection;
import java.net.URL;
import java.nio.charset.StandardCharsets;
import java.util.List;
import java.util.Scanner;

public class Sfb_Fy_Query_Command implements Command {

    private static final Logger log = LoggerFactory.getLogger("[高法]");

    private int max_try_conn = 3;

    private String sfb_fy_url = "http://59.255.4.84:8089/drsp-ebsm-server/api/services/57cd1b0073d8410eb811296af6315830?pageSize=${pageSize}";
    int pageNum = 1;
    int pageSize = 10000;

    @Override
    public void execute(Scanner in) {

        DBHelp help = new DBHelp();

        try {
            final long taskId = System.currentTimeMillis();
            log.info("[{}] --> 开始同步", taskId);
            int try_times = 0;

            while (try_times <= max_try_conn) {
                try_times++;
                if (help.connect().isConn()) {
                    break;
                } else {
                    log.error("第{}次连接失败，尝试重连，最大重连次数为:{}", try_times, max_try_conn, help.getErr("connect"));
                    Tool.sleepQuietly(1000);
                }
            }
            long count = help.count();
            log.info("[{}] --> 同步的总数为:{}", taskId, count);

            int queryCount = 0;
            while (queryCount != count) {

                DBHelp.QueryResult qr = help.query(pageNum, pageSize);

                if (qr == null) {
                    log.error("[{}] --> 同步当前页:{}，页数:{}, 数据库查询参数异常", taskId, pageNum, pageSize, help.getErr("query"));
                    return;
                }

                String xmlResult = callQueryInterface(qr.condition);
                if (Tool.isBlank(xmlResult)) {
                    log.error("[{}] --> 同步当前页:{}，页数:{}, 查询数:{}, 接口获取异常", taskId, pageNum, pageSize, qr.count);
                    return;
                }

                Handler handler = parseXML(xmlResult);
                int xml_count = handler.getCount();
                List<FyRyxx> fyRyxxes = handler.getFyRyxxes();

                int insert_count = 0;
                for (FyRyxx ryxx : fyRyxxes) {
                    help.insert(ryxx);
                    insert_count++;
                }

                log.info("[{}] --> 同步当前页:{}，页数:{}, 查询数:{}, 接口获取数:{}, 已插入:{}", taskId, pageNum, pageSize, qr.count, xml_count, insert_count);
                queryCount += qr.count;
                pageNum++;
            }

        } catch (Throwable e) {
            e.printStackTrace();
        } finally {
            help.close();
        }
    }

    private Handler parseXML(String xmlResult) throws Throwable {
        SAXParserFactory spf = SAXParserFactory.newInstance();
        SAXParser saxParser = spf.newSAXParser();
        Handler handler = new Handler();
        saxParser.parse(xmlResult, handler);
        return handler;
    }

    private String callQueryInterface(String bodyParam) throws Throwable {
        String uri = sfb_fy_url.replace("${pageSize}", pageSize + "");

        URL urll = new URL(uri);
        HttpURLConnection httpConn = (HttpURLConnection) urll.openConnection();

        httpConn.setRequestProperty("drsp_ticket", "dfaae41b26c74c109e1e85679fddc60d");//ticket
        httpConn.setRequestProperty("Content-Type", "application/xml");

        httpConn.setDoOutput(true); //需要输出 GET方式的时候设置为false
        httpConn.setDoInput(true); //需要输入
        httpConn.setUseCaches(false); //不允许缓存
        httpConn.setRequestMethod("POST"); //设置POST方式连接

        httpConn.connect();

        //建立输入流，向写入body中指向的URL传入参数
        OutputStreamWriter ops = new OutputStreamWriter(httpConn.getOutputStream(), StandardCharsets.UTF_8);
        if (Tool.isNotBlank(bodyParam)) {
            ops.write(bodyParam);
        }
        ops.flush();
        Tool.closeQuietly(ops);

        if (!httpConn.getHeaderField("X-Ca-Supporter-StatusCode").equals("200")) {
            //请求被平台拦截
            return null;
        }
        return Tool.readString(httpConn.getInputStream());
    }
}
