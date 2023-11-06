#ifndef PLAYR_H
#define PLAYR_H

#include "Action.h"

class PlayRecord : public Action {
public:
	PlayRecord(ApplicationManager* pl);

	virtual void ReadActionParameters();

	virtual void Execute(bool co = true);

	void undo();
	void redo();
};
#endif