//
// Created by thoma on 4/28/2026.
//

#ifndef BCS_230_TERM_PROJECT_LOGIN_H
#define BCS_230_TERM_PROJECT_LOGIN_H

#include <iostream>
#include <string>
using namespace std;

// For the csv file storing user credentials it should follow these columns: userID,password,firstName,lastName,email,phone


class Login{
    public:
        bool login(std::string& userID);
        bool createAccount(std::string& userID);

    private:
        bool validateUser(const std::string& userID, const std::string& password);
        bool userExists(const std::string& userID);

    void addUserToFile(
        const std::string& userID,
        const std::string& password,
        const std::string& firstName,
        const std::string& lastName,
        const std::string& email,
        const std::string& phone
    );

};

#endif //BCS_230_TERM_PROJECT_LOGIN_H