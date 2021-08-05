package net.skycoop;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.io.*;
import java.nio.charset.StandardCharsets;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.UUID;

public class Tool {

    public static String uuid() {
        return UUID.randomUUID().toString().replace("-", "");
    }

    public static String getTime() {
        SimpleDateFormat format = new SimpleDateFormat("yyyy-mm-dd HH:mm:ss");
        return format.format(new Date());
    }

    public static boolean isBlank(String s) {
        return s == null || s.trim().isEmpty();
    }

    public static boolean isNotBlank(String s) {
        return !isBlank(s);
    }

    public static void closeQuietly(Closeable... cs) {
        for (Closeable close : cs) {
            try {
                close.close();
            } catch (IOException e) {
                // ignored
            }
        }
    }

    public static boolean isEmpty(final CharSequence cs) {
        return cs == null || cs.length() == 0;
    }

    public static boolean isNumber(CharSequence cs) {
        if (isEmpty(cs)) {
            return false;
        }
        final int sz = cs.length();
        for (int i = 0; i < sz; i++) {
            if (!Character.isDigit(cs.charAt(i))) {
                return false;
            }
        }
        return true;
    }

    public static void sleepQuietly(long i) {
        try {
            Thread.sleep(i);
        } catch (InterruptedException e) {
            // ignore
        }
    }

    public static String readString(InputStream inputStream) {

        final int bufferSize = 1024;
        final char[] buffer = new char[bufferSize];
        final StringBuilder out = new StringBuilder();
        try (Reader in = new InputStreamReader(inputStream, StandardCharsets.UTF_8)) {
            for (; ; ) {
                int rsz = in.read(buffer, 0, buffer.length);
                if (rsz < 0)
                    break;
                out.append(buffer, 0, rsz);
            }
        } catch (IOException e) {
            return null;
        }

        return out.toString();
    }
}
