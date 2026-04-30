#include "Profile.h"
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

string getCurrentDate() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    
    string date = to_string(1900 + ltm->tm_year) + "-" +
                  to_string(1 + ltm->tm_mon) + "-" +
                  to_string(ltm->tm_mday);

    return date;
}

void Profile::updateMeasurements(const string& userID) {
    cout << "Enter your weight (lbs): ";
    cin >> weight;
    cout << "Enter your height (inches): ";
    cin >> height;

    lastUpdateDate = getCurrentDate();

    ofstream outFile("Profile.csv", ios::app);
    if (outFile.is_open()) {
        outFile << userID << "," << age << "," << height << "," << weight << "," << "," << gender << lastUpdateDate << endl;
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