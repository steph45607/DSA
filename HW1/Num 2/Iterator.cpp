#include <iostream>
#include <cassert>
#include "Iterator.h"
using namespace std;

template <class T>
Iterator<T>::Iterator()
{
    current = NULL;
}

template <class T>
Iterator<T>::Iterator(node<T> *ptr)
{
    current = ptr;
}

template <class T>
T Iterator<T>::operator*()
{
    return current->data;
}

template <class T>
Iterator<T> Iterator<T>::operator++()   
{
    current = current->link;

    return *this;
}

template <class T>
bool Iterator<T>::operator==(const Iterator<T>& right) const
{
    return (current == right.current);
}

template <class T>
bool Iterator<T>::operator!=(const Iterator<T>& right) const
{   
	return (current != right.current);
}
