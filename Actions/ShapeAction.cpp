#include "ShapeAction.h"
using Random = effolkronium::random_static;

ShapeAction::ShapeAction(ApplicationManager* pApp) : Action(pApp) {
	CountRect = 0, CountCirc = 0, CountSq = 0, CountTri = 0, CountHex = 0;
}
void ShapeAction::ReadActionParameters() {
	LoadAction l(pManager);
	l.Execute(false);
	pManager->UpdateInterface();
	int k; //draw colour
	int fo; //fill colour
	int n; //count of figures
	int m; //type of shape
	int s; //id of shape
	int fc; //fill colour
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
		if (ha == type) { //calculating counter of figures with same shape
			actualcount++;
		}
	}

}
void ShapeAction::Execute(bool co) {
	ReadActionParameters();

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//pOut->PrintMessage("Play with me! Pick all the figures based on SHAPES.");

	switch (type)
	{
	case 11:
		pOut->PrintMessage("Pick the Rectangles.");
		break;
	case 12:
		pOut->PrintMessage("Pick the Circles.");
		break;
	case 13:
		pOut->PrintMessage("Pick the Squares.");
		break;
	case 14:
		pOut->PrintMessage("Pick the Triangles.");
		break;
	case 15:
		pOut->PrintMessage("Pick the Hexagons.");
		break;
	}
	CFigure* R;
	int correctS = 0, incorrectS = 0;

	while (correctS < actualcount) {
		SelectAction s(pManager);
		s.Execute();
		while (pManager->getselfig() == nullptr){
			switch (type)
			{
			case 11:
				pOut->PrintMessage("Pick the Rectangles.");
				break;
			case 12:
				pOut->PrintMessage("Pick the Circles.");
				break;
			case 13:
				pOut->PrintMessage("Pick the Squares.");
				break;
			case 14:
				pOut->PrintMessage("Pick the Triangles.");
				break;
			case 15:
				pOut->PrintMessage("Pick the Hexagons.");
				break;
			}
			SelectAction s(pManager);
			s.Execute();
		}
		if (type == 11) {
			pOut->PrintMessage("Pick the Rectangles.");
			R = pManager->getselfig();
			CRectangle* ay7aga = dynamic_cast<CRectangle*>(R);
			if (dynamic_cast<CRectangle*>(R) != nullptr)
				correctS++;
			else incorrectS++;
		}
		else if (type == 12) {
			pOut->PrintMessage("Pick the Circles.");
			R = pManager->getselfig();
			CCircle* ay7aga = dynamic_cast<CCircle*>(R);
			if (dynamic_cast<CCircle*>(R) != nullptr)
				correctS++;
			else incorrectS++;
		}
		else if (type == 13) {
			pOut->PrintMessage("Pick the Squares.");
			R = pManager->getselfig();
			CSquare* ay7aga = dynamic_cast<CSquare*>(R);
			if (dynamic_cast<CSquare*>(R) != nullptr)
				correctS++;
			else incorrectS++;
		}			
		else if (type == 14) {
			pOut->PrintMessage("Pick the Triangles.");
			R = pManager->getselfig();
			CTriangle* ay7aga = dynamic_cast<CTriangle*>(R);
			if (dynamic_cast<CTriangle*>(R) != nullptr)
				correctS++;
			else incorrectS++;
		}

		else if (type == 15){
				pOut->PrintMessage("Pick the Hexagons.");
				R = pManager->getselfig();
				CHexagon* ay7aga = dynamic_cast<CHexagon*>(R);
				if (dynamic_cast<CHexagon*>(R) != nullptr)
					correctS++;
				else incorrectS++;
			}
		DeleteAction d1(pManager);
		d1.Execute();
		pManager->setselfig(NULL);
		pManager->UpdateInterface();
	}

	string message;
	if (incorrectS == 0) //This is grading criteria for the grade output
		message = "Excellent!";
	else if (incorrectS >= 1 && incorrectS <= 3)
		message = "Great!";
	else if (incorrectS <= 4 && incorrectS >= 6)
		message = "Good!";
	else message = "Not Bad!";

	//printing grade after converting it to string
	string correctSSTR = to_string(correctS);
	string incorrectSSTR = to_string(incorrectS);
	pOut->PrintMessage(message + " You chose " + correctSSTR + " correct figures and " + incorrectSSTR + " incorrect figures.");
}
void ShapeAction::undo() {}
void ShapeAction::redo() {}
