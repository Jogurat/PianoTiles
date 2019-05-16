#include "MIDIFormatter.h"



MIDIFormatter::MIDIFormatter()
{
}


MIDIFormatter::~MIDIFormatter()
{
}

void MIDIFormatter::makeFormat(Composition c, std::string name) const
{
	MidiFile outputfile;
	outputfile.absoluteTicks();
	std::vector<uchar> midievent;
	midievent.resize(3);
	int tpq = 48;
	outputfile.setTicksPerQuarterNote(tpq);
	outputfile.addTrack(1);
	bool split = false;
	int sameId = 0;
	int mrhythm, brhythm;
	int actionTime = 0;

	
	
	midievent[2] = 64; 



	//levo
	for (auto measure : c.getLeftPart()) {

		for (auto symbol : (*measure)) {
		if ((*symbol).getDuration() == Duration(0, 1))
				continue;
			if (split) { 
				split = false;
				continue;
			}

			if (sameId == symbol->getId())
				actionTime -= tpq / 2 * mrhythm; 
			midievent[0] = 0x90;

			sameId = symbol->getId(); 
			
			mrhythm = ((*symbol).getDuration() == Duration(1, 8) ? 1 : 2);
			//mrhythm = 1;
			if (symbol->isSplit()) { 
				mrhythm = 2; 
				split = true;
			}

			if (!symbol->isNote() && (*symbol).getDuration() != Duration(0, 1)) {
				actionTime += tpq / 2 * mrhythm;
				continue;
			}
			midievent[1] = (*symbol).getMidi();

			outputfile.addEvent(0, actionTime, midievent);
			actionTime += tpq / 2 * mrhythm;
			midievent[0] = 0x80;
			outputfile.addEvent(0, actionTime, midievent);
		}
	}



	//desno 
	sameId = 0;
	split = false;
	actionTime = 0;
	for (auto measure : c.getRightPart()) {

		for (auto symbol : (*measure)) {
			if ((*symbol).getDuration() == Duration(0, 1))
				continue;
			if (split) { 
				split = false;
				continue;
			}

			if (sameId == symbol->getId())
				actionTime -=  tpq / 2 * brhythm;
			midievent[0] = 0x90;

			sameId = symbol->getId(); 
			
			brhythm = ((*symbol).getDuration() == Duration(1, 8) ? 1 : 2);
			//brhythm = 1;

			if (symbol->isSplit()) { 
				brhythm = 2; 
				split = true;
			}

			if (!symbol->isNote() && (*symbol).getDuration() != Duration(0, 1)) {
				actionTime += tpq / 2 * brhythm;
				continue;
			}
			midievent[1] = (*symbol).getMidi();

			outputfile.addEvent(1, actionTime, midievent);
			actionTime += tpq / 2 * brhythm;
			midievent[0] = 0x80;
			outputfile.addEvent(1, actionTime, midievent);
		}
	}

	outputfile.sortTracks();
	outputfile.write(name+".mid");
	return;
}
