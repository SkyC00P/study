package net.skycoop.multidatasource.mysql.dao;

import net.skycoop.multidatasource.mysql.domain.MySQLStudentEntity;
import org.springframework.data.jpa.repository.JpaRepository;

public interface MySQLStudentDao extends JpaRepository<MySQLStudentEntity, Long> {
}
