--- 测试环境
drop table If Exists Person;
create table Person (Id int primary key , Email varchar(255));
insert into Person (Id, Email) values ('1', 'john@example.com');
insert into Person (Id, Email) values ('2', 'bob@example.com');
insert into Person (Id, Email) values ('3', 'john@example.com');

-- Delete Duplicate Emails
-- Write a SQL query to delete all duplicate email entries in a table named Person,
-- keeping only unique emails based on its smallest Id.
-- Your output is the whole Person table after executing your sql. Use delete statement
-- Runtime: 547 ms, faster than 90.27% of MySQL online submissions for Delete Duplicate Emails.
DELETE
FROM Person
WHERE Email IN (select a.Email FROM( SELECT Email FROM Person GROUP BY Email HAVING count(Email) > 1) a)
  AND id NOT IN (select b.id from (SELECT min(id) as id FROM Person GROUP BY Email HAVING count(Email) > 1) b);

select * from Person;
-- Delete Duplicate Emails done