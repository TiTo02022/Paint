#include <fstream>
#include "CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}


void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawSqr to draw a square on the screen	
	pOut->DrawTriangele(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}
bool CTriangle::pointcheck(Point v)
{
	Point v0;
	v0.x = Corner1.x;
	v0.y = Corner1.y;
	Point v1;
	Point v2;
	v1.x = (Corner2.x - Corner1.x);
	v1.y = (Corner2.y - Corner1.y);
	v2.x = (Corner3.x - Corner1.x);
	v2.y = (Corner3.y - Corner1.y);
	float dvv1, dvv2, dv0v1, dv0v2, dv1v2;
	dvv1 = (v.x * v1.y) - (v.y * v1.x);
	dvv2 = (v.x * v2.y) - (v.y * v2.x);
	dv0v1 = (v0.x * v1.y) - (v0.y * v1.x);
	dv0v2 = (v0.x * v2.y) - (v0.y * v2.x);
	dv1v2 = (v1.x * v2.y) - (v1.y * v2.x);
	float a, b;
	a = (dvv2 - dv0v2) / dv1v2;
	b = -(dvv1 - dv0v1) / dv1v2;
	if (a > 0 && b > 0 && (a + b) < 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void CTriangle::Save(ofstream& f, int y) {
	int x = TRI1;
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
	f << x << "   " << y << "   " << Corner1.x << "   " << Corner1.y << "   " << Corner2.x << "   " << Corner2.y << "   " <<Corner3.x << "   " <<Corner3.y << "   " << z << "   " << fill << '\n';
}
void CTriangle::Load(ifstream& f, CFigure* & R) {
	int z2;
	int fill2;
	//reads the info of figure from the file 
	f >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >>Corner3.x>>Corner3.y>> z2 >> fill2;
	setcolours(z2, fill2, FigGfxInfo);
	CTriangle * p = new CTriangle(Corner1, Corner2,Corner3, FigGfxInfo);
	R = p;
}
void CTriangle::move(int x, int y, CFigure*& l, CFigure*& m) {
	l = new CTriangle(Corner1, Corner2, Corner3, FigGfxInfo);
	int maxx;
	int minx;
	int maxy;
	int miny;
	//gets the max of x and y and min of x and y
	if (Corner1.x > Corner2.x && Corner1.x > Corner3.x)
		maxx = Corner1.x;
	else if (Corner2.x > Corner1.x && Corner2.x > Corner3.x)
		maxx = Corner2.x;
	else
		maxx = Corner3.x;
	if (Corner1.x < Corner2.x && Corner1.x < Corner3.x)
		minx = Corner1.x;
	else if (Corner2.x < Corner1.x && Corner2.x < Corner3.x)
		minx = Corner2.x;
	else
		minx = Corner3.x;
	if (Corner1.y > Corner2.y && Corner1.y > Corner3.y)
		maxy = Corner1.y;
	else if (Corner2.y > Corner1.y && Corner2.y > Corner3.y)
		maxy = Corner2.y;
	else
		maxy = Corner3.y;
	if (Corner1.y < Corner2.y && Corner1.y < Corner3.y)
		miny = Corner1.y;
	else if (Corner2.y < Corner1.y && Corner2.y < Corner3.y)
		miny = Corner2.y;
	else
		miny = Corner3.y;
	//gets kind of center to the triangle
	float avx = (maxx + minx) / (2.0);
	float avy = (maxy + miny) / (2.0);
	//gets the difference between the center and the destination point 
	float x1 = x - avx;
	float y1 = y - avy;
	Corner1.x += x1;
	Corner2.x += x1;
	Corner3.x += x1;
	Corner1.y += y1;
	Corner2.y += y1;
	Corner3.y += y1;
	m = new CTriangle(Corner1, Corner2, Corner3, FigGfxInfo);

}
void CTriangle::dlt(CFigure*& l) {
	l = new CTriangle(Corner1, Corner2, Corner3, FigGfxInfo);
}

void CTriangle::clr(CFigure*& l, CFigure*& m) {
	l = new CTriangle(Corner1, Corner2, Corner3, FigGfxInfo);
}