#include "SaveAction.h"
#include <fstream>
#include "..\ApplicationManager.h"

#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
SaveAction::SaveAction(ApplicationManager* pApp) :Action(pApp)
{}
void SaveAction::ReadActionParameters()
{
	int x, y;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Please enter the file name to save it");
	A = pIn->GetSrting(pOut);    //gets the file name
	pOut->PrintMessage("saved");
}
void SaveAction::Execute(bool co)
{
	Output* pOut = pManager->GetOutput();
	if (co) {
		ReadActionParameters();
	}
	else
	{
		A = "original file ";
	}
	int z;
	int fill;
	//gets the current draw color and current fill color
	if (pOut->getCrntDrawColor() == RED)
		z = RED2;
	else if (pOut->getCrntDrawColor() == ORANGE)
		z = ORANGE2;
	else if (pOut->getCrntDrawColor() == YELLOW)
		z = YELLOW2;
	else if (pOut->getCrntDrawColor() == GREEN)
		z = GREEN2;
	else if (pOut->getCrntDrawColor() == BLUE)
		z = BLUE2;
	else if (pOut->getCrntDrawColor() == BLACK)
		z = BLACK2;

	if (pOut->getCrntFillColor() == RED)
			fill = RED2;
	else if (pOut->getCrntFillColor() == ORANGE)
			fill = ORANGE2;
	else if (pOut->getCrntFillColor() == YELLOW)
			fill = YELLOW2;
	else if (pOut->getCrntFillColor() == GREEN)
			fill = GREEN2;
	else if (pOut->getCrntFillColor() == BLUE)
			fill = BLUE2;
	else if (pOut->getCrntFillColor() == BLACK)
			fill = BLACK2;
	else
		fill = Nofill2;
	
	ofstream f;
	f.open(A + ".txt", ios::out); // opens the file to create it or overwrite it 
	f<<z<<"   "<<fill << '\n';
	pManager->SaveAll(f);
	f.close();  //closes the file
}
void SaveAction::undo() {}
void SaveAction::redo() {}