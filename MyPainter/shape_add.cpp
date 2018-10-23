#include "StdAfx.h"
#include "shape_add.h"


shape_add::shape_add(CTypedPtrArray<CObArray, Figure*> &shapes, Figure *s):shapes(shapes), s(s)
{}


shape_add::~shape_add(void)
{}

void shape_add::perform()
{
	shapes.Add(s);
}

void shape_add::rollback()
{
	for (int i = 0; i < shapes.GetSize(); ++i)
		if (shapes[i] == s)
		{
			shapes.RemoveAt(i);
			return;
		}
}