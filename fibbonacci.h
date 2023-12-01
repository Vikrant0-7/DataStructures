//
// Created by vicky on 19-11-2023.
//

#ifndef LAB_FIBBONACCI_H
#define LAB_FIBBONACCI_H

#include <iostream>

void IntrativeFibbonacci(int n){
    if (n < 2) {
        std::cout << "0, 1, " << std::endl;
        return;
    }
    int a = 0, b = 1, tmp;
    std::cout << "0, 1, ";

    for(int i = 2; i <= n; ++i){
        tmp = a + b;
        a = b;
        b = tmp;
        std::cout << tmp << ", ";
    }
    std::cout << std::endl;
}

int RecurrsiveFibbonacci(int n){
    if(n < 2){
        return n;
    }
    int a = RecurrsiveFibbonacci(n - 1) + RecurrsiveFibbonacci(n - 2);
    return  a;
}

#endif //LAB_FIBBONACCI_H
