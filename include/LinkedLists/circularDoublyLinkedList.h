#include <iostream>
#include "doublyLinkedList.h"

template <typename T>
class dCircularList : List<T>
{
private:
    dNode<T> *last;

public:
    dCircularList()
    {
        last = 0;
    }
    void insertAsHead(T);
    void insertAsTail(T);



    T deleteHead();
    T deleteTail();

    void print();
};

template <typename T>
void dCircularList<T>::insertAsHead(T data)
{
    if (last == NULL)
    {
        last = new dNode<T>(data, 0, 0);
        last->next = last->previous = last;
    }
    else
    {
        last->next = new dNode<T>(data, last, last->next);
    }
}

template <typename T>
void dCircularList<T>::insertAsTail(T data)
{
    if (last == NULL)
    {
        last = new dNode<T>(data, 0, 0);
        last->next = last->previous = last;
    }
    else
    {
        last->next = new dNode<T>(data, last, last->next);
        last = last->next;
    }
}

template <typename T>
void dCircularList<T>::print()
{
    if (last == 0)
        return;
    dNode<T> *tmp = last->next;
    do
    {
        std::cout << tmp->data << ", ";
        tmp = tmp->next;
    } while (tmp != last->next);
    std::cout << "\n";
}

template <typename T>
T dCircularList<T>::deleteHead()
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
        dNode<T> *head = last->next;
        last->next = head->next;
        delete head;
        return data;
    }
}

template <typename T>
T dCircularList<T>::deleteTail()
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
        T data = last->previous->data;
        dNode<T> *head = last->next;
        last = last->previous;
        delete last->next;
        last->next = head;
        return data;
    }
}