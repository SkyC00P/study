#!/usr/bin/python
# coding:utf-8

import mysql.connector
from mysql.connector import Error
from mysql.connector import MySQLConnection
from configparser import ConfigParser


def connect():
    """ Connect to MySQL database """
    conn = None
    try:
        conn = mysql.connector.connect(host='localhost',
                                       database='elsi-test',
                                       user='root',
                                       password='IMCsoft.12345')
        if conn.is_connected():
            print('Connected to MySQL database')

    except Error as e:
        print(e)

    finally:
        if conn is not None and conn.is_connected():
            conn.close()


def read_db_config(filename='config.ini', section='mysql'):
    """ Read database configuration file and return a dictionary object
    :param filename: name of the configuration file
    :param section: section of database configuration
    :return: a dictionary of database parameters
    """
    # create parser and read ini configuration file
    parser = ConfigParser()
    parser.read(filename)

    # get section, default to mysql
    db = {}
    if parser.has_section(section):
        items = parser.items(section)
        for item in items:
            db[item[0]] = item[1]
    else:
        raise Exception(
            '{0} not found in the {1} file'.format(section, filename))

    return db


def connect_with_config():
    """ Connect to MySQL database """

    db_config = read_db_config()
    conn = None
    try:
        print('Connecting to MySQL database...')
        conn = MySQLConnection(**db_config)

        if conn.is_connected():
            print('Connection established.')
        else:
            print('Connection failed.')

    except Error as error:
        print(error)

    finally:
        if conn is not None and conn.is_connected():
            conn.close()
            print('Connection closed.')
    pass


def query_with_fetchone():
    """逐个获取"""
    try:
        dbconfig = read_db_config()
        conn = MySQLConnection(**dbconfig)
        cursor = conn.cursor()
        cursor.execute("SELECT * FROM customers")

        row = cursor.fetchone()

        while row is not None:
            print(row)
            row = cursor.fetchone()

    except Error as e:
        print(e)

    finally:
        cursor.close()
        conn.close()


def query_with_fetchall():
    try:
        dbconfig = read_db_config()
        conn = MySQLConnection(**dbconfig)
        cursor = conn.cursor()
        cursor.execute("SELECT * FROM customers")
        rows = cursor.fetchall()

        print('Total Row(s):', cursor.rowcount)
        for row in rows:
            print(row)

    except Error as e:
        print(e)

    finally:
        cursor.close()
        conn.close()


def iter_row(cursor, size=10):
    while True:
        rows = cursor.fetchmany(size)
        if not rows:
            break
        for row in rows:
            yield row


def query_with_fetchmany():
    """fetchmany 加入缓存，一次获取全部将耗时长且需要缓存空间大"""
    try:
        dbconfig = read_db_config()
        conn = MySQLConnection(**dbconfig)
        cursor = conn.cursor()

        cursor.execute("SELECT * FROM customers")

        for row in iter_row(cursor, 10):
            print(row)

    except Error as e:
        print(e)

    finally:
        cursor.close()
        conn.close()


def insert_data(name, address):
    query = "INSERT INTO customers(name,address) " \
            "VALUES(%s,%s)"
    args = (name, address)

    try:
        db_config = read_db_config()
        conn = MySQLConnection(**db_config)

        cursor = conn.cursor()
        cursor.execute(query, args)

        if cursor.lastrowid:
            print('last insert id', cursor.lastrowid)
        else:
            print('last insert id not found')

        conn.commit()
    except Error as error:
        print(error)

    finally:
        cursor.close()
        conn.close()


def insert_many_data(datas):
    query = "INSERT INTO customers(name,address) " \
            "VALUES(%s,%s)"

    try:
        db_config = read_db_config()
        conn = MySQLConnection(**db_config)

        cursor = conn.cursor()
        cursor.executemany(query, datas)

        conn.commit()
    except Error as e:
        print('Error:', e)

    finally:
        cursor.close()
        conn.close()


