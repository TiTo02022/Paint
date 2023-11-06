#ifndef ADD_HEX_ACTION_H
#define ADD_HEX_ACTION_H

#include "Action.h"
#include "../Figures/CFigure.h"

//Add Hexagon Action class
class AddHexAction : public Action
{
private:
	Point P1; //Hexagon center
	GfxInfo RectGfxInfo;
	CFigure* R;
	CFigure* last;
	color dc;
	bool issel;
public:
	AddHexAction(ApplicationManager* pApp);

	//Reads hexagon parameters
	virtual void ReadActionParameters();

	//Add hexagon to the ApplicationManager
	virtual void Execute(bool co = true);

	void undo();
	void redo();
};

#endif
