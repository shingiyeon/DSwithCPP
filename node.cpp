template <class T>
class Node{
    private:
        T data;
        Node* next;
    public:
        Node(T x=0, Node* ptr=NULL){
            data = x;
            next = ptr;
        };
        T getData(){
            return data;
        }
        Node* getNext(){
            return next;
        }
        void setData(T x){
            data = x;
        }
        void setNext(Node* ptr){
            next = ptr;
        }
};


