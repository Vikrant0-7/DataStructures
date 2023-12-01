#include "node.h"
#include <iostream>
using namespace std;



template<typename T>
class sLinkedList : public List<T>{
    private:
        Node<T> *head, *tail;
    public:

        sLinkedList();
        sLinkedList(sLinkedList &);

        void insertAsHead(T data);
        void insertAsTail(T data);

        Node<T>* getHead();
    
        T deleteHead();
        T deleteTail();
        bool deleteElement(T what);

        void print();
        
        void reverse();

        int search(T what);

        //class exclusive
        void concatenate(sLinkedList<T> &);

        ~sLinkedList();


};

template<typename T>
sLinkedList<T>::sLinkedList(sLinkedList &o) {
    head = new Node<T>(o.head->data);
    Node<T>* oTmp = o.head -> next;
    Node<T>* tmp = head;

    while(oTmp != NULL){
        tmp -> next = new Node(oTmp->data);
        tmp = tmp -> next;
        oTmp = oTmp -> next;
    }
}

template<typename T>
Node<T> *sLinkedList<T>::getHead() {
    return head;
}


template<typename T>
sLinkedList<T>::sLinkedList(){
    head = tail = NULL;
}

template<typename T>
void sLinkedList<T>::insertAsHead(T data){
    if(head == 0){
        head = tail = new Node<T>(data);
    }
    else{
        head = new Node<T>(data, head);
    }
}

template<typename T>
void sLinkedList<T>::insertAsTail(T data){
    if(tail == 0){
        head = tail = new Node<T>(data);
    }
    else{
        tail->next = new Node<T>(data);
        tail = tail->next;
        //tail = (tail->next = new Node(data));
    }
}

template<typename T>
T sLinkedList<T>::deleteHead(){
    if(head == 0){
        throw std::runtime_error("List has no head to delete");
    }
    else if (head == tail)
    {
        T data = head -> data;
        delete head;
        head = tail = 0;
        return data;
    }
    else{
        T data = head -> data;
        Node<T>* tmp = head;
        head = head->next;
        delete tmp;
        return data;
    }   
}

template<typename T>
T sLinkedList<T>::deleteTail(){
    if(tail == 0){
        throw std::runtime_error("No Tail found");
    }
    else if (head == tail)
    {
        T data = tail -> data;
        delete tail;
        head = tail = 0;
        return data;
    }
    else{
        T data = tail -> data;
        Node<T>* tmp = head;
        while(tmp -> next != tail){
            tmp = tmp -> next;
        }
        tmp -> next = 0;
        delete tail;
        tail = tmp;
        return data;
    } 
}

template<typename T>
void sLinkedList<T>::print(){
    Node<T>* tmp = head;
    while(tmp != 0){
        std::cout << tmp -> data << ", ";
        tmp = tmp-> next;
    }
    std::cout << std::endl;
}

template<typename T>
int sLinkedList<T>::search(T what){
    Node<T>* tmp;
    int counter = 0;
    for(tmp=head;tmp != 0 && tmp -> data != what; tmp = tmp->next)
        ++counter;
    if(tmp == 0)
        counter = -1;
    return counter;
}

template <typename T>
bool sLinkedList<T>::deleteElement(T what){
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
        Node<T> *tmp = head;
        for(;tmp->next !=0 && tmp->next->data != what; tmp = tmp->next);
        Node<T> *del = tmp->next;
        tmp->next = del->next;
        delete del;
        return true;
    }
    return false;
}

template <typename T>
void sLinkedList<T>::concatenate(sLinkedList<T> &l){
    tail -> next = l.head;
    tail = l.tail;
}

template <typename T>
void sLinkedList<T>::reverse(){
    Node<T>* t = head;
    sLinkedList<T>* l1 = new sLinkedList<T>();
    
    for(;t != 0;){
        l1->insertAsHead(t->data);
        Node<T>* tmp = t;
        t = t ->next;
        delete tmp;
    }

    head = l1->head;
    tail = l1->tail;
    delete l1;

}

template <typename T>
sLinkedList<T>::~sLinkedList(){
    if (tail != 0)
        delete tail;
    if(head != 0)
        delete head;
}
