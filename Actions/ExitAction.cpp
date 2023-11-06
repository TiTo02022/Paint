#include "ExitAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
ExitAction::ExitAction(ApplicationManager* pApp) :Action(pApp)
{}
void ExitAction::ReadActionParameters()
{}
void ExitAction::Execute(bool co)
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	int x, y;
	pOut->PrintMessage("click anywhere to exit");
	pIn->GetPointClicked(x, y);
}
void ExitAction::undo(){}

void ExitAction::redo(){}