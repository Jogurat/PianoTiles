
#include <iostream>
#include "helperfuns.h"
#include "Duration.h"
#include "Measure.h"
#include "Note.h"
#include "Part.h"
#include "Composition.h"
int main(int argc, char *argv[]) {

	std::string filePath = argv[1];
	std::map<char, std::pair<std::string, int>> noteMap; //mapa sa stringom (karakter koji predstavlja notu), 
																//i par -> string (sama nota), int (midi vrednost), iz map.csv
	noteMap = createInputMap(filePath); //f-ja iz helperfuns.h
	Duration d1(1, 2);
	Duration d2(1, 4);
	Duration d3;
	Note n(d1, "C#4", 30);
	Note m(d1, "C1", 32);
	Note k(d2, "D2", 25);
	Note p(d1, "D#3", 33);

	Measure takt(d1);
	Measure takt2(d1);
	Part p1;
	Composition::setNoteMap(&noteMap);
	Composition c1(d1);
	c1.readInputFile("test.txt");
	/*takt.addSymbol(&n);
	takt.addSymbol(&m);
	takt2.addSymbol(&k);
	takt2.addSymbol(&p);
	p1.addMeasure(takt);
	p1.addMeasure(takt2);*/
	//takt.goThrough();
	//std::cout << takt;
	//p1.goThrough();
	system("pause");
	return 0;
}