#include "StdAfx.h"
#include "Command.h"


Command::Command(void)
{
	size=0;
}


Command::~Command(void)
{
}

void Command::setSize()
{size++;}
int Command::getSize()
{return size;}