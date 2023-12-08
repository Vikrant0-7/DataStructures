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

/*!
 * @brief Adds element to queue
 * @param elem
 */
template<typename T>
void QueueUsingStack<T>::enqueue(T elem) {
    enqueueStack ->push(elem);
    ++queueSize;
}

/*!
 * @brief Removes and returns first element from queue
 * @return first element from queue
 * @throws std::runtime_error when queue is empty
 */

template<typename T>
T QueueUsingStack<T>::dequeue() {
    if(queueSize == 0){ //if queue is empty tell user queue is empty.
        throw std::runtime_error("Queue is Empty");
    }
    --queueSize;
    /*
     * let there be two stacks
     *      A               B
     *      1
     *      2
     *      3
     *
     * element 3,2,1 are added to A. if we pop from A, we will get 1. but in case we want
     * to follow FIFO, we should get 3. To counter this problem we will second stack. That will be used solely to
     * dequeue operation. When user does dequeue operation we pop all elements from A and push it to B. Which will
     * reverse the stack A.
     *      A               B
     *                      3
     *                      2
     *                      1
     * if we dequeue operation from B as long as it has elements in it. Once it is empty we will again do push and pop
     * combination.
     *      NOTE: New elements will only be added to Stack A.
     *
     *      A               B
     *      5               2
     *      4               1
     *
     *      stacks after dequeue() and enqueue(4,5)
     */


    if(dequeueStack -> getStackSize()){ // if dequeue stack i.e. second stack has element then pop it and return it
        return  dequeueStack -> pop();
    }
    else{ //if it is empty. pop all elements from A (enqueueStack) and push them to B(dequeueStack)
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
