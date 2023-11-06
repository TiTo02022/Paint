#include "Action.h"
#include "AddHexAction.h"
#include "../Figures/CHexagon.h"

#include "..\ApplicationManager.h"

#include "..\GUI/Input.h"
#include "..\GUI/Output.h"

AddHexAction::AddHexAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddHexAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hexagon: Click at Center");

	//Read center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	if (pManager->isfilled())  //changing the default of non filled, to be dependant on the getter isfilled
		RectGfxInfo.isFilled = true;
	else 
		RectGfxInfo.isFilled = false;
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddHexAction::Execute(bool co )
{
	if (co) {
		ReadActionParameters(); //This action needs to read some parameters first
	}
	//Create a hexagon with the parameters read from the user
	R = new CHexagon(P1, RectGfxInfo);

	//Add the hexagon to the list of figures
	pManager->AddFigure(R);
	pManager->Addundo(this);
	if (pManager->getisrec())
		pManager->Addreco(this); //record action
}

void AddHexAction::undo()
{
	dc = R->getcolourinfo().DrawClr;
	if (R == pManager->getselfig())
	{
		issel = 1;
	}
	pManager->Deleteandarrangelist(R);


}

void AddHexAction::redo()
{
	//Add the figure back to the list of figures
	pManager->AddFigure(R);
	if (issel == 1)
	{
		pManager->setselfig(R);
		R->SetSelected(true);
		R->ChngDrawClr(MAGENTA);
	}
	else
	{
		pManager->setselfig(nullptr);
		R->SetSelected(false);
		if (R->getcolourinfo().DrawClr == MAGENTA)
		{
			R->ChngDrawClr(dc);
		}
		else
		{
			R->ChngDrawClr(R->getcolourinfo().DrawClr);
		}
	}

}
