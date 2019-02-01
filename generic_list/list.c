#include "list.h"

void* list_setUp(size_t s)
{
    listS* p = malloc(sizeof(listS));
    p->dataSize = s;
    p->head = malloc(sizeof(ItemS));
    p->tail = p->head;
    p->listSize = 0;
    p->head->data = NULL;
    p->head->next = NULL;
    p->head->prev = NULL;
    return p;
}

void* list_extend(listS* p)
{
    if(p == NULL) return NULL;

    ItemS *thisItem = p->tail;
    thisItem->next = malloc(p->dataSize);
    if(thisItem->next == NULL) return NULL;

    thisItem->next->prev = thisItem;
    p->tail = thisItem->next;
    p->tail->data = NULL;
    p->tail->next = NULL;
    p->listSize += 1;
    thisItem->data = malloc(p->dataSize);
    return thisItem->data;
}

void list_removeElementAt(int index, listS* p)
{
    ItemS* itemToRemove = list_getItemAt(index, p);
    
    if (p->head == itemToRemove) //remove 1st element
    {
        if (p->listSize == 1) //if 1st is last
        { 
            p->head = malloc(sizeof(ItemS));
            p->tail = p->head;
            p->head->data = NULL;
            p->head->next = NULL;
            p->head->prev = NULL;
        }
        else
        {
            p->head = itemToRemove->next;
            p->head->prev = NULL;
        }
    }
    else if (p->tail == itemToRemove) //remove last elem
    {
        p->tail = itemToRemove->prev;
        p->tail->next = NULL;
    }
    else //remove something between head and tail
    {
        itemToRemove->prev->next = itemToRemove->next;
        itemToRemove->next->prev = itemToRemove->prev;
    }
    p->listSize -=1 ;
    free(itemToRemove->data);
    free(itemToRemove);
}

void* list_getElementAt(int index, listS* p)
{
    ItemS* thisItem = list_getItemAt(index, p);
    return thisItem != NULL ? thisItem->data : NULL;
}

void* list_getItemAt(int index, listS* p)
{
    if (index > p->listSize) return NULL;

    int i;
    ItemS* thisItem = p->head;
    for (i = 0; i < index; ++i) thisItem = thisItem->next;
    return thisItem;
}

void list_tearDown(listS *p)
{
    ItemS *thisItem = p->head;
    while (thisItem != NULL)
    {
        ItemS *ptrToFree = thisItem;
        thisItem = thisItem->next;
        if (ptrToFree->data != NULL) free(ptrToFree->data);
        free(ptrToFree);
    }
    free(p);
}