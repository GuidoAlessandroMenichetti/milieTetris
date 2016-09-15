#include "Menu.h"

Menu :: Menu(){
	option = 0;
	graphics = Graphics::getInstance();
}

int Menu :: start(){

	for(int i = 0; i < totalPieces; i++)
		positionPiece(i);

	active = true;
	while(active){
		check();
		draw();
	
		sceKernelDelayThread(10000);
	}
	
	return option;
}

void Menu :: positionPiece(int i){
	pieces[i].setY((rand() % 50) * -1);
	pieces[i].setX(-(rand() % 20) + (rand() % 30));
	pieces[i].rotate(rand() % 3);
}

void Menu :: check(){
	
	input.update();
	if(input.getUp())
		option = 0;
	else if(input.getDown())
		option = 1;
	else if(input.getCross())
		active = false;
	
	for(int i = 0; i < totalPieces; i++){
	
		pieces[i].setY(pieces[i].getY() + 1);
		if(pieces[i].getY() > 40)
			positionPiece(i);
	}
}

void Menu :: draw() const{

	graphics->clear();

	for(int i = 0; i < totalPieces; i++){
	
		if(pieces[i].getY() > 0)
			pieces[i].draw();
	}
	
	Text::draw("MILIE TETRIS", Piece::SIZE * 6, Piece::SIZE * 6, Piece::SIZE / 2, 0xFFFFFFFF);
	Text::draw("@ PLAY @", Piece::SIZE * 18, Piece::SIZE * 15, Piece::SIZE / 4, option == 0? 0xFF00FFFF: 0x66666666);
	Text::draw("@ EXIT @", Piece::SIZE * 18, Piece::SIZE * 17, Piece::SIZE / 4, option == 1? 0xFF00FFFF: 0x66666666);
	Text::draw("BY GBOT", Piece::SIZE * 35, Piece::SIZE * 25, Piece::SIZE / 4, 0xFFFFFFFF);
	Text::draw("V1", Piece::SIZE, Piece::SIZE * 25, Piece::SIZE / 4, 0x66666666);
	graphics->swapBuffer();
}