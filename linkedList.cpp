//
// Created by stein on 10/30/2019.
//
#include <iostream>
#include "Node.h"
#include "linkedList.h"
using namespace std;

linkedList::linkedList(){   //default constructor
    Node(0, nullptr);
}



linkedList::~linkedList() {     //destructor
    cout<<"Destructor called"<<endl;
    Node* current = head;
    while( current != 0 ) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = 0;
}

void linkedList::printList() {  //Prints linked list
    Node * current = head;
    if(current == nullptr){     //Outputs if there is no linked list
        cout<<"No list linked list"<<endl;
    }
    else{
        cout<<"Sorted Linked List:"<<endl;
        while ( current != nullptr ){   //Outputs each value in the list
            cout << current->value <<endl;
            current = current -> next ;
        }
    }
}

linkedList::linkedList(const linkedList& left){     //copy constructor used for deep copy
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

linkedList& linkedList::operator= ( linkedList& rhs) {     //copy assignment operator used for deep copy
    cout << "assignment operator called" << endl;
    linkedList temp(rhs); // copy constructor temp
    swap(head, rhs.head); //built-in swap
    return *this;
}

void linkedList::Append(int nNode){     //creates/inserts value into linked list
    if(head == nullptr){    //creates the first node in a list if it doesnt exist
        head = new Node(nNode);
    }
    else{   //creates and connects new node to list
        Node* current = head;
        while(current->next != nullptr){
            current = current->next;
        }
        current->next = new Node(nNode);

    }
}


void linkedList::insertionSort() {      //sorts linked list

    Node *temp = head;      //Create a temporary value
    Node *lead = head->next;    //Create lead value
    Node *trail = head;     //Create trail value to follow lead value

    if (head == nullptr ) {     //outputs notifies user if there is no list
       cout<< "No List"<< endl;
       return;
    }
    if(head->next == nullptr){      //Notifies user if there is only one value in list
        cout<<"Only one value in list"<<endl;
        return;
    }
    while (lead != nullptr) {       //loops until the end of the list is reached
        if (lead->value > trail->value) {   //moves to next values if they are in the right order
            lead = lead->next;
            trail= trail->next;
        } else {        //Removes node in wrong position from linked list
            if (lead->value < head->value) {
                trail->next = lead->next;
                lead->next = head;
                head = lead;
            } else {
                temp = head;
                while (temp->next->value < lead->value && temp != nullptr ) {   // moves through list and reinserts node into the correct position
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