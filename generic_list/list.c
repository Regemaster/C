#include "list.h"

void printl(char* printWay, myS* l)
{
    ItS *thisItem = l->head;
    while(thisItem->next != NULL)
    {
        printf(printWay, GET_DATA(int, thisItem));
        thisItem = thisItem->next;
    }
}

void* extend(myS* p)
{
    if(p == NULL) return NULL;

    ItS *thisItem = p->head;
    while(thisItem->next != NULL)
    {
        thisItem = thisItem->next;
    }
    thisItem->next = malloc(p->dataSize);
    thisItem->next->data = NULL;
    thisItem->next->next = NULL;

    thisItem->data = malloc(p->dataSize);
    return thisItem->data;
}

void* setUp(size_t s)
{
    myS* p = malloc(sizeof(myS));
    p->dataSize = s;
    p->head = malloc(sizeof(ItS));
    p->head->data = NULL;
    p->head->next = NULL;
    return p;
}

void tearDown(myS *p)
{
    ItS *thisItem = p->head;
    while(thisItem->next != NULL)
    {
        ItS *ptrToFree = thisItem;
        thisItem = thisItem->next;
        free(ptrToFree);
    }
    free(p);
}