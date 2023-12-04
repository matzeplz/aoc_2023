#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

class day2 {
public:
	day2();
	int part1();
	int getGameID(std::string line);
	bool isValidGame(std::string line);
	int part2();
};