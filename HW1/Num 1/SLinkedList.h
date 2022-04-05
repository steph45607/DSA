#ifndef H_UNORDEREDLINKEDLIST
#define H_UNORDEREDLINKEDLIST

#include "Node.h"

template <class T>
class SLinkedList
{
private:
    node<T> *first; //pointer to the first node of the list
    node<T> *last;  //pointer to the last node of the list
    int count; 		//variable to store the number of list elements

    //Function to make a copy of otherList.
    //Postcondition: A copy of otherList is created and assigned
    //    to this list.
    void copy(const SLinkedList<T>& list); 

public:
	//default constructor
    //Initializes the list to an empty state.
    //Postcondition: first = NULL, last = NULL, count = 0; 
    SLinkedList(); 

    //copy constructor
    SLinkedList(const SLinkedList<T>& list); 

    //Overload the assignment operator.
    const SLinkedList<T>& operator=
                         (const SLinkedList<T>&);

    //destructor
    //Deletes all the nodes from the list.
    //Postcondition: The list object is destroyed. 
    ~SLinkedList();   

    //Function to determine whether the list is empty. 
    //Postcondition: Returns true if the list is empty, otherwise
    //    it returns false.
    bool isEmpty() const;

    void clear();
    void push(const T& item);
    void pop();
    T top() const;

};
#endif
