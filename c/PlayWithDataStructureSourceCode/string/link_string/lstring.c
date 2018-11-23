#include "lstring.h"
#include <stdlib.h>
#include <stdio.h>

static inline void CheckPtr(const void * ptr) {
	if (!ptr) {
		fprintf(stderr, "%s:%d: 空指针异常\n", __FILE__, __LINE__);
		exit(-1);
	}
}
void printAllChar(String str);
static int needPrint = 0;
static inline void printMalloc(char *, int);
static inline void printFree(char *, int);
void printPtrNum();
static int gptrNum = 0;
/* 分配的空间等于字符数加结束符和一个String结构 */
String String_new(const char * chars)
{
	int ptrNum = 0;
	CheckPtr(chars);
	String str = malloc(sizeof(struct String));
	ptrNum += sizeof(struct String);
	str->head = malloc(sizeof(StrNode));
	ptrNum += sizeof(StrNode);

	StrNodePtr cur = str->head;

	int len = 0;
	char ch = chars[len];

	while (ch != '\0') {
		cur->ch = ch;
		StrNodePtr next = malloc(sizeof(StrNode));
		ptrNum += sizeof(StrNode);
		cur->next = next;
		len++;
		ch = chars[len];
		cur = next;
	}

	str->len = len;
	cur->ch = '\0';
	cur->next = NULL;

	printMalloc("[String_new]", ptrNum);
	return str;
}

/* 分配同s相同字符数的空间，一个结束字符和一个String的结构 */
String String_copy(String s)
{
	int ptrNum = 0;
	CheckPtr(s);
	String str = malloc(sizeof(struct String));
	ptrNum += sizeof(struct String);

	str->len = s->len;

	StrNodePtr strCopy = s->head;
	StrNodePtr strCur = str->head = malloc(sizeof(StrNode));
	ptrNum += sizeof(StrNode);

	while (strCopy->ch != '\0') {
		strCur->ch = strCopy->ch;
		strCur->next = malloc(sizeof(StrNode));
		ptrNum += sizeof(StrNode);

		strCur = strCur->next;
		strCopy = strCopy->next;
	}
	strCur->ch = '\0';
	strCur->next = NULL;
	printMalloc("[String_copy]", ptrNum);
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
		printFree("[String_clear]", sizeof(*freeNode));
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
		s1Ptr = s1Ptr->next;
		s2Ptr = s2Ptr->next;
	}
	return s->len - anotherString->len;
}

/* 分配的空间 (s.len + t.len + 1) * StrNode + String */
String String_concat(String s, String t)
{
	String c1 = String_copy(s);
	String c2 = String_copy(t);

	c1->len = c1->len + c2->len;
	StrNodePtr rear = c1->head;

	// 寻找c1最末尾的节点
	while (rear->next) {
		rear = rear->next;
	}

	StrNodePtr c2Head = c2->head;
	// 将c2的节点拼接到c1的末尾节点上
	rear->ch = c2Head->ch;
	rear->next = c2Head->next;
	printFree("[String_concat]", sizeof(*c2Head));
	free(c2Head);
	printFree("[String_concat]", sizeof(*c2));
	free(c2);
	return c1;
}

/*
  完整截断:分配len+1个StrNode和1个String
  非完整截断:分配s.len-pos+1个StrNode和1个节点
*/
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
	printMalloc("[String_subString]", sizeof(struct String));

	// 寻找pos位置的节点
	StrNodePtr posPtr = s->head;
	while (--pos) {
		posPtr = posPtr->next;
	}

	// 从当前节点截取复制剩下的节点
	str->len = 0;
	StrNodePtr cpPtr = str->head = malloc(sizeof(StrNode));
	printMalloc("[String_subString]", sizeof(StrNode));
	while (posPtr->next && len) {
		cpPtr->ch = posPtr->ch;
		cpPtr->next = malloc(sizeof(StrNode));
		printMalloc("[String_subString]", sizeof(StrNode));
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

	if (slen == 0 || tlen == 0) {
		return 0;
	}

	if (pos < 1 || pos > slen) {
		fprintf(stderr, "%s:%d: 非法参数:slen = %d, pos = %d\n", __FILE__, __LINE__,slen, pos);
		return 0;
	}

	// 判断s在pos位置后是否有足够长位置可匹配t
	if (t->len > slen - pos + 1) {
		return 0;
	}

	int index = pos;
	String sub = String_subString(s, pos, tlen);

	while (1)
	{
		if (String_compare(sub, t) == 0) {
			String_clear(sub);
			printFree("[String_indexof]", sizeof(*(sub->head)));
			free(sub->head);
			printFree("[String_indexof]", sizeof(*sub));
			free(sub);
			return index;
		}
		else
		{
			index++;
			String_clear(sub);
			printFree("[String_indexof]", sizeof(*(sub->head)));
			free(sub->head);
			printFree("[String_indexof]", sizeof(*sub));
			free(sub);
			if (tlen > slen - index + 1) {
				sub = NULL;
				break;
			}
			sub = String_subString(s, index, tlen);
		}
	}

	if (sub) {
		String_clear(sub);
		printFree("[String_indexof]", sizeof(*(sub->head)));
		free(sub->head);
		printFree("[String_indexof]", sizeof(*sub));
		free(sub);
	}
	return 0;
}

