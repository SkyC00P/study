# coding:utf-8

import cx_Oracle

"""
Connections are created by cx_Oracle.connect() or its alias cx_Oracle.Connection().
"""

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
            i += 1
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
            i += 1
            print "循环第 %s 次" % i
    elif mode == 'fetchall':
        print 'fetchall'
        while True:
            rows = cursor.fetchall()
            if not rows:
                break
            for row in rows:
                print switch_container(row)
            i += 1
            print "循环第 %s 次" % i

    # 第五步：释放资源
    cursor.close()
    connection.close()
    pass


class BaseDb:
    def __init__(self, connect_info):
        self.connect_info = connect_info

    def connect(self):
        return cx_Oracle.connect(self.connect_info['username'], self.connect_info['password'], self.connect_info['dsn'], encoding=self.connect_info['encoding'])


class DynamicQuery(BaseDb):

    __SQL = 'select t.id,t.scode as code,t.name,t.ALIAS,t.STATUS,t.PARENTID from msbase.mgrou t where t.id = :mid '
    __managerId = '24D5E5D2BDC24EBDB6244F3EBAE7ED5A'
    """
    动态查询
    """

    def queryByName(self, id, mode='dict'):
        "以键值对查询"
        try:
            with self.connect() as connect:
                with connect.cursor() as cursor:
                    if mode == 'dict':
                        cursor.execute(self.__SQL, {"mid": id})
                    else:
                        cursor.execute(self.__SQL, mid=id)

                    row = cursor.fetchone()
                    if row:
                        print '[%s] queryByName :' % mode, switch_container(
                            row)
        except cx_Oracle.Error as err:
            print err
        pass

    def queryfixed(self):
        "直接按位置绑定参数"
        try:
            with self.connect() as connect:
                with connect.cursor() as cursor:
                    # 这个会报错 ORA-01036: illegal variable name/number
                    # cursor.execute(DynamicQuery.__SQL, '24D5E5D2BDC24EBDB6244F3EBAE7ED5A')
                    # 正确的传值如下
                    cursor.execute(DynamicQuery.__SQL, [
                                   '24D5E5D2BDC24EBDB6244F3EBAE7ED5A'])
                    row = cursor.fetchone()
                    if row:
                        print 'queryfixed:', switch_container(row)
        except cx_Oracle.Error as err:
            print err
        pass

    def bindOutFromOracle(self):
        "从Oracle的存储过程或函数获得变量值"
        plsql = ('begin '
                 'select count(*) into :customer_count '
                 'from msbase.mgrou;'
                 'end;')
        try:
            with self.connect() as conn:
                with conn.cursor() as cursor:
                    count = cursor.var(int)
                    cursor.execute(plsql, customer_count=count)
                    print '[bindOutFromOracle] The count is %d' % count.getvalue()
        except cx_Oracle.Error as err:
            print err
        pass

    pass


class CURD(BaseDb):

    def query(self, sql, before_msg='', after_msg='', loop_msg=''):
        try:
            with self.connect() as conn:
                with conn.cursor() as cursor:
                    cursor.execute(sql)
                    rows = cursor.fetchall()
                    if rows is None:
                        return
                    if before_msg:
                        print before_msg,
                    for row in rows:
                        print loop_msg, switch_container(row),
                    if after_msg:
                        print after_msg,
        except cx_Oracle.Error as err:
            print err
        pass

    def insert(self, row):
        sql = "insert into mstest.EMPLOYEE_M(ENAME,EMPLOYEE_ID,MANAGER_ID) VALUES (:name,:id,:mid)"
        try:
            with self.connect() as conn:
                with conn.cursor() as cursor:
                    cursor.execute(sql, row)
                    conn.commit()
        except cx_Oracle.Error as err:
            print err
    pass

    def insert_many(self, rows):
        sql = "insert into mstest.EMPLOYEE_M(ENAME,EMPLOYEE_ID,MANAGER_ID) VALUES (:name,:id,:mid)"
        try:
            with self.connect() as conn:
                with conn.cursor() as cursor:
                    cursor.executemany(sql, rows)
                    conn.commit()
        except cx_Oracle.Error as err:
            print err
        pass

    def update(self, sql, vars=''):
        try:
            with self.connect() as conn:
                with conn.cursor() as cursor:
                    cursor.execute(sql, vars)
                    conn.commit()
        except cx_Oracle.Error as err:
            print err
        pass

    def delete(self, sql, vars=''):
        try:
            with self.connect() as conn:
                with conn.cursor() as cursor:
                    cursor.execute(sql, vars)
                    conn.commit()
        except cx_Oracle.Error as err:
            print err
        pass


