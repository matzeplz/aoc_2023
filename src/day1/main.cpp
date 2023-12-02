#include "calibration_decipherer.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


int main()
{
	std::ifstream infile("calibrationinput.txt");
	std::string line;
	int solution = 0;
	int test = 0;
	while (std::getline(infile, line))
	{
		int a, b;
		bool firstnumber = true;
		for (int i=0; i<line.length(); i++)
		{
			if (isdigit(line[i]))
			{
				if (firstnumber)
				{
					a = line[i] - '0';
					b = a;
					firstnumber = false;
				}
				else
					b = line[i] - '0';
			}
		}
		std::string astring = std::to_string(a);
		std::string bstring = std::to_string(b);
		std::string x = astring + bstring;
		int number = std::stoi(x);
		solution += number;
	}
	std::cout << solution;
	return 0;
}