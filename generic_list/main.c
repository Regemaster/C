#include "list.h"

int main(int argc, char* argv[])
{
    int val = 10;

    myS *l = setUp(sizeof(int));
    myS *cList = setUp(sizeof(char));

    SET_DATA(char, cList, 'a');
    SET_DATA(char, cList, 'b');
    SET_DATA(char, cList, 'c');

    SET_DATA(int, l, val);
    SET_DATA(int, l, val/2);
    SET_DATA(int, l, val/4);

    SET_DATA(char, cList, 'd');
    SET_DATA(char, cList, 'e');
    SET_DATA(char, cList, 'f');
    SET_DATA(char, cList, 'g');
    SET_DATA(char, cList, 'h');

    SET_DATA(int, l, val*2);
    SET_DATA(int, l, val*4);

    printl("%d ", l);
    puts("");
    
    printl("%c\t", cList);
    puts("");

    tearDown(l);
    tearDown(cList);
    return 0;
}