#include "Profile.h"
#include "Date.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

Profile::Profile() {
    weight = 0.0;
    height = 0.0;
    lastUpdateDate = "";
}



void Profile::updateMeasurements(const string& userID) {
    cout << "Enter your age (years): ";
    cin >> age;
    cout << "Enter your weight (lbs): ";
    cin >> weight;
    cout << "Enter your height (inches): ";
    cin >> height;

    gender = getGender(userID);
    lastUpdateDate = getCurrentDate();

    ofstream outFile("Profile.csv", ios::app);
    if (outFile.is_open()) {
        outFile << userID << "," << age << "," << height << "," << weight << "," << gender << "," << lastUpdateDate << endl;
        outFile.close();
        cout << "Profile updated successfully!" << endl;
    } else {
        cerr << "Error opening file for writing." << endl;
    }
}

void Profile::displayMeasurements(const string& userID) {
    ifstream 
inFile("Profile.csv");
    if (inFile.is_open()) {
        string line;
        bool found = false;
        while (getline(inFile, line)) {
            if (line.find(userID) == 0) {
                found = true;
                cout << "Profile for User ID: " << userID << endl;
                cout << "Weight: " << weight << " lbs" << endl;
                cout << "Height: " << height << " inches" << endl;
                cout << "Age: " << age << endl;
                cout << "Gender: " << gender << endl;
                cout << "Last Updated: " << lastUpdateDate << endl;
            }
        }
        if (!found) {
            cout << "Profile for User ID: " << userID << " not found." << endl;
        }
        inFile.close();
    } else {
        cerr << "Error opening file for reading." << endl;
    }
}

double Profile::getWeight(const string& userID) {
    return weight;
}

double Profile::getHeight(const string& userID) {
    return height;
}

int Profile::getAge(const string& userID) {
    return age;
}

string Profile::getGender(const string& userID) {
    return gender;
}

