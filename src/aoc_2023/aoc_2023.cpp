#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

//TODO: different approach to "replacewordswithnumber" so that it actually works

std::string replacewordswithnumbers(std::string line)
{
	std::string wordarray[9] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	std::string specialcase[7] = { "twone" , "oneight", "threeight", "fiveight" , "sevenine" , "nineight", "eighthree" };
	int numarray[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int specialnum[7] = { 21, 18, 38, 58, 79, 98, 83 };
	for (int n = 0; n < 7; n++)
		if (line.find(specialcase[n]) != std::string::npos)
			line.replace(line.find(specialcase[n]), specialcase[n].length(), std::to_string(specialnum[n]) + specialcase[n].back());
	for (int i = 0; i < 9; i++)
	{
		if (line.find(wordarray[i]) != std::string::npos)
			line.replace(line.find(wordarray[i]), wordarray[i].length(), std::to_string(numarray[i]) + wordarray[i].back());
	}
	return line;
}


int main()
{
	std::ifstream infile("calibrationinput.txt");
	std::string line;
	int solution = 0;
	while (std::getline(infile, line))
	{
		//line = replacewordswithnumbers(line);
		int a, b;
		bool firstnumber = true;
		for (int i = 0; i < line.length(); i++)
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