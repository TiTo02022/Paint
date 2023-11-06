#include "Action.h"
#include "AddTriAction.h"
#include "../Figures/CTriangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI/Input.h"
#include "..\GUI/Output.h"

AddTriAction::AddTriAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddTriAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at the first corner");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("Click at the second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	pOut->PrintMessage("Click at the third corner");

	//Read 3rd corner and store in point P3
	pIn->GetPointClicked(P3.x, P3.y);

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
void AddTriAction::Execute(bool co)
{
	if (co) {
		ReadActionParameters(); //This action needs to read some parameters first
	}
	//Create a triangle with the parameters read from the user
	R = new CTriangle(P1, P2, P3, RectGfxInfo);

	//Add the triangle to the list of figures
	pManager->AddFigure(R);
	pManager->Addundo(this);
	//Record action
	if (pManager->getisrec())
		pManager->Addreco(this);
}
void AddTriAction::undo()
{
	dc = R->getcolourinfo().DrawClr;
	if (R == pManager->getselfig())
	{
		issel = 1;
	}
	pManager->Deleteandarrangelist(R);


}
void AddTriAction::redo()
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
