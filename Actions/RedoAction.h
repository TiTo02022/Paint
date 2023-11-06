#ifndef REDO_ACTION_H
#define REDO_ACTION_H

#include "Action.h"

//Add Undo Action class
class RedoAction : public Action
{
private:

public:
	RedoAction(ApplicationManager* pApp);

	//Reads circle parameters
	virtual void ReadActionParameters();

	//Add circle to the ApplicationManager
	virtual void Execute(bool co = true);

	void undo();
	void redo();
};

#endif