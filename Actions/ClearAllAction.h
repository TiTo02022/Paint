#ifndef CLEARALLACTION_H
#define CLEARALLACTION_H
#include "Action.h"
class ClearAllAction : public Action
{
public:
	ClearAllAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute(bool co = true);

	void undo();
	void redo();
};
#endif
