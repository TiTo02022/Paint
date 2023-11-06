#include "../Figures/CFigure.h"
#include "UndoAction.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"

UndoAction::UndoAction(ApplicationManager* pApp) :Action(pApp)
{}

void UndoAction::ReadActionParameters()
{}

//Execute the action
void UndoAction::Execute(bool co)
{

	//calls the undo function to undo last action
	pManager->Undo();
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("undo");


}

void UndoAction::undo()
{

}

void UndoAction::redo()
{

}