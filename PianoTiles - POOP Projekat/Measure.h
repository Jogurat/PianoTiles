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
	Measure(Duration d) : _maxDuration(d) {
		_currDuration = *(new Duration(0, 1));
	
	};
	~Measure();
	Duration getMaxDuration();
	Duration getCurrDuration();
	MusicSymbol& peekFirst()const;
	void addSymbol(MusicSymbol *s);
	void addSymbolNoDuration(MusicSymbol *s);
	void goThrough();
	bool isFull();
	std::list<MusicSymbol*>::iterator begin();
	std::list<MusicSymbol*>::iterator end();
	friend std::ostream& operator<<(std::ostream &os, Measure &m);
};
#endif
