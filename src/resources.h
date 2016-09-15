#ifndef RESOURCES_H
#define RESOURCES_H

const char tetrisFont[][6][7] = {
	{
		"XXXXX",
		"X   X",
		"X   X",
		"X   X",
		"XXXXX"
	},
	{
		"    X",
		"    X",
		"    X",
		"    X",
		"    X"
	},
	{
		"XXXXX",
		"    X",
		"XXXXX",
		"X    ",
		"XXXXX"
	},
	{
		"XXXXX",
		"    X",
		"XXXXX",
		"    X",
		"XXXXX"
	},
	{
		"X   X",
		"X   X",
		"XXXXX",
		"    X",
		"    X"
	},
	{
		"XXXXX",
		"X    ",
		"XXXXX",
		"    X",
		"XXXXX"
	},
	{
		"XXXXX",
		"X    ",
		"XXXXX",
		"X   X",
		"XXXXX"
	},
	{
		"XXXXX",
		"    X",
		"    X",
		"    X",
		"    X"
	},
	{
		"XXXXX",
		"X   X",
		"XXXXX",
		"X   X",
		"XXXXX"
	},
	{
		"XXXXX",
		"X   X",
		"XXXXX",
		"    X",
		"    X"
	},
	{
		"XXXXX",
		"XXXXX",
		"XXXXX",
		"XXXXX",
		"XXXXX"
	},
	{
		"XXXXX",
		"XXXXX",
		"XXXXX",
		"XXXXX",
		"XXXXX"
	},
	{
		"XXXXX",
		"XXXXX",
		"XXXXX",
		"XXXXX",
		"XXXXX"
	},
	{
		"XXXXX",
		"XXXXX",
		"XXXXX",
		"XXXXX",
		"XXXXX"
	},
	{
		"XXXXX",
		"XXXXX",
		"XXXXX",
		"XXXXX",
		"XXXXX"
	},
	{
		"XXXXX",
		"XXXXX",
		"XXXXX",
		"XXXXX",
		"XXXXX"
	},
	{
		"XXXXX",
		"XXXXX",
		"XXXXX",
		"XXXXX",
		"XXXXX"
	},
	{
		"XXXXX",
		"X   X",
		"XXXXX",
		"X   X",
		"X   X"
	},
	{
		"XXXX ",
		"X   X",
		"XXXX ",
		"X   X",
		"XXXX "
	},
	{
		"XXXXX",
		"X    ",
		"X    ",
		"X    ",
		"XXXXX"
	},
	{
		"XXXX ",
		"X   X",
		"X   X",
		"X   X",
		"XXXX "
	},
	{
		"XXXXX",
		"X    ",
		"XXXXX",
		"X    ",
		"XXXXX"
	},
	{
		"XXXXX",
		"X    ",
		"XXXXX",
		"X    ",
		"X    "
	},
	{
		"XXXXX",
		"X    ",
		"X  XX",
		"X   X",
		"XXXXX"
	},
	{
		"X   X",
		"X   X",
		"XXXXX",
		"X   X",
		"X   X"
	},
	{
		"  X  ",
		"  X  ",
		"  X  ",
		"  X  ",
		"  X  "
	},
	{
		"    X",
		"    X",
		"X   X",
		"X   X",
		" XXXX"
	},
	{
		"X   X",
		"X  X ",
		"XXX  ",
		"X  X ",
		"X   X"
	},
	{
		"X    ",
		"X    ",
		"X    ",
		"X    ",
		"XXXXX"
	},
	{
		"X   X",
		"XX XX",
		"X X X",
		"X   X",
		"X   X"
	},
	{
		"X   X",
		"XX  X",
		"X X X",
		"X  XX",
		"X   X"
	},
	{
		"XXXXX",
		"X   X",
		"X   X",
		"X   X",
		"XXXXX"
	},
	{
		"XXXXX",
		"X   X",
		"XXXXX",
		"X    ",
		"X    "
	},
	{
		"XXXXX",
		"X   X",
		"X   X",
		"X X X",
		"XXXXX"
	},
	{
		"XXXX ",
		"X   X",
		"XXXX ",
		"X  X ",
		"X   X"
	},
	{
		"XXXXX",
		"X    ",
		"XXXXX",
		"    X",
		"XXXXX"
	},
	{
		"XXXXX",
		"  X  ",
		"  X  ",
		"  X  ",
		"  X  "
	},
	{
		"X   X",
		"X   X",
		"X   X",
		"X   X",
		" XXX "
	},
	{
		"X   X ",
		"X   X",
		"X   X",
		" X X ",
		"  X  "
	},
	{
		"X   X",
		"X   X",
		"X X X",
		"X X X",
		" X X "
	},
	{
		"X   X",
		" X X ",
		"  X  ",
		" X X ",
		"X   X"
	},
	{
		"X   X",
		" X X ",
		"  X  ",
		"  X  ",
		"  X  "
	},
	{
		"XXXXX",
		"   X ",
		"  X  ",
		" X   ",
		"XXXXX"
	}
};

const int colorsCount = 6;
const unsigned colors[colorsCount] = {
	/*0xFF0000FF,
	0x00FF00FF,
	0x0000FF00,
	0x00FFFFFF,
	0xFF00FFFF,
	0xFFFFFFFF*/
	0xFFFFFFFF,
	0xAAAAAAAA,
	0x88888888,
	0x55555555,
	0x44444444,
	0xCCCCCCCC
};

const int piecesCount = 7;
const unsigned char pieces[piecesCount][4][5] = {
	{
		"  X ",
		"  X ",
		"  X ",
		"  X "
	},
	{
		" X  ",
		" X  ",
		" XX ",
		"    "
	},
	{
		"  X ",
		"  X ",
		" XX ",
		"    "
	},
	{
		"    ",
		" XX ",
		" XX ",
		"    "
	},
	{
		"    ",
		" X  ",
		"XXX ",
		"    "
	},
	{
		"    ",
		" XX ",
		"XX  ",
		"    "
	},
	{
		"    ",
		" XX ",
		"  XX",
		"    "
	}
};

#endif