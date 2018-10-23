#pragma once
#include "command.h"
#include "Figure.h"

class shape_add :public Command
{
public:
	shape_add(CTypedPtrArray<CObArray, Figure*> &shapes, Figure *s);
	~shape_add(void);
	virtual void perform();
	virtual void rollback();
private:
	CTypedPtrArray<CObArray, Figure*> &shapes;
	Figure *s;
};