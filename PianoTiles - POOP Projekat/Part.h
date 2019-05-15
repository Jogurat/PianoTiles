#ifndef __PART_H__
#define __PART_H__
#include "Measure.h"
class Part
{
private:
	std::list<Measure*> _measureList;
	Duration _duration;
public:
	Part();
	Part(Duration d);
	~Part();
	void setDuration(Duration d);
	void addSymbol(MusicSymbol *m);
	void addMeasure(Measure &m);
	void goThrough();
};
#endif

