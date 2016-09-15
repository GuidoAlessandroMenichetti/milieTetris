#ifndef TETRIS_H
#define TETRIS_H

#include "gb/common.h"
#include "gb/Graphics.h"
#include "gb/Input.h"
#include "gb/Debug.h"
#include "Map.h"
#include "Text.h"
#include "Piece.h"
#include "Menu.h"
#include "Record.h"
#include "resources.h"

class Tetris {
	
public:
	Tetris();
	~Tetris();
	int start();
	bool isReady();
	
private:
	
	
	void control();
	
	void restart();
	void pause();
	void gameOver();
	
	void draw();
	void drawNextPiece();
	void drawGameOver() const;
	void drawScore() const;
	void drawPause() const;
	void drawBackground() const;

	bool active;
	bool ready;
	bool redrawNextPiece;
	bool buttonPressed;
	int tick;
	int tickWait;
	
	unsigned score;
	
	Menu menu;
	Map * map;
	Piece piece;
	Piece nextPiece;
	Input input;
	Record record;
	Graphics * graphics;
};

#endif