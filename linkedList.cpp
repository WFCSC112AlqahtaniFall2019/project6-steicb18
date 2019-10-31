//
// Created by stein on 10/30/2019.
//
#include <iostream>
#include "Node.h"
#include "linkedList.h"
using namespace std;

linkedList::linkedList(){
    Node(0, nullptr);
}



linkedList::~linkedList() {
    cout<<"Destructor called"<<endl;
    Node* current = head;
    while( current != 0 ) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = 0;
}

void linkedList::printList() {
    Node * current = head;
    if(current == nullptr){
        cout<<"No list"<<endl;
    }
    while ( current != nullptr ){
        cout << current->value << " ";
        current = current -> next ;
    }
}

linkedList::linkedList(const linkedList& left){ //copy constructor
    this->head = new Node(left.head->value, nullptr);
    Node* newCurrent = head->next;
    Node* current = left.head->next;
    Node* New = left.head;
    while(current->next!=nullptr) {
        newCurrent = new Node(current->value, nullptr);
        current = current->next;
        newCurrent = newCurrent->next;
    }
}

linkedList& linkedList::operator= ( linkedList& rhs) {
    cout << "assignment operator called" << endl;
    linkedList temp(rhs); // copy constructor temp
    swap(head, rhs.head); //built-in swap
    return *this;
}

void linkedList::Append(int nNode){
    if(head == nullptr){
        head = new Node(nNode);
    }
    else{
        Node* current = head;
        while(current->next != nullptr){
            current = current->next;
        }
        current->next = new Node(nNode);

    }
}


void linkedList::insertionSort() {

    Node *temp = head;
    Node *lead = head->next;
    Node *trail = head;

    if (head == nullptr ) {
        cout<< "No List"<< endl;
        return;
    }
    if(head->next = nullptr){
        cout<<"Only one value in list"<<endl;
    }
    while (lead != nullptr) {
        if (lead->value > trail->value) {
            trail= trail->next;
            lead = lead->next;
        } else {
            if (lead->value < head->value) {
                trail->next = lead->next;
                lead->next = head;
                head = lead;
            } else {
                temp = head;
                while (temp->next->value < lead->value && temp != nullptr ) {
                    temp = temp->next;
                }
                trail->next = lead->next;
                lead->next = temp->next;
                temp->next = lead;
            }
        }
        lead = trail->next;
    }
}