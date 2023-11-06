#include <fstream>
#include "CHexagon.h"
#include "CRectangle.h"
#include "CTriangle.h"

CHexagon::CHexagon(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
}


void CHexagon::Draw(Output* pOut) const
{
	//Call Output::DrawHex to draw a hexagon on the screen	
	pOut->DrawPoly(Center, FigGfxInfo, Selected);
}
bool CHexagon::pointcheck(Point c)
{
	Point p1, p2, p3, p4, p5, p6, p7, p8;
	p1.x = Center.x - 70;
	p1.y = Center.y + 40;
	p2.x = Center.x + 70;
	p2.y = Center.y - 40;
	p3.x = Center.x;
	p3.y = Center.y + 80;
	p4.x = Center.x - 70;
	p4.y = Center.y + 40;
	p5.x = Center.x + 70;
	p5.y = Center.y + 40;
	p6.x = Center.x;
	p6.y = Center.y - 80;
	p7.x = Center.x - 70;
	p7.y = Center.y - 40;
	p8.x = Center.x + 70;
	p8.y = Center.y - 40;
	CRectangle r(p1, p2, FigGfxInfo);
	CTriangle t1(p3, p4, p5, FigGfxInfo);
	CTriangle t2(p6, p7, p8, FigGfxInfo);
	int h;
	h = 0;
	h = r.pointcheck(c) + t1.pointcheck(c) + t2.pointcheck(c);
	if (h > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void CHexagon::Save(ofstream& f, int y) {
	int x = HEX1;
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
	f << x <<"   " << y<<"    " << Center.x <<"    " << Center.y <<"    " << z <<"    " << fill << '\n';
}
void CHexagon::Load(ifstream& f, CFigure* &R) {
	int z2;
	int fill2;
	//to get the colors to be saved
	f >> Center.x >> Center.y >> z2 >> fill2;
	setcolours(z2, fill2, FigGfxInfo);
	CHexagon *p = new CHexagon(Center, FigGfxInfo);
	R = p;
}
void CHexagon::move(int x, int y, CFigure*& l, CFigure*& m) {
	l = new CHexagon(Center, FigGfxInfo);
	//sets the new center
	Center.x = x;
	Center.y = y;
	m = new CHexagon(Center, FigGfxInfo);
}
void CHexagon::dlt(CFigure*& l) {
	l = new CHexagon(Center, FigGfxInfo);
}

void CHexagon::clr(CFigure*& l, CFigure*& m) {
	l = new CHexagon(Center, FigGfxInfo);
}