#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();		

	window* CreateWind(int, int, int , int) const; //creates the application window
	void CreateDrawToolBar1() const;	//creates Draw mode toolbar & menu
	void CreateDrawToolBar2() const;	//code for us
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar

	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	void ClearDrawArea1() const;
	
	// -- Figures Drawing functions
	
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected=false) const;  //Draw a rectangle
	void Drawcircle(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected = false);
	void DrawTriangele(Point P1, Point P2, Point P3, GfxInfo RectGfxInfo, bool selected);

	///Make similar functions for drawing all other figure types.
	void DrawPoly(Point P1, GfxInfo RectGfxInfo, bool selected = false) const;	//Draw a hexagon
	void DrawSqr(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected = false) const;	//Draw a square
	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	void setCrntDrawColor(color c) const;
	void setCrntFillColor(color c) const;

	int getCrntPenWidth() const;		//get current pen width

	
	~Output();
};

#endif