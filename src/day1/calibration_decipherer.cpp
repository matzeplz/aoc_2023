#include <fstream>
#include <sstream>
#include <string>
#include "calibration_decipherer.h"


void calibration_decipherer() {};

std::ostringstream deciphered_file() 
{
	std::ifstream infile("calibrationinput.txt");
	std::string line;
	std::ostringstream output;
	while (std::getline(infile, line))
	{
		std::istringstream tobedecipheredline(line);
		int a, b;
		bool firstnumber = true;
		char d;
		while (tobedecipheredline >> d)
		{
			if (isdigit(d))
			{
				if (firstnumber)
				{
					a = d;
					firstnumber = false;
				}
				else
					b = d;
			}
		}
		if (b == NULL)
			b = a;
		std::string astring = std::to_string(a);
		std::string bstring = std::to_string(b);
		std::string x = astring + bstring;
		output << x << std::endl;
	}
	return output;
};

int calculate_solution() 
{
	return 42;
};