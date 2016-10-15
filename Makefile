CC := arm-vita-eabi-gcc
CXX := arm-vita-eabi-g++
STRIP := arm-vita-eabi-strip

PROJECT := milieTetris
CXXFLAGS += -std=c++11 -I$(VITASDK)/arm-vita-eabi/include -L$(VITASDK)/arm-vita-eabi/lib
LIBS := -lc -lSceKernel_stub -lSceDisplay_stub -lSceGxm_stub -lSceCtrl_stub -lSceTouch_stub
OBJS := src/Main.o src/Menu.o src/Record.o src/Tetris.o src/Piece.o src/Text.o src/Map.o src/gb/Graphics.o src/gb/FrameBuffer.o src/gb/Debug.o src/gb/Input.o

all: $(PROJECT).velf

$(PROJECT).velf: $(PROJECT).elf
	$(STRIP) -g $<
	vita-elf-create $(PROJECT).elf $(PROJECT).velf db.json
	vita-make-fself -s $(PROJECT).velf eboot.bin
	vita-mksfoex -s TITLE_ID=GBOT00001 $(PROJECT) sce_sys/param.sfo
	7z a -tzip $(PROJECT).vpk -r sce_sys/* eboot.bin 
	rm $(OBJS) *.elf *.velf *.bin
	
$(PROJECT).elf: $(OBJS)
	$(CXX) -Wl,-q $(CXXFLAGS) -o $@ $^ $(LIBS) 

clean:
	-rm -f build/*.* $(PROJECT).elf *.velf $(OBJS) *.vpk
