/*
  用单链表的结构来实现字符串
  一个StrNode节点保存一个字符和保存下一个字符节点StrNode的指针。
  这么设计由于内存对齐的缘故，导致一个StrNode占16个字节，实际上用到的只有 8+1 个字节。
  空间就是这么浪费的，如果想改进可以改成保存一个8字节的char数组，降低空间的浪费。
*/
#ifndef HAVE_LSTRING_H
#define HAVE_LSTRING_H
#include "common.h"
typedef struct StrNode {
	char ch;
	struct StrNode * next;
}StrNode, * StrNodePtr;

typedef struct String {
	StrNode * head;
	int len;
}* String;

/* 生成一个其值等于字符串常量chars的串T */
String String_new(const char * chars);

/* 串S存在，由串S复制得串T */
String String_copy(String s);

/* 若串S存在，将串清空 */
void String_clear(String s);

/* 若串S为空，返回true,否则返回false */
Bool String_isEmpty(String s);

/* 返回串S的元素个数，即串的长度。 */
int String_length(String s);

/* 若S>T,返回值>0,若S=T，返回0，若S<T,返回值<0 */
int String_compare(String s, String anotherString);

/* 返回由S1,S2连接而成的新串 */
String String_concat(String s, String t);

/* 串S存在，1<=pos<=StrLength(S),且0<=len<=StrLength(S)-pos+1,返回串S的第pos个字符起长度为len的子串。 */
String String_subString(String s, int pos, int len);

/*  串S和T存在，T是非空串，1<=pos<=StrLength(S).若主串S存在和串T值相同的子串，则返回它在主串S中第pos个字符之后第一次出现的位置，否则返回0. */
int String_indexof(String s, String t, int pos);

/* 返回替换主串S中出现的所有与replaceStr相等的不重叠子串。 */
String String_replace(String s, String replaceStr);

/* 串S，串T存在，1<=pos<=StrLength(S) + 1，在串S的第pos个字符之前插入串T。 */
String String_insert(String s, int pos, String t);

/* StrDelete(S,pos,len): 串S存在，1<=pos<=StrLength(S)-len+1.从串S中删除第pos个字符起长度为len的子串。 */
String String_delete(String s, int pos, int len);

/* 转为C默认的字符串 */
char * String_toString(String s);
#endif // !HAVE_LSTRING_H
