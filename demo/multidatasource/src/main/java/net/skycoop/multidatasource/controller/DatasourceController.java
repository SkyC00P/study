package net.skycoop.multidatasource.controller;

import com.iotimc.pojo.reqresp.JsonRespond;
import net.skycoop.multidatasource.service.DatasourceService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class DatasourceController {

    @Autowired
    private DatasourceService datasourceService;

    @GetMapping("/mysql")
    public ResponseEntity<JsonRespond> mysql(@RequestParam(required = false, name = "filter") String filter) {
        Object result = datasourceService.mysql(filter);
        return ResponseEntity.ok(JsonRespond.Suc(result));
    }

    @GetMapping("/oracle")
    public ResponseEntity<JsonRespond> oracle(@RequestParam(required = false, name = "filter") String filter) {
        Object result = datasourceService.oracle(filter);
        return ResponseEntity.ok(JsonRespond.Suc(result));
    }
}
