#include "Tetris.h"

Tetris :: Tetris(){
	ready = false;
	graphics = NULL;
	map = NULL;
	
	Debug::log("Starting graphics");
	graphics = Graphics::getInstance();
	if(graphics){
	
		Debug::log("Graphics Started!");
		
		map = Map::getInstance();
		if(map)
			ready = true;
	}
}

Tetris :: ~Tetris(){

	Debug::log("Deleting tetris!");
		
	if(graphics)
		graphics->end();

	if(map)
		delete map;
}

void Tetris :: restart(){
	
	redrawNextPiece = false;
	buttonPressed = false;
	score = 0;
	tick = 0;
	tickWait = 10;
	
	//start map and create new piece
	map->restart();
	nextPiece.create();
	
	piece.create(&nextPiece);
	nextPiece.create();
	
	//draw background once in both buffers
	drawBackground();
	drawNextPiece();
	drawScore();
}

int Tetris :: start(){

	active = true;

	//call main menu
	if(menu.start() != 0)
		return 1;
	
	//load hiscore
	record.load();
	restart();

	//main loop
	while(active){
		control();
		draw();

		sceKernelDelayThread(50000);
	}
	
	return 0;
}

void Tetris :: control(){

	//button input
	input.update();
	
	if(input.getLeft())
		piece.move(-1);
	else if(input.getRight())
		piece.move(1);
	else if(input.getStart()){
		pause();
	}
		
	//shitty thread workaround

	//this controls the buttons that cant be hold (drop / rotate)
	if(!buttonPressed){
	
		buttonPressed = true;
	
		if(input.getCross())
			piece.rotate();
		else if(input.getCircle()){
			while(piece.goDown());
			tick = 0;
		
			redrawNextPiece = true;
			if(piece.goDown() == false && (piece.move(0) == false || map->limitReached()))
				gameOver();
		}	
		else 
			buttonPressed = false;
		
	}
	else if(!input.pressed())
		buttonPressed = false;
	
	tick++;
	if(input.getDown() || tick >= tickWait){
	
		tick = 0;
		
		redrawNextPiece = true;
		if(piece.goDown() == false && (piece.move(0) == false || map->limitReached()))
			gameOver();
	}
	
	//check if any line filled
	int fullLines = map->checkFullLines() ;
	if(fullLines){
		score += fullLines * fullLines * 50;
		drawScore();
	}
	
	//this adds some speed when certain scores are reached
	if(score >= 9000)
		tickWait = 3;
	else if(score >= 3000)
		tickWait = 4;
	else if(score >= 1000)
		tickWait = 6;
	
	//
}

void Tetris :: gameOver(){

	//beaten record?
	if(score > record.getScore()){
		record.setScore(score);
		record.save();
	}

	for(int i = 0; i < 2; i++){
		draw();
		drawGameOver();
	}
	
	sceKernelDelayThread(4 * 1000 * 1000);
	input.waitPress();
	restart();
}

void Tetris :: pause(){
	input.waitRelease();
	drawPause();
	
	do {
		input.update();
	} while(!input.getStart());
	input.waitRelease();
}

void Tetris :: draw(){

	map->draw();
	piece.draw();
	
	if(redrawNextPiece){
		drawNextPiece();
		redrawNextPiece = false;
	}
	
	graphics->swapBuffer();
}

void Tetris :: drawBackground() const{
	
	//game background
	for(int k = 0; k < 2; k++){
	
		graphics->clear();
		unsigned backColor = 0x11111111;
		
		for(int i = 0; i < Graphics::HEIGHT / Piece::SIZE; i++){
			graphics->drawRectangle(0, i * Piece::SIZE, Graphics::WIDTH, Piece::SIZE, backColor);
			for(int j = 0; j < Graphics::WIDTH / Piece::SIZE; j++)
				graphics->drawRectangleBorder(j * Piece::SIZE, i * Piece::SIZE, Piece::SIZE, Piece::SIZE, 0x00000000);
				
			backColor += 0x01010101;
		}

		int textX = Map::X + Map::WIDTH + 2;
		int textY = Map::Y + Map::HEIGHT - 5;
		
		Text::draw("X     ROTATE", textX * Piece::SIZE, textY * Piece::SIZE, Piece::SIZE / 5, 0xFFFFFFFF);
		Text::draw("O     DROP  ", textX * Piece::SIZE, (textY + 2) * Piece::SIZE, Piece::SIZE / 5, 0xFFFFFFFF);
		Text::draw("START PAUSE ", textX * Piece::SIZE, (textY + 4) * Piece::SIZE, Piece::SIZE / 5, 0xFFFFFFFF);
	
		graphics->swapBuffer();
	}
}

