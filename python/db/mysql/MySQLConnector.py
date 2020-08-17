#!/usr/bin/python
# coding:utf-8

import mysql.connector

connect_info = {
    "host": "localhost",
    "user": "root",
    "password": "IMCsoft.12345",
    "database": "elsi-test"
}


class Mysql_Tool:

    def create_with_no_database(self):
        return mysql.connector.connect(host=self.connect_info['host'], user=self.connect_info['user'], password=self.connect_info['password'])

    def create_with_database(self):
        return mysql.connector.connect(host=self.connect_info['host'], user=self.connect_info['user'], password=self.connect_info['password'], database=self.connect_info['database'])

    def __init__(self, connect_info):
        self.connect_info = connect_info
    pass


def test_connect():
    # 创建连接,不指定数据库
    mydb = mysql.connector.connect(
        host="localhost",
        user="root",
        password="IMCsoft.12345"
    )
    print(mydb)
    return mydb


def test_create_database():
    # 创建数据库
    mydb = test_connect()
    mycursor = mydb.cursor()
    mycursor.execute(
        "create database if not exists `elsi-test` default character set=utf8 default collate utf8_bin")
    mycursor.execute("show databases")

    for x in mycursor:
        print x
    pass


def test_connect_database():
    mydb = mysql.connector.connect(
        host="localhost",
        user="root",
        password="IMCsoft.12345",
        database="elsi-test"
    )

    cursor = mydb.cursor()
    cursor.execute("show tables")

    for x in cursor:
        print x


def test_create_table():
    mydb = Mysql_Tool(connect_info).create_with_database()
    cursor = mydb.cursor()
    cursor.execute(
        "CREATE TABLE customers (id INT AUTO_INCREMENT PRIMARY KEY, name VARCHAR(255), address VARCHAR(255))")
    pass


def test_get_insert_id():
    mydb = Mysql_Tool(connect_info).create_with_database()
    cursor = mydb.cursor()
    sql = "INSERT INTO customers (name, address) VALUES (%s, %s)"
    val = ("Michelle", "Blue Village")
    cursor.execute(sql, val)
    mydb.commit()

    print("1 record inserted, ID:", cursor.lastrowid)
    pass


def test_del():
    mydb = Mysql_Tool(connect_info).create_with_database()
    cursor = mydb.cursor()
    sql = "DELETE FROM customers WHERE id = %s"
    cursor.execute(sql, [1])
    mydb.commit()

    print(cursor.rowcount, "record(s) deleted")


if __name__ == "__main__":
    # test_create_database()
    # test_connect_database()
    # test_create_table()
    # test_get_insert_id()
    test_del()
    #mysql_tool = Mysql_Tool(connect_info)
    #mydb = mysql_tool.create_with_no_database()
    #print mydb
