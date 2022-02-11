package net.skycoop.multidatasource.pojo.reqresp;

import org.springframework.core.io.FileSystemResource;
import org.springframework.http.HttpHeaders;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;

import java.io.File;
import java.io.UnsupportedEncodingException;
import java.net.URLEncoder;
import java.util.Date;

public class StreamRespond {

    public static ResponseEntity<FileSystemResource> file(File file) {

        try {
            HttpHeaders headers = new HttpHeaders();
            headers.add("Pragma", "no-cache");
            headers.add("Cache-Control", "no-cache, no-store, must-revalidate");
            headers.add("Content-Disposition", "attachment;filename*=UTF-8''" + URLEncoder.encode(file.getName(), "UTF-8"));
            headers.add("Expires", "0");

            headers.add("Last-Modified", new Date().toString());
            headers.add("ETag", String.valueOf(System.currentTimeMillis()));

            return ResponseEntity.ok()
                    .headers(headers)
                    .contentLength(file.length())
                    .contentType(MediaType.parseMediaType("application/octet-stream"))
                    .body(new FileSystemResource(file));
        } catch (UnsupportedEncodingException e) {
            throw new RuntimeException(e);
        }
    }
}
