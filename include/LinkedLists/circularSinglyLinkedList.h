#include <iostream>
#include "singlyLinkedList.h"

template <typename T>
class CircularList : public List<T>
{
private:
    BSTNode<T> *last;

public:
    CircularList();
    bool isEmpty();

    void insertAsTail(T);
    void insertAsHead(T);
    
    T deleteHead();
    T deleteTail();
    bool deleteElement(T);


    void print();
    void reverse();
    int search(T);

    ~CircularList();


};

template<typename T>
bool CircularList<T>::isEmpty() {
    return last == NULL;
}

template<typename T>
CircularList<T>::CircularList() {
    last = NULL;
}

template <typename T>
void CircularList<T>::insertAsHead(T data)
{
    if (last == NULL)
    {
        last = new Node<T>(data);
        last->next = last;
    }
    else
    {
        last->next = new Node<T>(data, last->next);
    }
}

template <typename T>
void CircularList<T>::insertAsTail(T data)
{
    if (last == 0)
    {
        last = new Node<T>(data);
        last->next = last;
    }
    else
    {
        last->next = new Node<T>(data, last->next);
        last = last->next;
    }
}

template <typename T>
T CircularList<T>::deleteHead()
{
    if (last == 0)
    {
        throw -1;
    }
    else if (last == last->next)
    {
        T data = last->data;
        delete last;
        last = 0;
        return data;
    }
    else
    {
        T data = last->next->data;
        BSTNode<T>* head = last->next;
        last->next = head->next;
        delete head;
        return data;
    }
}

template <typename T>
T CircularList<T>::deleteTail()
{
    if (last == 0)
    {
        throw -1;
    }
    else if (last == last->next)
    {
        T data = last->data;
        delete last;
        last = 0;
        return data;
    }
    else{
        T data = last -> data;
        BSTNode<T>* tmp = last -> next;
        for(;tmp -> next != last; tmp = tmp -> next);
        last = tmp;
        tmp = last -> next;
        last -> next = tmp -> next;
        delete tmp;
        return data;
    }
}

template <typename T>
int CircularList<T>::search(T elem){
        BSTNode<T>* tmp = last -> next;
        int counter = 0;
        for(;tmp -> next != last -> next; tmp = tmp -> next){
            if(tmp -> data == elem){
                return counter;
            }
            counter++;
        }
        return -1;
}

template <typename T>
bool CircularList<T>::deleteElement(T elem){
    if(last == 0){
        return false;
    }
    if(last -> next == last){
        if(last -> data == elem){
            delete last;
            last = 0;
            return true;
        }
        return false;
    }
    else{
        BSTNode<T>* tmp = last;
        do{
            if(tmp -> next -> data == elem){
                BSTNode<T>* head = tmp->next;
                tmp->next = head->next;
                delete head;
                return true;
            }
            tmp = tmp -> next;
        }while(tmp -> next != last -> next);
        return false;
    }
}

template <typename T>
void CircularList<T>::print(){
    if(last == 0)
        return;
    BSTNode<T>* tmp = last -> next;
    do{
        std::cout << tmp -> data << ", ";
        tmp = tmp -> next;
    }while(tmp != last -> next);
    std::cout << "\n";
    
}

template <typename T>
void CircularList<T>::reverse(){
    CircularList<T>* l1 = new CircularList<int>();
    l1 -> last = last;
    last = NULL;
    while(!l1->isEmpty()){
        insertAsHead(l1->deleteHead());
    }
    delete l1;
}

template <typename T>
CircularList<T>::~CircularList(){
    delete last;
}