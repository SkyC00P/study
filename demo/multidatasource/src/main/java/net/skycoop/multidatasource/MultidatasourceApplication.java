package net.skycoop.multidatasource;

import com.slyak.spring.jpa.FreemarkerSqlTemplates;
import com.slyak.spring.jpa.GenericJpaRepositoryFactoryBean;
import com.slyak.spring.jpa.GenericJpaRepositoryImpl;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.annotation.Bean;
import org.springframework.data.jpa.repository.config.EnableJpaRepositories;

@SpringBootApplication
public class MultidatasourceApplication {

    public static void main(String[] args) {
        SpringApplication.run(MultidatasourceApplication.class, args);
    }

    @Bean
    public FreemarkerSqlTemplates freemarkerSqlTemplates() {
        FreemarkerSqlTemplates templates = new FreemarkerSqlTemplates();
        templates.setEncoding("UTF-8");
        templates.setSuffix(".sftl");
        templates.setTemplateBasePackage("");
        return templates;
    }
}
