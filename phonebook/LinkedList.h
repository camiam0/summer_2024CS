#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
#include <stdexcept>
#include "ListNode.h"
using namespace std;

class LinkedList {
private:
    ListNode* firstNode;
    ListNode* lastNode;
    string phonebook;

public:
    LinkedList(string phoneBookName);
    void insertAtFront(string in_LastName, string in_FirstName, string in_Address, int in_ZipCode, int in_PhoneNum);
    ListNode* removeFromFront();
    ListNode* removeAtIndex(int index);
    bool isEmpty();
    void print();
};

#endif