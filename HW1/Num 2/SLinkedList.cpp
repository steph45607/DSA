#include <iostream>
#include "SLinkedList.h"
using namespace std;

template <class T>
SLinkedList<T>::SLinkedList() //default constructor
{
    first = nullptr;
    last = nullptr;
    count = 0;
}

//overload the assignment operator
template <class T>
const SLinkedList<T>& SLinkedList<T>::operator=
                      (const SLinkedList<T>& list)
{ 
    if (this != &list) //avoid self-copy
    {
        copy(list);
    }//end else

     return *this; 
}



template <class T>
bool SLinkedList<T>::isEmpty() const
{
    return (first == nullptr);
}


template <class T>
void SLinkedList<T>::clear()
{
    node<T> *temp;   //pointer to deallocate the memory
                            //occupied by the node
    while (first != nullptr)   //while there are nodes in the list
    {
        temp = first;        //set temp to the current node
        first = first->link; //advance first to the next node
        delete temp;   //deallocate the memory occupied by temp
    }

    last = nullptr; //initialize last to NULL; first has already
                 //been set to NULL by the while loop
    count = 0;
}

template <class T>
void SLinkedList<T>::print() const
{
    node<T> *current; //pointer to traverse the list

    current = first;    //set current so that it points to 
                        //the first node
    while (current != nullptr) //while more data to print
    {
        cout << current->data << " ";
        current = current->link;
    }
}//end print

template <class T>
int SLinkedList<T>::length() const
{
    return count;
}  //end length

template <class T>
T SLinkedList<T>::front() const
{   
    assert(first != nullptr);

    return first->data; //return the data of the first node	
}//end front

template <class T>
T SLinkedList<T>::back() const
{   
    assert(last != nullptr);

    return last->data; //return the data of the last node	
}//end back


template <class T>
void SLinkedList<T>::insertFirst(const T& item)
{
    node<T> *newNode; //pointer to create the new node

    newNode = new node<T>; //create the new node

    newNode->data = item;    //store the new item in the node
    newNode->link = first;      //insert newNode before first
    first = newNode;            //make first point to the
                                //actual first node
    count++;                    //increment count

    if (last == nullptr)   //if the list was empty, newNode is also 
                        //the last node in the list
        last = newNode;
}//end insertFirst

template <class T>
void SLinkedList<T>::insertLast(const T& item)
{
    node<T> *newNode; //pointer to create the new node

    newNode = new node<T>; //create the new node

    newNode->data = item;  //store the new item in the node
    newNode->link = nullptr;     //set the link field of newNode
                              //to NULL

    if (first == nullptr)  //if the list is empty, newNode is 
                        //both the first and last node
    {
        first = newNode;
        last = newNode;
        count++;        //increment count
    }
    else    //the list is not empty, insert newNode after last
    {
        last->link = newNode; //insert newNode after last
        last = newNode; //make last point to the actual 
                        //last node in the list
        count++;        //increment count
    }
}//end insertLast


template <class T>
void SLinkedList<T>::deleteNode(const T& item)
{
    node<T> *current; //pointer to traverse the list
    node<T> *trailCurrent; //pointer just before current
    bool found;

    if (first == nullptr)    //Case 1; the list is empty. 
        cout << "Cannot delete from an empty list."
             << endl;
    else
    {
        if (first->data == item) //Case 2 
        {
            current = first;
            first = first->link;
            count--;
            if (first == nullptr)    //the list has only one node
                last = nullptr;
            delete current;
        }
        else //search the list for the node with the given data
        {
            found = false;
            trailCurrent = first;  //set trailCurrent to point
                                   //to the first node
            current = first->link; //set current to point to 
                                   //the second node

            while (current != nullptr && !found)
            {
                if (current->data != item) 
                {
                    trailCurrent = current;
                    current = current-> link;
                }
                else
                    found = true;
            }//end while

            if (found) //Case 3; if found, delete the node
            {
                trailCurrent->link = current->link;
                count--;

                if (last == current)   //node to be deleted 
                                       //was the last node
                    last = trailCurrent; //update the value 
                                         //of last
                delete current;  //delete the node from the list
            }
            else
                cout << "The item to be deleted is not in "
                     << "the list." << endl;
        }//end else
    }//end else
}//end deleteNode

template <class T>
bool SLinkedList<T>::search(const T& item) const
{
    node<T> *current; //pointer to traverse the list
    bool found = false;
    
    current = first; //set current to point to the first 
                     //node in the list

    while (current != nullptr && !found)    //search the list
        if (current->data == item) //searchItem is found
            found = true;
        else
            current = current->link; //make current point to
                                     //the next node
    return found; 
}//end search

template <class T>
SLinkedList<T>::~SLinkedList()
{
    node<T> *temp;   //pointer to deallocate the memory
                            //occupied by the node
    while (first != nullptr)   //while there are nodes in the list
    {
        temp = first;        //set temp to the current node
        first = first->link; //advance first to the next node
        delete temp;   //deallocate the memory occupied by temp
    }

    last = nullptr; //initialize last to NULL; first has already
                 //been set to NULL by the while loop
    count = 0;
	
	
}

template <class T>
Iterator<T> SLinkedList<T>::begin()
{
    Iterator<T> temp(first);

    return temp;
}

template <class T>
Iterator<T> SLinkedList<T>::end()
{
    Iterator<T> temp(nullptr);

    return temp;
}

template <class T>
SLinkedList<T>::SLinkedList
                      (const SLinkedList<T>& list)
{
   	first = nullptr;
    copy(list);
}//end copy constructor

template <class T>
void SLinkedList<T>::copy(const SLinkedList<T>& list) 
{
    node<T> *newNode; //pointer to create a node
    node<T> *current; //pointer to traverse the list

    if (first != nullptr) //if the list is nonempty, make it empty
       clear();

    if (list.first == nullptr) //otherList is empty
    {
        first = nullptr;
        last = nullptr;
        count = 0;
    }
    else
    {
        current = list.first; //current points to the 
                                   //list to be copied
        count = list.count;

            //copy the first node
        first = new node<T>;  //create the node

        first->data = current->data; //copy the data
        first->link = nullptr;        //set the link field of 
                                   //the node to NULL
        last = first;              //make last point to the
                                   //first node
        current = current->link;     //make current point to
                                     //the next node

           //copy the remaining list
        while (current != nullptr)
        {
            newNode = new node<T>;  //create a node
            newNode->data = current->data; //copy the data
            newNode->link = nullptr;       //set the link of 
                                        //newNode to NULL
            last->link = newNode;  //attach newNode after last
            last = newNode;        //make last point to
                                   //the actual last node
            current = current->link;   //make current point 
                                       //to the next node
        }//end while
    }//end else
}//end copyList

template <class T>
void SLinkedList<T>::ReversePrintRecursive(T* ptr){
    if(ptr != nullptr){
        T* current;
        current = ptr;
        ReversePrintRecursive(current -> link);
        cout << ptr -> data << endl;
    }
}
