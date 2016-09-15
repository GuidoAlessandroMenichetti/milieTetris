#ifndef INPUT_H
#define INPUT_H

#include "common.h"

class Input {

public:
	Input();
	void update();
	bool pressed() const;
	void waitRelease() const;
	void waitPress() const;
	bool getLeft() const;
	bool getRight() const;
	bool getUp() const;
	bool getDown() const;
	bool getCross() const;
	bool getTriangle() const;
	bool getCircle() const;
	bool getSquare() const;
	bool getRightTrigger() const;
	bool getLeftTrigger() const;
	bool getStart() const;
	bool getSelect() const;
	
private:
	
	bool left, right, up, down;
	bool cross, triangle, circle, square;
	bool r, l, select, start;
	
};

#endif