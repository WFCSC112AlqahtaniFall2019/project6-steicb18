//
// Created by stein on 10/30/2019.
//
#include <iostream>
#include "Node.h"
using namespace std;

class linkedList{
public:
    linkedList();   //default constructor
    linkedList(const linkedList& list);   //copy constructor
    void printList();
    ~linkedList();
    void Append(int nNode);
    linkedList& operator= (linkedList& rhs);
    void insertionSort();
private:
    Node* head = nullptr;
};

#ifndef BINARYINSERTIONSORT_LINKEDLIST_H
#define BINARYINSERTIONSORT_LINKEDLIST_H

#endif //BINARYINSERTIONSORT_LINKEDLIST_H
