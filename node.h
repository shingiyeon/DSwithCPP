template <class T>
class Node{
    private:
        T data;
        Node<T>* next;
    public:
        Node(T x=0, Node* ptr=0);
        ~Node();

        T getData();
        Node<T>* getNext();

        void setData(T x);
        void setNext(Node* ptr);
};

template <class T>
Node<T>::Node(T x, Node* ptr){
    data = x;
    next = ptr;
}

template <class T>
Node<T>::~Node(){
}

template <class T>
T Node<T>::getData(){
    return data;
}

template <class T>
Node<T>* Node<T>::getNext(){
    return next;
}

template <class T>
void Node<T>::setData(T x){
    data = x;
}

template <class T>
void Node<T>::setNext(Node* ptr){
    next = ptr;
}
