#include "Graphics.h"
#include "Debug.h"

static Graphics * instance = NULL;

Graphics * Graphics :: getInstance(){
		
	//get/create graphics
	if(!instance){
		
		//try to create graphics object
		Graphics * ret = new Graphics();
		if(!ret->isReady())
			delete ret;
		else
			instance = ret;
	}
	
	return instance;
}
	
void Graphics:: end(){
	
	if(instance){
		
		delete instance;
		instance = NULL;
	}
}

Graphics :: Graphics(){
	
	ready = false;
	currentBuffer = 0;
	
	//set gxm parameters
	SceGxmInitializeParams params;
	params.flags = 0;
	params.displayQueueMaxPendingCount = 2;
	params.displayQueueCallback = 0;
	params.displayQueueCallbackDataSize = 0;
	params.parameterBufferSize = 16 * 1024 * 1024;

	//start gxm
	Debug::log("sceGxmInitialize()");
	if(!sceGxmInitialize(&params)){
	
		//try to create framebuffers
		Debug::log("FrameBuffer::create()");
		frameBuffer[0] = FrameBuffer::create();
		frameBuffer[1] = FrameBuffer::create();
		
		if(frameBuffer[0] && frameBuffer[1]){
			
			//initial buffer swap
			swapBuffer();
			ready = true;
		}
	}
}
	
Graphics :: ~Graphics(){
	
	//delete framebuffers
	if(frameBuffer[0])
		delete frameBuffer[0];
	
	if(frameBuffer[1])
		delete frameBuffer[1];
	
	//end gxm
	sceGxmTerminate();
}

void Graphics :: clear(){
	frameBuffer[currentBuffer]->clear();
}

void Graphics :: drawPixel(unsigned x, unsigned y, unsigned color){
	frameBuffer[currentBuffer]->drawPixel(x, y, color);
}

void Graphics :: drawRectangle(unsigned x, unsigned y, unsigned width, unsigned height, unsigned color){
	
	if(x < 0 || y < 0 || x + width > WIDTH || y + height > HEIGHT)
		return;
		
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			drawPixel(x + j, y + i, color);
		}
	}
}

void Graphics :: drawRectangleBorder(unsigned x, unsigned y, unsigned width, unsigned height, unsigned color){
	
	if(x < 0 || y < 0 || x + width > WIDTH || y + height > HEIGHT)
		return;
		
	for(int i = 0; i < width; i++){
		drawPixel(x + i, y, color);
		drawPixel(x + i, y + height, color);
	}
	
	for(int j = 0; j < height; j++){
		drawPixel(x, y + j, color);
		drawPixel(x + width, y + j, color);
	}
}

void Graphics :: swapBuffer(){

	sceDisplaySetFrameBuf(frameBuffer[currentBuffer]->getBuffer(), SCE_DISPLAY_SETBUF_NEXTFRAME);
	sceDisplayWaitVblankStart();
	
	currentBuffer = !currentBuffer? 1: 0;
}

bool Graphics :: isReady() const{
	
	return ready;
}