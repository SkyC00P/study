package net.skycoop;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.UUID;

public class Tool {

    private static final Logger log = LoggerFactory.getLogger("test");

    public static String uuid() {
        return UUID.randomUUID().toString().replace("-", "");
    }

    public static Logger getDefaultLog() {
        return log;
    }

    public static String getTime() {
        SimpleDateFormat format = new SimpleDateFormat("yyyy-mm-dd HH:mm:ss");
        return format.format(new Date());
    }
}
