#include "../ALGraph.h"

typedef EdgeNodePtr SingleLinkList;

SingleLinkList SingleLinkList_init();

Status SingleLinkList_add(SingleLinkList list, int adjvex, AL_Weight weight);

void SingleLinkList_destroy(SingleLinkList list);

void SingleLinkList_clear(SingleLinkList list);