#include <fstream>
#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}
bool CRectangle::pointcheck(Point c)
{
	int x1, x2, y1, y2;
	if (Corner1.x > Corner2.x)
	{
		x1 = Corner1.x;
		x2 = Corner2.x;
	}
	else
	{
		x1 = Corner2.x;
		x2 = Corner1.x;
	}
	if (Corner1.y > Corner2.y)
	{
		y1 = Corner1.y;
		y2 = Corner2.y;
	}
	else
	{
		y1 = Corner2.y;
		y2 = Corner1.y;
	}
	if (c.x> x2 && c.x<x1 && c.y>y2 && c.y < y1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void CRectangle::Save(ofstream& f, int y) {
	int x = RECT1;
	int z;
	int fill;
	//to get the colors to be saved
	if (FigGfxInfo.DrawClr == RED)
		z = RED2;
	else if (FigGfxInfo.DrawClr == ORANGE)
		z = ORANGE2;
	else if (FigGfxInfo.DrawClr == YELLOW)
		z = YELLOW2;
	else if (FigGfxInfo.DrawClr == GREEN)
		z = GREEN2;
	else if (FigGfxInfo.DrawClr == BLUE)
		z = BLUE2;
	else if (FigGfxInfo.DrawClr == BLACK)
		z = BLACK2;
	else if (FigGfxInfo.DrawClr == MAGENTA)
		z = MAGENTA2;
	if (FigGfxInfo.isFilled) {
		if (FigGfxInfo.FillClr == RED)
			fill = RED2;
		else if (FigGfxInfo.FillClr == ORANGE)
			fill = ORANGE2;
		else if (FigGfxInfo.FillClr == YELLOW)
			fill = YELLOW2;
		else if (FigGfxInfo.FillClr == GREEN)
			fill = GREEN2;
		else if (FigGfxInfo.FillClr == BLUE)
			fill = BLUE2;
		else if (FigGfxInfo.FillClr == BLACK)
			fill = BLACK2;
	}
	else
		fill = Nofill2;
	//writes the info in the file
	f << x  <<"   "<< y<<"   " << Corner1.x <<"   "<< Corner1.y <<"   "<< Corner2.x <<"   "<< Corner2.y <<"   "<< z <<"   "<< fill << '\n';
}
void CRectangle::Load(ifstream& f, CFigure* &R) {
	int z2;
	int fill2;
	//to get the colors to be saved
	f >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> z2 >> fill2;
	setcolours(z2, fill2, FigGfxInfo);
	CRectangle *p = new CRectangle(Corner1, Corner2, FigGfxInfo);
	R = p;
}
void CRectangle::move(int x, int y, CFigure*& l, CFigure*& m) {
	l = new CRectangle(Corner1, Corner2, FigGfxInfo);
	//gets the difference between the center and the destination point 
	float avx = (Corner1.x + Corner2.x) / (2.0);
	float avy = (Corner1.y + Corner2.y) / (2.0);
	float x1 = x - avx;
	float y1 = y - avy;
	Corner1.x += x1;
	Corner2.x += x1;
	Corner1.y += y1;
	Corner2.y += y1;
	m = new CRectangle(Corner1, Corner2, FigGfxInfo);
}
void CRectangle::dlt(CFigure*& l) {
	l = new CRectangle(Corner1, Corner2, FigGfxInfo);
}

void CRectangle::clr(CFigure*& l, CFigure*& m) {
	l = new CRectangle(Corner1, Corner2, FigGfxInfo);
}