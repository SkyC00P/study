package net.skycoop.multidatasource.oracle.dao;

import com.slyak.spring.jpa.GenericJpaRepository;
import com.slyak.spring.jpa.TemplateQuery;
import net.skycoop.multidatasource.oracle.domain.Yidaoappsc;
import org.springframework.data.repository.query.Param;

import java.util.List;

public interface YidaoappscDao extends GenericJpaRepository<Yidaoappsc, String> {
    @TemplateQuery
    List<Yidaoappsc> findFilter(@Param("filter") String filter);
}
