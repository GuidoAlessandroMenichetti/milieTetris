#ifndef MENU_H
#define MENU_H

#include "gb/common.h"
#include "gb/Graphics.h"
#include "gb/Input.h"
#include "Text.h"
#include "Piece.h"
#include "resources.h"

class Menu {

public:
	Menu();
	int start();
	
	
private:
	void check();
	void draw() const;
	
	void positionPiece(int i);

	bool active;
	int option;
	static const int totalPieces = 14;
	
	Graphics * graphics;
	Piece pieces[totalPieces];
	Input input;
};



#endif