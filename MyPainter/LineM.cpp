#include "StdAfx.h"
#include "LineM.h"
IMPLEMENT_SERIAL(LineM, Figure, 1)
LineM::LineM(){}
LineM::LineM(BOOL isThin):Figure(isThin){}
LineM::~LineM(){}