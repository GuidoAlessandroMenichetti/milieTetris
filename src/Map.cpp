#include "Map.h"
#include "Piece.h"

static Map * instance = NULL;

Map * Map :: getInstance(){
	
	if(!instance){
		instance = new Map();
	}
	
	return instance;
}

Map :: Map(){
	graphics = Graphics::getInstance();
	restart();
}

void Map :: restart(){
	memset(map, 0x0, WIDTH * HEIGHT * sizeof(unsigned));

}

void Map :: draw() const{

	for(int i = 0; i < HEIGHT; i++){
		for(int j = 0; j < WIDTH; j++){
			graphics->drawRectangle((X + j) * Piece::SIZE, (Y + i) * Piece::SIZE, Piece::SIZE, Piece::SIZE, 0x00000000);
			graphics->drawRectangleBorder((X + j) * Piece::SIZE, (Y + i) * Piece::SIZE, Piece::SIZE, Piece::SIZE, 0x99999999);
		}
	}
	
	for(int i = 0; i < HEIGHT; i++){
		for(int j = 0; j < WIDTH; j++){
			if(map[i][j] != 0x0){
				graphics->drawRectangle((X + j) * Piece::SIZE, (Y + i) * Piece::SIZE, Piece::SIZE, Piece::SIZE, map[i][j]);
				graphics->drawRectangleBorder((X + j) * Piece::SIZE, (Y + i) * Piece::SIZE, Piece::SIZE, Piece::SIZE, 0x00000000);
			}
		}
	}
	
	//red line
	for(int i = X * Piece::SIZE; i < (X + WIDTH) * Piece::SIZE; i++)
		graphics->drawPixel(i, (Y + 2) * Piece::SIZE, 0xFF0000FF);
}

bool Map :: fullLine(int line) const{

	for(int i = 0; i < WIDTH; i++){
		if(!map[line][i])
			return false;
	}
	
	return true;
}

void Map :: deleteLine(int line){
	
	for(int i = line; i > 0; i--)
		memcpy(map[i], map[i - 1], WIDTH * sizeof(unsigned));
}

int Map :: checkFullLines(){
	
	int count = 0;
	for(int i = 0; i < HEIGHT; i++){
	
		if(fullLine(i)){
			deleteLine(i);
			count++;
		}
	}
	
	return count;
}

bool Map :: limitReached() const{
	
	for(int i = 0; i < WIDTH; i++){
	
		if(map[1][i])
			return true;
	}

	return false;
}

unsigned Map :: getPosition(int x, int y) const{
	return map[y][x];
}

void Map :: setPosition(int x, int y, unsigned color){
	map[y][x] = color;
}
