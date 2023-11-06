#include "MoveAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
MoveAction::MoveAction(ApplicationManager* pApp) :Action(pApp)
{}
//gets a pointer on the selected figure
void MoveAction::ReadActionParameters()
{
	R = pManager->getselfig();
}
void MoveAction::Execute(bool co)
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
		pOut->PrintMessage("Please select the destination");
		int x;
		int y;
		pIn->GetPointClicked(x, y);  //gets the new destination
		R->move(x, y, l, m);   //calls the function move depending on what that pointer points to
		pManager->Addundo(this);
	}
	//Record action
	if (pManager->getisrec())
		pManager->Addreco(this);
}

void MoveAction::undo()
{
	pManager->swap(l, m, R);
}
void MoveAction::redo()
{
	pManager->swap(m, l, R);
}
