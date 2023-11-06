#ifndef CTRI_H
#define CTRI_H

#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool pointcheck(Point c);
	void Save(ofstream& OutFile, int y);
	void Load(ifstream& Infile, CFigure* &F);
	void move (int x, int y, CFigure*& l, CFigure*& m);
	void dlt(CFigure*& l);
	void clr(CFigure*& l, CFigure*& m);
};

#endif