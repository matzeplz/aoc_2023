#include "day2.hpp"
#include <regex>

day2::day2() {};

int day2::part1()
{
	int solution = 0;
	std::ifstream inputstream("calibrationinputday2.txt");
	std::string line;

	while (std::getline(inputstream, line))
	{
		int currentgameID = getGameID(line);
		if (isValidGame(line))
			solution += currentgameID;
	}
	return solution;
}

int day2::getGameID(std::string line)
{
	std::regex pattern("Game [0-9]+");
	std::smatch match;
	if (std::regex_search(line, match, pattern))
	{
		std::string GameIDstring = match.str();
		GameIDstring = GameIDstring.replace(GameIDstring.find("Game"), 5, "");
		int GameID = std::stoi(GameIDstring);
		return GameID;
	}
	return 0;
}

bool day2::isValidGame(std::string line)
{
	int maxred = 12;
	int maxgreen = 13;
	int maxblue = 14;
	int maxvaluearray[3] = { maxred, maxgreen, maxblue };

	std::regex redpattern("[0-9]+ red");
	std::smatch redmatch;
	std::regex greenpattern("[0-9]+ green");
	std::smatch greenmatch;
	std::regex bluepattern("[0-9]+ blue");
	std::smatch bluematch;

	std::regex patternarray[3] = { redpattern, greenpattern, bluepattern };
	std::smatch matcharray[3] = { redmatch, greenmatch, bluematch };

	for (int n = 0; n < 3; n++)
	{
		for (std::sregex_iterator i = std::sregex_iterator(line.begin(), line.end(), patternarray[n]); i != std::sregex_iterator(); ++i)
		{
			std::smatch match = *i;
			std::string matchstring = match.str();
			int cutint;
			std::string cutstring;
			switch (n)
			{
			case 0:
				cutint = 3;
				cutstring = "red";
				break;
			case 1:
				cutint = 5;
				cutstring = "green";
				break;
			case 2:
				cutint = 4;
				cutstring = "blue";
				break;
			}
			matchstring = matchstring.replace(matchstring.find(cutstring), cutint, "");
			int matchnum = std::stoi(matchstring);
			if (matchnum > maxvaluearray[n])
				return false;
		}
	}
	return true;
}

int day2::part2()
{
	int solution = 0;
	std::ifstream inputstream("calibrationinputday2.txt");
	std::string line;

	while (std::getline(inputstream, line))
	{
		int redvalue = 0;
		int greenvalue = 0;
		int bluevalue = 0;
		int valuearray[3] = { redvalue, greenvalue, bluevalue };

		std::regex redpattern("[0-9]+ red");
		std::smatch redmatch;
		std::regex greenpattern("[0-9]+ green");
		std::smatch greenmatch;
		std::regex bluepattern("[0-9]+ blue");
		std::smatch bluematch;

		std::regex patternarray[3] = { redpattern, greenpattern, bluepattern };
		std::smatch matcharray[3] = { redmatch, greenmatch, bluematch };

		for (int n = 0; n < 3; n++)
		{
			for (std::sregex_iterator i = std::sregex_iterator(line.begin(), line.end(), patternarray[n]); i != std::sregex_iterator(); ++i)
			{
				std::smatch match = *i;
				std::string matchstring = match.str();
				int cutint;
				std::string cutstring;
				switch (n)
				{
				case 0:
					cutint = 3;
					cutstring = "red";
					break;
				case 1:
					cutint = 5;
					cutstring = "green";
					break;
				case 2:
					cutint = 4;
					cutstring = "blue";
					break;
				}
				matchstring = matchstring.replace(matchstring.find(cutstring), cutint, "");
				int matchnum = std::stoi(matchstring);
				if (matchnum > valuearray[n])
					valuearray[n] = matchnum;
			}

		}
		int minset = valuearray[0] * valuearray[1] * valuearray[2];
		solution += minset;
	}
	return solution;
}