#include "Duration.h"
#include "helperfuns.h"

Duration::Duration()
{
}

Duration::Duration(const Duration & d)
{
	_numerator = d._numerator;
	_denumerator = d._denumerator;
}

Duration::~Duration()
{
}

int Duration::getNum()
{
	return _numerator;
}

int Duration::getDenum()
{
	return _denumerator;
}

Duration operator+(Duration d1, Duration d2)
{
	int numerator, denumerator, gcd;
	numerator = d1._numerator * d2._denumerator + d2._numerator * d1._denumerator;
	denumerator = d1._denumerator * d2._denumerator;
	gcd = commonDiv(numerator, denumerator); //nzd
	//svodjenje razlomka
	/*numerator /= gcd;
	denumerator /= gcd;*/
	return Duration(numerator, denumerator);
}

Duration operator-(Duration d1, Duration d2)
{
	int numerator, denumerator, gcd;
	numerator = d1._numerator * d2._denumerator - d2._numerator * d1._denumerator;
	denumerator = d1._denumerator * d2._denumerator;
	gcd = commonDiv(numerator, denumerator); //nzd
	//svodjenje razlomka
	/*numerator /= gcd;
	denumerator /= gcd;*/

	return Duration(numerator, denumerator);
}

bool operator>(Duration d1, Duration d2)
{
	Duration d3 = d1 - d2;
	if (d3._numerator <= 0)
		return false;
	else
		return true;
}

bool operator==(Duration d1, Duration d2)
{
	Duration d3 = d1 - d2;
	return (d3._numerator == 0);
}

bool operator<(Duration d1, Duration d2)
{
	return (!(d1 > d2) && !(d1 == d2));
}
