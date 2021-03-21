//#include "..\..\pch.h"
#include"..\..\include\player\playerFactorry.h"
#include"..\..\include\player\player.h"

player * playerFactorry::createPlayer()
{
	return new player();
}

playerFactorry::playerFactorry()
{

}


playerFactorry::~playerFactorry()
{
}
