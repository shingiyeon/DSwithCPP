#include <stdio.h>
#include "list.cpp"

int main(){
    List<int> l;
    for(int i=0; i<5; i++) l.insertTail(i);
    printf("%d\n", l.frontValue());
    printf("%d\n", l.backValue());
    printf("%d\n", l.itemAt(3)->getData());
    printf("%d\n", l.search(2)->getData());
    l.removeHead();
    l.removeTail();
    printf("%d\n", l.frontValue());
    printf("%d\n", l.backValue());
    printf("%d\n", l.isEmpty());
}