//#include "..\..\pch.h"
#include"..\..\include\logger\GlobalLogger.h"
#include "..\..\include\cell\hotelCell.h"
#include<iostream>

int hotelCell::updateBalance(player * obj)
{
	
	std::string log;
	if (_owner == nullptr){
		_owner = obj;
		obj->reduceBalance(200);
		obj->addhotel();
		log = std::string("Visited Hotel to buy Player Name:- ") + obj->getPlayersId() + std::string(" New Balance-:")+ std::to_string(obj->getBalance());
		GlobalLogger::GetLogger()->Log( log); 
	}
	else if (_owner != nullptr && ((obj->getPlayersId()).compare(_owner->getPlayersId()) != 0))
	{
		obj->reduceBalance(50);
		_owner->addBalance(50);
		log= std::string("Visited Hotel Owned by :-")+_owner->getPlayersId()+std::string(" visitorr Player Name:- ") + obj->getPlayersId() + std::string(" New Balance-:") +  std::to_string(obj->getBalance());
		GlobalLogger::GetLogger()->Log(log);
	}
	else {
		GlobalLogger::GetLogger()->Log("Should Not Land here ERROR");
		// No actions needed 
		return -1;
	}
	
	return 0;
}

hotelCell::hotelCell()
{
	cellType = "hotel";
	_owner = nullptr;
	GlobalLogger::GetLogger()->Log("Created HotelCell");
	//std::cout << "Created HotelCell" << std::endl;
}


hotelCell::~hotelCell()
{
}
