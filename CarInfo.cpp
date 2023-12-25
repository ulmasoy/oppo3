#include "pch.h"
#include "CarInfo.h"
#include "Date.h"
#include <iostream>

// �������� ����������� �������, ����� static

void CarInfo::printCarInfo(std::ostream& out) const {
    out << "Date: ";
    date.print(out);
    out << ", Car number: " << carNumber << std::endl;
}
CarInfo CarInfo::readCarInfoFromFile(std::istream& inputFile) {
    CarInfo car;

    car.date = Date::create_from_stream(inputFile);
    inputFile >> car.carNumber;

    if (!car.isValid()) {
        throw std::runtime_error("�������� ������ CarInfo � �����.");
    }

    return car;
}

//CarInfo CarInfo::readCarInfoFromFile(std::istream& inputFile) {
//    CarInfo car;
//    car.date = Date::create_from_stream(inputFile);
//    inputFile >> car.carNumber;
//    return car;
//}
bool CarInfo::isValidCarNumber(const std::string& number) {
    if (number.length() != 6) {
        return false;
    }

    // ������ ������ - �����
    if (!std::isalpha(number[0])) {
        return false;
    }

    // ��������� 3 ������� - �����
    for (int i = 1; i <= 3; i++) {
        if (!std::isdigit(number[i])) {
            return false;
        }
    }

    // ��������� 2 ������� - �����
    if (!std::isalpha(number[4]) || !std::isalpha(number[5])) {
        return false;
    }

    return true;
}

bool CarInfo::isValid() const
{
    return date.isValid() && isValidCarNumber(carNumber);
}