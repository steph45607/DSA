#include <iostream>
#include "SLinkedList.h"
#include "SLinkedList.cpp"
using namespace std;

int main(){
    SLinkedList<int> arr;
    arr.push(3);
    arr.top();
    arr.push(5);
    arr.top();
    arr.push(6);
    arr.top();
    arr.pop();
    arr.top();
    arr.pop();
    arr.top();
    arr.pop();
}