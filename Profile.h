//
// Created on 4/27/2026.
//

#ifndef BCS_230_TERM_PROJECT_PROFILE_H
#define BCS_230_TERM_PROJECT_PROFILE_H

#include <iostream>
#include <string>
using namespace std;

class Profile {
    public:
        void createProfile();
        void updateProfile();
        void displayProfile();
    private:
        string fname;
        string lname;
        string email;
        string phone;
};


#endif //BCS_230_TERM_PROJECT_PROFILE_H