/* This is the main source cpp file for the project, we will run this 
Team: Creative Minds
Team Members: Pratyush Srivastava | Joseph Obeghe | Trudy-Ann Campbell | Esther Odesanya
Project: Wealth Watch - Personal Financial Tracker
*/

// WealthWatch.cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include "UserData.h"

struct Node {
    UserTile data;
    Node* next;
};

void writeListToCsv(Node* head, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Error: could not open file for writing" << std::endl;
        return;
    }

    outFile << "EntryName,EntryDate,EntryValue,Tag" << std::endl;

    Node* current = head;
    while (current != nullptr) {
        outFile << current->data.EntryName << ","
            << current->data.EntryDate << ","
            << current->data.EntryValue << ","
            << current->data.EntryTag << std::endl;
        current = current->next;
    }
    outFile.close();
}
Node* readListFromCsv(const std::string& filename) {
    Node* head = nullptr;

    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "Error: could not open file for reading" << std::endl;
        return head;
    }

    std::string line;
    std::getline(inFile, line); // Ignore header row
    while (std::getline(inFile, line)) {
        std::istringstream ss(line);
        std::string entryName, entryDate, entryValue, entryTag;
        std::getline(ss, entryName, ',');
        std::getline(ss, entryDate, ',');
        std::getline(ss, entryValue, ',');
        std::getline(ss, entryTag, ',');

        UserTile data;
        data.EntryName = entryName;
        data.EntryDate = entryDate;
        data.EntryValue = std::stof(entryValue);
        data.EntryTag = entryTag;

        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    inFile.close();
    return head;
}

void deleteEntry(Node*& head, const std::string& name) {
    Node* current = head;
    Node* previous = nullptr;
    while (current != nullptr) {
        if (current->data.EntryName == name) {
            if (previous == nullptr) {
                // The entry to delete is the first one in the list
                head = current->next;
                delete current;
            }
            else {
                // The entry to delete is not the first one in the list
                previous->next = current->next;
                delete current;
            }

            std::cout << "Entry deleted successfully!" << std::endl;
            return;
        }

        previous = current;
        current = current->next;
    }
}

void printList(Node* head) {
    std::cout << "Entry Name\tEntry Date\tEntry Value\tEntry Tag" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;


    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data.EntryName << "\t"
            << current->data.EntryDate << "\t"
            << current->data.EntryValue << "\t"
            << current->data.EntryTag << std::endl;
        current = current->next;
    }
}

int main() {
    std::cout << "Wealth Watch - Personal Financial Tracker"<<std::endl;
    std::cout << "Creative Minds" << std::endl;
    std::cout << "Members : Pratyush Srivastava | Joseph Obeghe | Trudy - Ann Campbell | Esther Odesanya"<<std::endl;
    std::string filename = "WWUserData.csv";
    std::cout << std::endl << "Reading from File: " << filename << std::endl<<std::endl;

    Node* head = readListFromCsv(filename);

    //UserData user;
    //std::cin >> user;
    //// std::ofstream file("WWUserData.txt"); //This is for the Text File
    //std::ofstream file("WWUserData.csv");   //This is for the CSV File
    //if (file.is_open()) {
    //    file << "Name: ," << user.getName() << std::endl;
    //    file << "Salary: ," << user.getSalary() << std::endl;
    //    std::cout << "User data stored in WWUserData.txt" << std::endl;
    //    file.close();
    //}
    //else {
    //    std::cerr << "Unable to open file" << std::endl;
    //    return 1;
    //}

 //   Node* head = nullptr;
    std::string input;
    do {
        std::cout << std::endl << "Menu:" << std::endl<<std::endl;
        std::cout << "1: Add new entry" << std::endl;
        std::cout << "2: Delete entry" << std::endl;
        std::cout << "3: Print table" << std::endl;
        std::cout << "4: Sort by (under development)" << std::endl;
        std::cout << "5: Exit" << std::endl << std::endl;
        std::cout << "Enter your choice: ";
        std::getline(std::cin, input);

        if (input == "1") {
            // Prompt the user for input and add new nodes to the linked list
            do {
                UserTile data;

                std::cout << "Enter the entry name: ";
                std::getline(std::cin, data.EntryName);

                std::cout << "Enter the entry date: ";
                std::getline(std::cin, data.EntryDate);

                std::cout << "Enter the entry value: ";
                std::string entryValue;
                std::getline(std::cin, entryValue);
                data.EntryValue = std::stof(entryValue);

                std::cout << "Enter the entry tag: ";
                std::getline(std::cin, data.EntryTag);

                Node* newNode = new Node;
                newNode->data = data;
                newNode->next = head;
                head = newNode;

                std::cout << "Entry added successfully!" << std::endl;
                std::cout << "Do you want to add another entry? (y/n) ";

                std::getline(std::cin, input);

                while (input != "y" && input != "Y" && input != "n" && input != "N") {
                    std::cout << "Invalid input. Please enter y or n: ";
                    std::getline(std::cin, input);
                }
            } while (input == "y" || input == "Y");

            if (input == "n" || input == "N") {
                std::cout << std::endl << "Returning to main menu..." << std::endl;
            }
        }
        else if (input == "2") {
            std::string nameToDelete;
            std::cout << "\nEnter Entry Name to delete: ";
            std::getline(std::cin, nameToDelete);
            deleteEntry(head,nameToDelete);

        }
        else if (input == "3") {
            // Print the linked list as a table
            printList(head);
        }
        else if (input == "4") {
            std::cout<<"This section is currently under development!"<<std::endl;
        }
        else if (input != "5") {
            // Invalid input
            std::cout << "Invalid input. Please enter 1, 2, 3, 4 or 5." << std::endl;
        }
    } while (input != "5");

    writeListToCsv(head, filename);
    //printList(head);
    // 
    // Free memory
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
