#include "SelectAction.h"
SelectAction::SelectAction(ApplicationManager* pApp) :Action(pApp)
{}
void SelectAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//pOut->PrintMessage("Select figure");
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->ClearStatusBar();

}
void SelectAction::Execute(bool co)
{
	ReadActionParameters();
	fig = pManager->GetFigure(P1.x, P1.y);
	if (fig != nullptr)
	{
		if (pManager->getselfig() == nullptr)
		{
				fig->SetSelected(true);
				fig->ChngDrawClr(MAGENTA);
				pManager->setselfig(fig);
			
		}
		else
		{
			CFigure* h = (pManager->getselfig());
			if (fig->IsSelected())
			{
				if (fig->getcolourinfo().DrawClr == MAGENTA)
				{
					fig->ChngDrawClr(fig->getnc());
					fig->SetSelected(false);
					pManager->setselfig(nullptr);
				}
				else
				{
					fig->ChngDrawClr(fig->getcolourinfo().DrawClr);
					fig->SetSelected(false);
					pManager->setselfig(nullptr);
				}
			}
			else
			{

				fig->SetSelected(true);
				pManager->setselfig(fig);
				fig->ChngDrawClr(MAGENTA);
			}
			if (fig->getcolourinfo().DrawClr == MAGENTA)
			{
				h->ChngDrawClr(h->getnc());
				h->SetSelected(false);
			}
			else
			{
				h->ChngDrawClr(h->getcolourinfo().DrawClr);
				h->SetSelected(false);
			}
		}
	}
}

void SelectAction::undo()
{

}

void SelectAction::redo()
{

}
