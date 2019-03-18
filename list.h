#include "node.h"
#include <iostream>
using namespace std;

template <class T>
class List{
    private:
        Node<T>* head;
        Node<T>* tail;
        int numOfItems;
    public:
        List();
        ~List();

        int size();
        bool isEmpty();

        Node<T>* getHead();
        Node<T>* getTail();

        Node<T>* search(T x);
        Node<T>* itemAt(int position);

        void remove_one_or_no();
        void removeHead();
        void removeTail();
        void removeValue(T x, int n=1);
        void removeAt(int pos);

        void insertHead(T x);
        void insertTail(T x);
        void insertAt(T x, int pos);

        void printList();
        T frontValue();
        T backValue();
};

template <class T>
List<T>::List(){
    head = NULL;
    tail = NULL;
    numOfItems = 0;
}

template <class T>
List<T>::~List(){
}

template <class T>
int List<T>::size(){
    return numOfItems;
}

template <class T>
Node<T>* List<T>::getHead(){
    return head;
}

template <class T>
Node<T>* List<T>::getTail(){
    return tail;
}

template <class T>
bool List<T>::isEmpty(){
    return (numOfItems == 0);
}

template <class T>
Node<T>* List<T>::search(T x){
    Node<T>* currentPtr = head;
    while(currentPtr != NULL){
        if(currentPtr->getData() == x)
            return currentPtr;
        currentPtr = currentPtr -> getNext();
    }
    return NULL;
}

template <class T>
Node<T>* List<T>::itemAt(int position){
    Node<T>* currentPtr = head;
    int idx = 0;
    while(idx != position){
        currentPtr = currentPtr->getNext();
        idx++;
    }
    return currentPtr;
}

template <class T>
void List<T>::remove_one_or_no(){
    if (numOfItems == 0) return;
    else if(numOfItems==1){
        delete head;
        head = NULL; tail = NULL; numOfItems = 0; return;
    }
}

template <class T>
void List<T>::removeHead(){
    remove_one_or_no();
    Node<T>* currentPtr = head;
    head = head->getNext();
    delete currentPtr;
    numOfItems--;    
}

template <class T>
void List<T>::removeTail(){
    remove_one_or_no();
    Node<T>* currentPtr = itemAt(numOfItems-2);
    currentPtr -> setNext(NULL);
    delete tail;
    tail = currentPtr;
    numOfItems--;
}

template <class T>
void List<T>::removeValue(T x, int n){
    int number = 0;

    if(!numOfItems){
        return;
    }

    Node<T>* beforePtr = head;
    Node<T>* currentPtr = head -> getNext();

    if(head -> getData() == x){
        removeHead();
    }

    else{
        while(currentPtr != tail && number < n){
            if(currentPtr->getData() == x){
                beforePtr->setNext( currentPtr->getNext() );
                delete currentPtr;
                numOfItems--;
                currentPtr = beforePtr->getNext();
                number++;
            }

            else{
                beforePtr = currentPtr;
                currentPtr = beforePtr->getNext();
            }
        }
    }
}

template <class T>
void List<T>::removeAt(int pos){
    int idx = 1;

    if( pos < 0 || pos >= numOfItems){
        return;
    } 

    if( pos == 0){
        removeHead();
        return;
    }

    Node<T>* beforePtr = head;
    Node<T>* currentPtr = head -> getNext();

    while(idx != pos){
        beforePtr = currentPtr;
        currentPtr = currentPtr -> getNext();
        idx++;
    }

    beforePtr->setNext(currentPtr->getNext());
    delete currentPtr;
    numOfItems--;

    return;
}

template <class T>
void List<T>::insertHead(T x){
    Node<T>* newHead = new Node<T>(x, head);
    head = newHead;
    if(tail == NULL){
        tail = head;
    }
    numOfItems++;
    return;
}

template <class T>
void List<T>::insertTail(T x){
    if(head==NULL){
        insertHead(x);
        return;
    }

    Node<T>* newTail = new Node<T>(x, NULL);
    tail->setNext(newTail);
    tail = newTail;
    numOfItems++;

    return;
}

template <class T>
void List<T>::insertAt(T x, int pos){
    int idx = 1;

    if(pos < 0 || pos > numOfItems){
        return;
    }

    if(pos == 0){
        insertHead(x);
        return;
    }

    if(pos == numOfItems){
        insertTail(x);
        return;
    }

    Node<T>* beforePtr = head;
    Node<T>* currentPtr = head->getNext();

    while(idx != pos){
        beforePtr = currentPtr;
        currentPtr = currentPtr->getNext();
        idx++;
    }

    Node<T>* newNode = new Node<T>(x, currentPtr);
    beforePtr->setNext(newNode);
    numOfItems++;

    return;
}

template <class T>
T List<T>::frontValue(){
    return head->getData();
}

template <class T>
T List<T>::backValue(){
    return tail->getData();
}

template <class T>
void List<T>::printList(){
    Node<T>* currentNode = head;
    while(currentNode->getNext()!=NULL){
        cout<< currentNode->getData() << " ";
        currentNode = currentNode -> getNext();
    }
    cout<<endl;
}