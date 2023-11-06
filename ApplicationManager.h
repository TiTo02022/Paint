#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Actions/Action.h"
#include "Actions/AddCircAction.h"
#include "Actions/AddHexAction.h"
#include "Actions/AddRectAction.h"
#include "Actions/AddSqrAction.h"
#include "Actions/AddTriAction.h"

#include "Actions\BothAction.h"
#include "Actions\ClearAllAction.h"
#include "Actions\ColourAction.h"
#include "Actions\DeleteAction.h"
#include "Actions/DrawColourAction.h"
#include"Actions\ExitAction.h"

#include "Actions/FillColourAction.h"
#include"Actions\LoadAction.h"
#include "Actions\MoveAction.h"
#include "Actions\PlayRecord.h"
#include "Actions\Record.h"

#include"Actions\SaveAction.h"
#include "Actions\SelectAction.h"
#include "Actions\ShapeAction.h"
#include "Actions\Stop.h"
#include"Actions\SwitchToDrawAction.h"
#include"Actions\SwitchToPlayAction.h"
#include "Actions\UndoAction.h"
#include "Actions\RedoAction.h"

#include "DEFS.h"
#include "Figures/CFigure.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include <fstream>
#include <Windows.h>

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	int RecCount;
	bool isrec;
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure
	CFigure* lastSelectedFig;

	Action* lastaction;

	Action* last5[5];
	int last5count;
	int maxredo;
	bool fill; //indicates if the next figure is filled or not
	CFigure* A;
	Action *RecList[20]; //array of size max 20

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

public:	
	ApplicationManager(); 
	~ApplicationManager();

	// -- Action-Related Functions
	int figureC();
	void setisrec(bool r);
	bool getisrec();
	int getRcount();
	void Playrecord();
	void Addundo(Action* l);
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	void Deleteandarrangelist(CFigure* pFig);
	
	
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	void Addreco(Action* arec);
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void setselfig(CFigure* c);
	void setlastselfig(CFigure* t);
	CFigure* getselfig();
	CFigure* getlastselfig();
	void setisfill(bool c);
	bool isfilled();
	void clearActions(bool p);
	void Undo();
	void Redo();
	void swap(CFigure*& l, CFigure*& m, CFigure*& R);
		
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void SaveAll(ofstream& f);
	void UpdateInterface() const;	//Redraws all the drawing window	
};

#endif