#include "Stop.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

Stop::Stop(ApplicationManager* st) :Action(st) {}
void Stop::ReadActionParameters() {}
void Stop::Execute(bool co) {
	pManager->setisrec(0); //set recording status to false 
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Recording has stopped");
}
void Stop::undo() {}
void Stop::redo() {}