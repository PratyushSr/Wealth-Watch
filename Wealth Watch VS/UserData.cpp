// UserData.cpp
#include "UserData.h"

std::istream& operator>>(std::istream& in, UserData& data) {
    std::cout << "Enter your name: ";
    std::getline(in, data.name);

    std::cout << "Enter your salary: ";
    in >> data.salary;

    return in;
}
