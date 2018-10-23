#pragma once  
#include "Figure.h"
class RTriangleM:public Figure{
public:
	DECLARE_SERIAL(RTriangleM)
	RTriangleM(); 
	RTriangleM(BOOL isThin); 
	~RTriangleM();
	void innerDraw(CDC *dc)
	{
		/*CPoint point((startP.x+endP.x)/2,endP.x);*/
		CPoint point(startP.x,endP.y);
		CPoint angle[] = { startP, endP,point};
		dc->Polygon(angle,3);
		/*dc->MoveTo(startP.x,startP.y);
		dc->LineTo(startP.x,endP.y);
		dc->LineTo(endP.x,endP.y);
		dc->LineTo(startP.x,startP.y);*/
	}

};