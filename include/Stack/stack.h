//
// Created by vicky on 10-11-2023.
//

#ifndef LAB_STACK_H
#define LAB_STACK_H
#include "../LinkedLists/singlyLinkedList.h"



template <typename T>
class Stack{
    sLinkedList<T>* list;
    int stackSize;


public:
    Stack();
    Stack(Stack<T> &);

    inline int getStackSize();
    inline bool isEmpty();
    void print();

    void push(T);
    T pop();
    T get();

    ~Stack();
};

template<typename T>
Stack<T>::Stack(Stack<T> &o) {
    list = new sLinkedList<T>(*(o.list));
    stackSize = o.getStackSize();
}

template<typename T>
T Stack<T>::get() {
    if(stackSize){
        return list -> getHead() -> data;
    }else{
        std::cout << "Stack is empty" << std::endl;
        return NULL;
    }
}

template<typename T>
void Stack<T>::print() {
    list -> print();
}

template<typename T>
bool Stack<T>::isEmpty() {
    return stackSize == 0;
}

template<typename T>
int Stack<T>::getStackSize() {
    return stackSize;
}

template<typename T>
Stack<T>::~Stack() {
    delete list;
}

template<typename T>
T Stack<T>::pop() {
    if(stackSize) {
        --stackSize;
        return list->deleteHead();
    }
    else{
        std::cout << "Stack is empty" << std::endl;
        return NULL;
    }
}

template<typename T>
void Stack<T>::push(T elem) {
    ++stackSize;
    list ->insertAsHead(elem);
}

template<typename T>
Stack<T>::Stack() {
    list = new sLinkedList<T>;
    stackSize = 0;
}

#endif //LAB_STACK_H
