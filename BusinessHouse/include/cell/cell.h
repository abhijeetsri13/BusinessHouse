#pragma once
#include<string>
#include"..\player\player.h"
class cell
{
	
public:
	std::string cellType;
	virtual int updateBalance(player*)=0;
	cell();
	static cell * create(std::string);
	~cell();
};

