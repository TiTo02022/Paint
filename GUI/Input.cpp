#include "Input.h"
#include "Output.h"


Input::Input(window* pW) 
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output *pO) const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;
			case ITM_CIRC: return DRAW_CIRC;
			case ITM_SQR:  return DRAW_SQR;
			case ITM_TRI:  return DRAW_TRI;
			case ITM_HEX:  return DRAW_HEX;
			case ITM_SLCT_ONE: return SLCT_ONE;
			case ITM_DRAW: return DRAW;
			case ITM_FILL: return FILL;
			case ITM_RED:  return RED1;
			case ITM_ORANGE: return ORANGE1;
			case ITM_YELLOW: return YELLOW1;
			case ITM_GREEN: return GREEN1;
			case ITM_BLUE: return BLUE1;
			case ITM_BLACK: return BLACK1;
			
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}
		if (y >= UI.ToolBarHeight && y < UI.ToolBarHeight*2)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_UNDO: return UNDO;
			case ITM_REDO: return REDO;
			case ITM_DELETE: return DLT1;
			case ITM_MOVE: return MOVE;
			case ITM_CLEAR: return CLEAR;
			case ITM_START: return START;
			case ITM_STOP: return STOP;
			case ITM_PLAY: return PLAY;
			case ITM_SAVE: return SAVE;
			case ITM_LOAD: return LOAD;
			case ITM_SWITCH: return TO_PLAY;
			case ITM_EXIT: return EXIT;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}
		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		///TODO:
		//perform checks similar to Draw mode checks above
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_SHAPE: return SHAPE;
			case ITM_COLOUR: return COLOUR;
			case ITM_BOTH: return BOTH;
			case ITM_SWITCH_PLAY: return TO_DRAW;
			case ITM_EXIT_PLAY: return EXIT;
			}
		}
		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;//and return the correspoding action
		return TO_PLAY;	//just for now. This should be updated
	}	

}
/////////////////////////////////
	
Input::~Input()
{
}
