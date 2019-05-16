#ifndef __MIDIFORMATTER_H__
#define __MIDIFORMATTER_H__
#include "Formatter.h"
#include "Binasc.h"
#include "MidiEvent.h"
#include "MidiEventList.h"
#include "MidiFile.h"
#include "MidiMessage.h"
#include "Options.h"
#include "Part.h"
#include<fstream>
#include<utility>
#include<regex>
#include<algorithm>
using namespace smf;

class MIDIFormatter : public Formatter
{
public:
	MIDIFormatter();
	~MIDIFormatter();
	void makeFormat(Composition c, std::string name) const override;
};
#endif
