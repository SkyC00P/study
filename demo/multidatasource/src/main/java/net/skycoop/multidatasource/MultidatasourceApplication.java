package net.skycoop.multidatasource;

import com.slyak.spring.jpa.FreemarkerSqlTemplates;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.annotation.Bean;

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
