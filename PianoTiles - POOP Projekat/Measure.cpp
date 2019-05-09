#include "Measure.h"


Measure::~Measure()
{
}

void Measure::addSymbol(MusicSymbol *s)
{
	_symbols.push_back(s);
	_currDuration = _currDuration + s->getDuration();
}

void Measure::goThrough()
{
	auto iter = _symbols.begin();
	while (iter != _symbols.end()) {
		//
		char c = '\0';
		if (_kbhit() != 0) {
			c = _getch();
		}
		
		if (c == 'd') {
			std::cout << *iter;
			iter++;
			std::cout << " ";
		}
			
		else if (c == 's') {
			(*iter)->editNote();
			iter++;
			//std::cout << *iter;
		}
	}
}

MusicSymbol & Measure::peekFirst() const
{
	return *_symbols.front();
}
