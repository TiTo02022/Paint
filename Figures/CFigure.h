#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	color nc;

	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);

	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected

	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	GfxInfo getcolourinfo(); //getter for the the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	void ChngDrawClr(color Dclr); //changes the figure's drawing color
	color getnc();
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	
	void setcolours(int z2, int fill2, GfxInfo& FigureGfxInfo);///sets the color of each figure
	virtual bool pointcheck(Point) = 0;//check if the given point is inside any figure
	virtual void Save(ofstream& OutFile, int y) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream& Infile, CFigure*& F) = 0;	//Load the figure parameters to the file
	virtual void move(int x, int y, CFigure*& l, CFigure*& m) = 0;  //to move the figure
	virtual void dlt(CFigure*& l) = 0;  //to delete the figure
	virtual void clr(CFigure*& l, CFigure*& m) = 0;
	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
};

#endif