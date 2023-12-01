//
// Created by vicky on 11-11-2023.
//

#ifndef LAB_QUEUE_H
#define LAB_QUEUE_H

#include "../LinkedLists/singlyLinkedList.h"

template <typename T>
class Queue{
    sLinkedList<T>* list;
    int queueSize;
public:
    Queue();

    int getSize();
    bool isEmpty();

    void enqueue(T);
    T dequeue();

    ~Queue();
};

template<typename T>
Queue<T>::Queue() {
    list = new sLinkedList<T>;
    queueSize = 0;
}

template<typename T>
int Queue<T>::getSize() {
    return queueSize;
}

template<typename T>
bool Queue<T>::isEmpty() {
    return queueSize == 0;
}

template<typename T>
void Queue<T>::enqueue(T elem) {
    list ->insertAsTail(elem);
    ++queueSize;
}

template<typename T>
T Queue<T>::dequeue() {
    if(queueSize){
        --queueSize;
        return  list -> deleteHead();
    }
    else{
        std::cout << "Queue is Empty" << std::endl;
        return NULL;
    }
}

template<typename T>
Queue<T>::~Queue() {
    delete list;
}

#endif //LAB_QUEUE_H
