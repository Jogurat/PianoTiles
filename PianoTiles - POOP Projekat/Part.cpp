#include "Part.h"



Part::Part()
{
}

Part::Part(Duration d)
{
	_duration = d;
}


Part::~Part()
{
}

void Part::setDuration(Duration d)
{
	_duration = d;
}

void Part::addSymbol(MusicSymbol * m)
{
	if (_measureList.size() == 0 || _measureList.back()->isFull())
		_measureList.push_back(new Measure(_duration));

	if (_measureList.back()->getCurrDuration() + m->getDuration() > _measureList.back()->getMaxDuration()) { //splitovanje znaka
		m->split();
		_measureList.back()->addSymbol(m);
		_measureList.push_back(new Measure(_duration));
		_measureList.back()->addSymbol(m);
	}
	else {
		_measureList.back()->addSymbol(m);
	}
	
}

void Part::addMeasure(Measure & m)
{
	_measureList.push_back(&m);
}

void Part::goThrough()
{
	auto iter = _measureList.begin();
	std::list<Measure*>::iterator prevIter = iter;
	while (prevIter != _measureList.end()) {
		if (iter == _measureList.begin()) {
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
			std::cout << **iter;
			iter++;
			if (iter == _measureList.end()) //poslednji takt
				return;
		}
		else if (c == 's') {
			(**prevIter).goThrough();
			if (iter == _measureList.end()) //krajnji slucaj
				return;
		}
	}
}
