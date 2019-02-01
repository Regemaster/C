#include <stdlib.h>
#include <stdio.h>

/**
 * List types
 * listS is main type of List. Its holds main list info.
 * ItemS is node of List which holds data and next chain element. 
 */
typedef struct listS listS;
typedef struct ItemS ItemS;

//macro for easy adding new simple type element to list.
#define LIST_SET_DATA(type, ptr, value) \
{\
    type *data = list_extend(ptr);\
    if(data != NULL)\
    {\
        *data = value;\
    }\
}

//macro for easy getting data from list node
#define LIST_GET_DATA(type, ptr) *((type*)ptr->data)

//macro for easy getting data at specified index
#define LIST_GET_AT(type, index, ptr) \
((list_getElementAt(index, ptr) != NULL) ? *((type*)list_getElementAt(index, ptr)) : 0)

// List types
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

/**
 * Function create list for specified type
 * 
 * @param s         size of type for which list is creating
 * @return          pointer to created List if successful allocated, NULL otherwise
 */
void* list_setUp(size_t s);

/**
 * Function extend given list for one type which was passed at create time.
 * 
 * @param p         pointer to list which should be extended
 * @return          pointer to place where data can be stored in new node if success, NULL otherwise
 */
void* list_extend(listS* p);

/**
 * Function removes element of List at specified possition
 * 
 * @param index     0-based element of List, which should be removed
 * @param p         pointer to List from which element at specified position should be removed
 * @return          void
 */
void list_removeElementAt(int index, listS* p);

/**
 *  Function remove whole List and clean up memmory where List was stored
 * 
 * @param p         pointer to list which should be removed
 * @return          void
 */
void list_tearDown(listS *p);

/**
 * Function gets List ItemS object at specified position
 * 
 * @param index     0-based ItemS object of List, which should be returned
 * @param p         pointer to list from which ItemS object should be returned
 * @return          pointer to ItemS object at List specified position if exist, NULL otherwise
 */
void* list_getItemAt(int index, listS* p);

/**
 * Function gets List element at specified position
 * 
 * @param index     0-based element of List, which should be returned
 * @param p         pointer to list from which element should be returned
 * @return          pointer to element at List specified position if exist, NULL otherwise
 */
void* list_getElementAt(int index, listS* p);