#include <stdlib.h>
#include <stdio.h>
typedef struct listS listS;
typedef struct ItemS ItemS;

#define LIST_SET_DATA(type, ptr, value) \
{\
    type *data = list_extend(ptr);\
    if(data != NULL)\
    {\
        *data = value;\
    }\
}
#define LIST_GET_DATA(type, ptr) *((type*)ptr->data)

#define LIST_GET_AT(type, index, ptr) ((list_getElementAt(index, ptr) != NULL) ? *((type*)list_getElementAt(index, ptr)) : 0)

struct listS{
    ItemS* head;
    ItemS* tail;
    size_t dataSize;
    unsigned int listSize;
};
struct ItemS{
    ItemS* next;
    ItemS* prev;
    void* data;
};

void* list_setUp(size_t s);
void* list_extend(listS* p);
void list_removeElementAt(int index, listS* p);
void list_tearDown(listS *p);
void* list_getItemAt(int index, listS* p);
void* list_getElementAt(int index, listS* p);