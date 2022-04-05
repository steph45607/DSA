#ifndef H_UNORDEREDLINKEDLIST
#define H_UNORDEREDLINKEDLIST

#include "Node.h"
#include "Iterator.h"

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

    //Function to return the number of nodes in the list.
    //Postcondition: The value of count is returned.
    int length() const;

    //Function to return the first element of the list.
    //Precondition: The list must exist and must not be empty.
    //Postcondition: If the list is empty, the program terminates;
    //    otherwise, the first element of the list is returned.
    T front() const; 

    //Function to return the last element of the list.
    //Precondition: The list must exist and must not be empty.
    //Postcondition: If the list is empty, the program
    //               terminates; otherwise, the last  
    //               element of the list is returned.
    T back() const; 

    //Function to insert newItem at the beginning of the list.
    //Postcondition: first points to the new list, newItem is
    //    inserted at the beginning of the list, last points to
    //    the last node, and count is incremented by 1.
    void insertFirst(const T& item);

    //Function to insert newItem at the end of the list.
    //Postcondition: first points to the new list, newItem is
    //    inserted at the end of the list, last points to the
    //    last node, and count is incremented by 1.
    void insertLast(const T& item);

    //Function to delete deleteItem from the list.
    //Postcondition: If found, the node containing deleteItem
    //    is deleted from the list. first points to the first 
    //    node, last points to the last node of the updated 
    //    list, and count is decremented by 1.
    void deleteNode(const T& item);
	
    //Function to destroy or clear the linkedlist storage
	void clear();

    //Function to determine whether searchItem is in the list.
    //Postcondition: Returns true if searchItem is in the list,
    //    otherwise the value false is returned.
    bool search(const T& item) const;

    //Function to return an iterator at the beginning of the linked list.
    //Postcondition: Returns an iterator such that current is set to first.
    Iterator<T> begin();

    //Function to return an iterator one element past the last element of the linked list. 
    //Postcondition: Returns an iterator such that current is set to NULL.
    Iterator<T> end();

    //Function to output the data contained in each node.
    //Postcondition: none
    void print() const;

    void ReversePrintRecursive(T* ptr);
    void ReversePrintIterative(T* ptr);

};

#endif
