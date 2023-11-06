#ifndef SELECT_ACTION_H
#define SELECT_ACTION_H

#include "Action.h"
#include "../Figures/CFigure.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
class SelectAction: public Action
{
private:
	Point P1;
	CFigure* fig;
	color nc;
public:
	SelectAction(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute(bool co = true);

	void undo();
	void redo();
};

#endif