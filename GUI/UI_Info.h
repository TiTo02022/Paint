#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY	//Playing mode
};

enum DrawMenuItem1 //The items of the Draw menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_RECT,
	ITM_CIRC,
	ITM_SQR,
	ITM_TRI,
	ITM_HEX,
	ITM_SLCT_ONE,
	ITM_DRAW,
	ITM_FILL,
	ITM_RED,
	ITM_ORANGE,
	ITM_YELLOW,
	ITM_GREEN,
	ITM_BLUE,
	ITM_BLACK,

	DRAW_ITM_COUNT1		//no. of menu items ==> This should be the last line in this enum
	
};
enum DrawMenuItem2 //The items of the Draw menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_UNDO,
	ITM_REDO,
	ITM_DELETE,
	ITM_MOVE,
	ITM_CLEAR,
	ITM_START,
	ITM_STOP,
	ITM_PLAY,
	ITM_SAVE,
	ITM_LOAD,
	ITM_SWITCH,
	ITM_EXIT,

	DRAW_ITM_COUNT2		//no. of menu items ==> This should be the last line in this enum

};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here

	//TODO: Add more items names here
	ITM_SHAPE,
	ITM_COLOUR,
	ITM_BOTH,
	ITM_SWITCH_PLAY,
	ITM_EXIT_PLAY,

	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
};





__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	
	int	width, height,	    //Window width and height
		wx , wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu
	

	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed
	
}UI;	//create a global object UI

#endif;