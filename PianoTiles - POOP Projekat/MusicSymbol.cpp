#include "MusicSymbol.h"

int MusicSymbol::ID = 0;


MusicSymbol::~MusicSymbol()
{
}

Duration MusicSymbol::getDuration() const
{
	return _duration;
}

void MusicSymbol::split()
{
	_isSplit = true;
}

int MusicSymbol::getId() const
{
	return _id;
}

std::ostream & operator<<(std::ostream & os, MusicSymbol * ms)
{
	ms->print(os);
	return os;
}
