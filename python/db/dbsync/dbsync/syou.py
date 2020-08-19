# coding:utf-8
import cx_Oracle
from configparser import ConfigParser

'''
同步的基本逻辑
1. 根据Oracle的层级查询查出指定根节点的组织架构
2. 根据第一步生成中间表t_sync_syou_cache，将原始数据全量同步到该表
3. 根据中间表更新映射表，为新增的分配ID
4. 根据映射表,中间表更新/插入数据到 elsi-trunk.syou 表
'''
# 同步的单位根节点
syou_root_id = ''
# mysql 保存的临时表
syou_cache_table = 't_sync_syou_cache'
# mysql 保存的主键映射表
syou_map_table = 't_sync_map_id'

SYNC_SYOU_SQL = "select t.id,t.scode as code,t.name,t.ALIAS,t.STATUS,t.PARENTID,t1.name as type,level as lvlcode from mgrou t \
    left join mgrcode t1 on t.OUTYPE = t1.id  connect by prior t.id = t.PARENTID start with t.id = :id"


class BaseTool():

    @staticmethod
    def read_config(filename='config.ini', section='mysql'):
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
    pass


class OracleDB():
    def __init__(self, config):
        pass

    def query(self, sql, mode='all'):
        pass
    pass


def query_syou_data_from_ms():
    config = BaseTool.read_config(section='oracle')
    return OracleDB(config).query(config['sql'])


def save_in_cache(data):
    pass


def updateOrInsertMap():
    pass


def updateOrInsertData():
    pass


if __name__ == "__main__":
    syou_data = query_syou_data_from_ms()
    save_in_cache(syou_data)
    updateOrInsertMap()
    updateOrInsertData()
    pass
