#ifndef Save_H
#define Save_H

#include "Action.h"
class SaveAction : public Action
{
private:
	string A;  //the file name to be entered
public:
	SaveAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute(bool co = true);

	void undo();
	void redo();
};
#endif
