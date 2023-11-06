#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

void CFigure::SetSelected(bool s)
{	
	nc = FigGfxInfo.DrawClr;
	Selected = s; }


color CFigure::getnc()
{
	return nc;
}

bool CFigure::IsSelected() const
{	return Selected; }

GfxInfo CFigure::getcolourinfo() {
	return FigGfxInfo;
}

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}
void CFigure:: setcolours(int z2, int fill2, GfxInfo& FigureGfxInfo) {
	
	if (z2 == RED2)
		FigGfxInfo.DrawClr = RED;
	else if (z2 == ORANGE2)
		FigGfxInfo.DrawClr = ORANGE;
	else if (z2 == YELLOW2)
		FigGfxInfo.DrawClr = YELLOW;
	else if (z2 == GREEN2)
		FigGfxInfo.DrawClr = GREEN;
	else if (z2 == BLUE2)
		FigGfxInfo.DrawClr = BLUE;
	else if (z2 == BLACK2)
		FigGfxInfo.DrawClr = BLACK;
	else if (z2 == MAGENTA2)
		FigGfxInfo.DrawClr = MAGENTA;
	if (fill2 != Nofill2) {
		if (fill2 == RED2)
			FigGfxInfo.FillClr = RED;
		else if (fill2 == ORANGE2)
			FigGfxInfo.FillClr = ORANGE;
		else if (fill2 == YELLOW2)
			FigGfxInfo.FillClr = YELLOW;
		else if (fill2 == GREEN2)
			FigGfxInfo.FillClr = GREEN;
		else if (fill2 == BLUE2)
			FigGfxInfo.FillClr = BLUE;
		else if (fill2 == BLACK2)
			FigGfxInfo.FillClr = BLACK;
	}
	else
		FigGfxInfo.isFilled = false;

}

