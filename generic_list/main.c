#include "list.h"

//user defined complex type
struct myDataS
{
    int i;
    char c;
    double d;
}typedef myDataS;

//user defined method for printing lists elements
void printl(char* printWay, listS* l);

int main(int argc, char* argv[])
{
    /**
     * 
     * Simple Example of genereic List usage
     * 
     */
    int val = 2;

    //create list on simple type
    listS *l = list_setUp(sizeof(int));
    
    //add values to list, use definded macro for simple adding
    for (int i=0; i<10; ++i)
    {
        LIST_SET_DATA(int, l, val + i*i);
    }

    //print list size
    printf("No. of elements@list: %d\n", l->listSize);

    //print all elements of list, use defined macro for simple getting
    for (int i=0; i<l->listSize; ++i)
    {
        printf("list[%d] = %d\n", i, LIST_GET_AT(int, i, l));
    }

    //remove random list elements
    puts("removing list elements!");
    list_removeElementAt(1, l);
    list_removeElementAt(3, l);
    list_removeElementAt(0, l);
    puts("removing done.");

    //print list size
    printf("No. of elements@list: %d\nList:\n", l->listSize);

    //print list with 'user defined' method
    printl("%d\n", l);

    //remove list
    list_tearDown(l);

    
    /**
     * 
     * Advanced Example of generic List usage
     * 
     */
    puts("\n\nCreate List on Struct:");

    //create list on 'user defined' type
    listS *mD_List = list_setUp(sizeof(myDataS));    

    //add values to list, cannot use macro on 'user defined' type
    for (int i=0; i<10; ++i)
    {
        myDataS *tmp = (myDataS*)list_extend(mD_List);
        tmp->i = i * i;
        tmp->c = 98 + i;
        tmp->d = 1.123 * (1.1 + i);
    }

    //print list size
    printf("No. of elements@list: %d\n", mD_List->listSize);

    //print all elements of list, cannot use macro on 'user defined' type
    for (int i=0; i<mD_List->listSize; ++i)
    {
        myDataS *tmp = (myDataS*)list_getElementAt(i, mD_List);
        printf("list[%d] = %d, %c, %f\n", i, tmp->i, tmp->c, tmp->d);
    }

    //remove random list elements
    puts("removing list elements!");
    list_removeElementAt(1, mD_List);
    list_removeElementAt(3, mD_List);
    list_removeElementAt(0, mD_List);
    puts("removing done.");

    //print list size
    printf("No. of elements@list: %d\n", mD_List->listSize);

    //print all elements of list, cannot use macro on 'user defined' type
    for (int i=0; i<mD_List->listSize; ++i)
    {
        myDataS *tmp = (myDataS*)list_getElementAt(i, mD_List);
        printf("list[%d] = %d, %c, %f\n", i, tmp->i, tmp->c, tmp->d);
    }

    //remove list
    list_tearDown(mD_List);
    return 0;
}

/**
 * user defined method for printing lists elements
 */
void printl(char* printWay, listS* l)
{
    ItemS *thisItem = l->head;
    while(thisItem->next != NULL)
    {
        printf(printWay, LIST_GET_DATA(int, thisItem));
        thisItem = thisItem->next;
    }
}