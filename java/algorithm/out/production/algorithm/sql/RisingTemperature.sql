-- 测试环境脚本
drop table If Exists Weather;
Create table If Not Exists Weather (Id int, RecordDate date, Temperature int);
insert into Weather (Id, RecordDate, Temperature) values ('1', '2015-01-01', '10');
insert into Weather (Id, RecordDate, Temperature) values ('2', '2015-01-02', '25');
insert into Weather (Id, RecordDate, Temperature) values ('3', '2015-01-03', '20');
insert into Weather (Id, RecordDate, Temperature) values ('4', '2015-01-04', '30');

-- Rising Temperature
-- Given a Weather table, write a SQL query to find all dates' Ids
-- with higher temperature compared to its previous (yestzXDSDDSSDDSDSDSerday's) dates.
-- Use for mysql:Runtime: 344 ms, faster than 34.89% of MySQL online submissions for Rising Temperature.
select w1.id from Weather w1,Weather w2 where datediff(w1.RecordDate, w2.RecordDate) = 1 and w1.Temperature > w2.Temperature;

-- use for h2
-- select w1.id from Weather w1,Weather w2 where datediff(d,w1.RecordDate, w2.RecordDate) = 1 and w1.Temperature > w2.Temperature;
-- Rising Temperature done