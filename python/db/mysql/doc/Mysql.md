要在Python里跑Mysql，需要安装驱动

```
yum install MySQL-python
```

这个也是装驱动 mysql-connector 似乎是官方驱动
```
python -m pip install mysql-connector-python
````

整个api接口与Oracle的基本一致，流程为
1. 先获取连接
2. 获取游标
3. 通过游标执行SQL语句
4. 回收资源

连接用`connect()`方法
游标用`cursor()`
执行单条SQL语句`execute()`
执行多条SQL语句`executemany()`
查询获取全部`fetchall()`
查询获取一条`fetchone()`
事务提交`commit()`

不同点在于获取SQL执行成功时返回的变量，如插入行的ID，动态绑定参数

动态绑定参数的占位符为%s,占位符传参似乎仅支持列表，元祖传参，按位置传参，尚不知是否支持按键值对传参

游标有特殊的变量 cursor.lastrowid 表插入的行号， cursor.rowcount 表示影响的行数

这里有MySQLdb的示例
https://www.tutorialspoint.com/python/python_database_access.htm

官方文档
https://dev.mysql.com/doc/connector-python/en/connector-python-example-connecting.html

Python 定义了通用的数据库接口 DB-API Python Database API
https://www.python.org/dev/peps/pep-0249/
https://halfcooked.com/presentations/osdc2006/python_databases.html

mysql文档说得比较详细的
https://www.mysqltutorial.org/python-mysql/
