#include <stdio.h>
#include "list.h"

int main(){
    List<int> l;
    for(int i=0; i<5; i++) l.insertTail(i);
    printf("%d ",  l.size());
    printf("%d ", l.isEmpty());

    printf("%d ", l.getHead()->getData());
    printf("%d ", l.getTail()->getData());

    printf("%d ", l.search(3)->getData());
    printf("%d ", l.itemAt(4)->getData());

    l.removeHead();
    l.removeTail();
    printf("\n");
    l.printList();
    printf("\n");
    printf("%d %d\n", l.frontValue(), l.backValue());

    l.insertAt(4, 1);
    l.insertAt(1, 1);
    l.insertAt(2, 2);
    printf("\n");
    l.printList();
    printf("\n")
}