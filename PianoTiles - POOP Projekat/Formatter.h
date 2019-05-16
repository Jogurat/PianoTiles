#ifndef __FORMATTER_H__
#define __FORMATTER_H__
#include "Composition.h"
class Formatter
{
public:
	Formatter();
	~Formatter();
	virtual void makeFormat(Composition c, std::string name) const = 0;
};
#endif
