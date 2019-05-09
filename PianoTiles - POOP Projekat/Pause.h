#ifndef __PAUSE_H__
#define __PAUSE_H__
#include "MusicSymbol.h"
class Pause : public MusicSymbol
{
private:
	void print(std::ostream &os)const override;
public:
	Pause(Duration d) : MusicSymbol(d) {};
	Pause(const Pause &p) : MusicSymbol(p._duration, p._id) {};
	~Pause();
	bool isNote() const override;
	std::string getName()const override;
};
#endif
