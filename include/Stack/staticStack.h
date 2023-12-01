//
// Created by vicky on 22-11-2023.
//

#ifndef LAB_STATICSTACK_H
#define LAB_STATICSTACK_H

#include <iostream>

/*!
 * @tparam T: datatype of stack's elements
 * @tparam SIZE: maximum number of elements this stack can hold
 */
template <typename T, int SIZE>
class StaticStack{
    int *items;
    int topIdx;

public:
    StaticStack();

    void push(T);
    T pop();

    bool isEmpty();
    bool isFull();

    int getSize();

    T get();

    void print();
};

/*!
 * Constructor
 * @tparam T
 * @tparam SIZE
 */
template <typename T, int SIZE>
StaticStack<T,SIZE>::StaticStack() {
    items = new int[SIZE];
    topIdx = 0;
}

/*!
 * Pushes element to stack.
 * @param elem: Element to be pushed onto stack
 */
template <typename T, int SIZE>
void StaticStack<T, SIZE>::push(T elem) {
    if(isFull()){
        std::cout << "Stack is full." << std::endl;
        return;
    }
    items[topIdx] = elem;

    ++topIdx;
}

/*!
 * @brief Returns element from stack while removing it from stack.
 * @return Returns Element from top of stack.
 */
template <typename T, int SIZE>
T StaticStack<T, SIZE>::pop(){
    if(isEmpty()){
        std::cout << "Stack is Empty" << std::endl;
        return;
    }
    --topIdx;
    return items[topIdx];
}

/*!
 * @brief tells if stack is empty of not
 * @return bool: true if stack has no elements in it.
 */
template <typename T, int SIZE>
bool StaticStack<T, SIZE>::isEmpty() {
    return topIdx == 0;
}

/*!
 * @brief tells if stack if full or not
 * @return bool: true is stack has reached its maximum capacity
 */
template <typename T, int SIZE>
bool StaticStack<T, SIZE>::isFull() {
    return topIdx == SIZE;
}

/*!
 * @brief gives information about number of element stored
 * @return int: size of stack
 */
template <typename T, int SIZE>
int StaticStack<T,SIZE>::getSize() {
    return topIdx;
}

/*!
 * @brief returns top element of stack ***without*** removing it.
 * @attention to get top element while also removing it. Use pop().
 * @return returns top element in stack.
 */
template <typename T, int SIZE>
T StaticStack<T,SIZE>::get(){
    if(isEmpty()){
        std::cout << "Stack is Empty" << std::endl;
        return nullptr;
    }
    return items[topIdx - 1];
}


template <typename T, int SIZE>
void StaticStack<T,SIZE>::print() {
    for(int i = 0; i < topIdx; ++i)
        std::cout << items[i] << ", ";
    std::cout << std::endl;
}

#endif //LAB_STATICSTACK_H
