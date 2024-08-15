#ifndef LISTNODE_H
#define LISTNODE_H

#include <string>
using namespace std;

class ListNode {
public:
    string lastName;
    string firstName;
    string address;
    int zipCode;
    int phoneNum;
    ListNode* nextNode;

    ListNode(string in_LastName, string in_FirstName, string in_Address, int in_ZipCode, int in_PhoneNum, ListNode* address_node = nullptr);

    // setter methods
    void setLastName(string up_LastName);
    void setFirstName(string up_FirstName);
    void setAddress(string up_Address);
    void setZipCode(int up_ZipCode);
    void setPhoneNum(int up_PhoneNum);
    void setNextNode(ListNode* next_address);

    // getter methods
    string getLastName();
    string getFirstName();
    string getAddress();
    int getZipCode();
    int getPhoneNum();
    ListNode* getNextNode();
};

#endif