#include "StdAfx.h"
#include "RectangleM.h"
IMPLEMENT_SERIAL(RectangleM, Figure, 1)
RectangleM::RectangleM(){}
RectangleM::RectangleM(BOOL isThin):Figure(isThin){}
RectangleM::~RectangleM(){}