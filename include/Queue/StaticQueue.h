//
// Created by vicky on 22-11-2023.
//

#ifndef LAB_STATICQUEUE_H
#define LAB_STATICQUEUE_H

#include <iostream>

template <typename T, int SIZE>
class StaticQueue{

    T* items;
    int frontEnd, rearEnd;

public:
    StaticQueue();

    void enqueue(T);
    T dequeue();

    int getSize();

    T get();

    bool isFull();
    bool isEmpty();

};



template<typename T, int SIZE>
StaticQueue<T, SIZE>::StaticQueue() {
    frontEnd = -1;
    rearEnd = 0;
    items = new int[SIZE];
}

template<typename T, int SIZE>
void StaticQueue<T, SIZE>::enqueue(T elem) {
    if(isFull()){
        std::cout << "Queue is full" << std::endl;
        return;
    }

    frontEnd++;

    if (frontEnd == SIZE) frontEnd %= SIZE;

    items[frontEnd] = elem;
}

template<typename T, int SIZE>
T StaticQueue<T, SIZE>::dequeue() {
    if(isEmpty()){
        std::cout << "Queue is Empty" << std::endl;
        return NULL;
    }
    T data = items[rearEnd];
    rearEnd++;
    if(rearEnd == SIZE) rearEnd %= SIZE;

    return  data;
}

template<typename T, int SIZE>
int StaticQueue<T, SIZE>::getSize() {
    return 0;
}

template<typename T, int SIZE>
T StaticQueue<T, SIZE>::get() {
    return items[rearEnd];
}

template<typename T, int SIZE>
bool StaticQueue<T, SIZE>::isFull() {
    return (frontEnd + 1) % SIZE == rearEnd && frontEnd != -1;
}

template<typename T, int SIZE>
bool StaticQueue<T, SIZE>::isEmpty() {
    return frontEnd == rearEnd || frontEnd < 0;
}


#endif //LAB_STATICQUEUE_H
