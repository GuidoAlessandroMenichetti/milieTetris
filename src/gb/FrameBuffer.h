#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include "common.h"

#define align_mem(addr, align) (((addr) + ((align) - 1)) & ~((align) - 1))

class FrameBuffer {
	
public:
	
	static FrameBuffer * create();
	~FrameBuffer();
	
	void clear();
	void drawPixel(unsigned x, unsigned y, unsigned color);
	
	SceDisplayFrameBuf * getBuffer();
	SceUID getMemory() const;
	bool isReady() const;
	
private:

	FrameBuffer();
	int setupBuffer();

	SceDisplayFrameBuf buffer;
	SceUID memory;
	bool ready;
};

#endif