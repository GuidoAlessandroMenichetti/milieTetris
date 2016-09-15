#ifndef DEBUG_H
#define DEBUG_H

#include "common.h"
#include "font.h"

namespace Debug {

	void createLog();
	void log(const char * str);
	void print(const char * str, unsigned color = 0xFFFFFFFF);
	void logPrint(const char * str, unsigned color = 0xFFFFFFFF);
	
	static const char * LOGPATH = "ux0:/temp/gblog.txt";
	static const int MAXLINES = 20;
};

#endif