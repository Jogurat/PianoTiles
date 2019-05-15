#include "Composition.h"



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

void Composition::addSymbol(MusicSymbol *m)
{
	if (m->getOctave() < 4) {
		addSymbolLeft(m);
	}
	else {
		addSymbolRight(m);
	}
}
