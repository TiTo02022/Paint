#ifndef STOP_H
#define STOP_H
#include "Action.h"
class Stop : public Action {
public:
	Stop(ApplicationManager* st);
	virtual void ReadActionParameters();

	virtual void Execute(bool co = true);

	void undo();
	void redo();
};
#endif