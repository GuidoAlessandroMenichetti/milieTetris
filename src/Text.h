#ifndef TEXT_H
#define TEXT_H

#include "gb/Graphics.h"
#include "resources.h"

namespace Text {

	void draw(const char * str, int x, int y, int size, unsigned color, unsigned back = 0x12345678);

};

#endif