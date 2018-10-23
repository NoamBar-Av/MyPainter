#pragma once  
#include "Figure.h"
class TriangleM:public Figure{
public:
	DECLARE_SERIAL(TriangleM)
	TriangleM(); 
	TriangleM(BOOL isThin); 
	~TriangleM();
	void innerDraw(CDC *dc)
	{
		/*CPoint point((startP.x+endP.x)/2,endP.x);*/
		CPoint point((startP.x+endP.x)/2,endP.y/2);
		CPoint angle[] = { startP , endP , point };
		dc->Polygon(angle,3);
		/*dc->MoveTo(startP.x,startP.y);
		dc->LineTo(startP.x,endP.y);
		dc->LineTo(endP.x,endP.y);
		dc->LineTo(startP.x,startP.y);*/
	}

};