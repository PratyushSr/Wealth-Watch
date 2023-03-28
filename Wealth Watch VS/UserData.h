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

class UserData {
public:
    UserData() : name(""), salary(0.0f) {}
    std::string getName() const { return name; }
    float getSalary() const { return salary; }
    friend std::istream& operator>>(std::istream& in, UserData& data);

private:
    std::string name;
    float salary;
};

#endif
