#include "LoadAction.h"
#include "..\Figures\CFigure.h"
#include "..\Figures\CRectangle.h"
#include"..\Figures\CCircle.h"
#include"..\Figures\CSquare.h"
#include"..\Figures\CTriangle.h"
#include"..\Figures\CHexagon.h"
#include <fstream>
#include "../ApplicationManager.h"
#include "ClearAllAction.h"
#include "../GUI/Output.h"
#include "../GUI/Input.h"
#include "..\defs.h"
ClearAllAction::ClearAllAction(ApplicationManager* pApp) :Action(pApp)
{}

void ClearAllAction::ReadActionParameters() {}
void ClearAllAction::Execute(bool co) {
	//clearing draw area
	//Output* pOut = pManager->GetOutput();
	//Input* pIn = pManager->GetInput();
	//pOut->ClearDrawArea();
	//clearing fig list
	pManager->clearActions(1);
	//Record action
	if (pManager->getisrec())
		pManager->Addreco(this);
}
void ClearAllAction::undo()
{

}

void ClearAllAction::redo()
{

}