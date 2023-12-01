//
// Created by vicky on 10-11-2023.
//

#ifndef QUEUE_H
#define QUEUE_H
#include "../Stack/stack.h"

template <typename T>
class QueueUsingStack{
    Stack<T>* enqueueStack;
    Stack<T>* dequeueStack;
    int queueSize;

public:
    QueueUsingStack();

    void enqueue(T);
    T dequeue();

    ~QueueUsingStack();

};

template<typename T>
QueueUsingStack<T>::QueueUsingStack() {
    enqueueStack = new Stack<T>;
    dequeueStack = new Stack<T>;
    queueSize = 0;
}

template<typename T>
void QueueUsingStack<T>::enqueue(T elem) {
    enqueueStack ->push(elem);
    ++queueSize;
}

template<typename T>
T QueueUsingStack<T>::dequeue() {
    if(queueSize == 0){
        std::cout << "Queue is Empty" << std::endl;
        return  NULL;
    }
    --queueSize;
    if(dequeueStack -> getStackSize()){
        return  dequeueStack -> pop();
    }
    else{
        while(enqueueStack ->getStackSize()){
            dequeueStack ->push(enqueueStack ->pop());
            if(enqueueStack ->getStackSize() == 1)
                break;
        }
        return  enqueueStack -> pop();
    }
}

template<typename T>
QueueUsingStack<T>::~QueueUsingStack() {
    delete enqueueStack;
    delete dequeueStack;
}


#endif //LAB_QUEUEUSINGSTACKS_H
