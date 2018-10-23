#pragma once  
#include "Figure.h"
class TrapezoidM:public Figure{
public:
	DECLARE_SERIAL(TrapezoidM)
	TrapezoidM(); 
	TrapezoidM(BOOL isThin); 
	~TrapezoidM();
	void innerDraw(CDC *dc)
	{
		CPoint midlleP((startP.x+endP.x)/2,(startP.y+endP.y)/2);
		CPoint point(startP.x-(endP.x-startP.x),endP.y),point2(startP.x+(endP.x-startP.x),startP.y);
		
		CPoint angle[] = { startP, point , endP ,point2};
		dc->Polygon(angle,4);
		/*CPoint point(endP.x+(endP.x-startP.x)/2,endP.y+(endP.x-startP.x)),point2(startP.x+(endP.x-startP.x)/2,startP.y+(endP.x-startP.x));
		CPoint angle[] = { startP, point2 , point, endP};
		dc->Polygon(angle,4);*/
	}

};