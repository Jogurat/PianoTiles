#include "MusicSymbol.h"

int MusicSymbol::ID = 0;


MusicSymbol::~MusicSymbol()
{
}

Duration MusicSymbol::getDuration() const
{
	return _duration;
}

void MusicSymbol::setDuration(Duration d)
{
	_duration = d;
}

void MusicSymbol::split()
{
	if (_duration.getDenum() == 4) {
		setDuration(*(new Duration(1, 8)));
	}
	_isSplit = true;
}

int MusicSymbol::getId() const
{
	return _id;
}

bool MusicSymbol::isSplit() const
{
	return _isSplit;
}

std::ostream & operator<<(std::ostream & os, MusicSymbol * ms)
{
	ms->print(os);
	return os;
}
