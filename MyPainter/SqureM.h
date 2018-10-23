#pragma once  
#include "Figure.h"
class SqureM:public Figure{
public:
	DECLARE_SERIAL(SqureM)
	SqureM(); 
	SqureM(BOOL isThin); 
	~SqureM();
	void innerDraw(CDC *dc)
	{
		CPoint point(startP.x+(startP.y-endP.y),startP.y-(startP.x-endP.x)),point2(endP.x+(startP.y-endP.y),endP.y-(startP.x-endP.x));
		CPoint angle[] = { point,startP,endP,point2};
		dc->Polygon(angle,4);
	}

};