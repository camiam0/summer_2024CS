#include "ListNode.h"

// Constructor
ListNode::ListNode(string in_LastName, string in_FirstName, string in_Address, int in_ZipCode, int in_PhoneNum, ListNode* address_node) {
    this->lastName = in_LastName;
    this->firstName = in_FirstName;
    this->address = in_Address;
    this->zipCode = in_ZipCode;
    this->phoneNum = in_PhoneNum;
    this->nextNode = address_node;
}

// setter methods
void ListNode::setLastName(string up_LastName) { this->lastName = up_LastName; }
void ListNode::setFirstName(string up_FirstName) { this->firstName = up_FirstName; }
void ListNode::setAddress(string up_Address) { this->address = up_Address; }
void ListNode::setZipCode(int up_ZipCode) { this->zipCode = up_ZipCode; }
void ListNode::setPhoneNum(int up_PhoneNum) { this->phoneNum = up_PhoneNum; }
void ListNode::setNextNode(ListNode* next_address) { this->nextNode = next_address; }

// getter methods
string ListNode::getLastName() { return this->lastName; }
string ListNode::getFirstName() { return this->firstName; }
string ListNode::getAddress() { return this->address; }
int ListNode::getZipCode() { return this->zipCode; }
int ListNode::getPhoneNum() { return this->phoneNum; }
ListNode* ListNode::getNextNode() { return this->nextNode; }