#include <iostream>
using namespace std;

template<typename T>
class CircularQueue
{
    unsigned QueueSize;
    int size;
    int front;
    int rear;
    T* val;
public:
    CircularQueue()
    {
        front = rear = 0;
        size = 0;
        QueueSize = 5;
        val = new T[QueueSize];
    }

    CircularQueue(int maxSize)
    {
        front = rear = 0;
        size = 0;
        QueueSize = maxSize;
        val = new T[QueueSize];
    }

    ~CircularQueue()
    {
        delete val;
    }

    void enqueue(T item)
    {
        if(isFull())
        {
            reSize();
        }
        else
        {
            val[rear] = item;
            rear = (rear+1)%QueueSize;
            size++;
        }
    }

    bool dequeue()
    {
        if(isEmpty())
        {
            return false;
        }
        else
        {
            front = (front+1)%QueueSize;
            size--;
        }
    }

    bool isFull()
    {
        return (rear+1)%QueueSize == front;
    }

    bool isEmpty()
    {
        return front == rear;
    }

    unsigned getSize()
    {
        return size;
    }

    void reSize()
    {
        T *cp = new T[QueueSize];

        /* copy items to cp */
        int loc = front;
        int i = 0;
        while(loc != rear)
        {
            cp[i++] = val[loc];
            loc = (loc+1)%QueueSize;
        }

        /* free memory */
        delete val;
        /* reinit */
        front = rear = 0;

        QueueSize *= 2;
        val = new T[QueueSize];

        /* reenqueue */
        int index=0;
        for(; index<i; index++)
        {
            enqueue(cp[index]);
        }
    }

    T getFront()
    {
        if(isEmpty())
        {
            return NULL;
        }
        return val[front];
    }

    void printItems()
    {
        if(isEmpty())
        {
            return;
        }
        int loc = front;
        while((loc+1)%QueueSize != rear)
        {
            std::cout<<val[loc]<<" ";
            loc = (loc+1)%QueueSize;

        }

        std::cout<<val[loc]<<std::endl;
    }
};

int main()
{
    CircularQueue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    cout<<"all items: \n";
    q.printItems();

    cout<<"get front item: \n";
    cout<<q.getFront()<<endl;
    q.dequeue();
    cout<<q.getFront()<<endl;
    q.dequeue();
    cout<<q.getFront()<<endl;
    q.dequeue();
    cout<<q.getFront()<<endl;
    return 0;
}
