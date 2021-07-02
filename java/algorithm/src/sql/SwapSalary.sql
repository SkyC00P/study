create table if not exists salary
(
    id     int,
    name   varchar(100),
    sex    char(1),
    salary int
);
Truncate table salary;
insert into salary (id, name, sex, salary)
values ('1', 'A', 'm', '2500');
insert into salary (id, name, sex, salary)
values ('2', 'B', 'f', '1500');
insert into salary (id, name, sex, salary)
values ('3', 'C', 'm', '5500');
insert into salary (id, name, sex, salary)
values ('4', 'D', 'f', '500');

-- +-------------+----------+
-- | Column Name | Type     |
-- +-------------+----------+
-- | id          | int      |
-- | name        | varchar  |
-- | sex         | ENUM     |
-- | salary      | int      |
-- +-------------+----------+
-- id is the primary key for this table.
-- The sex column is ENUM value of type ('m', 'f').
-- The table contains information about an employee.

-- Runtime: 174 ms, faster than 99.80% of MySQL online submissions for Swap Salary.
-- Memory Usage: 0B, less than 100.00% of MySQL online submissions for Swap Salary.
update salary
set sex = (case sex when 'm' then 'f' else 'm' end)
where sex = 'm'
   or sex = 'f'
