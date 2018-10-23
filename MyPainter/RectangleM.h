#pragma once  
#include "Figure.h"
class RectangleM:public Figure{
public:
	DECLARE_SERIAL(RectangleM)
	RectangleM();
	RectangleM(BOOL isThin);
	//Figure* createFigure() { return new RectangleM(); }
	void innerDraw(CDC *dc)
	{
		dc->Rectangle(startP.x, startP.y, endP.x, endP.y);
	}
	/*void Draw(CDC *dc)
	{
		dc->Rectangle(startP.x, startP.y, endP.x, endP.y);
	}*/
	~RectangleM();
};