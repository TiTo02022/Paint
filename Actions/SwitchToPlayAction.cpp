#include "SwitchToPlayAction.h"
#include "..\ApplicationManager.h"
#include"SaveAction.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
SwitchToPlayAction::SwitchToPlayAction(ApplicationManager* pApp) :Action(pApp)
{}
void SwitchToPlayAction::ReadActionParameters()
{}
void SwitchToPlayAction::Execute(bool co )
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea1();
	pOut->PrintMessage("Switched to Play Mode");
	pOut->CreatePlayToolBar();
	SaveAction S(pManager); //to save the original file before switching
	S.Execute(false);
}
void SwitchToPlayAction::undo() {}
void SwitchToPlayAction::redo() {}