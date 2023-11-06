#ifndef EXIT_H
#define EXIT_H

#include "Action.h"
class ExitAction : public Action
{
public:
	ExitAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute(bool co = true);

	void undo();
	void redo();
};
#endif

