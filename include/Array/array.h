#include <iostream>

template <typename T>
class Array
{
    T *items; //actual pointer that stores array elements
    int size; //number of elements that array has
    int capacity; //number of elements that array can store

public:
    Array();
    Array(int size); //creates array of specific size
    void append(T i); //standard insertion
    void insert(int,T i); //inserts element in between
    void print(); //prints array

    T deleteFront(); //removes first element of array.
    T deleteLast(); //removes last element of array.
    T deleteElement(int); //remove element from given index.


    T max(); //return maximum of array
    T secondMax(); //returns second maximum of array
};

template <typename T>
Array<T>::Array()
{
    this->size = 0;
    capacity = 1;
    items = new T[capacity];
}

template <typename T>
Array<T>::Array(int size)
{
    this->size = size;
    capacity = 1;
    while (capacity < size) //gets appropriate capacity in terms to powers of 2
    {
        capacity *= 2;
    }
    items = new T[capacity];
}

template <typename T>
void Array<T>::append(T i)
{
    if (size == capacity) //is array is full
    {
        capacity *= 2; //increase capacity of array

        T *tmp = items; //store current array pointer to temporary variable
        items = new T[capacity]; //create new pointer with increased capacity
        for (int x = 0; x < size; ++x) //copy all elements from old pointer to new pointer
        {
            x[items] = x[tmp];
        }
        delete[] tmp; //delete old pointer
    }
    /*
    * as previous size of array is last index of array with size = size+1
    * size++ return size then increments it.
    * So i is assigned at index size, then size is incremented.
    */
    items[size++] = i;
}

template <typename T>
void Array<T>::insert(int idx, T i)
{
    if(idx < 0 || idx >= size){ //is supplied index is out of bound throw an error
        throw std::out_of_range("Index is out of bounds");
    }

    if (size == capacity) //increases capacity of array as done before
    {
        capacity *= 2;
        T *tmp = items;
        items = new T[capacity];
        for (int x = 0; x < size; ++x)
        {
            items[x + 1] = x[tmp];
        }
        delete[] tmp;
    }
    for (int x = size; x > idx; --x) //shifts all elements from index idx to index size - 1 to one step right
    {
        x[items] = items[x - 1]; //copies i - 1 element to ith index starting from size + 1 till idx
    }
    items[idx] = i;

    ++size;
}

template <typename T>
void Array<T>::print() //prints all elements of array, comma seperated
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << items[i] << ", ";
    }
    std::cout << std::endl;
}

template <typename T>
T Array<T>::deleteFront() // deletes first element of array and returns it.
{
    T tmp = items[0];
    --size;
    for (int i = 0; i < size; ++i)
    {
        items[i] = items[i + 1];
    }
    return tmp;
}

template <typename T>
T Array<T>::deleteLast() //deletes last element of array.
{
    return items[--size];
}

template <typename T>
T Array<T>::deleteElement(int idx) // deletes first element of array and returns it.
{
    if(idx < 0 || idx >= size)
        throw std::out_of_range("Index is out of bounds");

    T tmp = items[idx];
    --size;
    for (int i = idx; i < size; ++i)
    {
        items[i] = items[i + 1];
    }
    return tmp;
}

template <typename T>
T Array<T>::max() //return maximum element of list.
{
    T _max = items[0];
    for (int i = 1; i < this->size; ++i)
        if (items[i] > _max)
            _max = items[i];

    return _max;
}

template <typename T>
T Array<T>::secondMax() //returns 2nd maximum of array.
{
    T _max1 = std::max(items[0], items[1]);
    T _max2 = std::min(items[0], items[1]);

    for (int i = 2; i < this->size; ++i)
    {
        if (items[i] > _max1)
        {
            _max2 = _max1;
            _max1 = items[i];
        }
    }
    return _max2;
}
