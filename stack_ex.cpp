#include <stdio.h>
#include "stack.h"

int main(){
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    while(!s.isEmpty()){
        printf("%d ", s.top());
        s.pop();
    }
}