#ifndef H_ITERATOR
#define H_ITERATOR
#include "Node.h"

template <class T>
class Iterator
{
private:
    node<T> *current; //pointer to point to the current node in the linked list
    
public:
    //Default constructor
    //Postcondition: current = NULL;
    Iterator();

    //Constructor with a parameter.
    //Postcondition: current = ptr;
    Iterator(node<T> *ptr);

    //Function to overload the dereferencing operator *.
    //Postcondition: Returns the info contained in the node.
    T operator*();

    //Overload the preincrement operator.
    //Postcondition: The iterator is advanced to the next node.
    Iterator<T> operator++();    

    //Overload the equality operator.
    //Postcondition: Returns true if this iterator is equal to 
    //    the iterator specified by right, otherwise it returns
    //    false.
    bool operator==(const Iterator<T>& right) const;

    //Overload the not equal to operator.
    //Postcondition: Returns true if this iterator is not equal to
    //    the iterator specified by right, otherwise it returns
    //    false.
    bool operator!=(const Iterator<T>& right) const;

};

#include "Iterator.cpp"

#endif
