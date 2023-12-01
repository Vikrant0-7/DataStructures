#include "include/Stack/stack.h"

#ifndef POST
#define POST
int pred(char op){
    if(op == '^')
        return 2;
    if(op == '*' || op == '/')
        return 1;
    if(op == '+' || op == '-')
        return 0;
    return  -1;
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
            while(!stack.isEmpty() && pred(c) <= pred(stack.get())){
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

#endif