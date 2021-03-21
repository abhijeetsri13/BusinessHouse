// BusinessHouse.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include "pch.h"
#include <iostream>
#include "include\game\gamePlan.h"
#include "include\logger\GlobalLogger.h"


int main()
{
	GlobalLogger::GetLogger()->Log("Game has started");
	gamePlan *playObj = new gamePlan();
	
	if (playObj->Initialize(std::cin) == 0)
	{
		if (playObj->Play() == -1)
			return -1;
		playObj->DeclareOutput();
	}
	
	return 0;
}
