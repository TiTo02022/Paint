#ifndef RECORD_H
#define RECORD_H
#include<iostream>
#include "Action.h"

class Rec : public Action
{
public:
	Rec(ApplicationManager* rec);
	virtual void ReadActionParameters();

	virtual void Execute(bool co = true);

	void undo();
	void redo();
};

#endif


