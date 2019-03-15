#include "node.cpp"

template <class T>
class List{
    private:
        Node<T>* head;
        Node<T>* tail;
        int numOfItems;
    public:
        List(){
            head = NULL;
            tail = NULL;
            numOfItems = 0;
        };
        int size(){
            return numOfItems;
        }
        Node<T>* getHead(){
            return head;
        }
        Node<T>* getTail(){
            return tail;
        }
        bool isEmpty(){
            return (!numOfItems);
        }
        Node<T>* search(T x){
            Node<T>* currentPtr = head;
            while(currentPtr != NULL){
                if(currentPtr->getData() == x)
                    return currentPtr;
                currentPtr = currentPtr -> getNext();
            }
            return NULL;
        }
        Node<T>* itemAt(int position){
            Node<T>* currentPtr = head;
            int idx = 0;
            while(idx != position){
                currentPtr = currentPtr->getNext();
                idx++;
            }
            return currentPtr;
        }
        void remove_one_or_no(){
            if (numOfItems == 0) return;
            else if(numOfItems==1){
                delete head;
                head = NULL; tail = NULL; numOfItems = 0; return;
            }
        }
        void removeHead(){
            remove_one_or_no();
            Node<T>* currentPtr = head;
            head = head->getNext();
            delete currentPtr;
            numOfItems--;
        }
        void removeTail(){
            remove_one_or_no();
            Node<T>* currentPtr = itemAt(numOfItems-2);
            currentPtr -> setNext(NULL);
            delete tail;
            tail = currentPtr;
            numOfItems--;
        }

        void removeValue(T x, int n=1){
            int number = 0;
            if(!numOfItems) return;
            Node<T>* beforePtr = head;
            Node<T>* currentPtr = head -> getNext();
            if(head -> getData() == x){
                removeHead(); return;
            }
            while(currentPtr != tail && number < n){
                if(currentPtr->getData() == x){
                    beforePtr->setNext( currentPtr->getNext() );
                    delete currentPtr; numOfItems--;
                    number++;
                }
                else{
                    beforePtr = currentPtr;
                }
                currentPtr = beforePtr->getNext();
            }
            return;
        }

        void removeAt(int pos){
            int idx = 1;
            if( pos < 0 || pos >= numOfItems) return;
            if( pos == 0){
                removeHead(); return;
            }
            Node<T>* beforePtr = head;
            Node<T>* currentPtr = head -> getNext();
            while(idx != pos){
                beforePtr = currentPtr;
                currentPtr = currentPtr -> getNext();
                idx++;
            }
            beforePtr->setNext(currentPtr->getNext());
            delete currentPtr; numOfItems--;
            return;
        }

        void insertHead(T x){
            Node<T>* newHead = new Node<T>(x, head);
            head = newHead;
            if(tail == NULL) tail = head;
            numOfItems++;
            return;
        }

        void insertTail(T x){
            if(head==NULL){
                insertHead(x); return;
            }
            Node<T>* newTail = new Node<T>(x, NULL);
            tail->setNext(newTail);
            tail = newTail;
            numOfItems++;
            return;
        }

        void insertAt(T x, int pos){
            int idx = 1;
            if(pos < 0 || pos > numOfItems) return;
            if(pos == 0) {
                insertHead(x); return;
            }
            if(pos == numOfItems){
                insertTail(x); return;
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
        T frontValue(){
            return head->getData();
        }
        T backValue(){
            return tail->getData();
        }
};