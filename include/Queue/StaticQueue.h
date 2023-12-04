//
// Created by vicky on 22-11-2023.
//

// TODO: Test the code.

#ifndef LAB_STATICQUEUE_H
#define LAB_STATICQUEUE_H

#include <iostream>


template <typename T, int SIZE>
class StaticQueue{

    T* items;
    int frontEnd, rearEnd;
    bool _isFull;

public:
    StaticQueue();

    void enqueue(T);
    T dequeue();

    T get();

    bool isFull();
    bool isEmpty();

    void print();

};

template<typename T, int SIZE>
void StaticQueue<T, SIZE>::print() {
    int i = frontEnd + 1;
    do{
        std::cout << items[i] << ", ";
        i = (i + 1) % SIZE;
    }while(i != rearEnd);
    if(isFull())
        std::cout << items[i];
    std::cout << std::endl;

}


template<typename T, int SIZE>
StaticQueue<T, SIZE>::StaticQueue() {
    frontEnd = 0;
    rearEnd = 0;
    _isFull = false;
    items = new int[SIZE];
}

template<typename T, int SIZE>
void StaticQueue<T, SIZE>::enqueue(T elem) {

    if((rearEnd + 1) % SIZE == frontEnd || isFull()){
        if(!isFull()){
            rearEnd = (rearEnd + 1) % SIZE;
            items[rearEnd] = elem;
        }
        _isFull = true;
        std::cout << "Queue is Full" << std::endl;
        return;
    }

    rearEnd = (rearEnd + 1) % SIZE;
    items[rearEnd] = elem;
}

template<typename T, int SIZE>
T StaticQueue<T, SIZE>::dequeue() {
    if(isEmpty()){
        std::cout << "Queue is Empty" << std::endl;
        return NULL;
    }
    _isFull = false;
    frontEnd = (frontEnd + 1) % SIZE;
    return  items[frontEnd];
}



template<typename T, int SIZE>
T StaticQueue<T, SIZE>::get() {
    if(!isEmpty())
        return items[frontEnd];
    return NULL;
}

template<typename T, int SIZE>
bool StaticQueue<T, SIZE>::isFull() {
    return _isFull && frontEnd == rearEnd;
}

template<typename T, int SIZE>
bool StaticQueue<T, SIZE>::isEmpty() {
    return frontEnd == rearEnd && !_isFull;
}


#endif //LAB_STATICQUEUE_H
