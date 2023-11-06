#include "ApplicationManager.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output 
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
	last5count = 0;
	maxredo = 0;
	RecCount = 0;
	isrec = 0;
	fill = false;
	SelectedFig = nullptr;

	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	

	for (int i = 0; i < 20; i++)
		RecList[i] = NULL;

	for (int i = 0; i < 5; i++)
		last5[i] = NULL;

	lastaction = nullptr;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	Action* LastAction = NULL;
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;

		case DRAW_SQR:
			pAct = new AddSqrAction(this);
			break;

		case DRAW_TRI:
			pAct = new AddTriAction(this);
			break;

		case DRAW_HEX:
			pAct = new AddHexAction(this);
			break;

		case DRAW_CIRC:
			pAct = new AddCircAction(this);
			break;

		case SLCT_ONE:
			pAct = new SelectAction(this);
			break;

		case DRAW:
			pAct = new DrawColourAction(this);
			break;

		case FILL:
			pAct = new FillColourAction(this);
			break;
	
		case DLT1:
			pAct = new DeleteAction(this);
			break;

		case MOVE:
			pAct = new MoveAction(this);
			break;

		case SAVE:
			pAct = new SaveAction(this);
			break;

		case LOAD:
			pAct = new LoadAction(this);
			break;

		case START:
			pAct = new Rec(this);
			break;

		case STOP:
			pAct = new Stop(this);
			break;

		case PLAY:
			pAct = new PlayRecord(this);
			break;

		case TO_PLAY:
			pAct = new SwitchToPlayAction(this);
			break;

		case TO_DRAW:
			pAct = new SwitchToDrawAction(this);
			break;

		case UNDO:
			pAct = new UndoAction(this);
			break;

		case REDO:
			pAct = new RedoAction(this);
			break;

		case SHAPE:
			pAct = new ShapeAction(this);
			break;

		case COLOUR:
			pAct = new ColourAction(this);
			break;

		case BOTH:
			pAct = new BothAction(this);
			break;

		case CLEAR:
			pAct = new ClearAllAction(this);
			break;

		case EXIT:
			pAct = new ExitAction(this);///create ExitAction here
			break;

		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute(true);//Execute
		//delete pAct;	//You may need to change this line depending to your implementation (Edit: we did change it)
		LastAction = pAct;
		//pAct = NULL;
	}
}
//to get the index to be arrange the list
void ApplicationManager::Deleteandarrangelist(CFigure* pFig) { 
	int z;
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i] == pFig) {
			z = i;
			break;
		}
	}
	int s = FigCount - z;
	for (int i = 0;i < s;i++) {
		FigList[z] = FigList[z + 1];
		z++;
	}
	FigList[FigCount] = NULL;
	FigCount--;

}
//loops on the figure list to save it 
void ApplicationManager::SaveAll(ofstream& f) 
{
	f << FigCount << '\n';
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Save(f, i);		//Call save function (virtual member fn)
}
void ApplicationManager::setisfill(bool c) { //setter for fill
	fill = c;
}
bool ApplicationManager::isfilled() { //getter for fill
	return fill;
}
void ApplicationManager::clearActions(bool p) //clears all actions
{
	if (p) {
		for (int i = 0; i < RecCount; i++) {
			delete RecList[i];
		}
		RecCount = 0;
	}
	for (int i = 0; i < FigCount; i++)
		delete FigList[i];
	FigCount = 0;
	fill = false;
	//pOut->setCrntDrawColor(BLUE);

}
//undo
void ApplicationManager::Addundo(Action* e)
{
	if (last5count < 5)
	{
		last5[last5count] = e;
		last5count++;
		maxredo++;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			last5[i] = last5[i + 1];
		}
		last5[4] = e;
		maxredo = 5;
	}
}

//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}

void ApplicationManager::Undo()
{
	if (last5count > 0)
	{
		last5count--;
		last5[last5count]->undo();
	}
}

void ApplicationManager::Redo()
{
	UndoAction* uptr = dynamic_cast<UndoAction*>(lastaction);
	RedoAction* rptr = dynamic_cast<RedoAction*>(lastaction);
	if (maxredo > 5)
	{
		maxredo = 5;
	}
	if ((dynamic_cast<UndoAction*>(uptr) != nullptr || dynamic_cast<RedoAction*>(rptr) != nullptr) && last5count < maxredo)
	{
		last5[last5count]->redo();
		last5count++;
	}
}

void ApplicationManager::swap(CFigure*& l, CFigure*& m, CFigure*& R)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (R == FigList[i] || A == FigList[i])
		{
			FigList[i] = l;
			A = m;
			A = FigList[i];
			FigList[i]->SetSelected(true);
			FigList[i]->ChngDrawClr(MAGENTA);
			setselfig(FigList[i]);
		}
	}

}

int ApplicationManager::figureC() {
	return FigCount;
}
void ApplicationManager::setisrec(bool r) {
	isrec = r;
}
bool ApplicationManager::getisrec() {
	return isrec;
}
int ApplicationManager::getRcount() {
	return RecCount;
}
void ApplicationManager::Addreco(Action* arec) {
	if (RecCount < 20)
		RecList[RecCount] = arec; //save pointer to action
	RecCount++;
}
void ApplicationManager::Playrecord() {
	for (int i = 0; i < RecCount; i++) {
		RecList[i]->Execute(false); //execute each action in the saved recording in reclist
		Sleep(1000); //stops for one sec
		UpdateInterface(); //update UI5
	}
}

////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	Point c;
	c.x = x;
	c.y = y;
	for (int i = FigCount-1; i >= 0; i--)
	{
		if (FigList[i]->pointcheck(c))
		{
			return FigList[i];
		}
	}
	return NULL;
}
CFigure* ApplicationManager::getselfig()
{
	return SelectedFig;
}

CFigure* ApplicationManager::getlastselfig()
{
	return lastSelectedFig;
}

void ApplicationManager::setselfig(CFigure* c)
{
	SelectedFig = c;
}

void ApplicationManager::setlastselfig(CFigure* h)
{
	lastSelectedFig = h;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	pOut->ClearDrawArea();
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////

//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
