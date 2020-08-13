#!/usr/bin/python
# coding:utf-8

"""
Mysql 基本功能
"""
import MySQLdb

db = MySQLdb.connect(host="loc",  # your host 
                     user="root",       # username
                     passwd="root",     # password
                     db="pythonspot")   # name of the database

# Create a Cursor object to execute queries.
cur = db.cursor()

# Select data from table using SQL query.
cur.execute("SELECT * FROM examples")

# print the first and second columns      
for row in cur.fetchall() :
    print row[0], " ", row[1]