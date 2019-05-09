#include "Pause.h"


void Pause::print(std::ostream & os) const
{
	os << "Pauza";
}

Pause::~Pause()
{
}

bool Pause::isNote() const
{
	return false;
}

std::string Pause::getName() const
{
	return "Pauza";
}
