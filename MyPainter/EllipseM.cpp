#include "StdAfx.h"
#include "EllipseM.h"
IMPLEMENT_SERIAL(EllipseM, Figure, 1)
EllipseM::EllipseM(){}
EllipseM::EllipseM(BOOL isThin):Figure(isThin){}
EllipseM::~EllipseM(){}