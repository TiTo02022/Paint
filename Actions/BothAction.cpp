#include "BothAction.h"
using Random = effolkronium::random_static;

BothAction::BothAction(ApplicationManager* pApp) : Action(pApp) {
}
void BothAction::ReadActionParameters() {
	//loading file
	LoadAction l(pManager);
	l.Execute(false);
	pManager->UpdateInterface();
	//initialising variables
	int k; //draw colour
	int fo; //fill colour
	int n; //count of figures
	int m; //type of shape
	int s; //id of shape
	//opening file
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

	//this checks the appropriate message according to the colour (fc is filling colour)
	switch (fc) {
	case 20:
		messagec = "red ";
		break;
	case 21:
		messagec = "orange ";
		break;
	case 22:
		messagec = "yellow ";
		break;
	case 23:
		messagec = "green ";
		break;
	case 24:
		messagec = "blue ";
		break;
	case 25:
		messagec = "black ";
		break;
	case 26:
		messagec = "non-filled ";
		break;
	}
	//this checks the appropriate message according to the shape 
	switch (type) {
	case 11:
		messagef = "rectangle(s).";
		break;
	case 12:
		messagef = "circle(s).";
		break;
	case 13:
		messagef = "square(s).";
		break;
	case 14:
		messagef = "triangle(s).";
		break;
	case 15:
		messagef = "hexagon(s).";
		break;

	}

	//==================================================================================//
	//							Now the for loops repeat themselves						//
	//==================================================================================//

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
		if (ha == type && fc1 == fc) { //calculating counter of figures with same shape and colour
			actualcount++;
		}
	}
}
void BothAction::Execute(bool co) {
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	int correctB = 0, incorrectB = 0, correctC = 0, incorrectC = 0;
	CFigure* R = NULL;
	//end of switch cases for the random value, now we play the game

	//conditions for shapes
	pOut->PrintMessage("Pick the " + messagec + messagef);
	int correctS = 0, incorrectS = 0;
	while (correctB < actualcount) {
		SelectAction s(pManager);
		s.Execute();
		while (pManager->getselfig() == nullptr) {
			pOut->PrintMessage("Pick the " + messagec + messagef);
			SelectAction s(pManager);
			s.Execute();
		}
		pOut->PrintMessage("Pick the " + messagec + messagef);
		if (fc == 20) {
			//pOut->PrintMessage("Pick the Red figures.");
			R = pManager->getselfig();
			if (R->getcolourinfo().isFilled && R->getcolourinfo().FillClr == RED)
				correctC++;
			else incorrectC++;
		}
		else if (fc == 21) {
			//pOut->PrintMessage("Pick the Orange Figures.");
			R = pManager->getselfig();
			if (R->getcolourinfo().isFilled && R->getcolourinfo().FillClr == ORANGE)
				correctC++;
			else incorrectC++;
		}
		else if (fc == 22) {
			//pOut->PrintMessage("Pick the Yellow Figures.");
			R = pManager->getselfig();
			if (R->getcolourinfo().isFilled && R->getcolourinfo().FillClr == YELLOW)
				correctC++;
			else incorrectC++;
		}
		else if (fc == 23) {
			//pOut->PrintMessage("Pick the Green Figures.");
			R = pManager->getselfig();
			if (R->getcolourinfo().isFilled && R->getcolourinfo().FillClr == GREEN)
				correctC++;
			else incorrectC++;
		}

		else if (fc == 24) {
			//pOut->PrintMessage("Pick the Blue Figures.");
			R = pManager->getselfig();
			if (R->getcolourinfo().isFilled && R->getcolourinfo().FillClr == BLUE)
				correctC++;
			else incorrectC++;
		}
		else if (fc == 25) {
			//pOut->PrintMessage("Pick the Black Figures.");
			R = pManager->getselfig();
			if (R->getcolourinfo().isFilled && R->getcolourinfo().FillClr == BLACK)
				correctC++;
			else incorrectC++;
		}
		else if (fc == 26) {
			//pOut->PrintMessage("Pick the non-filled Figures.");
			R = pManager->getselfig();
			if (!R->getcolourinfo().isFilled)
				correctC++;
			else incorrectC++;
		}
		if (type == 11) {
			//pOut->PrintMessage("Pick the Rectangles.");
			R = pManager->getselfig();
			CRectangle* ay7aga = dynamic_cast<CRectangle*>(R);
			//else ay7aga1 = dynamic_cast<CRectangle*>(R);
			if (dynamic_cast<CRectangle*>(R) != nullptr)
				correctS++;
			else incorrectS++;
			//break;
		}
		else if (type == 12) {
			//pOut->PrintMessage("Pick the Circles.");
			R = pManager->getselfig();
			CCircle* ay7aga = dynamic_cast<CCircle*>(R);
			if (dynamic_cast<CCircle*>(R) != nullptr)
				correctS++;
			else incorrectS++;
			//break;
		}
		else if (type == 13) {
			//pOut->PrintMessage("Pick the Squares.");
			R = pManager->getselfig();
			CSquare* ay7aga = dynamic_cast<CSquare*>(R);
			if (dynamic_cast<CSquare*>(R) != nullptr)
				correctS++;
			else incorrectS++;
		}
		else if (type == 14) {
			//pOut->PrintMessage("Pick the Triangles.");
			R = pManager->getselfig();
			CTriangle* ay7aga = dynamic_cast<CTriangle*>(R);
			if (dynamic_cast<CTriangle*>(R) != nullptr)
				correctS++;
			else incorrectS++;
		}

		else if (type == 15) {
			//pOut->PrintMessage("Pick the Hexagons.");
			R = pManager->getselfig();
			CHexagon* ay7aga = dynamic_cast<CHexagon*>(R);
			if (dynamic_cast<CHexagon*>(R) != nullptr)
				correctS++;
			else incorrectS++;
		}
		if (correctC == 1 && correctS == 1)
			correctB++;
		else incorrectB++;
		correctC = 0;
		correctS = 0;
		DeleteAction d1(pManager);
		d1.Execute();
		pManager->setselfig(NULL);
		pManager->UpdateInterface();
	}
	string message;
	if (incorrectB == 0) //This is grading criteria for the grade output
		message = "Excellent!";
	else if (incorrectB >= 1 && incorrectB <= 3)
		message = "Great!";
	else if (incorrectB <= 4 && incorrectB >= 6)
		message = "Good!";
	else message = "Not Bad!";
	//printing grade after converting it to string
	string correctBSTR = to_string(correctB);
	string incorrectBSTR = to_string(incorrectB);
	pOut->PrintMessage(message + " You chose " + correctBSTR + " correct figures and " + incorrectBSTR + " incorrect figures.");
}
void BothAction::undo()
{

}

void BothAction::redo()
{

}
