package net.skycoop.multidatasource.pojo.reqresp;

import com.alibaba.fastjson.JSONObject;
import com.iotimc.elsi.terminal.web.utils.BusException;
import com.iotimc.elsi.terminal.web.utils.StringTool;

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

    public static JsonRespond Err(Throwable e) {
        JsonRespond respond = new JsonRespond();
        JsonErrResult errResult = new JsonErrResult();
        if (e instanceof BusException) {
            BusException busException = (BusException) e;
            int errCode = busException.getCode();
            respond.errCode = errCode;
            errResult.setCode(errCode);
            errResult.setMsg(busException.getMsg());
            if (busException.getE() != null) {
                String stackTrace = StringTool.getStackTrace(busException.getE());
                errResult.setStacktrace(stackTrace);
            }
            return respond.init("业务错误", System.currentTimeMillis(), 0, errResult);
        } else {
            respond.errCode = 500;
            errResult.setCode(500);
            errResult.setMsg(e.getMessage());
            errResult.setStacktrace(StringTool.getStackTrace(e));
            return respond.init("未知错误", System.currentTimeMillis(), 0, errResult);
        }
    }

    public int errCode() {
        return errCode;
    }
}
