//#include "..\..\pch.h"
#include "..\..\include\cell\treasureCell.h"
#include<iostream>
#include"GlobalLogger.h"

int treasureCell::updateBalance(player * obj)
{
	obj->addBalance(200);
	GlobalLogger::GetLogger()->Log(std::string("Visited Treasure PlayerName:- ") + obj->getPlayersId() + std::string(" New Balance-:") +
		std::to_string(obj->getBalance()));
	return 0;
}

treasureCell::treasureCell()
{
	cellType = "treasureCell";
	GlobalLogger::GetLogger()->Log("Created treasureCell");
}


treasureCell::~treasureCell()
{
}
