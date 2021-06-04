package net.skycoop.multidatasource.mysql.dao;

import com.slyak.spring.jpa.GenericJpaRepository;
import com.slyak.spring.jpa.TemplateQuery;
import net.skycoop.multidatasource.mysql.domain.MySQLStudentEntity;
import org.springframework.data.repository.query.Param;

import java.util.List;

public interface MySQLStudentDao extends GenericJpaRepository<MySQLStudentEntity, Long> {

    @TemplateQuery
    List<MySQLStudentEntity> findFilter(@Param("filter") String filter);
}
