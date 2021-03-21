//#include"..\..\pch.h"
#include"..\..\include\player\player.h"
#include"..\..\include\logger\GlobalLogger.h"

player::player()
{
	playerBalance = 1000;
	hotelcount = 0;
}
int player::reduceBalance(int num) {
	if ((this->playerBalance - num) < 0)
	{
		GlobalLogger::GetLogger()->Log(this->getPlayersId() + std::string(" has gone Bankrupt"));
		return -1;
	}
	else
		this->playerBalance = this->playerBalance - num;
	return 0;
}

int player::addBalance(int num)
{
	this->playerBalance = this->playerBalance + num;
	return 0;
}

bool player::compare(const player* lhs, const player * rhs)
{
	return (lhs->getBalance() > rhs->getBalance());
}
bool player::operator >(const player * rhs)
{
	return (this->getBalance() > rhs->getBalance());
}

player::player(std::string  &playerId, int &playerBalance)
{
	this->playerId = playerId;
	this->playerBalance = playerBalance;
	hotelcount = 0;
}

player::~player()
{
}
