#include "ChildBrotherTree.h"
#include <ctype.h>
#include <string.h>
#include "help/HashMap.h"
static CBNodePtr get_node_from_cache(HashMap cache, HashMap_Key_T key);
static void CBNodePtr_free(CBNodePtr value);

Status CBTree_init(CBTree * T)
{
	if (*T) { return ERROR; }
	*T = NULL;
	return OK;
}

void CBTree_clear(CBTree * T)
{
}

void CBTree_destroy(CBTree * T)
{
}

Bool CBTree_isEmpty(CBTree T)
{
	return T == NULL ? TRUE : FALSE;
}
/*
 ?��θ����ļ��Ķ�����������Ҳ����Ҫ��API
 ?������ΰ�html������dom������ν���������ɱ��ʽ��

�ⷨ:ÿ������㶼�������ݣ�����ӣ����ֵ�����ֵ����������򽫽���������С�����
	R	A	^
	A	D	B
	B	^	C
	C	F	^
	D	^	E
	E	^	^
	F	G	^
	G	^	H
	H	^	K
	K	^	^
	������������� RA#ADBB#CCF#D#EE##FG#G#HH#KK##
1. ÿ�ζ�ȡ����ֵ��������2����㣬һ����һ���������������ʹ�ò������Ľ������һ�������µĲ�����������ֵΪ0��1��2
2. ���ܵĲ��������Ϊn����һ�ζ�ȡʱ��nΪ1(�����)����ÿ�ζ�ȡ��n�Ľ������Ϊ n-1, n, n+1
3. ÿһ��Ҷ�ӽ�㶼��ʹn-1, Ҳ����˵������ʼ��OKʱ��nΪ0�������һ��Ҷ�ӽ��Ҳ����ȡ������
����������Ҫһ�����ҽṹ��Key - Value��Map

���ⲽ��:
	1. ��ȡ�ļ����������������Ϊ�ַ�������,һ���ַ�������һ����
	2. ÿ�δ�����ַ�����ȡ3��ֵ���ж���3��ֵ�Ƿ��Ѿ��ڻ���������������һ���µĽ�㣬����ڣ���ӻ������ȡ��㣬ͨ���ڶ��͵���λ�Ľ��ʹ�õ�һ����������������δ�����Ľ�㱣�浽������
	3. �ظ��ڶ���ֱ���ַ�������
*/
Status CBTree_create(FILE * fp, CBTree * T)
{
	CheckPtr(fp);
	CheckPtr(T);

	char str[255];
	fgets(str, sizeof(str), fp); // ������Buffer��������������Ūһ���������ļ�
	if (!feof(fp)) {
		fprintf(stderr, "more than one line\n");
		return ERROR;
	}

	int len = strlen(str);
	if (len % 3 != 0) {
		fprintf(stderr, "The content is Non-conformity\n");
		return ERROR;
	}
	HashMap cache = HashTable_init();
	for (int i = 0; i < len; i += 3) {
		char c1 = str[i];
		char c2 = str[i + 1];
		char c3 = str[i + 2];

		CBNodePtr cp1, cp2, cp3;
		cp1 = get_node_from_cache(cache, c1);
		cp2 = cp3 = NULL;

		if (c2 != '#') {
			cp2 = get_node_from_cache(cache, c2);
		}
		if (c3 != '#') {
			cp3 = get_node_from_cache(cache, c3);
		}

		cp1->fristChild = cp2;
		cp1->nextBrother = cp3;

		if (HashMap_contain(cache, cp1->data)) {
			HashMap_remove(cache, cp1->data);
		}

		if (cp2) {
			HashMap_put(cache, c2, cp2);
		}

		if (cp3) {
			HashMap_put(cache, c3, cp3);
		}
	}

	Status status = HashMap_isEmpty(cache) ? ERROR : OK;
	HashMap_destory(cache, CBNodePtr_free);
	return status;
}

static CBNodePtr get_node_from_cache(HashMap cache, HashMap_Key_T key) {
	CBNodePtr node = NULL;
	if (HashMap_contain(cache, key)) {
		node = malloc(sizeof(CBNode));
		if (!node) {
			fprintf(stderr, "[get_node_from_cache] Error malloc.\n");
			return NULL;
		}
		node->data = key;
	}
	else {
		node = HashMap_get(cache, key);
	}
	return node;
}

int CBTree_degree(CBTree T)
{
	return 0;
}

int CBTree_depth(CBTree T)
{
	return 0;
}

CBData CBTree_root(CBTree T)
{
	return 0;
}

int CBTree_value(CBTree T, int i)
{
	return 0;
}

CBNodePtr CBTree_order(CBTree T, CBData e)
{
	return NULL;
}

Status CBTree_assign(CBTree T, CBData old, CBData new)
{
	return OK;
}

CBData CBTree_child(CBTree T, CBData e, int order)
{
	return 0;
}

CBData CBTree_brother(CBTree T, CBData e, int order)
{
	return 0;
}

int CBTree_child_count(CBTree T, CBData p)
{
	return 0;
}

Status CBTree_insert(CBTree T, CBData e, int i, CBTree t)
{
	return OK;
}

Status CBTree_delete(CBTree T, CBData e, int i)
{
	return OK;
}

void CBTree_level_order_traverse(CBTree T, void(Visit)(CBData))
{
}

void CBTree_preorder_traverse(CBTree T, void(Visit)(CBData))
{
}

void CBTree_inorder_traverse(CBTree T, void(Visit)(CBData))
{
}

void CBTree_print(CBTree T)
{
}

static void CBNodePtr_free(CBNodePtr value) {

}