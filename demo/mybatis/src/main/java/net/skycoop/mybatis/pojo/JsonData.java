package net.skycoop.mybatis.pojo;

import com.alibaba.fastjson.JSONArray;
import com.alibaba.fastjson.JSONObject;

import java.util.ArrayList;
import java.util.List;

public class JsonData extends JSONObject {

    public JSONObject Data() {
        JSONObject data = this.getJSONObject("data");
        if (data == null) {
            throw new NullPointerException();
        }
        return data;
    }

    public String dataString(String k) {
        return Data().getString(k);
    }

    public Long dataLong(String k) {
        return Data().getLong(k);
    }

    public <T> T dataCast(String k, Class<T> T) {
        return Data().getJSONObject(k).toJavaObject(T);
    }

    public <T> T cast(Class<T> T) {
        return Data().toJavaObject(T);
    }

    public JsonPage PageInfo() {
        JSONObject pageInfo = this.getJSONObject("pageInfo");
        return pageInfo == null ? null : JsonPage.wrapper(pageInfo.getIntValue("pageNo"), pageInfo.getIntValue("pageSize"));
    }

    public <T> List<T> dataList(String key, Class<T> tClass) {
        JSONArray array = Data().getJSONArray(key);
        return array == null ? new ArrayList<>() : parseArray(array.toJSONString(), tClass);
    }

}
