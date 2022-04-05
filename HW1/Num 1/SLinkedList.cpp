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
SLinkedList<T>::SLinkedList(const SLinkedList<T>& list)
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
void SLinkedList<T>::push(const T& item){
    struct node<T> *newNode;
    newNode = new node<T>;
    newNode -> data = item;
    newNode -> link = last;
    if(isEmpty()){
        first  = newNode;
        last = newNode;
    }
    else{
        last = newNode;
    }
}

template <class T>
void SLinkedList<T>::pop(){
    if(isEmpty()){
        cout << "Stack is empty" << endl;
    }
    else{
        cout << "Popped: " << last -> data << endl;
        last = last -> link;
    }
}

template <class T>
T SLinkedList<T>::top() const{
    if(isEmpty()){
        cout << "Stack is empty" << endl;
    }
    else{
        cout << "Data on top of the stack is: " << last -> data << endl;
    }
}