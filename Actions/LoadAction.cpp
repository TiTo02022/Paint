#include "..\Figures\CFigure.h"
#include "..\Figures\CRectangle.h"
#include"..\Figures\CCircle.h"
#include"..\Figures\CSquare.h"
#include"..\Figures\CTriangle.h"
#include"..\Figures\CHexagon.h"
#include <fstream>
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "ClearAllAction.h"
#include "LoadAction.h"

LoadAction::LoadAction(ApplicationManager* pApp) :Action(pApp)
{}
void LoadAction::ReadActionParameters()
{
	
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Please enter the file name to load it");
	A = pIn->GetSrting(pOut);//gets the file name
}
void LoadAction::Execute(bool co)
{
	if (co) {
		ReadActionParameters();
	}
	else {
		A = "original file ";
	}
	ClearAllAction c(pManager);
	c.Execute();
	GfxInfo FigureGfxInfo;
	Output* pOut = pManager->GetOutput();
	
	int k; //draw colour
	int fo; //fill colour
	int n; //count of figures
	int m; //type of shape
	int s; //id of shape
	ifstream f;
	f.open(A + ".txt");   //opens the file to load it
	f >> k >> fo;
	Point p1, p2;
	p1.x = 0;
	p1.y = 0;
	p2.x = 5;
	p2.y = 5;
	CRectangle pt(p1, p2, FigureGfxInfo);//create an object of class rectangle to call its functions as setcolors  
	pt.setcolours(k, fo, FigureGfxInfo);
	pOut->setCrntDrawColor(FigureGfxInfo.DrawClr);//sets the current draw color
	pOut->setCrntFillColor(FigureGfxInfo.FillClr);//sets the current fill color
	f >> n;
	for (int i = 0; i < n; i++) {
		f >> m>>s;
		CFigure* R=NULL;
		if (m == 11) { //Rectangle
			Point p1, p2;
			p1.x = 0;
			p1.y = 0;
			p2.x = 5;
			p2.y = 5;
			CRectangle b(p1, p2, FigureGfxInfo);//create a object of class rectangle to call its functions as load
			b.Load(f, R);
			pManager->AddFigure(R);
		}
		else if (m == 12) { //Circle
			Point p1, p2;
			p1.x = 0;
			p1.y = 0;
			p2.x = 5;
			p2.y = 5;
			CCircle b(p1, p2, FigureGfxInfo); //create a object of class circle to call its functions as load
			b.Load(f, R);
			pManager->AddFigure(R);
		}
		else if (m == 13) { //Square
			Point p1;
			p1.x = 0;
			p1.y = 0;
			CSquare b(p1, FigureGfxInfo);//create a object of class square to call its functions as load
			b.Load(f, R);
			pManager->AddFigure(R);
		}
		else if (m == 14) {
			Point p1, p2,p3;
			p1.x = 0;
			p1.y = 0;
			p2.x = 5;
			p2.y = 5;
			p3.x = 10;
			p3.y = 10;
			CTriangle b(p1,p2,p3, FigureGfxInfo); //create a object of class triangle to call its functions as load
			b.Load(f, R);
			pManager->AddFigure(R);
		}
		else if (m == 15) {
			Point p1;
			p1.x = 0;
			p1.y = 0;
			CHexagon b(p1, FigureGfxInfo); //create a object of class hexagon to call its functions as load
			b.Load(f, R);
			pManager->AddFigure(R);
		}

	}
	f.close(); //closes the file
}
void LoadAction::undo() {}

void LoadAction::redo() {}