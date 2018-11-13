# 循环链表 - C代码实现
```
make           // 测试使用尾指针表示的循环列表
make head     //  测试使用头指针表示的循环列表(todo)
```

**loop_link_list.c**
> 循环链表 - C代码实现

**loop_link_list.h**
> 循环链表抽象数据结构声明

**test.c**
> 单元测试的定义与声明

**makefile**
> 项目构建文件

**执行结果**
```
gcc -Wall loop_link_list.c test.c -o test -I../../

------------------ Test Use Tail LinkList ------------------

expect clear node num is 0,and actual clear node num is 0
expect clear node num is 2,and actual clear node num is 2

88/88 (100.00%) passed

------------------------------------------------------------
```