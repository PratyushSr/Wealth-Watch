/* This is the main source cpp file for the project, we will run this 
Team: Creative Minds
Team Members: Pratyush Srivastava | Joseph Obeghe | Trudy-Ann Campbell | Esther Odesanya
Project: Wealth Watch - Personal Financial Tracker
*/

// WealthWatch.cpp
#include <iostream>
#include <fstream>
#include "UserData.h"

int main() {
    UserData user;
    std::cin >> user;

    std::ofstream file("WWUserData.txt");
    if (file.is_open()) {
        file << "Name: " << user.getName() << std::endl;
        file << "Salary: " << user.getSalary() << std::endl;
        std::cout << "User data stored in WWUserData.txt" << std::endl;
        file.close();
    }
    else {
        std::cerr << "Unable to open file" << std::endl;
        return 1;
    }

    return 0;
}
