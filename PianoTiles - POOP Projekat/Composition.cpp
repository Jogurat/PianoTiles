#include "Composition.h"

std::map<char, std::pair<std::string, int>>*Composition::noteMap = nullptr;

void Composition::addSymbolLeft(MusicSymbol * m)
{
	_partLeft.addSymbol(m);
}

void Composition::addSymbolRight(MusicSymbol * m)
{
	_partRight.addSymbol(m);
}

Composition::Composition()
{
}

Composition::Composition(Duration d)
{
	_duration = d;
	_partLeft.setDuration(d);
	_partRight.setDuration(d);
}


Composition::~Composition()
{
}

void Composition::readInputFile(std::string input)
{
	std::ifstream inputFile;
	std::string filePath = "\input\\" + input;
	inputFile.open(filePath);

	std::regex lineRx("([^\\[]*)\\[([^\\]]*)\\]");
	std::regex bracketsRx("([#a-zA-Z0-9]+)");
	std::regex noBracketsRx("([ ]*)([|#a-zA-Z0-9]+)([ ]*)");

	std::string line, brackets, noBrackets;

	while (getline(inputFile, line)) {
		std::sregex_iterator begin(line.begin(), line.end(), lineRx);
		std::sregex_iterator empty;
		if (begin == empty) {
			parseNoBrackets(noBracketsRx, line);
		}
		while (begin != empty) {
			std::smatch result = *begin;
			noBrackets = result.str(1);
			//van zagrada
			parseNoBrackets(noBracketsRx, line);
			brackets = result.str(2);
			parseBrackets(bracketsRx, line);
			//u zagradama
			begin++;
		}
	}
}

void Composition::parseBrackets(std::regex rx, std::string lineToParse)
{
}

void Composition::parseNoBrackets(std::regex rx, std::string lineToParse)
{
	std::sregex_iterator begin(lineToParse.begin(), lineToParse.end(), rx);
	std::sregex_iterator empty;
	std::string symbols;
	Duration eight(1, 8);
	Duration quarter(1, 4);
	std::string spaceBefore, spaceAfter;

	while (begin != empty) {
		std::smatch result = *begin;
		spaceBefore = result.str(1);
		symbols = result.str(2);
		spaceAfter = result.str(3);

		for (char c : spaceBefore) {
			addBothHands(new Pause(eight));
		}

		for (char c : symbols) {
			if (c == '|') {
				addBothHands(new Pause(quarter));
			}
			else {
				Note n(quarter, (*noteMap)[c].first, (*noteMap)[c].second);
				addSymbol(&n);
			}
				
		}

		for (char c: spaceAfter) {
			addBothHands(new Pause(eight));
		}

		begin++;
	}
}

void Composition::addSymbol(MusicSymbol *m)
{
	Pause p(m->getDuration());
	if (m->getOctave() < 4) {
		addSymbolLeft(m);
		addSymbolRight(&p);
	}
	else {
		addSymbolRight(m);
		addSymbolLeft(&p);
	}
}

void Composition::addBothHands(MusicSymbol * m)
{
	_partLeft.addSymbol(m);
	_partRight.addSymbol(m);
}

