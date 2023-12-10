//
// Created by vicky on 10-12-2023.
//

#ifndef LAB_STACK_APPLICATIONS_H
#define LAB_STACK_APPLICATIONS_H

#include "include/Stack/stack.h"


int __pred(char op){
    if(op == '^')
        return 2;
    if(op == '*' || op == '/')
        return 1;
    if(op == '+' || op == '-')
        return 0;
    return  -1;
}

char __match(char bracket){
    if (bracket == '(')
        return ')';
    else if (bracket == '[')
        return ']';
    else if (bracket == '{')
        return '}';
    else
        return '\0';
}

bool __is_bracket(char symbol){
    if (symbol == '(' || symbol == '[' || symbol == '{' || symbol == ')' || symbol == ']' || symbol == '}')
        return true;
    return  false;
}

std::string postfix(std::string expr){
    if(expr.length() == 0)
        return "";

    std::string output = "";
    Stack<char> stack;
    for(int i = 0; i < expr.length(); ++i){
        char c = expr[i];
        if(c >= 'a' && c <= 'z')
            output += c;
        else if (c == '('){
            stack.push(c);
        }
        else if(c == ')'){
            while(stack.get() != '(')
                output += stack.pop();
            stack.pop();
        }
        else if(c == '^' || c == '*' || c == '/' || c == '+' || c == '-') {
            while(!stack.isEmpty() && __pred(c) <= __pred(stack.get())){
                output += stack.pop();
            }
            stack.push(c);
        }
        else{
            std::cout << "Invalid character " << c << "\na-z ()+-^*/ are valid characters" << std::endl;
        }
    }
    while(!stack.isEmpty()){
        if(stack.get() == '('){
            std::cout << "Invalid Expression" << std::endl;
            return "";
        }
        output += stack.pop();
    }

    std::cout << output << std::endl;
    return output;
}

void infix(std::string expr){
    Stack<std::string> stack;
    for(int i = 0; i < expr.length(); ++i){
        char c = expr[i];
        if(c >= 'a' && c <= 'z'){
            std::string str = std::string(1,c);
            stack.push(str);
        }
        else if(c == '^' || c == '*' || c == '/' || c == '+' || c == '-'){
            std::string op2 = stack.pop();
            std::string op1 = stack.pop();
            std::string binaryOp = "(" + op1 + c + op2 + ")";
            stack.push(binaryOp);
        }
    }
    std::cout << stack.pop() << std::endl;
}

bool bracketMatching(std::string expr){
    Stack<char> stack;

    for(auto _char:expr){
        if(!__is_bracket(_char)){
            continue;
        }
        if (_char == '(' || _char == '[' || _char == '{'){
            stack.push(_char);
        }
        else{
            if(__match(stack.get()) == _char){
                stack.pop();
            }
            else{
                std::cout << "Was expecting " << __match(stack.get()) << " but got " << _char << std::endl;
                return  false;
            }
        }
    }
    return  true;
}

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



#endif //LAB_STACK_APPLICATIONS_H
