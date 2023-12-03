#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

class day2 {
public:
	day2();
	int calculate();
	int getGameID(std::string line);
	bool isValidGame(std::string line);
};