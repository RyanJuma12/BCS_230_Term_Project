#include "Date.h"

string getCurrentDate() {
    time_t now = time(0);
    char* dt = ctime(&now);
    return dt;
}