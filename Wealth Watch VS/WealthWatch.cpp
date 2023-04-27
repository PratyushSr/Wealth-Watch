/* This is the main source cpp file for the project, we will run this 
Team: Creative Minds
Team Members: Pratyush Srivastava | Joseph Obeghe | Trudy-Ann Campbell | Esther Odesanya
Project: Wealth Watch - Personal Financial Tracker
*/

// WealthWatch.cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <windows.h>
#include "UserData.h"
#include "Sorting.h"

//The Console Calls and handles for User UI Colors were also learned from w3school's c++ tutorials
int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << "Wealth Watch: ";
    SetConsoleTextAttribute(hConsole, 14);
    std::cout<<"Personal Financial Tracker"<<std::endl;
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << "Team: ";
    SetConsoleTextAttribute(hConsole, 14);
    std::cout<<"Creative Minds" << std::endl;
    SetConsoleTextAttribute(hConsole, 6);
    std::cout << "Members: ";
    SetConsoleTextAttribute(hConsole, 14);
    std::cout<<"Pratyush Srivastava | Joseph Obeghe | Trudy - Ann Campbell | Esther Odesanya"<<std::endl;
    std::string filename = "WWUserData.csv";
    SetConsoleTextAttribute(hConsole, 10);
    std::cout << std::endl << "Reading from File: ";
    SetConsoleTextAttribute(hConsole, 11); 
    std::cout << filename << std::endl << std::endl;
    Node* head = readListFromCsv(filename);

 // Node* head = nullptr; //for different initialization, incase we dont already have 
    std::string input;
    do {
        SetConsoleTextAttribute(hConsole, 13);
        std::cout << std::endl << "Menu:" << std::endl<<std::endl;
        SetConsoleTextAttribute(hConsole, 15);
        std::cout << "1: Add new entry" << std::endl;
        std::cout << "2: Delete entry" << std::endl;
        std::cout << "3: Print table" << std::endl;
        std::cout << "4: Sort by" << std::endl;
        std::cout << "5: Search Entry" << std::endl;
        std::cout << "6: Exit" << std::endl << std::endl;
        SetConsoleTextAttribute(hConsole, 10);
        std::cout << "Enter your choice: ";
        SetConsoleTextAttribute(hConsole, 15);
        std::getline(std::cin, input);

        if (input == "1") {
            // Prompt the user for input and add new nodes to the linked list
            head = addEntry(head);                
        }
        else if (input == "2") {
            system("CLS");
            // Search for an entry by EntryName then delete it.
            std::string nameToDelete;
            SetConsoleTextAttribute(hConsole, 4);
            std::cout << "\nEnter Entry Name to delete: ";
            SetConsoleTextAttribute(hConsole, 15);
            std::getline(std::cin, nameToDelete);
            deleteEntry(head,nameToDelete);
        }
        else if (input == "3") {
            system("CLS");
            // Print the linked list as a table
            printList(head);
            TotalSum(head);
        }
        else if (input == "4") {
            //goes to sorting.cpp
            sortList(head);
        }
        else if (input == "5") {
            system("CLS");
            std::cout << std::endl << "Enter Name you want to search" << std::endl;
            std::string s;
            std::getline(std::cin,s);
            searchList(head, s);
            std::cout << std::endl;
        }
    } while (input != "6");

    writeListToCsv(head, filename);

    SetConsoleTextAttribute(hConsole, 6);
    std::cout << std::endl << "Wealth Watch - Personal Financial Tracker Exited, Goodbye!" << std::endl;
    
    SetConsoleTextAttribute(hConsole, 10);
    std::cout << std::endl << "Data stored to: ";
    SetConsoleTextAttribute(hConsole, 11);
    std::cout << filename << std::endl << std::endl;
    SetConsoleTextAttribute(hConsole, 15);

    // Free memory
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
