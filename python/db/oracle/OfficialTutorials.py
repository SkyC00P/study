# coding:utf-8

import cx_Oracle

connect_info = {
    "username": "msbase",
    "password": "ms123",
    "dsn": "192.168.8.205/orcl",
    "port": 1512,
    "encoding": 'UTF-8'
}


class ForceStr(str):
    def __repr__(self):
        return super(ForceStr, self).__str__()


def switch_container(data):
    ret = None
    if isinstance(data, str):
        ret = ForceStr(data)
    elif isinstance(data, list) or isinstance(data, tuple):
        ret = [switch_container(var) for var in data]
    elif isinstance(data, dict):
        ret = dict((switch_container(k), switch_container(v))
                   for k, v in data.iteritems())
    else:
        ret = data
    return ret


def dynamic_query(connect_info):
    """
    动态查询
    """
    # Establish the database connection
    connection = cx_Oracle.connect(
        connect_info['username'], connect_info['password'], connect_info['dsn'])

    # Obtain a cursor
    cursor = connection.cursor()

    # Data for binding
    managerId = '24D5E5D2BDC24EBDB6244F3EBAE7ED5A'

    # Execute the query
    sql = """select * from msbase.mgrou where id = :mid """
    cursor.execute(sql, mid=managerId)
    # Loop over the result set
    for row in cursor:
        print(row)
    pass


def standalone_connect(connect_info):
    """
    Oracle 直连 - 常规
    """
    connection = None
    try:
        connection = cx_Oracle.connect(
            connect_info['username'],
            connect_info['password'],
            connect_info['dsn'],
            encoding=connect_info['encoding']
        )

        print(connection.version)
    except cx_Oracle.Error as err:
        print(err)
    finally:
        if connection:
            connection.close()
    pass


def with_standalone_connect(connect_info):
    """
    Oracle 直连 - With语法
    """
    try:
        with cx_Oracle.connect(
                connect_info['username'],
                connect_info['password'],
                connect_info['dsn'],
                encoding=connect_info['encoding']) as connection:
            print(connection.version)
    except cx_Oracle.Error as err:
        print(err)
    pass


POOL = None


def pool_connect(connect_info):
    """
    Oracle 连接池
    """
    global POOL
    # 这里还需判断连接池是否关闭
    if POOL is None:
        POOL = cx_Oracle.SessionPool(connect_info['username'], connect_info['password'],
                                     connect_info['dsn'], min=2, max=5, increment=1, encoding=connect_info['encoding'])
        print("create pool")

    connect = POOL.acquire()
    print("Use connect:", connect.version)
    print("Release connect")
    POOL.release(connect)
    print("Close connect")
    POOL.close()
    pass


def query(mode='fetchall'):
    """
    调用 fetchone(),fetchmany(),fetchall() 方法来进行查询
    尽管 fetchone() 每次仅返回一条数据，但是内部已经缓存了一部分数据，缓存的数量为Cursor.arraysize，可以在调用Cursor.execute()修改该值
    """
    # 第一步：获取连接
    connection = cx_Oracle.connect(
        connect_info['username'],
        connect_info['password'],
        connect_info['dsn'],
        encoding=connect_info['encoding'])
    # 第二步：创建游标
    cursor = connection.cursor()
    # 第三步: 执行SQL语句
    sql = 'select t.id,t.scode as code,t.name,t.ALIAS,t.STATUS,t.PARENTID,t1.name as type from mgrou t \
    left join mgrcode t1 on t.OUTYPE = t1.id  where rownum<=3'
    cursor.execute(sql)
    # 第四步：获取数据
    i = 0
    if mode == 'fetchone':
        print 'fetchone'
        while True:
            row = cursor.fetchone()
            if row is None:
                break
            i+=1
            print switch_container(row)
            print "循环第 %s 次" % i
    elif mode == 'fetchmany':
        print 'fetchmany'
        while True:
            rows = cursor.fetchmany(2)
            if not rows:
                break
            for row in rows:
                print switch_container(row)
            i+=1
            print "循环第 %s 次" % i
    elif mode == 'fetchall':
        print 'fetchall'
        while True:
            rows = cursor.fetchall()
            if not rows:
                break
            for row in rows:
                print switch_container(row)
            i+=1
            print "循环第 %s 次" % i

    # 第五步：释放资源
    cursor.close()
    connection.close()
    pass


if __name__ == "__main__":
    # dynamic_query(connect_info)
    # standalone_connect(connect_info)
    # with_standalone_connect(connect_info)
    # pool_connect(connect_info)
    # pool_connect(connect_info)
    query()
    query('fetchone')
    query('fetchmany')
    query('fetchall')
    pass
