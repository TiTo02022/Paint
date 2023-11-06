#include "FillColourAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
FillColourAction::FillColourAction(ApplicationManager* pApp) :Action(pApp)
{}
//gets a pointer on the selected figure
void FillColourAction::ReadActionParameters()
{
	R = pManager->getselfig();
}

void FillColourAction::Execute(bool co)
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
		R->clr(z, m);
		pOut->PrintMessage("please select the fill colour");
		pManager->setisfill(true);
		ActionType ActType = pIn->GetUserAction();
		switch (ActType) {
		case RED1:
			pOut->setCrntFillColor(RED);
			R->ChngFillClr(RED);
			break;
		case ORANGE1:
			pOut->setCrntFillColor(ORANGE);
			R->ChngFillClr(ORANGE);
			break;
		case YELLOW1:
			pOut->setCrntFillColor(YELLOW);
			R->ChngFillClr(YELLOW);
			break;
		case GREEN1:
			pOut->setCrntFillColor(GREEN);
			R->ChngFillClr(GREEN);
			break;
		case BLUE1:
			pOut->setCrntFillColor(BLUE);
			R->ChngFillClr(BLUE);
			break;
		case BLACK1:
			pOut->setCrntFillColor(BLACK);
			R->ChngFillClr(BLACK);
			break;
		}
		R->clr(m, z);
	}
	//Record action
	if (pManager->getisrec()) {
		pManager->Addreco(this);
	}
	pManager->Addundo(this);
}

	void FillColourAction::undo()
	{
		pManager->swap(z, m, R);
	}

	void FillColourAction::redo()
	{
		pManager->swap(m, z, R);
	}