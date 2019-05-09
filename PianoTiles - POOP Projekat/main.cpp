
#include <iostream>
#include "helperfuns.h"
#include "Duration.h"
#include "Measure.h"
#include "Note.h"
int main(int argc, char *argv[]) {

	std::string filePath = argv[1];
	std::map<std::string, std::pair<std::string, int>> noteMap; //mapa sa stringom (karakter koji predstavlja notu), 
																//i par -> string (sama nota), int (midi vrednost), iz map.csv
	noteMap = createInputMap(filePath); //f-ja iz helperfuns.h
	Duration d1(1, 4);
	Duration d2(1, 4);
	Duration d3;
	Note n(d1, "C#4", 30);
	Note m(d1, "C1", 32);


	Measure takt(d1);

	takt.addSymbol(&n);
	takt.addSymbol(&m);
	takt.goThrough();
	system("pause");
	return 0;
}