// sorting.h

#ifndef SORTING_H
#define SORTING_H

#include "UserData.h"  // Include the UserTile struct definition
#include <Windows.h>

void sortByName(Node* head);
void sortByDate(Node* head);
void sortByValue(Node* head);
void sortByTag(Node* head);
void sortList(Node*& head);

#endif // SORTING_H
