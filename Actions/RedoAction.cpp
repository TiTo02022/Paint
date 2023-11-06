#include "../Figures\CFigure.h"
#include"RedoAction.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"

RedoAction::RedoAction(ApplicationManager* pApp) :Action(pApp)
{}

void RedoAction::ReadActionParameters(){}

//Execute the action
void RedoAction::Execute(bool co)
{

	//calls the undo function to undo last action
	pManager->Redo();
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("redo");
}

void RedoAction::undo() {}
void RedoAction::redo() {}