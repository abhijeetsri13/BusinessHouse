//#include "..\..\pch.h"
#include "..\..\include\cell\jailCell.h"
#include<iostream>
#include"..\..\include\player\player.h"
#include"..\..\include\logger\GlobalLogger.h"

jailCell::jailCell()
{
	cellType = "Jail";
	GlobalLogger::GetLogger()->Log("Created JailCell");
}

int jailCell::updateBalance(player *obj)
{
	obj->reduceBalance(150);
	GlobalLogger::GetLogger()->Log(std::string("Visited Jail PlayerName:- ") + 
								   obj->getPlayersId() + std::string(" New Balance-:") + 
								   std::to_string(obj->getBalance()));
	//std::string("Visited Jail PlayerName:- ") + obj->getPlayersId() << std::string(" New Balance-:") + std::to_string(obj->getBalance());
	return 0;

}

jailCell::~jailCell()
{
}
