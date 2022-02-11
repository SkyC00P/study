package net.skycoop.multidatasource.pojo.reqresp;

import com.alibaba.fastjson.JSONObject;

public class JsonDataBuild {

    private JsonData data = new JsonData();

    private JSONObject jdata = new JSONObject();

    public JsonData build() {
        data.put("data", jdata);
        return data;
    }

    public JsonDataBuild putData(String key, Object val) {
        jdata.put(key, val);
        return this;
    }

    public JsonDataBuild pageInfo(int pageNo, int pageSize) {
        data.put("pageInfo", JsonPage.wrapper(pageNo, pageSize));
        return this;
    }
}
