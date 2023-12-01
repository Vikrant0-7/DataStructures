#ifndef NODE_H
#define NODE_H

#include <iostream>

template <typename T>
class Node{

    private:    
        T data;
        Node* leftChild;
        Node* rightChild;

    public:

        Node(T);

        inline void setLeftChild(Node*);
        inline void setRightChild(Node*);

        inline Node* getLeftChild();
        inline Node* getRightChild();

        inline T getData();
        inline void setData(T);

        inline void postOrder();
        inline void preOrder();
        inline void inOrder();

};

template <typename T>
Node<T>::Node(T data){
    this -> data = data;
    leftChild = rightChild = NULL;
}

template <typename T>
void Node<T>::setLeftChild(Node* l){
    this -> leftChild = l;
}

template <typename T>
void Node<T>::setRightChild(Node* r){
    this -> rightChild = r;
}

template <typename T>
Node<T>* Node<T>::getLeftChild(){
    return this -> leftChild;
}

template <typename T>
Node<T>* Node<T>::getRightChild(){
    return this -> rightChild;
}

template <typename T>
T Node<T>::getData(){
    return data;
}

template <typename T>
void Node<T>::setData(T data){
    this -> data = data;
}

template <typename T>
void Node<T>::preOrder(){
    std::cout << this -> data << ", ";
    
    if(this -> leftChild != NULL){
        leftChild -> preOrder();
    }

    if(this -> rightChild != NULL){
        rightChild -> preOrder();
    }
}

template <typename T>
void Node<T>::postOrder(){
    if(this -> leftChild != NULL){
        leftChild -> postOrder();
    }

    if(this -> rightChild != NULL){
        rightChild -> postOrder();
    }

    std::cout << this -> data << ", ";
}

template <typename T>
void Node<T>::inOrder(){    
    if(this -> leftChild != NULL){
        leftChild -> inOrder();
    }

    std::cout << this -> data << ", ";

    if(this -> rightChild != NULL){
        rightChild -> inOrder();
    }
}

#endif