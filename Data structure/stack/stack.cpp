#include <iostream>

template<typename T>
class Stack{
    int top;
    unsigned MAX_SIZE ;
    T *val;
    unsigned size ;

public:
    Stack(){
        /* use top == -1 to represent the stack is empty */
        this->top = -1;

        MAX_SIZE = 2;
        size = 0;
        val = new T[MAX_SIZE];
    }

    ~Stack(){
        delete val;
    }

    void reSize(){
        unsigned newSize = MAX_SIZE * 2;
        T* newVal = new T[newSize];
        for(int i=0;i<size;i++){
            newVal[i] = val[i];
        }
        // free memory
        delete val;
        // update size and pointer
        val = newVal;
        MAX_SIZE = newSize;
    }

    void push(T item){
        if(isFull()){
            reSize();
        }

        val[++top] = item;
        size++;
    }

    bool pop(){
        if(isEmpty()){
            return false;
        }else{
            top--;
            size--;
        }
    }

    bool isEmpty(){
        return top == -1;
    }

    bool isFull(){
        return top == MAX_SIZE - 1;
    }

    unsigned getSize(){
        return size;
    }

    void printItems(){
        for(int i=0;i<(int)size-1;i++){
            std::cout<< val[i] <<" ";
        }
        std::cout << val[size-1] << std::endl;
    }

};

int main()
{
    Stack<int> s ;
    for(int i=0;i<30;i++){
        s.push(i);
    }
    s.printItems();
    return 0;
}
