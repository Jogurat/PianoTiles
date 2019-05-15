#ifndef __COMPOSITION_H__
#define __COMPOSITION_H__
#include "Part.h"
class Composition
{
private:
	Duration _duration;
	Part _partLeft;
	Part _partRight;
	void addSymbolLeft(MusicSymbol *m);
	void addSymbolRight(MusicSymbol *m);
public:
	Composition();
	Composition(Duration d);
	~Composition();
	void addSymbol(MusicSymbol *m);
};
#endif

