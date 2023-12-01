#include <iostream>
#include "node.h"



template <typename T>
class dLinkedList : public List<T>
{
    dNode<T> *head;
    dNode<T> *tail;

public:
    dLinkedList();

    void insertAsHead(T);
    void insertAsTail(T);

    T deleteHead();
    T deleteTail();
    bool deleteElement(T);

    void print();
    void reverse();

    int search(T);

    ~dLinkedList();
};
template <typename T>
dLinkedList<T>::dLinkedList()
{
    head = tail = 0;
}

template <typename T>
void dLinkedList<T>::insertAsHead(T data)
{
    if (head == 0)
    {
        tail = head = new dNode<T>(data, 0, 0);
    }
    else
    {
        head->previous = new dNode<T>(data, 0, head);
        head = head->previous;
    }
}

template <typename T>
void dLinkedList<T>::insertAsTail(T data)
{
    if (tail == 0)
    {
        tail = head = new dNode<T>(data, 0, 0);
    }
    else
    {
        tail->next = new dNode<T>(data, tail, 0);
        tail = tail->next;
    }
}

template <typename T>
T dLinkedList<T>::deleteHead()
{
    if (head == 0)
    {
        throw -1;
    }
    else if (head == tail)
    {
        T data = head->data;
        delete head;
        tail = head = 0;
        return data;
    }
    else
    {
        T data = head->data;
        head = head->next;
        delete head->previous;
        head->previous = 0;
        return data;
    }
}

template <typename T>
T dLinkedList<T>::deleteTail()
{
    if (tail == 0)
    {
        throw -1;
    }
    else if (head == tail)
    {
        int data = tail->data;
        delete tail;
        tail = head = 0;
        return data;
    }
    else
    {
        int data = tail->data;
        tail = tail->previous;
        delete tail->next;
        tail->next = 0;
        return data;
    }
}

template <typename T>
void dLinkedList<T>::print()
{
    dNode<T> *tmp = head;
    while (tmp != 0)
    {
        std::cout << tmp->data << ", ";
        tmp = tmp->next;
    }
    std::cout << "\n";
}

template <typename T>
void dLinkedList<T>::reverse()
{
    dNode<T> *tmp = head;
    dNode<T> *t;
    for (; tmp != 0; tmp = tmp->previous)
    {
        // a = a + b;
        // b = a + b - b = a;
        // a = a - b;

        t = tmp->next;
        tmp->next = tmp->previous;
        tmp->previous = t;
    }
    tmp = head;
    head = tail;
    tail = tmp;
}

template <typename T>
int dLinkedList<T>::search(T what){
    dNode<T>* tmp;
    int counter = 0;
    for(tmp=head;tmp != 0 && tmp -> data != what; tmp = tmp->next)
        ++counter;
    if(tmp == 0)
        counter = -1;
    return counter;
}

template <typename T>
bool dLinkedList<T>::deleteElement(T what){
    if(head == 0){
        throw -1;
    }
    else if(head == tail){
        if(head -> data == what){
            delete head;
            head = tail = 0;
            return true;
        }
        return false;
    }
    else{
        dNode<T> *tmp = head;
        for(;tmp->next !=0 && tmp->next->data != what; tmp = tmp->next);
        dNode<T> *del = tmp->next;
        tmp->next = del->next;
        delete del;
        return true;
    }
    return false;
}


template <typename T>
dLinkedList<T>::~dLinkedList(){
    if(tail != 0)
        delete tail;
    
    if(head != 0)
        delete head;
}