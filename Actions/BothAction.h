#ifndef BOTHACTION_H
#define BOTHACTION_H

#include "Action.h"
#include "ShapeAction.h"
#include "DeleteAction.h"
#include "LoadAction.h"
#include "../random-master/include/effolkronium/random.hpp"
#include <fstream>
#include <string>
#include "Action.h"
#include "../ApplicationManager.h"

#include "../Figures/CFigure.h"
#include "../Figures/CCircle.h"
#include "../Figures/CHexagon.h"
#include "../Figures/CRectangle.h"
#include "../Figures/CSquare.h"
#include "../Figures/CTriangle.h"
#include "SelectAction.h"

class BothAction : public Action
{
private:
	int actualcount, type, fc; 
	string messagef, messagec; //these are the randomized output messages

public:
	BothAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool co = true);

	void undo();
	void redo();
};

#endif
