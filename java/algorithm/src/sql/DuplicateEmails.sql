--- 测试环境
Create table If Not Exists Person (Id int, Email varchar(255));
Truncate table Person;
insert into Person (Id, Email) values ('1', 'a@b.com');
insert into Person (Id, Email) values ('2', 'c@d.com');
insert into Person (Id, Email) values ('3', 'a@b.com');

--- Write a SQL query to find all duplicate emails in a table named Person.
--- Runtime: 203 ms, faster than 37.26% of MySQL online submissions for Duplicate Emails.
select count_table.Email from
       (select Person.Email,count(Person.Email) as count from Person group by Person.Email) as count_table
where count_table.count > 1;