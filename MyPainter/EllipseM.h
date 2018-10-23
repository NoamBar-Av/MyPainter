#pragma once  
#include "Figure.h"
class EllipseM:public Figure{
public:
	DECLARE_SERIAL(EllipseM)
	EllipseM(); 
	EllipseM(BOOL isThin); 
	//Figure* createFigure() { return new EllipseM(); }
	void innerDraw(CDC *dc)
	{
		dc->Ellipse(startP.x, startP.y, endP.x, endP.y);
	}
	/*static EllipseM* getInstance() {
		static EllipseM* instance = new EllipseM();
		return instance;
	}*/
	/*void Draw(CDC *dc)
	{
		dc->Ellipse(startP.x, startP.y, endP.x, endP.y);
	}*/
	~EllipseM();
	private:
		//EllipseM(void);
};