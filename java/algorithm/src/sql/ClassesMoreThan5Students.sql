Create table If Not Exists courses (student varchar(255), class varchar(255));
Truncate table courses;
insert into courses (student, class) values ('A', 'Math');
insert into courses (student, class) values ('B', 'English');
insert into courses (student, class) values ('C', 'Math');
insert into courses (student, class) values ('D', 'Biology');
insert into courses (student, class) values ('E', 'Math');
insert into courses (student, class) values ('F', 'Computer');
insert into courses (student, class) values ('G', 'Math');
insert into courses (student, class) values ('H', 'Math');
insert into courses (student, class) values ('I', 'Math');

-- Runtime: 245 ms, faster than 70.04% of MySQL online submissions for Classes More Than 5 Students.
-- Memory Usage: 0B, less than 100.00% of MySQL online submissions for Classes More Than 5 Students.
select class from courses group by class having count(distinct student) >= 5
