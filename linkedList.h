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
    void printList();       //print function
    ~linkedList();      //deconstructor
    void Append(int nNode);     //add nodes to list
    linkedList& operator= (linkedList& rhs);    //copy assignment
    void insertionSort();   //sort linked list
private:
    Node* head = nullptr;   //create head private value
};

#ifndef BINARYINSERTIONSORT_LINKEDLIST_H
#define BINARYINSERTIONSORT_LINKEDLIST_H

#endif //BINARYINSERTIONSORT_LINKEDLIST_H
