#include "StdAfx.h"
#include "TriangleM.h"
IMPLEMENT_SERIAL(TriangleM, Figure, 1)
TriangleM::TriangleM(){}
TriangleM::TriangleM(BOOL isThin):Figure(isThin){}
TriangleM::~TriangleM(){}