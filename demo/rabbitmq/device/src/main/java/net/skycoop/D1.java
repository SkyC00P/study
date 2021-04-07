package net.skycoop;

import java.io.IOException;
import java.util.concurrent.TimeoutException;

/**
 * 设备1
 * 上发信息：`cns.device.<id>.info.common`
 * 监听事件：`cns.device.<id>.*.req`
 */
public class D1 {

    public static void main(String[] args) throws IOException, TimeoutException {
        Tool.initMQ( "d1");
    }

}
