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
    Node *current = head;
    if (current = nullptr) {
        cout << "Empty List" << endl;
    }
    else {
            cout<<"here";
            cout <<"current->value"<< endl;
            current = current->next;


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

/*void linkedList::insertionSort() {
    Node* leadValue = head->next;
    Node* trailValue = head;
    if(trailValue == nullptr){
        cout<<"No values in list."<<endl;
        return;
    }
    while(leadValue != nullptr){
        if(leadValue > trailValue){
            trailValue = leadValue;
            leadValue = leadValue->next;
        }
        else{
            trailValue = leadValue;
            leadValue = leadValue->next;

        }
    }

}*/

void linkedList::insertionSort() {
    Node *curr = head->next;      //creating the nodes used to traverse the linked list
    Node *prev = head;
    Node *check = head;
    if (head->next == nullptr || curr->next == nullptr) {   //checking to see if their are any values in the list or only 1 value in the list
        cout << "Not enough values in the list" << endl;  //if their are not enough values print this and return
        return;
    }
    while (curr != nullptr) {    //do this until curr reaches nullPtr
        if (curr->value > prev->value) {    //if the current value is greater then the prev value move curr and prev forward 1
            curr = curr->next;  //moving curr and prev forward in the list
            prev = prev->next;
        } else {         //do this if the values need to be rearranged
            if (head->value > curr->value) {      //if head's value is greater then curr's value
                prev->next = curr->next;      //sets prev's next equal to curr's next
                curr->next = head;     //sets curr's next equal to the head
                head = curr;            //sets curr's value equal to head
            } else {
                check = head;     //set check equal to head
                while (check != nullptr && check->next->value < curr->value) {   //while check dosn't reach the end of the list and checks next value is less then curr's value
                    check = check->next;   //iterate check through the list
                }
                prev->next = curr->next;     //when it reaches a value that must be swapped set prev's next equal to curr's next
                curr->next = check->next;     //set curr's next equal to check's next
                check->next = curr;              //set check's next equal to curr
            }
        }
        curr = prev->next;     //iterates curr
    }
}
