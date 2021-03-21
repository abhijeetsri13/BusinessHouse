//#include "..\..\pch.h"
#include"..\..\include\cell\cell.h"
#include<string>
#include"..\..\include\cell\emptyCell.h"
#include"..\..\include\cell\jailCell.h"
#include"..\..\include\cell\hotelCell.h"
#include"..\..\include\cell\treasureCell.h"

cell::cell()
{
}

cell* cell::create(std::string type)
{
	if (type.compare("E") == 0)
		return new emptyCell();
	else if (type.compare("J") == 0)
		return new jailCell();
	else if (type.compare("H") == 0 )
		return new hotelCell();
	else if (type.compare("T") == 0)
		return new treasureCell();
	else
		return nullptr;

}

cell::~cell()
{
}
