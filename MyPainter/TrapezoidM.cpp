#include "StdAfx.h"
#include "TrapezoidM.h"
IMPLEMENT_SERIAL(TrapezoidM, Figure, 1)
TrapezoidM::TrapezoidM(){}
TrapezoidM::TrapezoidM(BOOL isThin):Figure(isThin){}
TrapezoidM::~TrapezoidM(){}