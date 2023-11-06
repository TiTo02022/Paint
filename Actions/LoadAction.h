#ifndef Load_H
#define Load_H

#include "Action.h"
class LoadAction : public Action
{
private:
	string A;  //the file name to be entered
public:
	LoadAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();


	virtual void Execute(bool co = true);

	void undo();
	void redo();
};
#endif
