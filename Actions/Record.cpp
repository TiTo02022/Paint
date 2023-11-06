#include "Record.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

Rec::Rec(ApplicationManager* rec) :Action(rec)
{}
void Rec::ReadActionParameters() {}
void Rec::Execute(bool co) {
	if (pManager->figureC() == 0) { // check if figcount is zero
		pManager->setisrec(1); // set recording status to true
		Output* pOut = pManager->GetOutput();
		pOut->PrintMessage("Recording has started");
	}
}
void Rec::undo() {}
void Rec::redo() {}
