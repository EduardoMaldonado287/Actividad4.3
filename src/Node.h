template <class T>

class Node
{
public:
    Node(T data)
    {
        this->data = data;
        this->next = nullptr;
    }

    Node(T data, Node<T> *next){
        this->data = data;
        this->next = next;
    }

    T getData(){
        return data;
    }

    Node<T>* getNext(){
        return next;
    }

    void setData(T data){
        this->data = data;
    }

    void setNext(Node<T> *next){
        this->next = next;
    }

private:
    T data;
    Node<T> *next;
};
