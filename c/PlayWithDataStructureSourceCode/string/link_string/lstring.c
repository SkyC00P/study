#include "lstring.h"
#include <stdlib.h>
#include <stdio.h>

static inline CheckPtr(void * ptr) {
	if (!ptr) {
		fprintf(stderr, "%s:%d: 空指针异常\n", __FILE__, __LINE__);
		exit(-1);
	}
}

String String_new(char * chars)
{
	CheckPtr(chars);
	String str = malloc(sizeof(struct String));
	str->head = malloc(sizeof(StrNode));
	StrNodePtr cur = str->head;

	int len = 0;
	char ch = chars[len];

	while (ch != '\0') {
		cur->ch = ch;
		StrNodePtr next = malloc(sizeof(StrNode));
		cur->next = next;
		len++;
		ch = chars[len];
		cur = next;
	}

	str->len = len;
	cur->ch = '\0';
	cur->next = NULL;
	return str;
}

String String_copy(String s)
{
	CheckPtr(s);
	String str = malloc(sizeof(struct String));
	int len = str->len = s->len;

	StrNodePtr strCopy = s->head;
	StrNodePtr strCur = str->head = malloc(sizeof(StrNode));

	while (strCopy.ch != '\0') {
		strCur->ch = strCopy->ch;
		strCur->next = malloc(sizeof(StrNode));

		strCur = strCur->next;
		strCopy = strCopy->next;
	}

	strCur->ch = '\0';
	strCur->next = NULL;
	return str;
}

void String_clear(String s)
{
	CheckPtr(s);
	s->len = 0;
	s->head->ch = '\0';
	StrNodePtr freeNode = s->head->next;
	StrNodePtr tmpNode = NULL;
	while (freeNode) {
		tmpNode = freeNode->next;
		free(freeNode);
		freeNode = tmpNode;
	}
	s->head->next = NULL;
}

Bool String_isEmpty(String s)
{
	CheckPtr(s);
	return s->len == 0 ? TRUE : FALSE;
}

int String_length(String s)
{
	CheckPtr(s);
	return s->len;
}

/*
  比较算法
  1. 优先比较字符序列
  2. 字符序列相同的情况下，比较长度
*/
int String_compare(String s, String anotherString)
{
	CheckPtr(s);
	CheckPtr(anotherString);

	StrNodePtr s1Ptr = s->head;
	StrNodePtr s2Ptr = anotherString->head;

	while (s1Ptr->next && s2Ptr->next) {
		if (s1Ptr->ch != s2Ptr->ch) {
			return s1Ptr->ch - s2Ptr->ch;
		}
	}
	return s->len - anotherString->len;
}

String String_concat(String s, String t)
{
	String c1 = String_copy(s);
	String c2 = String_copy(t);

	c1->len = c1->len + c2->len;
	StrNodePtr rear = s->head;

	// 寻找c1最末尾的节点
	while (rear->next) {
		rear = rear->next;
	}

	StrNodePtr c2Head = c2->head;
	// 将c2的节点拼接到c1的末尾节点上
	rear->ch = c2Head->ch;
	rear->next = c2Head->next;
	free(c2Head);
	return c1;
}

String String_subString(String s, int pos, int len)
{
	CheckPtr(s);
	if (pos < 1 || pos >  String_length(s)) {
		fprintf(stderr, "%s:%d: 非法参数:pos = %d\n", __FILE__, __LINE__, pos);
		return NULL;
	}

	if (len < 1) {
		fprintf(stderr, "%s:%d: 非法参数:len = %d\n", __FILE__, __LINE__, len);
		return NULL;
	}
	String str = malloc(sizeof(struct String));

	// 寻找pos位置的节点
	StrNodePtr posPtr = s->head;
	while (--pos){
		posPtr = posPtr->next;
	}

	// 从当前节点截取复制剩下的节点
	str->len = 0;
	StrNodePtr cpPtr = str->head = malloc(sizeof(StrNode));

	while (posPtr && len) {
		cpPtr->ch = posPtr->ch;
		cpPtr->next = malloc(sizeof(StrNode));
		str->len++;
		len--;
		cpPtr = cpPtr->next;
		posPtr = posPtr->next;
	}

	cpPtr->ch = '\0';
	cpPtr->next = NULL;
	return str;
}

int String_indexof(String s, String t, int pos)
{
	CheckPtr(s);
	CheckPtr(t);
	int slen = String_length(s);
	int tlen = String_length(t);
	if (pos < 1 || pos > slen) {
		fprintf(stderr, "%s:%d: 非法参数:pos = %d\n", __FILE__, __LINE__, pos);
		exit(-1);
	}

	// 判断s在pos位置后是否有足够长位置可匹配t
	if (t > slen - pos + 1) {
		return 0;
	}

	// 定位串s的pos位置节点
	int index = pos;
	StrNodePtr posPtr = s->head;
	while (--index) {
		posPtr = posPtr->next;
	}

	// 跟t进行对比
	int cur = pos;
	StrNodePtr sPtr = posPtr;
	StrNodePtr tPtr = t->head;

	while (slen - cur >= tlen){
		Bool findit = TRUE;

		while (tPtr->next){
			if (sPtr->ch != tPtr->ch) {
				findit = FALSE;
				break;
			}

			sPtr = sPtr->next;
			tPtr = tPtr->next;
		}

		if (!findit) {
			sPtr = posPtr = posPtr->next;
			cur++;
		}
		else {
			return cur;
		}
	}

	return 0;
}

String String_replace(String s, String replaceStr)
{
	return String();
}

String String_insert(String s, int pos, String t)
{
	return String();
}

String String_delete(String s, int pos, int len)
{
	return String();
}

char * String_toString(String s)
{
	return NULL;
}
