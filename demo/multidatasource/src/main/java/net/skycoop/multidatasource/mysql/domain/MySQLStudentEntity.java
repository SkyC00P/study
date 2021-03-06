package net.skycoop.multidatasource.mysql.domain;

import javax.persistence.*;

@Entity
@Table(name = "student", schema = "test", catalog = "")
public class MySQLStudentEntity {
    private Long id;
    private String name;

    @Id
    @Column(name = "id")
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    @Basic
    @Column(name = "name")
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
}
