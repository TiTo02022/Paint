#ifndef CHEX_H
#define CHEX_H

#include "../Figures/CFigure.h"

class CHexagon : public CFigure
{
private:
	Point Center;
public:
	CHexagon(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool pointcheck(Point c);
	void Save(ofstream& OutFile, int y);
	void Load(ifstream& Infile, CFigure* &F);
	void move(int x, int y, CFigure*& l, CFigure*& m);
	void dlt(CFigure*& l);
	void clr(CFigure*& l, CFigure*& m);
};

#endif