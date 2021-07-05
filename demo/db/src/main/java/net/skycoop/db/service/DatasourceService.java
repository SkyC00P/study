package net.skycoop.db.service;

import com.iotimc.pojo.reqresp.JsonPage;
import net.skycoop.db.dao.YidaoappscDao;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.domain.Pageable;
import org.springframework.stereotype.Service;

@Service
public class DatasourceService {

    @Autowired
    private YidaoappscDao oracleStudentDao;

    public Object oracle(String filter, Pageable pageable) {
        return JsonPage.wrapper(oracleStudentDao.findFilter(pageable));
//        return oracleStudentDao.findAll(pageable);
    }
}
