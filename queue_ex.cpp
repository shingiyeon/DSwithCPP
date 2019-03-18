#include "queue.h"
#include <stdio.h>

int main(){
    Queue<int> q;
    for(int i=0; i<5; i++) q.push(i);

    while(!q.isEmpty()){
        printf("%d ", q.front());
        q.pop();
    }

    return 0;
}