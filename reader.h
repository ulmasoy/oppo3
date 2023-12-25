#pragma once
#ifndef DATA_H
#define DATA_H

#include <vector>
#include <fstream>
#include "CarInfo.h"

// Объявление функций
void readCarInfo(std::istream& inputFile, std::vector<CarInfo>& carList);
void displayCarInfo(const std::vector<CarInfo>& carList, std::ostream& out);

#endif // DATA_H