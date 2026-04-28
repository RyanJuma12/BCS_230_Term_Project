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
        void updateMeasurements(const std::string& userID);
        void displayMeasurements(const std::string& userID);
};



#endif //BCS_230_TERM_PROJECT_PROFILE_H