package net.skycoop.multidatasource.pojo.reqresp;

import com.alibaba.fastjson.JSONObject;

/**
 * {
 * 	"message":"错误编号:1300。非法请求系统不予处理！",
 * 	"result":{
 * 		"code":1300,
 * 		"msg":"非法参数",
 * 		"stacktrace":"异常堆栈"
 *        },
 * 	"status":0,
 * 	"time":1449629042614
 * }
 */
public class JsonErrResult extends JSONObject {

    public static final String CODE = "code";
    public static final String MSG = "msg";
    public static final String STACKTRACE = "stacktrace";

    public void setCode(int code) {
        put(CODE, code);
    }

    public void setMsg(String msg) {
        put(MSG, msg);
    }

    public void setStacktrace(String stacktrace) {
        put(STACKTRACE, stacktrace);
    }
}
