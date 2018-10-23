#pragma once  
#include "Figure.h"
class ParallelogramM:public Figure{
public:
	DECLARE_SERIAL(ParallelogramM)
	ParallelogramM(); 
	ParallelogramM(BOOL isThin); 
	~ParallelogramM();
	void innerDraw(CDC *dc)
	{
		
		CPoint point(endP.x+endP.x-startP.x,endP.y+endP.x-startP.x),point2(startP.x+endP.x-startP.x,startP.y+endP.x-startP.x);
		CPoint angle[] = { startP, point2 , point, endP};
		dc->Polygon(angle,4);

		/*CPoint midlleP((startP.x+endP.x)/2,(startP.y+endP.y)/2);
		CPoint point(midlleP.x+40,midlleP.y+40),point2(midlleP.x-40,midlleP.y-40);
		CPoint midlleP2((point.x+point2.x)/2,(point.y+point2.y)/2);
		CPoint angle[] = { startP, point , endP,point2};
		dc->Polygon(angle,4);*/
	}

};