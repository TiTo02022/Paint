#include "Action.h"
#include "PlayRecord.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

PlayRecord::PlayRecord(ApplicationManager* pl) :Action(pl) {}

void PlayRecord::ReadActionParameters() {}

void PlayRecord::Execute(bool co) {
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Playing recording");
	pManager->clearActions(0);
	pManager->Playrecord(); //start playing saved recording
}
void PlayRecord::undo() {}
void PlayRecord::redo() {}
