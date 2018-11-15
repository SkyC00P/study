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
	int len = 0;
	str->head = malloc(sizeof(StrNode));
	StrNodePtr cur = str->head;

	char ch = chars[len];
	cur->ch = ch;

	while (ch = chars[len + 1] != '\0') {
		StrNodePtr next = malloc(sizeof(StrNode));
		cur->next = next;
		next->next = NULL;
		next->ch = ch;
		str->len = ++len;
		cur = next;
	}

	return str;
}

String String_copy(String s)
{
	CheckPtr(s);
	String str = malloc(sizeof(struct String));
	int len = str->len = s->len;

	StrNodePtr * arr = malloc(sizeof(StrNodePtr) * s->len);
	
	StrNodePtr tmp = s->head;
	int index = 0;
	while (len--){
		arr[index]->ch = tmp->ch;
		arr[index]->next = tmp->next;
		tmp = tmp->next;
	}
	str->head = arr;

	return str;
}

void String_clear(String s)
{
}

Bool String_isEmpty(String s)
{
	return Bool();
}

int String_length(String s)
{
	return 0;
}

int String_compare(String s, String anotherString)
{
	return 0;
}

String String_concat(String s, String t)
{
	return String();
}

String String_subString(String s, int pos, int len)
{
	return String();
}

int String_indexof(String s, String t, int pos)
{
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
