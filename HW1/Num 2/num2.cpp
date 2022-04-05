#include <iostream>
#include "SLinkedList.h"
#include "SLinkedList.cpp"
using namespace std;

int main(){
    SLinkedList<int> arr;
    arr.insertFirst(3);
    arr.insertLast(35);
    arr.insertLast(5);
    arr.print();
    arr.ReversePrintRecursive();
    arr.ReversePrintIterative();
}