# 双向链表 - C代码实现
```
make           //  测试使用尾指针表示的循环又双向的列表
make single    //  测试使用头指针表示的单循环列表(todo)
```

**double_link_list.c**
> 双向链表 - C代码实现

**loop_link_list.h**
> 双向链表抽象数据结构声明

**test.c**
> 单元测试的定义与声明

**makefile**
> 项目构建文件

**执行结果**
```
gcc -Wall double_link_list.c test.c -o test -I../../

------------------ Test Use Loop DulLinkList --------------------

expect clear node num is 0,and actual clear node num is 0
expect clear node num is 2,and actual clear node num is 2

108/108 (100.00%) passed

-----------------------------------------------------------------
```