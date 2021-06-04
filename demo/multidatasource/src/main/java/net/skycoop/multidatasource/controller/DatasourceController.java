package net.skycoop.multidatasource.controller;

import com.iotimc.pojo.reqresp.JsonRespond;
import net.skycoop.multidatasource.service.DatasourceService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class DatasourceController {

    @Autowired
    private DatasourceService datasourceService;

    @GetMapping("/mysql")
    public ResponseEntity<JsonRespond> mysql() {
        Object result = datasourceService.mysql();
        return ResponseEntity.ok(JsonRespond.Suc(result));
    }

    @GetMapping("/oracle")
    public ResponseEntity<JsonRespond> oracle() {
        Object result = datasourceService.oracle();
        return ResponseEntity.ok(JsonRespond.Suc(result));
    }
}
