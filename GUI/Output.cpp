#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 70;
	UI.MenuItemWidth = 70;
	
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar1();
	CreateDrawToolBar2();

	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight*2, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar1() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT1];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\IconsImages\\rect.jpg";
	MenuItemImages[ITM_CIRC] = "images\\MenuItems\\IconsImages\\circ.jpg";
	MenuItemImages[ITM_SQR] = "images\\MenuItems\\IconsImages\\squ.jpg";
	MenuItemImages[ITM_TRI] = "images\\MenuItems\\IconsImages\\tri.jpg";
	MenuItemImages[ITM_HEX] = "images\\MenuItems\\IconsImages\\hexa.jpg";
	MenuItemImages[ITM_SLCT_ONE] = "images\\MenuItems\\IconsImages\\select.jpg";
	MenuItemImages[ITM_DRAW] = "images\\MenuItems\\IconsImages\\draw.jpg";
	MenuItemImages[ITM_FILL] = "images\\MenuItems\\IconsImages\\fill.jpg";
	MenuItemImages[ITM_RED] = "images\\MenuItems\\IconsImages\\red.jpg";
	MenuItemImages[ITM_ORANGE] = "images\\MenuItems\\IconsImages\\orange.jpg";
	MenuItemImages[ITM_YELLOW] = "images\\MenuItems\\IconsImages\\yellow.jpg";
	MenuItemImages[ITM_GREEN] = "images\\MenuItems\\IconsImages\\green.jpg";
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\IconsImages\\blue.jpg";
	MenuItemImages[ITM_BLACK] = "images\\MenuItems\\IconsImages\\black.jpg";

	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT1; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
	for (int i = 0; i < DRAW_ITM_COUNT1; i++) {
		pWind->SetPen(RED, 3);
		pWind->DrawLine(i * UI.MenuItemWidth, 0, i * UI.MenuItemWidth, UI.ToolBarHeight);
	}

}
void Output::CreateDrawToolBar2() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT2];
	MenuItemImages[ITM_UNDO] = "images\\MenuItems\\IconsImages\\undo.jpg";
	MenuItemImages[ITM_REDO] = "images\\MenuItems\\IconsImages\\redo.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\IconsImages\\delete.jpg";
	MenuItemImages[ITM_MOVE] = "images\\MenuItems\\IconsImages\\move.jpg";
	MenuItemImages[ITM_CLEAR] = "images\\MenuItems\\IconsImages\\clear.jpg";
	MenuItemImages[ITM_START] = "images\\MenuItems\\IconsImages\\start.jpg";
	MenuItemImages[ITM_STOP] = "images\\MenuItems\\IconsImages\\stop.jpg";
	MenuItemImages[ITM_PLAY] = "images\\MenuItems\\IconsImages\\play.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\IconsImages\\save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\IconsImages\\load.jpg";
	MenuItemImages[ITM_SWITCH] = "images\\MenuItems\\IconsImages\\switch.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\IconsImages\\exit.jpg";
	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT2; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, UI.ToolBarHeight, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight*2, UI.width, UI.ToolBarHeight*2);
	for (int i = 0; i < DRAW_ITM_COUNT2; i++) {
		pWind->SetPen(RED, 3);
		pWind->DrawLine(i * UI.MenuItemWidth, UI.ToolBarHeight, i * UI.MenuItemWidth, UI.ToolBarHeight * 2);
	}


}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	///TODO: write code to create Play mode menu
	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_SHAPE] = "images\\MenuItems\\IconsImages\\shape.jpg";
	MenuItemImages[ITM_COLOUR] = "images\\MenuItems\\IconsImages\\colour.jpg";
	MenuItemImages[ITM_BOTH] = "images\\MenuItems\\IconsImages\\both.jpg";
	MenuItemImages[ITM_SWITCH_PLAY] = "images\\MenuItems\\IconsImages\\switch.jpg";
	MenuItemImages[ITM_EXIT_PLAY] = "images\\MenuItems\\IconsImages\\exit.jpg";
	//Draw menu item one image at a time
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight*2, UI.width, UI.height - UI.StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea1() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::setCrntDrawColor(color c) const	//get current drawing color
{
	UI.DrawColor = c;
}
void Output::setCrntFillColor(color c) const	//get current filling color
{
	 UI.FillColor=c;
}

int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);	
}
void Output::Drawcircle(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) {
	const double rad = (double)sqrt(((pow((P2.x - P1.x),2) + pow((P2.y - P1.y),2))));
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawCircle(P1.x, P1.y, rad, style);

}

void Output::DrawTriangele(Point P1, Point P2, Point P3, GfxInfo RectGfxInfo, bool selected) {
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
}
void Output::DrawSqr(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;
	int RF = 1; //Resize factor 
	P1.x = P1.x - (RF * 100);
	P1.y = P1.y - (RF * 100);
	P2.x = P1.x + (RF * 200);
	P2.y = P1.y + (RF * 200);

	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}

void Output::DrawPoly(Point P1, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;
	int RF = 1; //Resize factor
	const int Ax[6] = { P1.x,P1.x + (RF * 70),P1.x + (RF * 70),P1.x,P1.x - (RF * 70),P1.x - (RF * 70) };
	const int Ay[6] = { P1.y + (RF * 80),P1.y + (RF * 40),P1.y - (RF * 40),P1.y - (RF * 80),P1.y - (RF * 40),P1.y + (RF * 40) };

	pWind->DrawPolygon(Ax, Ay, 6, style);

}
//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

