package net.skycoop.db.dao;

import com.slyak.spring.jpa.GenericJpaRepository;
import com.slyak.spring.jpa.TemplateQuery;
import net.skycoop.db.domain.Yidaoappsc;
import org.springframework.data.domain.Page;
import org.springframework.data.domain.Pageable;

import java.util.Map;


public interface YidaoappscDao extends GenericJpaRepository<Yidaoappsc, String> {
    @TemplateQuery
    Page<Map<String,Object>> findFilter( Pageable pageable);
}
