#include "UserData.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <Windows.h>

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
    HANDLE plConsole = GetStdHandle(STD_OUTPUT_HANDLE);
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
            SetConsoleTextAttribute(plConsole, 12);
            std::cout << "Entry deleted successfully!" << std::endl;
            return;
        }
        previous = current;
        current = current->next;
    }
}
void printList(Node* head) {
    HANDLE plConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(plConsole, 6);
    std::cout << "Entry Name\tEntry Date\tEntry Value\tEntry Tag" << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    SetConsoleTextAttribute(plConsole, 15);
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data.EntryName << "\t"
            << current->data.EntryDate << "\t"
            << current->data.EntryValue << "\t\t"
            << current->data.EntryTag << std::endl;
        current = current->next;
    }
}
void TotalSum(Node* head) {
    float total = 0;
    Node* current = head;
    while (current != nullptr) {
        total = total + current->data.EntryValue;
        current = current->next;
    }
    HANDLE plConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(plConsole, 11);
    std::cout << std::endl << "Total Value = ";
    SetConsoleTextAttribute(plConsole, 14);
    std::cout<<"$"<< total << std::endl;
}
Node* addEntry(Node* head) {
    UserTile data;
    HANDLE plConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(plConsole, 6);
    std::cout << std::endl << "Adding New Entry" << std::endl;
    SetConsoleTextAttribute(plConsole, 14);
    std::cout << "Enter the entry name: ";
    std::getline(std::cin, data.EntryName);

    std::cout << "Enter the entry date(m/dd/yyyy) : ";
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
    SetConsoleTextAttribute(plConsole, 2);
    std::cout << "Entry added successfully!" << std::endl << std::endl;
    SetConsoleTextAttribute(plConsole, 6);
    std::cout << "Do you want to add another entry? (y/n) ";

    std::string input;
    std::getline(std::cin, input);

    if (input == "y" || input == "Y") {
        system("CLS");
        std::cout << "Adding Another Entry. " << std::endl;
        head = addEntry(head);
    }
    else if (input == "n" || input == "N") {
        std::cout << std::endl << "Returning to main menu..." << std::endl;
    }

    return head;
}