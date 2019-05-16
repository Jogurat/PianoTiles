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
		std::sregex_iterator rxIter(line.begin(), line.end(), lineRx), empty;
		if (rxIter == empty) {
			parseNoBrackets(noBracketsRx, line);
		}
		while (rxIter != empty) {
			std::smatch result = *rxIter;
			noBrackets = result.str(1);
			//van zagrada
			parseNoBrackets(noBracketsRx, noBrackets);
			brackets = result.str(2);
			//u zagradama
			parseBrackets(bracketsRx, brackets);
			rxIter++;
		}
	}
}

void Composition::parseBrackets(std::regex rx, std::string lineToParse)
{
	std::sregex_iterator rxIter(lineToParse.begin(), lineToParse.end(), rx), empty;
	std::string symbols;

	Duration eight(1, 8);
	Duration quarter(1, 4);

	while (rxIter != empty) {
		std::smatch result = *rxIter;
		symbols = result.str(1);
		if (symbols.size() == 1) {
			char c = symbols[0];
			if (c != '|') {
				Note *n = new Note(eight, (*noteMap)[c].first, (*noteMap)[c].second);
				addSymbol(n);
			}
				
		}
		else { 	
			bool insertLeft = false;
			bool insertRight = false;
			int sameId = 0;
			int timesAdded = 0;
			Note *n = nullptr;

			for (char c : symbols) {
				if (sameId == 0) { 
					Note *temp = new Note(quarter, (*noteMap)[c].first, (*noteMap)[c].second);
					n = temp;
					sameId = n->getId();
					timesAdded++;
				}
				else {
					Note *temp2 = new Note(quarter, (*noteMap)[c].first, (*noteMap)[c].second, sameId);
					n = temp2;
					timesAdded++;
				}
				
				if (n->getOctave() < 4) {
					addSymbolLeft(n);
				}
				else {
					addSymbolRight(n);
				}
									
			}
			if (!insertLeft) {
				Pause* pause = new Pause(quarter, sameId);
				addSymbolLeft(pause);
			}
			else if (!insertRight) {
				Pause* pause = new Pause(quarter, sameId);
				addSymbolRight(pause);
			}
			
		}
		rxIter++;
	}
}

void Composition::parseNoBrackets(std::regex rx, std::string lineToParse)
{
	std::sregex_iterator rxIter(lineToParse.begin(), lineToParse.end(), rx), empty;
	std::string symbols;
	Duration eight(1, 8);
	Duration quarter(1, 4);
	std::string spaceBefore, spaceAfter;

	while (rxIter != empty) {
		std::smatch result = *rxIter;
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
				Note *n = new Note(quarter, (*noteMap)[c].first, (*noteMap)[c].second);
				addSymbol(n);
			}
				
		}

		for (char c: spaceAfter) {
			addBothHands(new Pause(eight));
		}

		rxIter++;
	}
}

void Composition::addSymbol(MusicSymbol *m)
{
	Pause *p = new Pause((m->getDuration()));
	if (m->getOctave() < 4) {
		addSymbolLeft(m);
		addSymbolRight(p);
	}
	else {
		addSymbolRight(m);
		addSymbolLeft(p);
	}
}

void Composition::addBothHands(MusicSymbol * m)
{
	_partLeft.addSymbol(m);
	_partRight.addSymbol(m);
}

Part & Composition::getLeftPart()
{
	return _partLeft;
}

Part & Composition::getRightPart()
{
	return _partRight;
}

