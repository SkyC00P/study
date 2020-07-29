# coding:utf-8
import cx_Oracle

"""
动态查询
"""

# Establish the database connection
connection = cx_Oracle.connect("msbase", "ms123", "192.168.8.205/orcl")

# Obtain a cursor
cursor = connection.cursor()

# Data for binding
managerId = '24D5E5D2BDC24EBDB6244F3EBAE7ED5A'

# Execute the query
sql = """select * from msbase.mgrou where id = :mid """
cursor.execute(sql, mid = managerId)

# Loop over the result set
for row in cursor:
    print(row)