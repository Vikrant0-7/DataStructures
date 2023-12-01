#include <cmath>
#include <iostream>

#ifndef TREE_H
#define TREE_H

#define getLeftChildIdx(i) 2 * i + 1
#define getRightChildIdx(i) 2 * i + 2
#define getParentIdx(i) (i - 1) / 2
#define height ceil(log2(this->size))
#define internal (int)floor((this->size - 2) / 2.0)

template <typename T>
class Tree
{
protected:
    T *items;
    int capacity; //in powers of 2. Actual size i.e. size on memory of dynamic array
    int size; //size as per user.

    inline void swap(int, int);

public:
    Tree();
    inline T getElement(int);

    virtual void addElement(T);
    virtual void addElements(T*);
    virtual T pop();

    void print();
    inline int getCapacity();
    inline int getSize();
};


template <typename T>
void Tree<T>::swap(int i, int j)
{
    if (i >= size || j >= size || i < 0 || j < 0)
        throw -1;
    T tmp = i[items];
    i[items] = j[items];
    j[items] = tmp;
    /*
    i[items] += j[items]; //a = a + b
    j[items] = i[items] - j[items]; //b = a - b = (a+b) - b = a
    i[items] -= j[items]; //a = a - b = a + b - a = b
    */
}

template <typename T>
Tree<T>::Tree()
{
    items = new T[1];
    capacity = 1;
    size = 0;
}

template <typename T>
T Tree<T>::getElement(int i)
{
    return i[items];
}

template <typename T>
void Tree<T>::addElement(T i)
{
    if (size == capacity) //if size is equal to capacity that means array is full
    {
        capacity *= 2; 

        //copy items to new array with increased size
        T *tmp = items;
        items = new T[capacity];
        for (int x = 0; x < size; ++x)
        {
            x[items] = x[tmp];
        }
        delete[] tmp; //delete previous array
        items[size++] = i; 
    }
    else
    {
        items[size++] = i; //when new element is added, it is added at last index, which is size of array without that element.
        /*
            items[size] = i;
            ++size;
        */
    }
}

//return root and makes last element as root
template <typename T>
T Tree<T>::pop(){
    T tmp = items[0];
    items[0] = items[--size];
    return tmp;
}

template <typename T>
void Tree<T>::print()
{

    int idx = 0;
    for(int i = 0; i < height; ++i){
        int padding = (int)pow(2,height-i-1);

        for(int row = 0; row < pow(2,i); ++row){
            for(int j = 0; j < padding - 1; ++j){
                std::cout << " ";
            }
            if(idx >= this -> size)
                return;
            std::cout << idx[items];
            ++idx;
            for(int j = 0; j < padding; ++j){
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }

    /*int i=0;
    for (int j = 0; j <= height; ++j)
    {
        int stop = int(pow(2, j)) + i;
        //std::cout << "start: " << i << " stop: " << stop << std::endl;
        while (i < stop && i < size)
        {
            std::cout << items[i] << ", ";
            ++i;
        }
        std::cout << "\n";
    }*/
}

template <typename T>
int Tree<T>::getCapacity(){
    return capacity;
}


template <typename T>
int Tree<T>::getSize(){
    return size;
}

#endif /*TREE_H*/