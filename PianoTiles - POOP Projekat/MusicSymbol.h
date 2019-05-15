#ifndef __MUSIC_SYMBOL_H__
#define __MUSIC_SYMBOL_H__
#include "Duration.h"

class MusicSymbol
{
private:
	static int ID;
protected:
	Duration _duration;
	int _id;
	bool _isSplit = false;
	virtual void print(std::ostream &os)const = 0;
public:
	MusicSymbol(Duration d) : _duration(d), _id(++ID) {};
	MusicSymbol(Duration d, int id) : _duration(d), _id(id) {};
	virtual ~MusicSymbol() = 0;
	Duration getDuration() const;
	void split();
	int getId() const;
	friend std::ostream& operator<<(std::ostream &os, MusicSymbol *ms);
	virtual int getMidi()const = 0;
	virtual bool isNote()const = 0;
	virtual void editNote() {};
	virtual int getOctave() const{};
	virtual void changeOctave(int i) {};
	virtual std::string getName()const = 0;

};

#endif

