//
// Created by vicky on 12-11-2023.
//

#ifndef LAB_AVL_NODE_H
#define LAB_AVL_NODE_H

#include <iostream>

template <typename T>
class AVLNode{
private:
    T data;
    AVLNode<T>* leftChild;
    AVLNode<T>* rightChild;
    AVLNode<T>* parent;
    int balanceFactor;
public:
    AVLNode(T data, AVLNode<T>* _parent);

    T getData();
    void setData(T _data);

    AVLNode<T>* getRightChild();
    void setRightChild(AVLNode<T>* r);

    AVLNode<T>* getLeftChild();
    void setLeftChild(AVLNode<T>* l);

    AVLNode<T>* getParent();
    void setParent(AVLNode<T>* p);

    void inc();
    void dec();
    int getBalanceFactor();
    void setBalanceFactor(int i);

    int getHeight();

    void preOrder();
    void postOrder();
    void inOrder();

};

template<typename T>
AVLNode<T>::AVLNode(T data, AVLNode<T> *_parent) {
    this -> parent = _parent;
    this -> data = data;

    leftChild = NULL;
    rightChild = NULL;
    balanceFactor = 0;
}

template<typename T>
T AVLNode<T>::getData() {
    return data;
}

template<typename T>
void AVLNode<T>::setData(T _data) {
    this -> data = _data;
}

template<typename T>
AVLNode<T> *AVLNode<T>::getRightChild() {
    return rightChild;
}

template<typename T>
void AVLNode<T>::setRightChild(AVLNode<T> *r) {
    rightChild = r;
    if(r != NULL)
        r ->setParent(this);
}

template<typename T>
AVLNode<T> *AVLNode<T>::getLeftChild() {
    return leftChild;
}

template<typename T>
void AVLNode<T>::setLeftChild(AVLNode<T> *l) {
    leftChild = l;
    if(l != NULL)
        l ->setParent(this);
}

template<typename T>
AVLNode<T> *AVLNode<T>::getParent() {
    return parent;
}

template <typename T>
void AVLNode<T>::setParent(AVLNode<T> *p) {
    this -> parent = p;
    if(p != NULL){
        if(data <= p -> getData()){
            p -> leftChild = this;
        }else{
            p -> rightChild = this;
        }

    }
}


template<typename T>
void AVLNode<T>::inc() {
    ++balanceFactor;
}

template<typename T>
void AVLNode<T>::dec() {
    --balanceFactor;
}

template<typename T>
int AVLNode<T>::getBalanceFactor() {
    return balanceFactor;
}
template<typename T>
void AVLNode<T>::setBalanceFactor(int i) {
    balanceFactor = i;
}

template<typename T>
int AVLNode<T>::getHeight() {
    if(leftChild == NULL && rightChild == NULL){
        return  1;
    }

    int h = 1;
    if(leftChild != NULL){
        h = leftChild -> getHeight();
    }
    if(rightChild != NULL){
        h = std::max(h,rightChild -> getHeight());
    }

    return  h+1;
}

template<typename T>
void AVLNode<T>::preOrder() {
    std::cout << data << ", ";
    if(leftChild != NULL){
        leftChild->preOrder();
    }
    if(rightChild!= NULL){
        rightChild->preOrder();
    }
}

template<typename T>
void AVLNode<T>::postOrder() {
    if(leftChild != NULL){
        leftChild->postOrder();
    }
    if(rightChild!= NULL){
        rightChild->postOrder();
    }
    std::cout << data << ", ";
}

template<typename T>
void AVLNode<T>::inOrder() {
    if(leftChild != NULL){
        leftChild->inOrder();
    }
    std::cout << data << ", ";
    if(rightChild!= NULL){
        rightChild->inOrder();
    }
}

#endif //LAB_AVL_NODE_H
