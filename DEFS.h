#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_RECT,		//Draw Rectangle
	DRAW_CIRC,
	DRAW_SQR,
	DRAW_TRI,
	DRAW_HEX,
	SLCT_ONE,
	DRAW,
	FILL,
	RED1,
	ORANGE1,
	YELLOW1,
	GREEN1,
	BLUE1,
	BLACK1,
	UNDO,
	REDO,
	DLT1,
	MOVE,
	CLEAR,
	START,
	STOP,
	PLAY,
	SAVE,
	LOAD,
	EXIT,			//Exit
	TO_PLAY,         //Switch interface to Play mode
	TO_DRAW,		//Switch interface to Draw mode
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	SHAPE,
	COLOUR,
	BOTH,
	///TODO: Add the other action types of the two modes
};
enum figuretype {
	RECT1=11,
	CIRC1=12,
	SQR1=13,
	TRI1=14,
	HEX1=15,
};
enum colourtype {
	RED2=20,
	ORANGE2=21,
	YELLOW2=22,
	GREEN2=23,
	BLUE2=24,
	BLACK2=25,
	Nofill2=26,
	MAGENTA2=27,
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif