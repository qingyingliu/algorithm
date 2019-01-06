#include <iostream>

template<typename T>
class LinkQueue
{
    struct Node
    {
        Node()
        {
            next = NULL;
        }
        Node(T val)
        {
            this->val = val;
            next = NULL;
        }

        Node* next;
        T val;
    };
    Node* _front, *_rear;
    unsigned int size;

public:
    LinkQueue()
    {
        this->_front = new Node();
        this->_rear = this->_front;
        size = 0;
    }

    ~LinkQueue(){
        Node* item = this->_front;
        while(item != NULL){
            Node* nextItem = item->next;
            delete item;
            item = nextItem;
        }
    }

    void push(T& item)
    {
        Node *newItem = new Node(item);
        _rear->next = newItem;
        _rear = newItem;
        size++;
    }

    bool pop()
    {
        if(isEmpty())
        {
            return false;
        }
        Node* p = _front;
        while(p!=NULL && p->next != _rear)
        {
            p = p->next;
        }
        /* free memory */
        delete _rear;
        _rear = p;
        p->next = NULL;
        size--;
        return true;
    }

    bool isEmpty()
    {
        return _front == _rear;
    }

    unsigned getSize(){
        return size;
    }

    void printItems()
    {
        if(isEmpty())
            return;
        Node* item = _front->next;
        while(item!=_rear)
        {
            std::cout<<item->val<<" ";
            item = item->next;
        }
        std::cout<<_rear->val<<std::endl;
    }
};

int main()
{
    LinkQueue<int> q;
    for(int i=0; i<10; i++)
    {
        q.push(i);
    }
    q.pop();
    q.pop();

    std::cout<<"size: "<<q.getSize()<<std::endl;
    q.printItems();
    return 0;
}
