#include "helperfuns.h"

std::map<std::string, std::pair<std::string, int>> createInputMap(std::string filePath) {

	std::string line;
	std::ifstream inputMap;
	std::regex lineRegex("([^,]*),([^,]*),([^,]*)");
	inputMap.open(filePath); //otvaranje map.csv
	std::map<std::string, std::pair<std::string, int>> noteMap;

	while (getline(inputMap, line)) {
		std::smatch result;
		if (regex_match(line, result, lineRegex)) {
			std::string inputChar = result.str(1);
			std::pair<std::string, int> inputPair;
			inputPair.first = result.str(2);
			inputPair.second = atoi(result.str(3).c_str());

			noteMap[inputChar] = inputPair;
		}
	}

	inputMap.close();
	return noteMap;
}

int commonDiv(int a, int b)
{
	double r;
	a = abs(a);
	b = abs(b);
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}
