#ifndef FILLCOLOUR_H
#define FILLCOLOUR_H
#include "..\Figures\CFigure.h"
#include "Action.h"
class FillColourAction : public Action
{
private:
	CFigure* R;
	CFigure* z;
	CFigure* m;
public:
	FillColourAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute(bool co = true);

	void undo();
	void redo();
};
#endif




