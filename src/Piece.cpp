#include "Piece.h"
#include "Map.h"

Piece :: Piece(){
	nextPiece = NULL;
	create();
}

void Piece :: create(Piece * nextPiece){

	this->nextPiece = nextPiece;

	//position piece
	y = 1;
	x = Map::WIDTH / 2 - 2;
	
	if(nextPiece){
	
		color = nextPiece->getColor();
		type = nextPiece->getType();
		
	}
	else {
		//set piece color
		color = colors[rand() % colorsCount];
		
		//set piece type
		type = rand() % piecesCount;
		
	}
	
	for(int i = 0; i < 4; i++)
		memcpy(shape[i], pieces[type][i], 4);
	
	
}

bool Piece :: checkCollision(int newx, int newy) const{
	
	Map * map = Map::getInstance();
	
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			
			if(shape[i][j] != ' '){
				if(newx + j < 0 || newx + j >= Map::WIDTH || newy + i >= Map::HEIGHT || map->getPosition(newx + j, newy + i))
					return true;
			}
		}
	}
	
	return false;
}

bool Piece :: move(int dx, int dy){

	if(checkCollision(x + dx, y + dy))
        return false;

    x += dx;
    y += dy;

    return true;
}

bool Piece :: goDown(){

	if(move(0, 1) == false){
	
		Map * map = Map::getInstance();
		
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				if(shape[i][j] != ' ')
					map->setPosition(x + j, y + i, color);
			}
		}
		
		create(nextPiece);
		if(nextPiece)
			nextPiece->create();
		
		return false;
	}
	
	return true;
}

void Piece :: rotate(){

	rotate(1);
	if(checkCollision(x, y))
		rotate(3);
}

void Piece :: rotate(int times){

	char tempShape[4][4];
	
	for(int k = 0; k < times; k++){
		memcpy(tempShape, shape, 16);
		
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++)
				shape[3 - j][i] = tempShape[i][j];
		}
	}
}

void Piece :: draw() const{

	Graphics * graphics = Graphics::getInstance();
	if(graphics){
	
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				if(shape[i][j] != ' '){
				
					graphics->drawRectangle((Map::X + x + j) * SIZE, (Map::Y + y + i) * SIZE, SIZE, SIZE, color);
					graphics->drawRectangleBorder((Map::X + x + j) * SIZE, (Map::Y + y + i) * SIZE, SIZE, SIZE, 0x00000000);
				}
			}
		}
	}
}

int Piece :: getType() const{
	return type;
}

unsigned Piece :: getColor() const{
	return color;
}

int Piece :: getX() const{
	return x;
}

int Piece :: getY() const{
	return y;
}

void Piece :: setX(int x){
	this->x = x;
}

void Piece :: setY(int y){
	this->y = y;
}