
#include <iostream>
#include "helperfuns.h"
#include "Duration.h"
int main(int argc, char *argv[]) {

	std::string filePath = argv[1];
	std::map<std::string, std::pair<std::string, int>> noteMap; //mapa sa stringom (karakter koji predstavlja notu), 
																//i par -> string (sama nota), int (midi vrednost), iz map.csv
	noteMap = createInputMap(filePath); //f-ja iz helperfuns.h
	Duration d1(1, 4);
	Duration d2(1, 4);
	if (d1 > d2) {
		printf("manji su");
	}

	system("pause");
	return 0;
}