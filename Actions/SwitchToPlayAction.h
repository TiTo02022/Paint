#ifndef SWITCHTOPLAY_H
#define SWITCHTOPLAY_H

#include "Action.h"
class SwitchToPlayAction : public Action
{
public:
	SwitchToPlayAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute(bool co = true);
	void undo();
	void redo();
};
#endif
