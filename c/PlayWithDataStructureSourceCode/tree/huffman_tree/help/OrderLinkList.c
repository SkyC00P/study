#include "OrderLinkList.h"

OrderLinkList OrderLinkList_init(OrderLinkList_FucPtr_compare compare)
{
	OrderLinkList list = malloc(sizeof(struct _order_link_list_st));
	if (!list) {
		exit(OVERFLOW);
	}

	list->compare = compare;
	list->head = NULL;
	list->len = 0;

	return list;
}

Status OrderLinkList_add(OrderLinkList list, void * val)
{
	CheckPtr(list);
	OrderLinkListNodePtr ptr = malloc(sizeof(OrderLinkListNode));
	if (!ptr) {
		exit(OVERFLOW);
	}

	ptr->data = val;
	ptr->next = NULL;

	if (!list->head) {
		list->head = ptr;
		list->len++;
		return OK;
	}

	if (list->compare) {
		OrderLinkListNodePtr tmp, node = list->head;

		for (int i = 0; i < list->len; i++) {
			if (list->compare(node->data, ptr->data) < 0) {
				tmp = node;
				node = node->next;
			}
			else {
				break;
			}
		}

		tmp->next = ptr;
		ptr->next = node;
	}
	else {
		ptr->next = list->head;
		list->head = ptr;
	}
	list->len++;
	return OK;
}

int OrderLinkList_size(OrderLinkList list)
{
	CheckPtr(list);
	return list->len;
}

void OrderLinkList_destroy(OrderLinkList list, OrderLinkList_FucPtr_free_val fuc)
{
	if (list) {
		OrderLinkListNodePtr tmp, freeNode = list->head;
		while (freeNode) {
			tmp = freeNode->next;
			if (fuc) {
				free(freeNode->data);
			}
			free(freeNode);
			freeNode = tmp;
		}
		free(list);
	}
}

void * OrderLinkList_remove_frist(OrderLinkList list)
{
	CheckPtr(list);
	OrderLinkListNodePtr ptr = list->head;
	if (ptr) {
		list->head = ptr->next;
		list->len--;
		return ptr;
	}
	return NULL;
}