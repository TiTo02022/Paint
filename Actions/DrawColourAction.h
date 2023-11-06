#ifndef DRAWCOLOUR_H
#define DRAWCOLOUR_H
#include "..\Figures\CFigure.h"
#include "Action.h"
class DrawColourAction : public Action
{
private:
	CFigure* R;
	CFigure* l;
	CFigure* m;
public:
	DrawColourAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute(bool co = true);

	void undo();
	void redo();
};
#endif



