#include "Tetris.h"

int main(){

	Debug::log("Starting tetris!");
	
	Tetris * tetris = new Tetris();
	if(tetris->isReady())
		tetris->start();
	
	delete tetris;
	
	Debug::log("bye");
	sceKernelExitProcess(0);
	return 0;
}