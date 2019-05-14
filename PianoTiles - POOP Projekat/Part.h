#ifndef __PART_H__
#define __PART_H__
#include "Measure.h"
class Part
{
private:
	std::list<Measure*> _measureList;
public:
	Part();
	~Part();
	void addMeasure(Measure &m);
	void goThrough();
};
#endif

