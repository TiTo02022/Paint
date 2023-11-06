#ifndef ADD_TRI_ACTION_H
#define ADD_TRI_ACTION_H

#include "Action.h"
#include "../Figures/CFigure.h"

//Add Rectangle Action class
class AddTriAction : public Action
{
private:
	Point P1, P2, P3; //Rectangle Corners
	GfxInfo RectGfxInfo;
	CFigure* R;
	bool issel;
	CFigure* last;
	color dc;
public:
	AddTriAction(ApplicationManager* pApp);

	//Reads triangle parameters
	virtual void ReadActionParameters();

	//Add triangle to the ApplicationManager
	virtual void Execute(bool co = true);

	void undo();
	void redo();
};

#endif
