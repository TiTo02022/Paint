#ifndef COLOURACTION_H
#define COLOURACTION_H

#include "Action.h"
#include <fstream>
#include <string>
#include "ShapeAction.h"
#include "SelectAction.h"
#include "DeleteAction.h"
#include"LoadAction.h"
#include "Action.h"

#include "../Figures/CFigure.h"
#include "../Figures/CCircle.h"
#include "../Figures/CHexagon.h"
#include "../Figures/CRectangle.h"
#include "../Figures/CSquare.h"
#include "../Figures/CTriangle.h"
#include "../ApplicationManager.h"
#include "../random-master/include/effolkronium/random.hpp"
class ColourAction : public Action {
private:
	int CountBlack, CountYellow, CountOrange, CountRed, CountGreen, CountBlue, type, fc, actualcount, correctC, incorrectC;

public:
	ColourAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool co = true);

	void undo();
	void redo();

};
#endif
