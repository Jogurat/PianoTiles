#include "Part.h"



Part::Part()
{
}


Part::~Part()
{
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