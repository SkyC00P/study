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
select DISTINCT e.SALARY as SecondHighestSalary from Employee e order by e.SALARY desc limit 1 offset 1;

-- Runtime: 157 ms, faster than 11.10% of MySQL online submissions for Second Highest Salary
SELECT
    (SELECT DISTINCT
            Salary
        FROM
            Employee
        ORDER BY Salary DESC
        LIMIT 1 OFFSET 1) AS SecondHighestSalary
;

-- Runtime: 162 ms, faster than 8.31% of MySQL online submissions for Second Highest Salary.
SELECT
    IFNULL(
      (SELECT DISTINCT Salary
       FROM Employee
       ORDER BY Salary DESC
        LIMIT 1 OFFSET 1),
    NULL) AS SecondHighestSalary;

truncate table Employee;

-- Runtime: 145 ms, faster than 29.22% of MySQL online submissions for Second Highest Salary
SELECT MAX(Salary) AS SecondHighestSalary
FROM Employee
WHERE Salary < (SELECT MAX(Salary) FROM Employee)
