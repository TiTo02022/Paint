#ifndef UNDO_ACTION_H
#define UNDO_ACTION_H

#include "Action.h"

//Add Undo Action class
class UndoAction : public Action
{
private:

public:
	UndoAction(ApplicationManager* pApp);

	//Reads circle parameters
	virtual void ReadActionParameters();

	//Add circle to the ApplicationManager
	virtual void Execute(bool co = true);

	void undo();
	void redo();
};

#endif