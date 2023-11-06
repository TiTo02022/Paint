#ifndef CSQR_H
#define CSQR_H

#include "CFigure.h"

class CSquare : public CFigure
{
private:
	Point Center;
public:
	CSquare(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool pointcheck(Point c);
	void Save(ofstream& OutFile, int y);
	void Load(ifstream& Infile, CFigure* &F);
	void move(int x, int y, CFigure*& l, CFigure*& m);
	void dlt(CFigure*& l);
	void clr(CFigure*& l, CFigure*& m);
};

#endif