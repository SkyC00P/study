package net.skycoop.db.controller;

import com.iotimc.pojo.reqresp.JsonData;
import com.iotimc.pojo.reqresp.JsonRespond;
import net.skycoop.db.service.DatasourceService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.domain.Pageable;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class DatasourceController {

    @Autowired
    private DatasourceService datasourceService;

    @GetMapping("/oracle")
    public ResponseEntity<JsonRespond> oracle(@RequestBody JsonData data) {
        String filter = data.dataString("filter");
        Pageable pageable = data.PageInfo();
        Object result = datasourceService.oracle(filter, pageable);
        return ResponseEntity.ok(JsonRespond.Suc(result));
    }
}
