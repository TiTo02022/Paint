#ifndef DELETE_H
#define DELETE_H
#include "..\Figures\CFigure.h"
#include "Action.h"
class DeleteAction : public Action
{
private:
	CFigure* R;   //pointer on the pointer that will be deleted
	CFigure* q;
	CFigure* last;
	color dc;
public:
	DeleteAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute(bool co = true);

	void undo();
	void redo();
	//void addundo();
};
#endif

