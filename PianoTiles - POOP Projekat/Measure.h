#ifndef __MEASURE_H__
#define __MEASURE_H__
#include <list>
#include <iterator>
#include <conio.h>
#include "MusicSymbol.h"
class Measure
{
private:
	std::list<MusicSymbol*> _symbols;
	Duration _maxDuration;
	Duration _currDuration;
public:
	Measure(Duration d) : _maxDuration(d) {};
	~Measure();
	MusicSymbol& peekFirst()const;
	void addSymbol(MusicSymbol *s);
	void goThrough();
};
#endif