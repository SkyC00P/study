# coding:utf-8
import cx_Oracle
"""
一般默认的Centos7发行版的Python版本为Python 2.7.5
要使用python连接到Oracle，有几个必要条件
1. 安装Oracle的客户端依赖
2. 安装Python依赖组件 cx_Oracle
"""

conn = cx_Oracle.connect("msbase", "ms123", "192.168.8.205/orcl")

# 打印数据库版本
print(conn.version)

# 执行查询
cur = conn.cursor()
cur.execute('select * from msbase.mgrou')

max_print = 2
count = 0
for result in cur:
    if count == max_print:
        break

    count = count + 1
    print(result)

cur.close()
conn.close()
