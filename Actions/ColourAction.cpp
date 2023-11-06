#include "ColourAction.h"
using Random = effolkronium::random_static;


ColourAction::ColourAction(ApplicationManager* pApp) : Action(pApp) {
	CountBlack = 0, CountYellow = 0, CountOrange = 0, CountRed = 0, CountGreen = 0, CountBlue = 0;
}
void ColourAction::ReadActionParameters() {
	LoadAction l(pManager);
	l.Execute(false);
	pManager->UpdateInterface();
	int k; //draw colour
	int fo; //fill colour
	int n; //count of figures
	int m; //type of shape
	int s; //id of shape
	ifstream f;
	f.open("original file .txt");
	f >> k >> fo;
	f >> n;

	auto val = Random::get(0, n - 1); //randomized property
	//this for loop checks the type of the randomized output "val"
	for (int i = 0; i < val + 1; i++) {
		f >> type >> s;
		if (type == 11) {
			f >> k >> fo >> k >> k >> fo >> fc;
		}
		else if (type == 12) {
			f >> k >> fo >> k >> k >> fo >> fc;
		}
		else if (type == 13) {
			f >> k >> fo >> k >> fc;
		}
		else if (type == 14) {
			f >> k >> fo >> k >> k >> fo >> k >> k >> fc;
		}
		else if (type == 15) {
			f >> k >> fo >> k >> fc;
		}
	}

	int ha; //another variable for type, so we can compare it with type and calculate the counter
	int fc1; //another variable for fc, so we can compare it with fc and calculate the counter
	actualcount = 0; // indicates how many figures are set to the same shape AND colour
	f.close(); // closes the opened file as we need to read it again
	f.open("original file .txt");
	f >> k >> fo;
	f >> n;
	for (int i = 0; i < n; i++) {
		f >> ha >> s;
		if (ha == 11) {
			f >> k >> fo >> k >> k >> fo >> fc1;
		}
		else if (ha == 12) {
			f >> k >> fo >> k >> k >> fo >> fc1;
		}
		else if (ha == 13) {
			f >> k >> fo >> k >> fc1;
		}
		else if (ha == 14) {
			f >> k >> fo >> k >> k >> fo >> k >> k >> fc1;
		}
		else if (ha == 15) {
			f >> k >> fo >> k >> fc1;
		}
		if (fc1 == fc) { //calculating counter of figures with same colour
			actualcount++;
		}
	}
}
void ColourAction::Execute(bool co) {
	ReadActionParameters();

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//pOut->PrintMessage("Play with me! Pick all the figures based on COLOURS.");

	switch (fc)
	{
	case 20:
		pOut->PrintMessage("Pick the Red Figures.");
		break;
	case 21:
		pOut->PrintMessage("Pick the Orange Figures.");
		break;
	case 22:
		pOut->PrintMessage("Pick the Yellow Figures.");
		break;
	case 23:
		pOut->PrintMessage("Pick the Green Figures.");
		break;
	case 24:
		pOut->PrintMessage("Pick the Blue Figures.");
		break;
	case 25:
		pOut->PrintMessage("Pick the Black Figures.");
		break;
	case 26:
		pOut->PrintMessage("Pick the non-filled Figures.");
		break;
	}
	CFigure* R;
	int correctC = 0, incorrectC = 0;

	while (correctC < actualcount) {
		SelectAction s(pManager);
		s.Execute();
		while (pManager->getselfig() == nullptr) {
			switch (fc)
			{
			case 20:
				pOut->PrintMessage("Pick the Red Figures.");
				break;
			case 21:
				pOut->PrintMessage("Pick the Orange Figures.");
				break;
			case 22:
				pOut->PrintMessage("Pick the Yellow Figures.");
				break;
			case 23:
				pOut->PrintMessage("Pick the Green Figures.");
				break;
			case 24:
				pOut->PrintMessage("Pick the Blue Figures.");
				break;
			case 25:
				pOut->PrintMessage("Pick the Black Figures.");
				break;
			case 26:
				pOut->PrintMessage("Pick the non-filled Figures.");
				break;
			}
			SelectAction s(pManager);
			s.Execute();
		}
		if (fc == 20) {
			pOut->PrintMessage("Pick the Red Figures.");
			R = pManager->getselfig();
			if (R->getcolourinfo().isFilled && R->getcolourinfo().FillClr == RED)
				correctC++;
			else incorrectC++;
		}
		else if (fc == 21) {
			pOut->PrintMessage("Pick the Orange Figures.");
			R = pManager->getselfig();
			if (R->getcolourinfo().isFilled && R->getcolourinfo().FillClr == ORANGE)
				correctC++;
			else incorrectC++;
		}
		else if (fc == 22) {
			pOut->PrintMessage("Pick the Yellow Figures.");
			R = pManager->getselfig();
			if (R->getcolourinfo().isFilled && R->getcolourinfo().FillClr == YELLOW)
				correctC++;
			else incorrectC++;
		}
		else if (fc == 23) {
			pOut->PrintMessage("Pick the Green Figures.");
			R = pManager->getselfig();
			if (R->getcolourinfo().isFilled && R->getcolourinfo().FillClr == GREEN)
				correctC++;
			else incorrectC++;
		}

		else if (fc == 24) {
			pOut->PrintMessage("Pick the Blue Figures.");
			R = pManager->getselfig();
			if (R->getcolourinfo().isFilled && R->getcolourinfo().FillClr == BLUE)
				correctC++;
			else incorrectC++;
		}
		else if (fc == 25) {
			pOut->PrintMessage("Pick the Black Figures.");
			R = pManager->getselfig();
			if (R->getcolourinfo().isFilled && R->getcolourinfo().FillClr == BLACK)
				correctC++;
			else incorrectC++;
		}
		else if (fc == 26) {
			pOut->PrintMessage("Pick the non-filled Figures.");
			R = pManager->getselfig();
			if (!R->getcolourinfo().isFilled)
				correctC++;
			else incorrectC++;
		}
		DeleteAction d1(pManager);
		d1.Execute();
		pManager->setselfig(NULL);
		pManager->UpdateInterface();
	}
	string message;
	if (incorrectC == 0) //This is grading criteria for the grade output
		message = "Excellent!";
	else if (incorrectC >= 1 && incorrectC <= 3)
		message = "Great!";
	else if (incorrectC <= 4 && incorrectC >= 6)
		message = "Good!";
	else message = "Not Bad!";
	//printing grade after converting it to string
	string correctCSTR = to_string(correctC);
	string incorrectCSTR = to_string(incorrectC);
	pOut->PrintMessage(message + " You chose " + correctCSTR + " correct figures and " + incorrectCSTR + " incorrect figures.");
}
void ColourAction::undo()
{

}

void ColourAction::redo()
{

}