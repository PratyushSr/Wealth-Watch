// sorting.cpp

#include "Sorting.h"  // Include the sorting header file
#include"UserData.h"

// Comparison functions for sorting
void sortByName(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    Node* i, * j;
    UserTile temp;
    for (i = head; i->next != nullptr; i = i->next) {
        for (j = i->next; j != nullptr; j = j->next) {
            if (i->data.EntryName > j->data.EntryName) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}
void sortByDate(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    Node* i, * j;
    UserTile temp;
    for (i = head; i->next != nullptr; i = i->next) {
        for (j = i->next; j != nullptr; j = j->next) {
            if (i->data.EntryDate > j->data.EntryDate) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}
void sortByValue(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    Node* i, * j;
    UserTile temp;
    for (i = head; i->next != nullptr; i = i->next) {
        for (j = i->next; j != nullptr; j = j->next) {
            if (i->data.EntryValue > j->data.EntryValue) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}
void sortByTag(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    Node* i, * j;
    UserTile temp;
    for (i = head; i->next != nullptr; i = i->next) {
        for (j = i->next; j != nullptr; j = j->next) {
            if (i->data.EntryTag > j->data.EntryTag) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}
void sortList(Node*& head) {
    int choice = 0;
    system("CLS");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 10);
    std::cout << "Sort by: " << std::endl; 
    SetConsoleTextAttribute(hConsole, 11);
    std::cout << "1. Entry Name" << std::endl;
    SetConsoleTextAttribute(hConsole, 12);
    std::cout << "2. Entry Date" << std::endl;
    SetConsoleTextAttribute(hConsole, 13);
    std::cout << "3. Entry Value" << std::endl;
    SetConsoleTextAttribute(hConsole, 14);
    std::cout << "4. Entry Tag" << std::endl << std::endl;;
    SetConsoleTextAttribute(hConsole, 10);
    std::cout << "Please select a sorting option: ";
    SetConsoleTextAttribute(hConsole, 15);
    std::cin >> choice;
    std::cout<<std::endl;

    switch (choice) {
    case 1:
        sortByName(head); 
        SetConsoleTextAttribute(hConsole, 11);
        std::cout << "List sorted by name!";
        break;
    case 2:
        sortByDate(head); SetConsoleTextAttribute(hConsole, 12);
        std::cout << "List sorted by Date!";
        break;
    case 3:
        sortByValue(head);SetConsoleTextAttribute(hConsole, 13);
        std::cout << "List sorted by Value!";
        break;
    case 4:
        sortByTag(head);SetConsoleTextAttribute(hConsole, 14);
        std::cout << "List sorted by Tag!";
        break;
    default:
        SetConsoleTextAttribute(hConsole, 14);
        std::cout << "Invalid choice" << std::endl;
        return;
    }
    std::cout << std::endl;
//    printList(head);
}
