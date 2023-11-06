#ifndef CCIRC_H
#define CCIRC_H

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point Cen;
	Point Cir;
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool pointcheck(Point c);
	void Save(ofstream& OutFile, int y);
	void Load(ifstream& Infile, CFigure*& F);
	void move(int x, int y, CFigure*& l, CFigure*& m);
	void dlt(CFigure*& l);
	void clr(CFigure*& l, CFigure*& m);
};

#endif