void Tetris :: drawNextPiece(){

	int nextPieceX = Map::X - 7;
	int nextPieceY = Map::Y;

	nextPiece.setX(nextPieceX - Map::X + 1);
	nextPiece.setY(1);
	
	for(int k = 0; k < 2; k++){
	
		for(int i = 0; i < 6; i++){
			for(int j = 0; j < 6; j++){
				graphics->drawRectangle((nextPieceX + j) * Piece::SIZE, (nextPieceY + i) * Piece::SIZE, Piece::SIZE, Piece::SIZE, 0x00000000);
				graphics->drawRectangleBorder((nextPieceX + j) * Piece::SIZE, (nextPieceY + i) * Piece::SIZE, Piece::SIZE, Piece::SIZE, 0x99999999);
			}
		}
		
		nextPiece.draw();
		graphics->swapBuffer();
	}
}

void Tetris :: drawScore() const{

	//draw score background
	int scoreX = Map::X + Map::WIDTH + 1;
	int scoreY = Map::Y;
	
	char highScore[16];
	sprintf(highScore, "%06d", score > record.getScore()? score: record.getScore());
	char scoreString[16];
	sprintf(scoreString, "%06d", score);
	
	
	for(int k = 0; k < 2; k++){
	
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				graphics->drawRectangle((scoreX + j) * Piece::SIZE, (scoreY + i) * Piece::SIZE, Piece::SIZE, Piece::SIZE, 0x00000000);
				graphics->drawRectangleBorder((scoreX + j) * Piece::SIZE, (scoreY + i) * Piece::SIZE, Piece::SIZE, Piece::SIZE, 0x99999999);
			}
		}
		
		Text::draw("BEST", (scoreX + 1) * Piece::SIZE, (scoreY + 1) * Piece::SIZE, Piece::SIZE / 5, 0xFFFFFFFF);
		Text::draw(highScore, (scoreX + 1) * Piece::SIZE, (scoreY + 3) * Piece::SIZE, Piece::SIZE / 5, 0xFFFFFFFF);
		Text::draw("SCORE", (scoreX + 1) * Piece::SIZE, (scoreY + 5) * Piece::SIZE, Piece::SIZE / 5, 0xFFFFFFFF);
		Text::draw(scoreString, Piece::SIZE * (scoreX + 1), Piece::SIZE * (scoreY + 7), Piece::SIZE / 5, 0xFFFFFFFF);
		graphics->swapBuffer();
	}
}

void Tetris :: drawPause() const{

	for(int i = 0; i < 2; i++){
		Text::draw("PAUSE", (Map::X + 2) * Piece::SIZE, (Map::Y + 10) * Piece::SIZE, Piece::SIZE / 5, 0xFF0000FF);
		graphics->swapBuffer();
	}
}

void Tetris :: drawGameOver() const{

	for(int i = 0; i < 2; i++){	
	
		Text::draw("GAME", (Map::X + 3) * Piece::SIZE, (Map::Y + 9) * Piece::SIZE, Piece::SIZE / 5, 0xFF0000FF);
		Text::draw("OVER", (Map::X + 3) * Piece::SIZE, (Map::Y + 11) * Piece::SIZE, Piece::SIZE / 5, 0xFF0000FF);
		graphics->swapBuffer();	
	}
}

bool Tetris :: isReady(){
	return ready;
}
