#include "SwitchToDrawAction.h"
#include "..\ApplicationManager.h"
#include"LoadAction.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
SwitchToDrawAction::SwitchToDrawAction(ApplicationManager* pApp) :Action(pApp)
{}
void SwitchToDrawAction::ReadActionParameters()
{}
void SwitchToDrawAction::Execute(bool co)
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea1();
	pOut->PrintMessage("Switched to Draw Mode");
	pOut->CreateDrawToolBar1();
	pOut->CreateDrawToolBar2();
	LoadAction S(pManager); //to load the original file before switching back
	S.Execute(false);
}
void SwitchToDrawAction::undo() {}
void SwitchToDrawAction::redo() {}
