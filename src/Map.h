#ifndef MAP_H
#define MAP_H

#include "gb/Graphics.h"
#include "gb/common.h"

class Map {

public:
	
	static Map * getInstance();
	void restart();
	void draw() const;
	int checkFullLines();
	bool limitReached() const;
	void setPosition(int x, int y, unsigned color);
	unsigned getPosition(int x, int y) const;
	
	static const int WIDTH = 10;
	static const int HEIGHT = 23;
	static const int X = 18;
	static const int Y = 2;
	
private:
	Map();
	
	bool fullLine(int line) const;
	void deleteLine(int line);
	
	unsigned map[HEIGHT][WIDTH];
	Graphics * graphics;
};

#endif