#include <fstream>
#include "CSquare.h"

CSquare::CSquare(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P1;
}


void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawSqr to draw a square on the screen	
	pOut->DrawSqr(Center, Center, FigGfxInfo, Selected);
}
bool CSquare::pointcheck(Point c)
{
	if (abs(Center.x - c.x) <= 100 && abs(Center.y - c.y) <= 100)
	{
		return true;
	}
	else

	{
		return false;
	}
}

void CSquare::Save(ofstream& f, int y) {
	int x = SQR1;
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
	f << x << "   " << y << "   " << Center.x << "   " << Center.y << "   " << z << "   " << fill << '\n';
}
void CSquare::Load(ifstream& f, CFigure* &R) {
	int z2;
	int fill2;
	//to get the colors to be saved
	f >> Center.x >> Center.y>> z2 >> fill2;
	setcolours(z2, fill2, FigGfxInfo);
	CSquare*p = new CSquare(Center, FigGfxInfo);
	R = p;
}
void CSquare::move(int x, int y, CFigure*& l, CFigure*& m) {
	l = new CSquare(Center, FigGfxInfo);
	//sets the new center
	Center.x = x;
	Center.y = y;
	m = new CSquare(Center, FigGfxInfo);
}
void CSquare::dlt(CFigure*& l) {
	l = new CSquare(Center, FigGfxInfo);
}

void CSquare::clr(CFigure*& l, CFigure*& m) {
	l = new CSquare(Center, FigGfxInfo);
}