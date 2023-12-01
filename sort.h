//
// Created by vicky on 10-11-2023.
//
#include "include/Stack/stack.h"

template <typename T>
Stack<T>* stackSort(Stack<T> s){
    const int tarSize = s.getStackSize();

    Stack<T>* s1 = new Stack<T>;
    T tmp;

    tmp = s.pop();
    s1 -> push(tmp);
    tmp = s.pop();

    while(s1 -> getStackSize() != tarSize){
        if(s1 -> isEmpty() || tmp >= s1 -> get()){
            s1 -> push(tmp);
            tmp = s.pop();
        }
        else{
            s.push(s1 -> pop());
        }
    }

    return s1;
}