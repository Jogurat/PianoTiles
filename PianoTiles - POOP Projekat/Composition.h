#ifndef __COMPOSITION_H__
#define __COMPOSITION_H__
#include "Part.h"
#include "Note.h"
#include "Pause.h"
#include <map>
#include <fstream>
#include <regex>
class Composition
{
private:
	Duration _duration;
	Part _partLeft;
	Part _partRight;
	static std::map<char, std::pair<std::string, int>> *noteMap;
	void addSymbolLeft(MusicSymbol *m);
	void addSymbolRight(MusicSymbol *m);
public:
	Composition();
	Composition(Duration d);
	~Composition();
	void readInputFile(std::string input);
	void parseBrackets(std::regex rx, std::string lineToParse);
	void parseNoBrackets(std::regex rx, std::string lineToParse);
	void addSymbol(MusicSymbol *m);
	void addBothHands(MusicSymbol *m);
	static void setNoteMap(std::map<char, std::pair<std::string, int>> *notes) { noteMap = notes; }
};
#endif

