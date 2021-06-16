package net.skycoop.mybatis.pojo;

public class BusException extends RuntimeException {
    private int code;
    private String msg;
    private Throwable e;

    private static final String DEFAULT_ERR_MSG = "后台错误";
    private static final int DEFAULT_ERR_CODE = 503;

    public BusException() {
        super(DEFAULT_ERR_MSG);
        init(DEFAULT_ERR_CODE, DEFAULT_ERR_MSG, null);
    }

    public BusException(int code, String msg, Throwable e) {
        super(msg, e);
        init(code, msg, e);
    }

    public BusException(String message) {
        super(message);
        init(DEFAULT_ERR_CODE, message, null);
    }

    public BusException(String message, Throwable cause) {
        super(message, cause);
        init(DEFAULT_ERR_CODE, message, cause);
    }

    public BusException(Throwable cause) {
        super(cause);
        init(DEFAULT_ERR_CODE, DEFAULT_ERR_MSG, cause);
    }

    private void init(int code, String msg, Throwable e) {
        this.code = code;
        this.msg = msg;
        this.e = e;
    }

    public int getCode() {
        return code;
    }

    public String getMsg() {
        return msg;
    }

    public Throwable getE() {
        return e;
    }
}
