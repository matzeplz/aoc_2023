#include "day2.hpp"
#include <regex>

day2::day2() {};

int day2::calculate()
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

	std::regex redpattern("[0-9]+ red");
	std::smatch redmatch;
	if (std::regex_search(line, redmatch, redpattern))
	{
		for (std::sregex_iterator i = std::sregex_iterator(line.begin(), line.end(), redpattern); i!= std::sregex_iterator(); ++i)
		{
			redmatch = *i;
			std::string redstring = redmatch.str();
			redstring = redstring.replace(redstring.find("red"), 3, "");
			int rednum = std::stoi(redstring);
			if (rednum > maxred)
				return false;
		}
	}

	std::regex greenpattern("[0-9]+ green");
	std::smatch greenmatch;
	if (std::regex_search(line, greenmatch, greenpattern))
	{
		for (std::sregex_iterator i = std::sregex_iterator(line.begin(), line.end(), greenpattern); i != std::sregex_iterator(); ++i)
		{
			greenmatch = *i;
			std::string greenstring = greenmatch.str();
			greenstring = greenstring.replace(greenstring.find("green"), 5, "");
			int greennum = std::stoi(greenstring);
			if (greennum > maxgreen)
				return false;
		}
	}

	std::regex bluepattern("[0-9]+ blue");
	std::smatch bluematch;
	if (std::regex_search(line, bluematch, bluepattern))
	{
		for (std::sregex_iterator i = std::sregex_iterator(line.begin(), line.end(), bluepattern); i != std::sregex_iterator(); ++i)
		{
			bluematch = *i;
			std::string bluestring = bluematch.str();
			bluestring = bluestring.replace(bluestring.find("blue"), 4, "");
			int bluenum = std::stoi(bluestring);
			if (bluenum > maxblue)
				return false;
		}
	}
	return true;
}