#ifndef __NOTE_H__
#define __NOTE_H__
#include "MusicSymbol.h"
class Note : public MusicSymbol
{
private:
	std::string _name;
	char _note;
	bool _isHigh;
	int _midiVal;
	int _octave;
	void print(std::ostream &os)const override;
public:
	Note(Duration d, std::string name, int midiVal);
	Note(Duration d, std::string name, int midiVal, int id);
	//Note(const Note &n);
	~Note();

	int getMidi()const override;
	bool isNote() const override;
	void editNote() override;
	int getOctave() const override;
	void changeOctave(int i) override;
	std::string getName()const override;
	//Note splitNote();
};
#endif

