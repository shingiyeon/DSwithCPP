#include "list.h"

template <class T>
class Stack{
    private:
        List<T> l;
    public:
        Stack();
        ~Stack();

        void push(T x);
        void pop();
        T top();
        int size();
        bool isEmpty();
};

template <class T>
Stack<T>::Stack(){
}

template <class T>
Stack<T>::~Stack(){
}

template <class T>
void Stack<T>::push(T x){
    l.insertTail(x);
}

template <class T>
void Stack<T>::pop(){
    l.removeTail();
}

template <class T>
T Stack<T>::top(){
    return l.getTail()->getData();
}

template <class T>
int Stack<T>::size(){
    return l.size();
}

template <class T>
bool Stack<T>::isEmpty(){
    return l.isEmpty();
}