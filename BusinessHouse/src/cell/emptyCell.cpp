//#include "..\..\pch.h"
#include"..\..\include\cell\emptyCell.h"
#include"..\..\include\logger\GlobalLogger.h"
#include<iostream>

int emptyCell::updateBalance(player * obj)
{
	GlobalLogger::GetLogger()->Log(std::string("Visited Emptycell PlayerName:- ") + obj->getPlayersId() + std::string(" New Balance-:")
		+ std::to_string(obj->getBalance()));
	//std::cout << "Visited Emptycell PlayerName:- " << obj->getPlayersId() << " New Balance-:" << obj->getBalance() << std::endl;
	return 0;
}

emptyCell::emptyCell()
{
	this->cellType = "emptyCell";
	GlobalLogger::GetLogger()->Log(std::string("Created EmptyCell"));
	//std::cout << "Created EmptyCell" << std::endl;
}


emptyCell::~emptyCell()
{
}
