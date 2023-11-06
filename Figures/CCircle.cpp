#include <fstream>
#include "CCircle.h"

CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Cen = P1;
	Cir = P2;
}


void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawCirc to draw a circle on the screen	
	pOut->Drawcircle(Cen, Cir, FigGfxInfo, Selected);
}

bool CCircle::pointcheck(Point c)
{
	int r = sqrt(pow((Cen.x - Cir.x), 2) + pow((Cen.y - Cir.y), 2));
	int d = sqrt(pow((Cen.x - c.x), 2) + pow((Cen.y - c.y), 2));
	if (d <= r)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void CCircle::Save(ofstream& f, int y){
	int x = CIRC1;
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
	f << x << "   " << y << "   " << Cen.x << "   " << Cen.y << "   " << Cir.x << "   " << Cir.y << "   " << z << "   " << fill << '\n';
}
void CCircle::Load(ifstream& f, CFigure* &R) {
	int z2;
	int fill2;
	//to get the colors to be saved
	f >> Cen.x >> Cen.y >> Cir.x >> Cir.y >> z2 >> fill2;
	setcolours(z2, fill2, FigGfxInfo);
	CCircle* p = new CCircle(Cen, Cir, FigGfxInfo);
	R = p;
}
void CCircle::move(int x, int y, CFigure*& l, CFigure*& m) {
	l = new CCircle(Cen, Cir, FigGfxInfo);
	int x2 = Cir.x - Cen.x;
	int y2 = Cir.y - Cen.y;
	//sets the new center and adjusts the circumfrence
	Cen.x = x;
	Cen.y = y;
	Cir.x = x + x2;
	Cir.y = y + y2;
	m = new CCircle(Cen, Cir, FigGfxInfo);
}
void CCircle::dlt(CFigure*& l) {
	l = new CCircle(Cen, Cir, FigGfxInfo);
}
void CCircle::clr(CFigure*& l, CFigure*& m) {
	l = new CCircle(Cen, Cir, FigGfxInfo);
}