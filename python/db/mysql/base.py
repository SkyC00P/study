#!/usr/bin/python
# coding:utf-8

"""
Mysql 基本功能
"""
import MySQLdb

db = MySQLdb.connect(host="localhost",  # your host 
                     user="root",       # username
                     passwd="IMCsoft.12345",     # password
                     db="elsi-terminal")   # name of the database

# Create a Cursor object to execute queries.
cur = db.cursor()

# Select data from table using SQL query.
cur.execute("SELECT * FROM police limit 5")

# print the first and second columns      
for row in cur.fetchall() :
    print row[0], " ", row[1]