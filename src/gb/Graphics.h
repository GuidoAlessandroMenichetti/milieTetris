#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "common.h"
#include "FrameBuffer.h"

class Graphics {
	
public:

	static Graphics * getInstance();	
	static void end();
	
	void clear();
	void drawPixel(unsigned x, unsigned y, unsigned color = 0xFFFFFFFF);
	void drawRectangle(unsigned x, unsigned y, unsigned width, unsigned height, unsigned color = 0xFFFFFFFF);
	void drawRectangleBorder(unsigned x, unsigned y, unsigned width, unsigned height, unsigned color = 0xFFFFFFFF);
	void swapBuffer();
	bool isReady() const;
	
	static const int WIDTH = 960, HEIGHT = 544;
	
private:
	
	Graphics();
	~Graphics();
	
	FrameBuffer * frameBuffer[2];
	int currentBuffer;
	bool ready;
};

#endif