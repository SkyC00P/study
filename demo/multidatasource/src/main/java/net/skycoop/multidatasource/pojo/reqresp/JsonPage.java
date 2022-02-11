package net.skycoop.multidatasource.pojo.reqresp;

import com.alibaba.fastjson.JSONObject;
import org.springframework.data.domain.Page;

public class JsonPage extends JSONObject {

    private static final String list = "list";
    private static final String pageInfo = "pageInfo";
    private static final String pageNo = "pageNo";
    private static final String pageSize = "pageSize";
    private static final String totalPage = "totalPage";
    private static final String totalSize = "totalSize";

    public static JsonPage wrapper(Page page) {
        JsonPage jPage = new JsonPage();
        jPage.put(list, page.getContent());

        if (page.getPageable().isPaged()) {
            JSONObject jPageInfo = new JSONObject();
            jPageInfo.put(pageNo, page.getNumber() + 1);
            jPageInfo.put(pageSize, page.getSize());
            jPageInfo.put(totalPage, page.getTotalPages());
            jPageInfo.put(totalSize, page.getTotalElements());
            jPage.put(pageInfo, jPageInfo);
        }
        return jPage;
    }

    public static JsonPage wrapper(int pageNo, int pageSize) {
        JsonPage jPage = new JsonPage();
        jPage.put(JsonPage.pageNo, pageNo);
        jPage.put(JsonPage.pageSize, pageSize);
        return jPage;
    }
}