class Transaction(BaseDb, object):

    """
    在执行插入，更新，删除时，默认是自动提交到数据库的，所以需要手动调用 Connection.commit() 方法
    如果需要回滚，则需要手动调用 connection.rollback()
    默认未提交的在连接关闭之后会自动回滚
    通过设置 Connection.autocommit 为true可自动提交，默认为false
    也可以显式申明事务的开始 Connection.begin()
    """
    __conn = None
    __cursor = None

    def __init__(self, connect_info):
        super(Transaction, self).__init__(connect_info)
        self.__conn = super(Transaction, self).connect()
        self.__cursor = self.__conn.cursor()
    pass

    def begin(self):
        self.__conn.begin()
        pass

    def insert_teacher(self, name):
        sql = "insert into mstest.t_teacher(name) values(:name) returning id into :id"
        id = self.__cursor.var(str)
        self.__cursor.execute(sql, name=name, id=id)
        return id.getvalue()[0]

    def insert_student(self, students, teacher_id):
        sql = "insert into mstest.t_student(name,sex,teacherFk) values (:name,:sex,:id)"
        if students and teacher_id:
            for student in students:
                student['id'] = teacher_id
            pass
            self.__cursor.executemany(sql, students)

    def commit(self):
        self.__conn.commit()

    def rollback(self):
        self.__conn.rollback()

    def close(self):
        if self.__cursor:
            self.__cursor.close()
        if self.__conn:
            self.__conn.close()
        pass


def conn_test():
    standalone_connect(connect_info)
    with_standalone_connect(connect_info)
    pool_connect(connect_info)
    pool_connect(connect_info)
    pass


def query_test():
    query()
    query('fetchone')
    query('fetchmany')
    query('fetchall')

    dynamic_query = DynamicQuery(connect_info)
    dynamic_query.queryfixed()
    dynamic_query.queryByName('24D5E5D2BDC24EBDB6244F3EBAE7ED5A')
    dynamic_query.queryByName('24D5E5D2BDC24EBDB6244F3EBAE7ED5A', 'no dict')
    dynamic_query.bindOutFromOracle()
    pass


def curd_test():
    curd = CURD(connect_info)
    count_sql = 'select count(1) from mstest.EMPLOYEE_M'
    print '插入单条数据, 列表传参'
    curd.query(count_sql, before_msg='插入前', loop_msg='count:')
    curd.insert(['skycoop', 1, 1])
    curd.query(count_sql, before_msg='插入后', loop_msg='count:')

    print '\n插入单条数据，字典传参'
    curd.query(count_sql, before_msg='插入前', loop_msg='count:')
    curd.insert({"name": 'skycoop', "id": 1, "mid": 1})
    curd.query(count_sql, before_msg='插入后', loop_msg='count:')

    print '\n插入单条数据，元祖传参'
    curd.query(count_sql, before_msg='插入前', loop_msg='count:')
    curd.insert(('skycoop',  1,  1))
    curd.query(count_sql, before_msg='插入后', loop_msg='count:')

    print '\n插入多条数据,元祖列表'
    curd.query(count_sql, before_msg='插入前', loop_msg='count:')
    curd.insert_many(
        [('skycoop',  1,  1), ('skycoop',  1,  1), ('skycoop',  1,  1)])
    curd.query(count_sql, before_msg='插入后', loop_msg='count:')

    print '\n插入多条数据,字典列表'
    curd.query(count_sql, before_msg='插入前', loop_msg='count:')
    curd.insert_many([{"name": 'skycoop', "id": 1, "mid": 1}, {
                     "name": 'skycoop', "id": 1, "mid": 1}])
    curd.query(count_sql, before_msg='插入后', loop_msg='count:')

    print '\n更新name从skycoop变为Unkown'
    curd.update('update mstest.employee_m set ename = \'skycoop\'')
    check_sql = 'select count(1) from mstest.employee_m where ename=\'skycoop\''
    curd.query(check_sql, before_msg='skycoop count:')
    curd.update('update mstest.employee_m set ename = :newname where ename= :oldname', [
                'Unkown', 'skycoop'])
    curd.query(check_sql, before_msg='skycoop count:')

    print '\n删除所有叫 Unkown'
    curd.query(count_sql, before_msg='del befroe count:')
    curd.delete(
        'delete from mstest.employee_m where ename = :name', ['Unkown'])
    curd.query(count_sql, before_msg='del after count:')
    pass


def transaction_test():
    """
    drop table t_teacher;
    drop table t_student;
    create table t_teacher(
    id       VARCHAR2(36) default sys_guid() not null   primary key,  
    name    varchar2(20) not null 
    );

    create table t_student(  
    id       VARCHAR2(36) default sys_guid() not null   primary key,  
    name    varchar2(20) not null,  
    sex     varchar2(3) ,
    teacherFk VARCHAR2(36)
    ); 
    测试方法：新增一个老师并且返回老师的id，新增多个学生并指定为新增的老师id，如果都成功则提交，否则回滚
    """
    list_student = [{'name': '小马', 'sex': '男'}, {
        'name': '小红', 'sex': '女'}, {'name': '小明', 'sex': '男'}]

    transaction = None
    try:
        transaction = Transaction(connect_info)
        print '连接建立成功', switch_container(transaction)
        transaction.begin()
        print '开启事务'
        teacher_id = transaction.insert_teacher('skycoop')
        print '新增老师:', teacher_id
        transaction.insert_student(list_student, teacher_id)
        print '新增学生'
        transaction.commit()
        print '提交事务'
    except cx_Oracle.Error as err:
        print 'SQL 异常:', err
        if transaction:
            print '回滚事务'
            transaction.rollback()
        pass
    finally:
        if transaction:
            print '回收资源'
            transaction.close()

    pass


if __name__ == "__main__":
    # conn_test()
    # query_test()
    # curd_test()
    transaction_test()
    pass
