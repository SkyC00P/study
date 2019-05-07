--- 测试环境
Create table If Not Exists Customers (Id int, Name varchar(255));
Create table If Not Exists Orders (Id int, CustomerId int);
Truncate table Customers;
insert into Customers (Id, Name) values ('1', 'Joe');
insert into Customers (Id, Name) values ('2', 'Henry');
insert into Customers (Id, Name) values ('3', 'Sam');
insert into Customers (Id, Name) values ('4', 'Max');
Truncate table Orders;
insert into Orders (Id, CustomerId) values ('1', '3');
insert into Orders (Id, CustomerId) values ('2', '1');

--- 查询语句 Write a SQL query to find all customers who never order anything.
--- Runtime: 241 ms, faster than 92.79% of MySQL online submissions for Customers Who Never Order.
select CUSTOMERS.NAME as Customers from CUSTOMERS left join ORDERS on CUSTOMERS.id = ORDERS.CUSTOMERID
where ORDERS.CUSTOMERID is null;
