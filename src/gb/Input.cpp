#include "Input.h"

Input :: Input(){
	left = right = up = down = false;
	cross = triangle = circle = square = false;
	r = l = select = start = false;
}

void Input :: update(){
	SceCtrlData data;
	sceCtrlReadBufferPositive(0, &data, 1);
	
	left = data.buttons & SCE_CTRL_LEFT;
	right = data.buttons & SCE_CTRL_RIGHT;
	up = data.buttons & SCE_CTRL_UP;
	down = data.buttons & SCE_CTRL_DOWN;
	cross = data.buttons & SCE_CTRL_CROSS;
	triangle = data.buttons & SCE_CTRL_TRIANGLE;
	circle = data.buttons & SCE_CTRL_CIRCLE;
	square = data.buttons & SCE_CTRL_SQUARE;
	r = data.buttons & SCE_CTRL_RTRIGGER;
	l = data.buttons & SCE_CTRL_LTRIGGER;
	start = data.buttons & SCE_CTRL_START;
	select = data.buttons & SCE_CTRL_SELECT;
}

bool Input :: pressed() const{
	SceCtrlData data;
	sceCtrlReadBufferPositive(0, &data, 1);
	return data.buttons != 0;
}

void Input :: waitPress() const{

	SceCtrlData data;
	do {
		sceCtrlReadBufferPositive(0, &data, 1);
	} while(!data.buttons);
}

void Input :: waitRelease() const{
	
	SceCtrlData data;
	do {
		sceCtrlReadBufferPositive(0, &data, 1);
	} while(data.buttons);
}

bool Input :: getLeft() const{
	return left;
}

bool Input :: getRight() const{
	return right;
}

bool Input :: getUp() const{
	return up;
}

bool Input :: getDown() const{
	return down;
}

bool Input :: getCross() const{
	return cross;
}

bool Input :: getSquare() const{
	return square;
}

bool Input :: getTriangle() const{
	return triangle;
}

bool Input :: getCircle() const{
	return circle;
}

bool Input :: getLeftTrigger() const{
	return l;
}

bool Input :: getRightTrigger() const{
	return r;
}

bool Input :: getSelect() const{
	return select;
}

bool Input :: getStart() const{
	return start;
}