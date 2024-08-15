#include "LinkedList.h"

// Constructor
LinkedList::LinkedList(string phoneBookName) {
    this->phonebook = phoneBookName;
    firstNode = lastNode = nullptr;
}

// insertAtFront method
void LinkedList::insertAtFront(string in_LastName, string in_FirstName, string in_Address, int in_ZipCode, int in_PhoneNum) {
    if (isEmpty()) {
        firstNode = lastNode = new ListNode(in_LastName, in_FirstName, in_Address, in_ZipCode, in_PhoneNum);
    } else {
        ListNode* newNode = new ListNode(in_LastName, in_FirstName, in_Address, in_ZipCode, in_PhoneNum);
        newNode->setNextNode(firstNode);
        firstNode = newNode;
    }
}

// removeFromFront method
ListNode* LinkedList::removeFromFront() {
    if (isEmpty()) {
        throw runtime_error(phonebook + " is empty");
    }

    ListNode* removedItem = firstNode;

    if (firstNode == lastNode) {
        firstNode = lastNode = nullptr;
    } else {
        firstNode = firstNode->getNextNode();
    }

    return removedItem;
}

// removeAtIndex method
ListNode* LinkedList::removeAtIndex(int index) {
    if (isEmpty()) {
        throw runtime_error(phonebook + " is empty");
    }

    if (index < 0) {
        throw invalid_argument("Index cannot be negative");
    }

    if (index == 0) {
        return removeFromFront();
    }

    ListNode* previous = nullptr;
    ListNode* current = firstNode;
    int currentIndex = 0;

    while (current != nullptr && currentIndex < index) {
        previous = current;
        current = current->getNextNode();
        currentIndex++;
    }

    if (current == nullptr) {
        throw out_of_range("Index " + to_string(index) + " is out of bounds");
    }

    if (current == lastNode) {
        lastNode = previous;
    }

    if (previous != nullptr) {
        previous->setNextNode(current->getNextNode());
    } else {
        firstNode = current->getNextNode();
    }

    return current;
}

// isEmpty method
bool LinkedList::isEmpty() {
    return firstNode == nullptr;
}

// print method
void LinkedList::print() {
    if (isEmpty()) {
        cout << "Empty " << phonebook << endl;
        return;
    }

    cout << "People in the " << phonebook << ":" << endl;
    ListNode* current = firstNode;

    while (current != nullptr) {
        cout << current->getLastName() << " " << current->getFirstName() << ", " 
             << current->getAddress() << ", " << current->getZipCode() << ", " 
             << current->getPhoneNum() << endl;
        current = current->getNextNode();
    }

    cout << endl;
}