void String_replace(String s, String search, String replaceStr)
{
	
	CheckPtr(s);
	CheckPtr(search);
	CheckPtr(replaceStr);

	if (String_isEmpty(s) || String_isEmpty(search) || String_isEmpty(replaceStr)) {
		fprintf(stderr, "%s:%d: 非法参数:不能为空字符串\n",
			__FILE__, __LINE__);
		return;
	}

	int len = String_length(s);
	int index = 1;

	do {
		index = String_indexof(s, search, index);
		if (index != 0) {
			String_delete(s, index, String_length(search));
			String_insert(s, index, replaceStr);
			index += String_length(replaceStr);
			len = String_length(s);
		}
	} while (index != 0 && index <=len );
}

// 复制t得到副本cp,cp插入s
String String_insert(String s, int pos, String t)
{
	CheckPtr(s);
	CheckPtr(t);
	if (pos < 1 || pos > String_length(s) + 1) {
		fprintf(stderr, "%s:%d: 非法参数:pos = %d\n", __FILE__, __LINE__, pos);
		return NULL;
	}
	if (String_isEmpty(t)) {
		return s;
	}

	String cp = String_copy(t);
	StrNodePtr rearBef, rear;
	rear = cp->head;
	while (rear->ch != '\0')
	{
		rearBef = rear;
		rear = rear->next;
	}

	if (pos == 1) {
		rearBef->next = s->head;
		s->head = cp->head;
	}
	else
	{
		StrNodePtr insert, insertBef;
		int index = 1;
		insert = s->head;
		while (index != pos)
		{
			insertBef = insert;
			insert = insert->next;
			index++;
		}
		insertBef->next = cp->head;
		rearBef->next = insert;
	}

	s->len = s->len + t->len;
	printFree("[String_insert]", sizeof(*rear));
	free(rear);
	printFree("[String_insert]", sizeof(*cp));
	free(cp);
	return s;
}

/* 删除len个字符 */
String String_delete(String s, int pos, int len)
{
	CheckPtr(s);
	if (pos < 1 || pos > s->len) {
		fprintf(stderr, "%s:%d: 非法参数:pos = %d\n", __FILE__, __LINE__, pos);
		return NULL;
	}

	if (len < 0) {
		fprintf(stderr, "%s:%d: 非法参数:len = %d\n", __FILE__, __LINE__, len);
		return NULL;
	}

	// 这里的链表设计成单链表真是败笔，而且还是没有头结点的单链表
	// 导致删除时需要前置节点,要分类讨论首位删除和非首位删除
	StrNodePtr delBeforePtr, delNode, tmp;
	int delNum = 0;
	if (pos == 1) {
		delNode = s->head;
		while (delNum != len && delNode->ch != '\0') {
			tmp = delNode->next;
			printFree("[String_delete]", sizeof(*delNode));
			free(delNode);
			delNum++;
			delNode = tmp;
		}
		s->head = delNode;
	}
	else
	{
		delBeforePtr = s->head;
		for (int i = 2; i < pos; i++) {
			delBeforePtr = delBeforePtr->next;
		}
		delNode = delBeforePtr->next;

		while (delNum != len && delNode->ch != '\0')
		{
			tmp = delNode->next;
			delBeforePtr->next = delNode->next;
			printFree("[String_delete]", sizeof(*delNode));
			free(delNode);
			delNum++;
			delNode = tmp;
		}
	}

	s->len -= delNum;
	return s;
}

/* 分配等同于s字符长度和结束符的char */
char * String_toString(String s)
{
	int ptrNum = 0;

	CheckPtr(s);
	int size = s->len + 1;
	char * str = malloc(sizeof(char) * size);

	ptrNum += sizeof(char) * size;
	StrNodePtr cur = s->head;
	for (int i = 0; i < size; i++) {
		str[i] = cur->ch;
		cur = cur->next;
	}

	printMalloc("[String_toString]", ptrNum);
	return str;
}

inline void printMalloc(char * msg, int ptrNum)
{
	gptrNum += ptrNum;
	if (needPrint)
		printf("%s malloc point num : %d\n", msg, ptrNum);
}

inline void printFree(char * msg, int ptrNum)
{
	gptrNum -= ptrNum;
	if (needPrint)
		printf("%s free point num : %d\n", msg, ptrNum);
}

void printPtrNum()
{
	if (needPrint)
		printf("Point num : %d\n", gptrNum);
}

void printAllChar(String s) {
	CheckPtr(s);
	printf("len:%d, str:", s->len);
	StrNodePtr head = s->head;
	while (head) {
		if (head->ch == '\0') {
			printf("\\0");
		}
		else
		{
			printf("%c", head->ch);
		}
		head = head->next;
	}
	printf("\n");
}

void resetPtrNum() {
	gptrNum = 0;
}

int getPtrNum() {
	return gptrNum;
}