#include "FrameBuffer.h"
#include "Graphics.h"
#include "Debug.h"

FrameBuffer * FrameBuffer :: create(){
	
	//try to instance a framebuffer
	FrameBuffer * ret = new FrameBuffer();
	if(!ret->isReady()){
		
		//delete failed framebuffer
		delete ret;
		return NULL;
	}
	
	return ret;
}

FrameBuffer :: FrameBuffer(){
	
	ready = false;
	memory = 0;
	
	if(!setupBuffer())
		ready = true;
}

FrameBuffer :: ~FrameBuffer(){
	
	if(memory > 0){
		
		//unmap gpu address
		if(buffer.base){
			Debug::log("sceGxmUnmapMemory()");
			sceGxmUnmapMemory(buffer.base);
		}
		
		//free memory block
		Debug::log("sceKernelFreeMemBlock()");
		sceKernelFreeMemBlock(memory);
	}
}

int FrameBuffer :: setupBuffer(){
	
	//setup parameters
	buffer.size = sizeof(SceDisplayFrameBuf);
	buffer.pitch = Graphics::WIDTH;
	buffer.pixelformat = SCE_DISPLAY_PIXELFORMAT_A8B8G8R8;
	buffer.width = Graphics::WIDTH;
	buffer.height = Graphics::HEIGHT;
	
	//create memory block
	Debug::log("sceKernelAllocMemBlock()");
	memory = sceKernelAllocMemBlock("FB", SCE_KERNEL_MEMBLOCK_TYPE_USER_CDRAM_RW, align_mem(buffer.width * buffer.height * 4, 256 * 1024), NULL);
	if(memory < 0)
		return 1;
	
	//get base address
	Debug::log("sceKernelGetMemBlockBase()");
	if(sceKernelGetMemBlockBase(memory, &buffer.base) < 0)
		return 2;
	
	if(!buffer.base)
		return 3;
	
	//map gpu address
	Debug::log("sceGxmMapMemory()");
	if(sceGxmMapMemory(buffer.base, align_mem(buffer.width * buffer.height * 4, 256 * 1024), SCE_GXM_MEMORY_ATTRIB_RW) < 0)
		return 4;
	
	return 0;
}

void FrameBuffer :: clear(){
	memset(buffer.base, 0x0, buffer.width * buffer.height * 4);
}

void FrameBuffer :: drawPixel(unsigned x, unsigned y, unsigned color){
	
	unsigned * start = (unsigned *) buffer.base;
	start[x + y * buffer.pitch] = color;
}

SceDisplayFrameBuf * FrameBuffer :: getBuffer(){
	return &buffer;
}

SceUID FrameBuffer :: getMemory() const {
	return memory;
}

bool FrameBuffer :: isReady() const {
	return ready;
}

