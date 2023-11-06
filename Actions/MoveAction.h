#ifndef MOVE_H
#define MOVE_H
#include "..\Figures\CFigure.h"
#include "Action.h"
class MoveAction : public Action
{
private:
	CFigure* R;
	CFigure* l;
	CFigure* m;
public:
	MoveAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute(bool co = true);

	void undo();
	void redo();
};
#endif


