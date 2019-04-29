drop TABLE Employee;
CREATE TABLE Employee (
  `id`     bigint       NOT NULL,
  `Salary` double NULL,
  PRIMARY KEY (`id`)
);

INSERT INTO Employee (`id`,`Salary`) VALUES ('1', '100.00');
INSERT INTO Employee (`id`,`Salary`) VALUES ('2', '200.00');
INSERT INTO Employee (`id`,`Salary`) VALUES ('3', '300.00');

-- 需要返回為null，当第二高不存在时
select e.SALARY as SecondHighestSalary from Employee e order by e.SALARY desc limit 1,1;

truncate table Employee;

SELECT max(Salary)
    FROM Employee
    WHERE Salary < (SELECT max(Salary) FROM Employee)