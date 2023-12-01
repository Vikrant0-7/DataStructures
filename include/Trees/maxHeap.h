#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include "tree.h"

template <typename T>
class MaxHeap : public Tree<T>{
    
    void moveUp(int);
    void moveDown(int);
    

    public:
        MaxHeap();
        void addElement(T);
        void convert(Tree<T>*);
        T pop();

};


//climbs up the hierarchy till current node is smaller than parent
template <typename T>
void MaxHeap<T>::moveUp(int i){
    if(i == 0)
        return; //stop climbing if current node is root 

    //compare current element to its parent, and swap if current is smaller than parent
    if(Tree<T>::getElement(getParentIdx(i)) < Tree<T>::getElement(i)){
        Tree<T>::swap(getParentIdx(i),i); //swap
        moveUp(getParentIdx(i)); /*now current node is in parent's position
        switch to parent's position and contiune comparing with grand parent */ 
    }

    //stop climbing if parent is smaller than current node
}

//moves node with small values to bottom
template <typename T>
void MaxHeap<T>::moveDown(int i){
    if(i > internal) //return if i is a leaf node or i is not even a valid node
        return;
    
    //std::cout << '\n';this -> print(); std::cout << std::endl;

    int greatest = i;

    //if left child exist and has greater value than current
    if(getLeftChildIdx(i) < this -> size && this -> getElement(getLeftChildIdx(i)) > this -> getElement(i)){
        greatest = getLeftChildIdx(i); //asigning left child's index as greatest
    }
    //if right child exists and has greater value than previously know value i.e. either left child or current node
    if(getRightChildIdx(i) < this -> size && this -> getElement(getRightChildIdx(i)) > this -> getElement(greatest)){
        greatest = getRightChildIdx(i); //asigning right child's index as greatest
    }

    if(greatest == i) //return if current node is largest
        return;
    
    this->swap(i, greatest); //swap current with largest child
    moveDown(greatest); //modify the sub tree of child that is swapped
}

template <typename T>
MaxHeap<T>::MaxHeap
() : Tree<T>() { }

template <typename T>
void MaxHeap<T>::addElement(T e){
    Tree<T>::addElement(e);
    moveUp(Tree<T>::size - 1); //start climbing
}

//converts any binary heap to min binary heap
template <typename T>
void MaxHeap<T>::convert(Tree<T>* tree){

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
T MaxHeap<T>::pop(){
    T tmp = Tree<T>::pop(); //returns root and assigns last element as root
    moveDown(0); //current root climbs down the hierarchy till child is less than parent
    return tmp; //return root
}


#endif