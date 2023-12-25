#include <locale>
#include "reader.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "CarInfo.h"  

using namespace std;

int main() {
    setlocale(0, "");
    std::vector<CarInfo> carList;

    std::ifstream inputFile("D:\\avtomobili.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        exit(1);
    }

    try {
        readCarInfo(inputFile, carList);
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка при чтении CarInfo из файла: " << e.what() << std::endl;
        // Перехват исключения или обработка по необходимости
    }

    displayCarInfo(carList, std::cout);
    return 0;
}