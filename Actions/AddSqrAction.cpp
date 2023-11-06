#include "Action.h"
#include "AddSqrAction.h"
#include "../Figures/CSquare.h"

#include "..\ApplicationManager.h"

#include "..\GUI/Input.h"
#include "..\GUI/Output.h"

AddSqrAction::AddSqrAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddSqrAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at Center");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	if (pManager->isfilled()) //changing the default of non filled, to be dependant on the getter isfilled
		RectGfxInfo.isFilled = true;
	else 	
		RectGfxInfo.isFilled = false;
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddSqrAction::Execute(bool co)
{
	if (co) {
		ReadActionParameters(); //This action needs to read some parameters first
	}

	//Create a rectangle with the parameters read from the user
	R = new CSquare(P1, RectGfxInfo);

	//Add the square to the list of figures
	pManager->AddFigure(R);
	pManager->Addundo(this);
	//Record action
	if (pManager->getisrec())
		pManager->Addreco(this);
}
void AddSqrAction::undo()
{
	dc = R->getcolourinfo().DrawClr;
	if (R == pManager->getselfig())
	{
		issel = 1;
	}
	pManager->Deleteandarrangelist(R);


}

void AddSqrAction::redo()
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
