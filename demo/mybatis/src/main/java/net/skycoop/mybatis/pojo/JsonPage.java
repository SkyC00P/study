package net.skycoop.mybatis.pojo;

import com.alibaba.fastjson.JSONObject;
import com.github.pagehelper.Page;
import com.github.pagehelper.PageHelper;

import java.util.List;

public class JsonPage extends JSONObject {

    private static final String LIST = "list";
    private static final String PAGE_INFO = "pageInfo";
    private static final String PAGE_NO = "pageNo";
    private static final String PAGE_SIZE = "pageSize";
    private static final String TOTAL_PAGE = "totalPage";
    private static final String TOTAL_SIZE = "totalSize";

    public static JsonPage wrapper(int pageNo, int pageSize) {
        JsonPage jPage = new JsonPage();
        jPage.put(JsonPage.PAGE_NO, pageNo);
        jPage.put(JsonPage.PAGE_SIZE, pageSize);
        return jPage;
    }

    public interface PageHelp<T> {
        List<T> execute();
    }

    public static <T> JsonPage wrapper(JsonPage pageInfo, PageHelp<T> help) {
        JsonPage jPage = new JsonPage();
        if (pageInfo == null) {
            jPage.put(LIST, help.execute());
            return jPage;
        }
        Integer _pageNo = pageInfo.getInteger(PAGE_NO);
        Integer _pageSize = pageInfo.getInteger(PAGE_SIZE);

        _pageNo = _pageNo == null ? 1 : _pageNo;
        _pageSize = _pageSize == null ? 999999 : _pageSize;

        PageHelper.startPage(_pageNo, _pageSize);
        Page<T> page = (Page<T>) help.execute();
        if (page != null) {
            pageInfo.put(TOTAL_PAGE, page.getPages());
            pageInfo.put(TOTAL_SIZE, page.getTotal());
            pageInfo.put(PAGE_NO, _pageNo);
            pageInfo.put(PAGE_SIZE, _pageSize);
            jPage.put(PAGE_INFO, pageInfo);
        }
        jPage.put(LIST, page);
        return jPage;
    }
}
