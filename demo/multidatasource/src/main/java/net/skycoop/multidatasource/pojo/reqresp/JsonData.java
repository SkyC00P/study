package net.skycoop.multidatasource.pojo.reqresp;

import com.alibaba.fastjson.JSONArray;
import com.alibaba.fastjson.JSONObject;
import org.springframework.data.domain.PageRequest;
import org.springframework.data.domain.Pageable;

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

    public <T> T cast(Class<T> T) {
        return Data().toJavaObject(T);
    }

    public Pageable PageInfo() {
        JSONObject pageInfo = this.getJSONObject("pageInfo");
        return pageInfo == null ? null : PageRequest.of(pageInfo.getIntValue("pageNo") - 1, pageInfo.getIntValue("pageSize"));
    }

    public <T> List<T> dataList(String key, Class<T> tClass) {
        JSONArray array = Data().getJSONArray(key);
        return array == null ? new ArrayList<>() : parseArray(array.toJSONString(), tClass);
    }

}
