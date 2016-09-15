#include "Text.h"

void Text :: draw(const char * str, int x, int y, int size, unsigned color, unsigned back){

	Graphics * graphics = Graphics::getInstance();
	
	for(int index = 0; index < strlen(str); index++){
	
		if(str[index] != ' '){
			for(int i = 0; i < 5; i++){
				for(int j = 0; j < 5; j++){
				
					if(tetrisFont[(unsigned char)str[index] - 0x30][i][j] != ' ')
						graphics->drawRectangle(x + j * size, y + i * size, size, size, color);
					else if(back != 0x12345678)
						graphics->drawRectangle(x + j * size, y + i * size, size, size, back);
				}
			}
		}
		
		if(back != 0x12345678){
			for(int i = 0; i < 5; i++)
				graphics->drawRectangle(x + 6 * size, y + i * size, size, size, back);
		}
		
		x += size * 6;
	}
}