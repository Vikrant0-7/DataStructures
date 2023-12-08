//
// Created by vicky on 08-12-2023.
//

#ifndef LAB_DOUBLE_ENDED_QUEUE_H
#define LAB_DOUBLE_ENDED_QUEUE_H

#include "../LinkedLists/doublyLinkedList.h"

// Notation
//                      D.E.Queue
//      ----------------------------------------
// Front End                                Rear End
//      ----------------------------------------


template<typename T>
class deQueue{
private:
    dLinkedList<T> list;
    int _size;

public:
    deQueue();

    void enqueue(T,bool=true);
    T dequeue(bool=false);

    bool isEmpty();
    int size();
};

/*!
 * @brief Returns number of elements in queue
 * @return int
 */

template<typename T>
int deQueue<T>::size() {
    return _size;
}

template<typename T>
bool deQueue<T>::isEmpty() {
    return _size == 0;
}

/*!
 * @brief Removes and returns element from given end.
 * @param pos 1/true: means rear end \n
 * 0/false means: front end \n
 * default 0; front end
 * @return Element from queue
 * @throws std::runtime_error when Queue is empty
 */
template<typename T>
T deQueue<T>::dequeue(bool pos) {
    if (isEmpty())
        throw std::runtime_error("Queue is Empty");
    if(pos == 1){//dequeue from rear end (not possible in regular Queues)
        --_size;
        return list.deleteTail();
    }
    --_size;
    return  list.deleteHead(); //dequeue from front end, same as regular queues.
}

template<typename T>
deQueue<T>::deQueue() {
    _size = 0;
}

/*!
 * @brief Adds given element to Queue.
 * @tparam T
 * @param data 1/true: means rear end \n
 * 0/false means: front end \n
 * default 1; rear end
 * @param pos
 */

template<typename T>
void deQueue<T>::enqueue(T data, bool pos) {
    //pos = 0 means insert in beginning and 1 means at ending
    if(pos == 0){ //enqueue in front end (not possible in regular queues).
        list.insertAsHead(data);
        _size++;
    }
    else{ //dequeue in rear end, same as regular queues.
        list.insertAsTail(data);
        _size++;
    }
}





#endif //LAB_DOUBLE_ENDED_QUEUE_H
