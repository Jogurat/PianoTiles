#ifndef __DURATION_H__
#define __DURATION_H__
#include <iostream>
#include <string>
class Duration
{
private:
	int _numerator; //brojilac
	int _denumerator; //imenilac
public:
	Duration();
	Duration(const Duration &d);
	Duration(int num, int denum): _numerator(num), _denumerator(denum) {}
	~Duration();
	int getNum();
	int getDenum();
	friend Duration operator+(Duration d1, Duration d2);
	friend Duration operator-(Duration d1, Duration d2);
	friend bool operator>(Duration d1, Duration d2);
	friend bool operator==(Duration d1, Duration d2);
	friend bool operator!=(Duration d1, Duration d2);
	friend bool operator<(Duration d1, Duration d2);
};

#endif