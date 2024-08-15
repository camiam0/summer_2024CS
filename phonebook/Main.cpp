#include <iostream>
#include <string>
#include <limits>
#include "LinkedList.h"

using namespace std;

class Main {
private:
    LinkedList phonebook;
public:
    Main() : phonebook("Phonebook") {}
    void menu();
    void insertPerson();
    void removePerson();
    void displayPhonebook();
};

int main() {
    Main mainApp;
    mainApp.menu();
    return 0;
}

void Main::menu() {
    bool menuflag = false;
    char menuinput;

    do {
        cout << "Please type a command:\n"
             << "   \"a\" to add someone to the phonebook.\n"
             << "   \"r\" to remove someone from the phonebook.\n"
             << "   \"d\" to display phonebook.\n"
             << "   \"q\" to quit the program.\n";
        cin >> menuinput;

        switch (menuinput) {
        case 'a':
            insertPerson();
            break;
        case 'r':
            removePerson();
            break;
        case 'd':
            displayPhonebook();
            break;
        case 'q':
            cout << "Goodbye." << endl;
            menuflag = true;
            break;
        default:
            cout << "Invalid command. Please try again." << endl;
            break;
        }
    } while (!menuflag);
}

void Main::insertPerson() {
    string lastName, firstName, address;
    int zipCode, phoneNum;

    cout << "Enter last name: ";
    cin >> lastName;
    cout << "Enter first name: ";
    cin >> firstName;
    cout << "Enter address: ";
    cin >> address;

    cout << "Enter zip code: ";
    while (!(cin >> zipCode)) {
        cout << "Invalid input for zip code. Please enter a valid integer: ";
        cin.clear(); // Clear the error flag on cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the incorrect input
    }

    cout << "Enter phone number in format 1234567890: ";
    while (!(cin >> phoneNum)) {
        cout << "Invalid input for phone number. Please enter a valid integer: ";
        cin.clear(); // Clear the error flag on cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the incorrect input
    }

    phonebook.insertAtFront(lastName, firstName, address, zipCode, phoneNum);
}

void Main::removePerson() {
    int index;

    cout << "Enter index point for removal (entries are organized from newest to oldest, numbered starting at 0): ";
    cin >> index;

    phonebook.removeAtIndex(index);
}

void Main::displayPhonebook() {
    phonebook.print();
}