#ifndef RECORD_H
#define RECORD_H

#include "gb/common.h"

class Record {

public:

	Record();
	bool load();
	bool save();
	
	void setScore(unsigned score);
	unsigned getScore() const;
	
private:

	const char * path = "ux0:/temp/milieTetris.gbt";
	const int defaultScore = 1500;
	unsigned score;
};

#endif