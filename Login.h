//
// Created by thoma on 4/28/2026.
//

#ifndef BCS_230_TERM_PROJECT_LOGIN_H
#define BCS_230_TERM_PROJECT_LOGIN_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

// For the csv file storing user credentials it should follow these columns: userID,password,firstName,lastName,email,phone


class Login {
    private:
        string currentUserID;
        string currentPassword;

    public:
        bool login(string& userID);
        bool createAccount(string& userID);

    private:
        bool validateUser(const string& userID, const string& password);
        bool userExists(const string& userID);

        void addUserToFile(
            const string& userID,
            const string& password,
            const string& firstName,
            const string& lastName,
            const string& email,
            const string& phone
        );
};


#endif //BCS_230_TERM_PROJECT_LOGIN_H