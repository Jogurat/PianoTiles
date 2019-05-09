#include "Note.h"



void Note::print(std::ostream & os) const
{
	os << _name;
}

Note::Note(Duration d, std::string name, int midiVal):
	MusicSymbol(d), _name(name), _midiVal(midiVal)
{
	if (name.length() == 3) {
		_note = name[0];
		_octave = atoi(&_name[2]);
		_isHigh = true;
	}
	else if (name.length() ==2 ){
		_note = name[0];
		_octave = atoi(&_name[1]);
		_isHigh = false;
	}
	else {
		//greska
	}
}


Note::~Note()
{
}



int Note::getMidi() const
{
	return _midiVal;
}

bool Note::isNote() const
{
	return true;
}

void Note::editNote()
{
	std::cout << "Menjam notu !" << _name << std::endl;
}

void Note::changeOctave(int i)
{
	return;
}

std::string Note::getName() const
{
	return _name;
}
