#ifndef SHAPEACTION_H
#define SHAPEACTION_H

#include "Action.h"
#include <fstream>
#include <string>
#include "SelectAction.h"
#include "DeleteAction.h"
#include"LoadAction.h"
#include "Action.h"
#include "AddCircAction.h"
#include "AddHexAction.h"
#include "AddRectAction.h"
#include "AddSqrAction.h"
#include "AddTriAction.h"

#include "../Figures/CFigure.h"
#include "../Figures/CCircle.h"
#include "../Figures/CHexagon.h"
#include "../Figures/CRectangle.h"
#include "../Figures/CSquare.h"
#include "../Figures/CTriangle.h"
#include "../ApplicationManager.h"
#include "../random-master/include/effolkronium/random.hpp"

class ShapeAction : public Action {
private:
	int CountRect, CountCirc,CountSq, CountTri, CountHex, type, actualcount;
public:
	ShapeAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool co = true);

	void undo();
	void redo();
};
#endif