def test_insert_many():
    datas = [('Harry Potter And The Order Of The Phoenix', '9780439358071'),
             ('Gone with the Wind', '9780446675536'),
             ('Pride and Prejudice (Modern Library Classics)', '9780679783268')]
    insert_many_data(datas)


def update_data(id, name):
    # read database configuration
    db_config = read_db_config()

    # prepare query and data
    query = """ UPDATE customers
                SET name = %s
                WHERE id = %s """

    data = (name, id)

    try:
        conn = MySQLConnection(**db_config)

        # update book title
        cursor = conn.cursor()
        cursor.execute(query, data)

        # accept the changes
        conn.commit()

    except Error as error:
        print(error)

    finally:
        cursor.close()
        conn.close()


def delete_data(id):
    db_config = read_db_config()

    query = "DELETE FROM customers WHERE id = %s"

    try:
        # connect to the database server
        conn = MySQLConnection(**db_config)

        # execute the query
        cursor = conn.cursor()
        cursor.execute(query, (id,))

        # accept the change
        conn.commit()

    except Error as error:
        print(error)

    finally:
        cursor.close()
        conn.close()


"""
创建函数
use `elsi-test`;
DELIMITER $$
CREATE PROCEDURE find_all ( ) 
BEGIN
	SELECT
		id,
		CONCAT( NAME, ' in ', address ) AS content 
	FROM
		customers;
END$$

DELIMITER ;

DELIMITER $$

CREATE PROCEDURE find_by_id(
	IN p_id VARCHAR(13),
    OUT p_title VARCHAR(255)
)
BEGIN
	SELECT CONCAT( NAME, ' in ', address ) AS content  
    INTO p_title 
    FROM customers
	WHERE id = p_id;
END$$
DELIMITER ;

call find_all();
call find_by_id(1,@content);
select @content;
"""


def call_find_all():
    try:
        db_config = read_db_config()
        conn = MySQLConnection(**db_config)
        cursor = conn.cursor()

        cursor.callproc('find_all')

        # print out the result
        for result in cursor.stored_results():
            print(result.fetchall())

    except Error as e:
        print(e)

    finally:
        cursor.close()
        conn.close()


def call_find_by_id():
    try:
        db_config = read_db_config()
        conn = MySQLConnection(**db_config)
        cursor = conn.cursor()

        args = ['1', 0]
        result_args = cursor.callproc('find_by_id', args)

        print(result_args[1])

    except Error as e:
        print(e)

    finally:
        cursor.close()
        conn.close()


def read_file(filename):
    with open(filename, 'rb') as f:
        photo = f.read()
    return photo


def update_blob(author_id, filename):
    # read file
    data = read_file(filename)

    # prepare update query and data
    query = "UPDATE authors " \
            "SET photo = %s " \
            "WHERE id  = %s"

    args = (data, author_id)

    db_config = read_db_config()

    try:
        conn = MySQLConnection(**db_config)
        cursor = conn.cursor()
        cursor.execute(query, args)
        conn.commit()
    except Error as e:
        print(e)
    finally:
        cursor.close()
        conn.close()


def write_file(data, filename):
    with open(filename, 'wb') as f:
        f.write(data)


def read_blob(author_id, filename):
    # select photo column of a specific author
    query = "SELECT photo FROM authors WHERE id = %s"

    # read database configuration
    db_config = read_db_config()

    try:
        # query blob data form the authors table
        conn = MySQLConnection(**db_config)
        cursor = conn.cursor()
        cursor.execute(query, (author_id,))
        photo = cursor.fetchone()[0]

        # write blob data into a file
        write_file(photo, filename)

    except Error as e:
        print(e)

    finally:
        cursor.close()
        conn.close()


if __name__ == '__main__':
    # print read_db_config()
    # connect()
    # connect_with_config()
    # query_with_fetchone()
    # query_with_fetchall()
    # insert_data('skycoop','my skycoop address')
    # test_insert_many()
    # update_data(9, 'skycoop')
    # delete_data(9)
    # call_find_all()
    call_find_by_id()
