#include "Date.h"

string getCurrentDate() {
    time_t now = time(0);
    tm* ltm = localtime(&now);

    char buffer[20];
    strftime(buffer, sizeof(buffer), "%m/%d/%Y", ltm);

    return string(buffer);
}