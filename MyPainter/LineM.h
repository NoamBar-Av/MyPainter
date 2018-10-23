#pragma once  
#include "Figure.h"
class LineM:public Figure{
public:
	DECLARE_SERIAL(LineM)
	LineM(); 
	LineM(BOOL isThin); 
	//Figure* createFigure() { return new LineM();}
	void innerDraw(CDC *dc)
	{
		dc->MoveTo(startP.x, startP.y);
		dc->LineTo(endP.x, endP.y);
	}
	~LineM(); 
	/*static LineM* getInstance() {
		if (instance == 0)
			instance = new LineM();
		return instance;
	}*/
private:
	/*LineFactory(void);
	static LineFactory *instance;*/

};