#include <iostream>
#include <fstream>
#include <string>
#include <sstream>  // for istringstream
#include <algorithm> // for remove

using namespace std;

// Function prototypes
void intro();
int menu();
void CreateMadLib();
void ViewMadLib();

int main() {
    
    intro();
    menu();
    return 0;

}

void intro() {
    
    cout << "Welcome to the game of mad libs." << endl
         << "I will ask you to provide various words" << endl
         << "and phrases to fill a story." << endl
         << "The result will be written to an output file." << endl << endl;

} // end of intro

int menu() {
    
    bool menuFlag = false;
    int menuSelect = 0;

    cout << "Please make a selection:" << endl
         << "   \"1\" to create a mad lib." << endl
         << "   \"2\" to view a mad lib." << endl
         << "   \"3\" to quit the program." << endl;
    cin >> menuSelect;

    do {
    
    switch (menuSelect) {
        
        case 1:
            
            CreateMadLib();
            menuFlag = true;
            break;
        
        case 2:
            
            ViewMadLib();
            menuFlag = true;
            break;
        
        case 3:
            
            menuFlag = true;
            break;
        
        default:

            std::cout << "Invalid selection, please try again.\n";
            break;
    
    } // end of menu switch case

    } while (!menuFlag);
    
    return 0;

} // end of menu

void CreateMadLib() {
    
    // Input and output file paths
    cout << "Please enter name of input file: ";
    string inputFilePath;
    cin >> inputFilePath;
    cout << "Please enter name of output file: ";
    string outputFilePath;
    cin >> outputFilePath;

    ifstream inputFile(inputFilePath);
    ofstream outputFile(outputFilePath);

    if (!inputFile) {
        
        cerr << "Error: Input file not found." << endl
             << "Please make sure you enter the type of file after the file name (i.e., filename.txt)" << endl;
        
        return;
    
    } // end of if

    string line;
    while (getline(inputFile, line)) {
        
        istringstream scanLine(line);
        string token;
        while (scanLine >> token) {
            
            if (token[0] == '<') {
                
                token.erase(0, 1); // Remove the '<'
                token.erase(token.size() - 1, 1); // Remove the '>'
                token.erase(remove(token.begin(), token.end(), '-'), token.end()); // Remove '-'
                cout << "Please enter a " << token << ": ";
                string userWord;
                cin >> userWord;
                outputFile << userWord << " ";

            } else {outputFile << token << " ";} // end of if/else

        } // end of inner while
        
        outputFile << endl; // Write a new line after each line from the input file
    
    } // end of outer while

    cout << "File processing completed successfully." << endl;

    inputFile.close();
    outputFile.close();

} // end of create mad lib

void ViewMadLib() {
    
    cout << "Please enter the name of the file you want to view: ";
    string inputFilePath;
    cin >> inputFilePath;

    ifstream inputFile(inputFilePath);

    if (!inputFile) {
        
        cerr << "Error: Input file not found." << endl
             << "Please make sure you enter the correct file name." << endl;
        
        return;

    } // end of if

    string line;
    while (getline(inputFile, line)) {cout << line << endl;}

    inputFile.close();

} // end of view mad lib