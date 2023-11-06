#include "DeleteAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
DeleteAction::DeleteAction(ApplicationManager* pApp) :Action(pApp)
{ 
	q = nullptr;
}
//gets a pointer on the selected figure
void DeleteAction::ReadActionParameters()
{
	R = pManager->getselfig();
}
void DeleteAction::Execute(bool co)
{
	if (co) {
		ReadActionParameters(); //This action needs to read some parameters first
	}
	dc = R->getnc();
	Output* pOut = pManager->GetOutput();
	if (R == nullptr) {
		pOut->PrintMessage("Please select the figure first");
	}
	else {

		pManager->Deleteandarrangelist(R);   //calls the delete and arrange list in the application manager to delete selected figure and arrange the figure list
	}
	//Record action
	if (pManager->getisrec())
		pManager->Addreco(this);

	pManager->Addundo(this);
	pManager->setselfig(nullptr);
	R->SetSelected(false);
	R->ChngDrawClr(dc);
}

void DeleteAction::undo()
{
		pManager->AddFigure(R);

			if (pManager->getselfig() == nullptr)
			{
				R->SetSelected(true);
				R->ChngDrawClr(MAGENTA);
				pManager->setselfig(R);

			}
			else
			{
				q = pManager->getselfig();
				CFigure* h = (pManager->getselfig());
				pManager->setlastselfig(h);
				if (R->IsSelected())
				{
					if (R->getcolourinfo().DrawClr == MAGENTA)
					{
						R->ChngDrawClr(dc);
						R->SetSelected(false);
						pManager->setselfig(nullptr);
					}
					else
					{
						R->ChngDrawClr(R->getcolourinfo().DrawClr);
						R->SetSelected(false);
						pManager->setselfig(nullptr);
					}
				}
				else
				{

					R->SetSelected(true);
					pManager->setselfig(R);
					R->ChngDrawClr(MAGENTA);
				}
				if (R->getcolourinfo().DrawClr == MAGENTA)
				{
					h->ChngDrawClr(dc);
					h->SetSelected(false);
				}
				else
				{
					h->ChngDrawClr(h->getcolourinfo().DrawClr);
					h->SetSelected(false);
				}
			}
}

void DeleteAction::redo()
{
	if (R->getcolourinfo().DrawClr == MAGENTA)
	{
		R->ChngDrawClr(dc);
		R->SetSelected(false);
		pManager->setselfig(nullptr);
	}
	else
	{
		R->ChngDrawClr(R->getcolourinfo().DrawClr);
		R->SetSelected(false);
		pManager->setselfig(nullptr);
	}
	pManager->Deleteandarrangelist(R);
	if (q == nullptr)
	{

	}
	else
	{
		pManager->setselfig(q);
		q->ChngDrawClr(MAGENTA);
		q->SetSelected(true);

	}
					
}
