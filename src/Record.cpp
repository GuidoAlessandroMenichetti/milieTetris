#include "Record.h"

Record :: Record(){
	score = defaultScore;
}

bool Record :: load(){
	
	SceUID stream = sceIoOpen(path, SCE_O_RDONLY, 0777);
	if(stream < 0)
		return false;
		
	unsigned value;
	int bytes = sceIoRead(stream, &value, sizeof(unsigned));
	if(bytes == sizeof(unsigned) && value < 999999)
		score = value;
		
	sceIoClose(stream);
	return true;
}

bool Record :: save(){
	
	SceUID stream = sceIoOpen(path, SCE_O_TRUNC | SCE_O_CREAT | SCE_O_WRONLY, 0777);
	if(stream < 0)
		return false;

	sceIoWrite(stream, &score, sizeof(unsigned));
	sceIoClose(stream);
	
	return true;
}

unsigned Record :: getScore() const {
	return score;
}

void Record :: setScore(unsigned score){
	this->score = score;
}
