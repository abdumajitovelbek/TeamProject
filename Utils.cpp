#include "Utils.h"
#include <ctime>

std::string getCurrentDate() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    char buffer[11];
    strftime(buffer, 11, "%Y-%m-%d", ltm);
    return std::string(buffer);
}
