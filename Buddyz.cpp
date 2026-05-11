#include "Buddyz.h"
#include "Date.h"
#include "ConsoleColors.h"

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <sstream>
using namespace std;

bool Buddyz::login(string& userID) {
    string password;
    int attempts = 0;

    while (attempts < 3) {
        setColor(CYAN);
        cout << "Enter User ID: ";
        setColor(WHITE);
        cin >> userID;

        setColor(CYAN);
        cout << "Enter Password: ";
        setColor(WHITE);
        cin >> password;
        cout << endl;

        if (validateUser(userID, password)) {
            setColor(GREEN);
            cout << "Login successful!\n";
            setColor(WHITE);
            return true;
        }

        attempts++;
        setColor(RED);
        cout << "Invalid credentials.\n";
        cout << "Attempts remaining: " << (3 - attempts) << "\n";
        setColor(WHITE);
    }

    setColor(RED);
    cout << "Too many failed attempts. Exiting...\n";
    setColor(WHITE);

    setColor(CYAN);
    cout << "Press ENTER to continue...";
    cin.ignore();
    cin.get();

    return false;
}

bool Buddyz::createAccount(string& userID) {
    string password, firstName, lastName, email, phone, dateCreated, caloricGoal;

    setColor(CYAN); 
    cout << "Enter New User ID: ";
    setColor(WHITE);
    cin >> userID;

    if (userExists(userID)) {
        setColor(RED);
        cout << "User already exists.\n";
        return false;
    }

    setColor(CYAN);
    cout << "Enter Password: ";
    setColor(WHITE);
    cin >> password;

    setColor(CYAN);
    cout << "Enter First Name: ";
    setColor(WHITE);
    cin >> firstName;

    setColor(CYAN);
    cout << "Enter Last Name: ";
    setColor(WHITE);
    cin >> lastName;

    setColor(CYAN);
    cout << "Enter Email: ";
    setColor(WHITE);

    while (true) {
    cin >> email;
        if (email.find('@') == string::npos || email.find('.') == string::npos) {
            setColor(RED);
            cout << "Invalid email format Email must contain @ and .\n";
            cout << "Reenter Email: ";
            setColor(WHITE);
        } else {
            break;
        }
    }   


    setColor(CYAN);
    cout << "Enter Phone Number (No Spaces or Hyphens): ";
    setColor(WHITE);
    
    while (true) {
    cin >> phone;
        if (phone.length() != 10) {

            setColor(RED);
            cout << "Invalid phone number format.\n";
            cout << "Reenter Phone Number: ";
            setColor(WHITE);
        }else {
            break;
        }
    }

    dateCreated = getCurrentDate();

    setColor(CYAN);
    cout << "Choose a Caloric Goal: \n"
         << "1. Maintain\n"
         << "2. Lose Weight\n"
         << "3. Gain Muscle\n";
    setColor(WHITE);
    cin >> caloricGoal;

    if (caloricGoal == "1") caloricGoal = "Maintain";
    else if (caloricGoal == "2") caloricGoal = "Lose Weight";
    else if (caloricGoal == "3") caloricGoal = "Gain Muscle";
    else caloricGoal = "Maintain";

    addUserToFile(userID, password, firstName, lastName, email, phone, dateCreated, caloricGoal);

    setColor(GREEN);
    cout << "Account created successfully!\n";
    return true;
}

bool Buddyz::validateUser(const string& userID, const string& password) {
    ifstream file("data/Users.csv");

    if (!file.is_open()) {
        setColor(RED);
        cout << "Error opening users file.\n";
        return false;
    }

    string line;

    while (getline(file, line)) {
        size_t p1 = line.find(',');
        size_t p2 = line.find(',', p1 + 1);

        string storedID = line.substr(0, p1);
        string storedPassword = line.substr(p1 + 1, p2 - p1 - 1);

        if (storedID == userID && storedPassword == password) {
            return true;
        }
    }

    return false;
}

bool Buddyz::userExists(const string& userID) {
    ifstream file("data/Users.csv");

    if (!file.is_open()) return false;

    string line;

    while (getline(file, line)) {
        string storedID = line.substr(0, line.find(','));
        if (storedID == userID) return true;
    }

    return false;
}

void Buddyz::addUserToFile(
    const string& userID,
    const string& password,
    const string& firstName,
    const string& lastName,
    const string& email,
    const string& phone,
    const string& dateCreated,
    const string& caloricGoal
) {
    ofstream outFile("data/Users.csv", ios::app);

    if (outFile.is_open()) {
        outFile << userID << "," << password << "," << firstName << "," << lastName << "," << email << "," << phone << "," << dateCreated << "," << caloricGoal << endl;

        outFile.close();
        setColor(GREEN);
        cout << "User account created successfully!" << endl;
    } 
    else {
        setColor(RED);
        cerr << "Error opening file for writing." << endl;
    }
}

void Buddyz::getUserName(const string& userID,
                        string& firstName,
                        string& lastName) {

    ifstream file("data/Users.csv");

    if (!file.is_open()) {
        return;
    }

    string line;

    while (getline(file, line)) {

        stringstream ss(line);

        string id;
        string password;
        string email;
        string phone;
        string signupDate;
        string caloricGoal;

        getline(ss, id, ',');
        getline(ss, password, ',');
        getline(ss, firstName, ',');
        getline(ss, lastName, ',');
        getline(ss, email, ',');
        getline(ss, phone, ',');
        getline(ss, signupDate, ',');
        getline(ss, caloricGoal, ',');

        if (id == userID) {
            return;
        }
    }
}