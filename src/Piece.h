#ifndef PIECE_H
#define PIECE_H

#include "gb/common.h"
#include "gb/Graphics.h"
#include "resources.h"

class Piece {

public:
	Piece();
	void create(Piece * nextPiece = NULL);
	void draw() const;
	bool goDown();
	bool move(int x, int y = 0);
	void rotate();
	void rotate(int times);
	
	void setX(int x);
	void setY(int y);
	int getX() const;
	int getY() const;
	int getType() const;
	unsigned getColor() const;
	
	static const int SIZE = 20;
	
private:
	bool checkCollision(int newx = 0, int newy = 0) const;

	int type;
	unsigned color;
	int x, y;
	char shape[4][4];
	Piece * nextPiece;
};

#endif