package net.skycoop.mybatis.pojo;

import com.alibaba.fastjson.JSONObject;

public class JsonRespond extends JSONObject {

    private static final String MSG = "msg";
    private static final String TIME = "time";
    private static final String STATUS = "status";
    private static final String RESULT = "result";

    private int errCode = 500;

    private JsonRespond init(String msg, long time, int status, Object obj) {
        put(MSG, msg);
        put(TIME, time);
        put(STATUS, status);
        put(RESULT, obj);
        return this;
    }

    public static JsonRespond Suc(Object result) {
        JsonRespond respond = new JsonRespond();
        return respond.init("SUC",System.currentTimeMillis(), 1, result);
    }

    public static JsonRespond Suc() {
        JsonRespond respond = new JsonRespond();
        return respond.init("SUC",System.currentTimeMillis(), 1, "");
    }


    public int errCode() {
        return errCode;
    }
}
