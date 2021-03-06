package net.skycoop.multidatasource.service;

import net.skycoop.multidatasource.mysql.dao.MySQLStudentDao;
import net.skycoop.multidatasource.oracle.dao.YidaoappscDao;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class DatasourceService {

    private static final Logger log = LoggerFactory.getLogger(DatasourceService.class);

    @Autowired
    private MySQLStudentDao mySQLStudentDao;

    @Autowired
    private YidaoappscDao oracleStudentDao;

    public Object mysql(String filter) {
        return mySQLStudentDao.findFilter(filter);
//        return mySQLStudentDao.findAll();
    }

    public Object oracle(String filter) {
        return oracleStudentDao.findFilter(filter);
//        return oracleStudentDao.findAll();
    }
}
