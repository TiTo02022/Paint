#ifndef SWITCHTODRAW_H
#define SWITCHTODRAW_H

#include "Action.h"
class SwitchToDrawAction : public Action
{
public:
	SwitchToDrawAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute(bool co = true);

	void undo();
	void redo();
};
#endif
