#include "StdAfx.h"
#include "ParallelogramM.h"
IMPLEMENT_SERIAL(ParallelogramM, Figure, 1)
ParallelogramM::ParallelogramM(){}
ParallelogramM::ParallelogramM(BOOL isThin):Figure(isThin){}
ParallelogramM::~ParallelogramM(){}