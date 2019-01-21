#include <stdlib.h>
#include <stdio.h>
typedef struct myS myS;
typedef struct ItS ItS;

#define SET_DATA(type, ptr, value) \
{\
    type *data = extend(ptr);\
    if(data != NULL)\
    {\
        *data = value;\
    }\
}
#define GET_DATA(type, ptr) *((type*)ptr->data)

struct myS{
    ItS* head;
    size_t dataSize;
    unsigned int listSize;
};
struct ItS{
    ItS* next;
    void* data;
};

void* setUp(size_t s);
void* extend(myS* p);
void tearDown(myS *p);
void printl(char* printWay, myS* l);