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
	std::list<MusicSymbol*>::iterator prevIter = iter;
	while (prevIter != _symbols.end()) {
		if (iter == _symbols.begin()) {
			prevIter = iter;
		}
		else {
			prevIter = std::prev(iter);
		}
		
		char c = '\0';
		if (_kbhit() != 0) {
			c = _getch();
		}
		
		if (c == 'd') {
			if (iter != _symbols.end()) {
				iter++;
				std::cout << *std::prev(iter);
				std::cout << " ";
			}
			
		}		
		else if (c == 's') {
			(*prevIter)->editNote();
			if (iter == _symbols.end()) //krajnji slucaj
				return;
			//iter++;
			//std::cout << *iter;
		}
	}
}

bool Measure::isFull()
{
	return _currDuration == _maxDuration;
}

MusicSymbol & Measure::peekFirst() const
{
	return *_symbols.front();
}

std::ostream & operator<<(std::ostream & os, Measure & m)
{
	auto iter = m._symbols.begin();
	while (iter != m._symbols.end()) {
		os << *iter << " ";
		iter++;
	}
	os << std::endl;
	//os << *iter;
	return os;
}
