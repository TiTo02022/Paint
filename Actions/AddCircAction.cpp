#include "Action.h"
#include "AddCircAction.h"
#include "../Figures/CCircle.h"

#include "../ApplicationManager.h"

#include "../GUI/Input.h"
#include "../GUI/Output.h"

AddCircAction::AddCircAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddCircAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at the center");

	//Read center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("Click at the Circumference");

	//Read Circumference and store in point P2
	pIn->GetPointClicked(P2.x, P2.y); 
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
void AddCircAction::Execute(bool co )
{
	if (co) {
		ReadActionParameters(); //This action needs to read some parameters first
	}
	
	//Create a circle with the parameters read from the user
	R = new CCircle(P1, P2, RectGfxInfo);

	//Add the circle to the list of figures
	pManager->AddFigure(R);
	pManager->Addundo(this);
	//Record action
	if (pManager->getisrec())
		pManager->Addreco(this);
}

void AddCircAction::undo()
{
	dc = R->getcolourinfo().DrawClr;
	if (R == pManager->getselfig())
	{
		issel = 1;
	}
	pManager->Deleteandarrangelist(R);


}

void AddCircAction::redo()
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

