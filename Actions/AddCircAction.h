#ifndef ADD_CIRC_ACTION_H
#define ADD_CIRC_ACTION_H

#include "Action.h"
#include "../Figures/CFigure.h"

//Add Circle Action class
class AddCircAction : public Action
{
private:
	Point P1, P2; //Circle center and Circumference
	GfxInfo RectGfxInfo;
	CFigure* R;
	CFigure* last;
	color dc;
	bool issel;
public:
	AddCircAction(ApplicationManager* pApp);

	//Reads circle parameters
	virtual void ReadActionParameters();

	//Add circle to the ApplicationManager
	virtual void Execute(bool co = true);
	
	void undo();
	void redo();
};

#endif
