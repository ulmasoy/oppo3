#pragma once
#include "Date.h"

#include <fstream>
#include <string>

struct CarInfo {
    Date date;
    std::string carNumber;

    bool isValid() const;
    static bool isValidCarNumber(const std::string& number);

    static CarInfo readCarInfoFromFile(std::istream& inputFile);
    void printCarInfo(std::ostream& out) const;
};