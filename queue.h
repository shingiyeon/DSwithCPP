#include "list.h"

template <class T>
class Queue{
    private:
        List<T> l;
    public:
        Queue();
        ~Queue();

        void push(T x);
        void pop();
        T front();
        bool isEmpty();
        int size();
};

template <class T>
Queue<T>::Queue(){
}

template <class T>
Queue<T>::~Queue(){
}

template <class T>
void Queue<T>::push(T x){
    l.insertTail(x);
}

template <class T>
void Queue<T>::pop(){
    l.removeHead();
}

template <class T>
T Queue<T>::front(){
    return l.getHead()->getData();
}

template <class T>
bool Queue<T>::isEmpty(){
    return l.isEmpty();
}

template <class T>
int Queue<T>::size(){
    return l.size();
}