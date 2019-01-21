#include "list.h"

struct myDataS
{
    int i;
    char c;
    double d;
}typedef myDataS;
void printl(char* printWay, listS* l);
void printl_r(char* printWay, listS* l);
int main(int argc, char* argv[])
{
    /**
     * Simple Example of genereic List usage
     */
    int val = 2;
    listS *l = list_setUp(sizeof(int));
    
    for (int i=0; i<10; ++i)
    {
        LIST_SET_DATA(int, l, val + i*i);
    }
    printf("No. of elements@list: %d\n", l->listSize);
    for (int i=0; i<l->listSize; ++i)
    {
        printf("list[%d] = %d\n", i, LIST_GET_AT(int, i, l));
    }

    puts("removing list elements!");
    list_removeElementAt(1, l);
    list_removeElementAt(3, l);
    list_removeElementAt(0, l);
    puts("removing done.");

    printf("No. of elements@list: %d\nList:\n", l->listSize);
    printl("%d\n", l);

    list_tearDown(l);

    puts("\n\nCreate List on Struct:");
    /**
     * Advanced Example of generic List usage
     */
    listS *mD_List = list_setUp(sizeof(myDataS));    

    for (int i=0; i<10; ++i)
    {
        myDataS *tmp = (myDataS*)list_extend(mD_List);
        tmp->i = i * i;
        tmp->c = 98 + i;
        tmp->d = 1.123 * (1.1 + i);
    }
    printf("No. of elements@list: %d\n", mD_List->listSize);
    for (int i=0; i<mD_List->listSize; ++i)
    {
        myDataS *tmp = (myDataS*)list_getElementAt(i, mD_List);
        printf("list[%d] = %d, %c, %f\n", i, tmp->i, tmp->c, tmp->d);
    }

    puts("removing list elements!");
    list_removeElementAt(1, mD_List);
    list_removeElementAt(3, mD_List);
    list_removeElementAt(0, mD_List);
    puts("removing done.");

    printf("No. of elements@list: %d\n", mD_List->listSize);
    for (int i=0; i<mD_List->listSize; ++i)
    {
        myDataS *tmp = (myDataS*)list_getElementAt(i, mD_List);
        printf("list[%d] = %d, %c, %f\n", i, tmp->i, tmp->c, tmp->d);
    }

    list_tearDown(mD_List);
    return 0;
}

void printl(char* printWay, listS* l)
{
    ItemS *thisItem = l->head;
    while(thisItem->next != NULL)
    {
        printf(printWay, LIST_GET_DATA(int, thisItem));
        thisItem = thisItem->next;
    }
}