#ifndef BST_NODE_H
#define BST_NODE_H

#include <iostream>

template <typename T>
class BSTNode{

    private:    
        T data;
        BSTNode* leftChild;
        BSTNode* rightChild;

    public:

        BSTNode(T);

        inline void setLeftChild(BSTNode*);
        inline void setRightChild(BSTNode*);

        inline BSTNode* getLeftChild();
        inline BSTNode* getRightChild();

        inline T getData();
        inline void setData(T);

        inline void postOrder();
        inline void preOrder();
        inline void inOrder();

};

template <typename T>
BSTNode<T>::BSTNode(T data){
    this -> data = data;
    leftChild = rightChild = NULL;
}

template <typename T>
void BSTNode<T>::setLeftChild(BSTNode* l){
    this -> leftChild = l;
}

template <typename T>
void BSTNode<T>::setRightChild(BSTNode* r){
    this -> rightChild = r;
}

template <typename T>
BSTNode<T>* BSTNode<T>::getLeftChild(){
    return this -> leftChild;
}

template <typename T>
BSTNode<T>* BSTNode<T>::getRightChild(){
    return this -> rightChild;
}

template <typename T>
T BSTNode<T>::getData(){
    return data;
}

template <typename T>
void BSTNode<T>::setData(T data){
    this -> data = data;
}

template <typename T>
void BSTNode<T>::preOrder(){
    std::cout << this -> data << ", ";
    
    if(this -> leftChild != NULL){
        leftChild -> preOrder();
    }

    if(this -> rightChild != NULL){
        rightChild -> preOrder();
    }
}

template <typename T>
void BSTNode<T>::postOrder(){
    if(this -> leftChild != NULL){
        leftChild -> postOrder();
    }

    if(this -> rightChild != NULL){
        rightChild -> postOrder();
    }

    std::cout << this -> data << ", ";
}

template <typename T>
void BSTNode<T>::inOrder(){
    if(this -> leftChild != NULL){
        leftChild -> inOrder();
    }

    std::cout << this -> data << ", ";

    if(this -> rightChild != NULL){
        rightChild -> inOrder();
    }
}

#endif