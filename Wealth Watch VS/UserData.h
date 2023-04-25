// UserData.h
#ifndef USER_DATA_H
#define USER_DATA_H

#include <string>
#include <iostream>

struct UserTile {
    std::string EntryName;
    std::string EntryDate;
    float EntryValue;
    std::string EntryTag;
};

struct Node {
    UserTile data;
    Node* next;
};

void writeListToCsv(Node* head, const std::string& filename);
Node* readListFromCsv(const std::string& filename);
void deleteEntry(Node*& head, const std::string& name);
void printList(Node* head);
Node* addEntry(Node* head);
void TotalSum(Node* head);

#endif
