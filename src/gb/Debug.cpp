#include "Debug.h"
#include "Graphics.h"

bool started = false;
int y = 0;

void Debug :: createLog(){

	SceUID stream = sceIoOpen(LOGPATH, SCE_O_WRONLY | SCE_O_TRUNC | SCE_O_CREAT, 0777);
	if(stream >= 0){	
		sceIoClose(stream);
		started = true;
	}
}

void Debug :: log(const char * str){
	if(!started)
		createLog();
		
	SceUID stream = sceIoOpen(LOGPATH, SCE_O_WRONLY | SCE_O_APPEND, 0777);
	if(stream >= 0){
		sceIoLseek(stream, SCE_SEEK_END, 0);
		sceIoWrite(stream, str, strlen(str));
		sceIoWrite(stream, "\n", 1);
		sceIoClose(stream);
	}
}

void Debug :: print(const char * str, unsigned color){
	
	Graphics * graphics = Graphics::getInstance();
	if(graphics){
		
		int x = 0;
		
		//for all string characters
		for(int i = 0; i < strlen(str); i++){
			
			//special characters check
			if(str[i] == '\n'){
				y++;
				x = 0;
			}
			else if(str[i] == ' ')
				x += 10;
			else if(str[i] == '\t')
				x += 64;
			else {
			
				//I stole this
				//print the char
				unsigned int finalY = y * 18;
				unsigned char * fontChar = (unsigned char *)(font + (str[i] - 32) * 8);
				int k, j, posX, posY;
				for(k = 0; k < 8; ++k) {
					posY = finalY + k * 2;
					for (j = 0; j < 8; ++j){
						
						posX = x + j * 2;
						if((*fontChar & (128 >> j))){
						
							graphics->drawPixel(posX, posY, color); 
							graphics->drawPixel(posX + 1, posY, color); 
							graphics->drawPixel(posX, posY + 1, color); 
							graphics->drawPixel(posX + 1, posY + 1, color); 
						}
					}
					
					++fontChar;
				}
				
				x += 16;
			}	
		}
		
		if(++y > MAXLINES)
			y = 0;
	}
}

void Debug :: logPrint(const char * str, unsigned color){
	log(str);
	print(str, color);
}