#ifndef NODE_H
#define NODE_H

#include <iostream>

template<typename T>
class Node{
    public:
        T data;
        Node<T> *next;
        Node(T i,Node<T>* next = NULL){
            data = i;
            this->next = next;
        }
};

template <typename T>
class dNode
{
public:
    dNode<T> *previous;
    dNode<T> *next;
    T data;

    dNode(T data, dNode<T> *previous = 0, dNode<T> *next = 0)
    {
        this->data = data;
        this->previous = previous;
        this->next = next;
    }
};


template <typename T>
class List{
    public:
        virtual void insertAsHead(T) = 0;
        virtual void insertAsTail(T) = 0;
        
        virtual T deleteHead() = 0;
        virtual T deleteTail() = 0;
        virtual bool deleteElement(T) = 0;
        
        virtual void print() = 0;
        
        virtual void reverse() = 0;

        virtual int search(T)= 0;

        virtual ~List(){
            
        }

};
#endif /*NODE_H*/