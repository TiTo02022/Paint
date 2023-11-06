#include "DrawColourAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
DrawColourAction::DrawColourAction(ApplicationManager* pApp) :Action(pApp)
{}
//gets a pointer on the selected figure
void DrawColourAction::ReadActionParameters()
{
	R = pManager->getselfig();
}

void DrawColourAction::Execute(bool co)
{
	if (co) {
		ReadActionParameters(); //This action needs to read some parameters first
	}
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	if (R == nullptr) {
		pOut->PrintMessage("Please select the figure first");
	}
	else {
		R->clr(l, m);
		pOut->PrintMessage("Please select the draw border colour");
		ActionType ActType =pIn->GetUserAction();
		switch (ActType) {
		case RED1:
			pOut->setCrntDrawColor(RED);
			R->ChngDrawClr(RED);
			break;
		case ORANGE1:
			pOut->setCrntDrawColor(ORANGE);
			R->ChngDrawClr(ORANGE);
			break;
		case YELLOW1:
			pOut->setCrntDrawColor(YELLOW);
			R->ChngDrawClr(YELLOW);
			break;
		case GREEN1:
			pOut->setCrntDrawColor(GREEN);
			R->ChngDrawClr(GREEN);
			break;
		case BLUE1:
			pOut->setCrntDrawColor(BLUE);
			R->ChngDrawClr(BLUE);
			break;
		case BLACK1:
			pOut->setCrntDrawColor(BLACK);
			R->ChngDrawClr(BLACK);
			break;
		}
		
	}
	//Record action
	if (pManager->getisrec())
		pManager->Addreco(this);
	pManager->Addundo(this);
}

void DrawColourAction::undo()
{
	pManager->swap(l, m, R);
}

void DrawColourAction::redo()
{
	pManager->swap(m, l, R);
}
