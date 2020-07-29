# cx_Oracle 安装指南

安装需要，适用平台Centos7

1. Python 2.7 or 3.5 以及更高
2. Oracle client libraries.

[API文档](https://cx-oracle.readthedocs.io/en/7.3/api_manual/module.html#module)

[帮助例子](https://github.com/oracle/python-cx_Oracle/blob/master/samples)

## 快速安装

从`PyPI`安装`cx_Oracle`
```
python -m pip install cx_Oracle --upgrade
```

添加 Oracle client libraries 到库搜索路径如：`LD_LIBRARY_PATH`

PS:如果Oracle数据库没有跟cx_Oracle安装在一起，则需要从 [Oracle Instant Client](https://www.oracle.com/database/technologies/instant-client.html) 下载"Basic" 或者 "Basic Light"包进行安装。

> Version 19, 18 and 12.2 client libraries can connect to Oracle Database 11.2 or greater. Version 12.1 client libraries can connect to Oracle Database 10.2 or greater. Version 11.2 client libraries can connect to Oracle Database 9.2 or greater.

