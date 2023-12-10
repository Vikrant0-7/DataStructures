#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include "tree.h"

template <typename T>
class MinTree : public Tree<T>{
    
    void moveUp(int);
    void moveDown(int);
    

    public:
        MinTree();
        void addElement(T);
        void addElement(T*,int);
        void convert(Tree<T>*);
        T pop();

};

template<typename T>
void MinTree<T>::addElement(T * data, int si) {
    for(int i = 0; i < si; ++i){
        this ->addElement(data[i]);
    }
}

//climbs up the hierarchy till current node is greater than parent
template <typename T>
void MinTree<T>::moveUp(int i){
    if(i == 0)
        return; //stop climbing if current node is root 

    //compare current element to its parent, and swap if current is smaller than parent
    if(Tree<T>::getElement(getParentIdx(i)) > Tree<T>::getElement(i)){
        Tree<T>::swap(getParentIdx(i),i); //swap
        moveUp(getParentIdx(i)); /*now current node is in parent's position
        switch to parent's position and contiune comparing with grand parent */ 
    }

    //stop climbing if parent is smaller than current node
}

//moves node with large values to bottom
template <typename T>
void MinTree<T>::moveDown(int i){
    if(i < 0 || i > internal) //return if i is a leaf node
        return;
    
    //std::cout << '\n';this -> print(); std::cout << std::endl;

    int least = i;

    //if left child exist and has smaller value than current
    if(getLeftChildIdx(i) < this -> size && this -> getElement(getLeftChildIdx(i)) < this -> getElement(i)){
        least = getLeftChildIdx(i);
    }
    //if right child exists and has greater value than previously know value i.e. either left child or current node
    if(getRightChildIdx(i) < this -> size && this -> getElement(getRightChildIdx(i)) < this -> getElement(least)){
        least = getRightChildIdx(i);
    }
    if(least == i) //return if current node is smallest
        return;
    
    this->swap(i,least); //swap current with smallest child
    moveDown(least); //modify the sub tree of child that is swapped
}

template <typename T>
MinTree<T>::MinTree() : Tree<T>() { }

template <typename T>
void MinTree<T>::addElement(T e){
    Tree<T>::addElement(e);
    moveUp(Tree<T>::size - 1); //start climbing
}

//converts any binary heap to min binary heap
template <typename T>
void MinTree<T>::convert(Tree<T>* tree){

    //copies properties from tree
    this->size = tree -> getSize();
    this->capacity = tree -> getCapacity();
    this->items = new T[this->capacity];
    
    //copies elements from tree
    for(int i = 0; i < this->size; ++i){
        i[this->items] = tree->getElement(i);
    }

    for(int i = getParentIdx(this->size - 1); i >= 0; --i){
        moveDown(i);
    }
}

//return root and reconstructs tree
template <typename T>
T MinTree<T>::pop(){
    T tmp = Tree<T>::pop(); //returns root and assigns last element as root
    moveDown(0); //current root climbs down the hierarchy till child is greater than parent
    return tmp; //return root
}


#endif