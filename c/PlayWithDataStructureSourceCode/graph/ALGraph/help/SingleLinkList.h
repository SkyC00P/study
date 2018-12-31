#include "../ALGraph.h"

typedef EdgeNodePtr SingleLinkList;

SingleLinkList SingleLinkList_init();

Status SingleLinkList_add(SingleLinkList list, int adjvex, AL_Weight weight);

void SingleLinkList_destroy(SingleLinkList list);

void SingleLinkList_clear(SingleLinkList list);

EdgeNodePtr SingleLinkList_get(SingleLinkList list, int adjvex);

int SingleLinkList_size(SingleLinkList list);

EdgeNodePtr SingleLinkList_remove(SingleLinkList list, int index);