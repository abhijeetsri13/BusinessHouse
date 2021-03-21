#include"..\..\include\logger\GlobalLogger.h"
#include "..\..\include\game\gamePlan.h"
#include <iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include "..\..\include\game\boardCell.h"

int gamePlan::createCellObj(std::vector<std::string> v)
{
	for (size_t i = 0; i < v.size(); i++){
		cell *cellObj = cell::create(v[i]);
		if (cellObj == nullptr)
			return -1;
		boardCell * obj  = getcellMapping();
		obj->addCell(cellObj);
	}
	return 0;
}

int gamePlan::getNumberofPlayers(std::istream& input)
{
	int ret_code = -1;
	std::cout << "Please enter the number of Players" << std::endl;
	input >> _numberOfPlayersPlaying;
	//_numberOfPlayersPlaying = 3;
	int trail = 3;
	while (trail--)
	{
		
		if (_numberOfPlayersPlaying < 2 )
		{
			std::cout << "Number of players should be greater than two:-" << std::endl;
			std::cout << "Please re-enter" << std::endl;
			std::cout << "Please enter the number of Players" << std::endl;
			input >> _numberOfPlayersPlaying;
		}
		else {
			ret_code = 0;
			break;
		}
	}
	return ret_code;
}

void gamePlan::createPlayerObj()
{
	int initialBalance = 1000;
	for (int i = 0; i < _numberOfPlayersPlaying; i++)
	{
		std::string playerName = std::string("Player") + std::to_string(i + 1);
		player *temp = new player(playerName, initialBalance);
		allPlayers.push_back(temp);
	}
}

int gamePlan::getCellAndPosition(std::istream& input)
{
	int ret_code = -1;
	std::string inptStr;
	std::cout << "Please Enter cellPosition and Type:-" << std::endl;
	//std::cin >> inptStr;
	input >> inptStr;
	//inptStr = "E,E,J,H,E,T,J,T,E,E,H,J,T,H,E,E,J,H,E,T,J,T,E,E,H,J,T,H,J,E,E,J,H,E,T,J,T,E,E,H,J,T,E,H,E";
	std::vector<std::string> v;

	std::stringstream ss(inptStr);
	while (ss.good()) {
		std::string substr;
		getline(ss, substr, ',');
		v.push_back(substr);
	}

	createCellObj(v);
	for (size_t i = 0; i < v.size(); i++){
		std::cout << v[i] << std::endl;
	}

	return 0;
}

int gamePlan::getDiceInput(std::istream& input)
{
	std::string str;
	std::cout << "You can enter your Dice val as input with comma separated" << std::endl;
	//std::cin >> str;
	input >> str;
	//str = "4,4,4,6,7,8,5,11,10,12,2,3,5,6,7,8,5,11,10,12,2,3,5,6,7,8,5,11,10,12";
	std::stringstream ss(str);

	for (int i; ss >> i;) {
		_diceVal.push_back(i);
		if (ss.peek() == ',')
			ss.ignore();
	}
	if (_diceVal.size() != _numberOfPlayersPlaying * 10)
	{
		GlobalLogger::GetLogger()->Log("Dice ROll input is not as per the number of players");
		return -1;
	}
	return 0;
}

int gamePlan::Play()
{
	_cellMappingObj->InitializeMap(allPlayers);
	for (size_t i = 0; i < _diceVal.size(); i++)
	{
		if (_cellMappingObj->MovePlayer(allPlayers[i % _numberOfPlayersPlaying], _diceVal[i]) == -1)
			return -1;
	}
	return 0;
}

int gamePlan::Initialize(std::istream& input)
{
	int ret_code = -1;
	
	if ((ret_code = getNumberofPlayers(input)) == -1)
	{
		GlobalLogger::GetLogger()->Log("ERROR with the Number of players entered");
		return ret_code;
	}
	createPlayerObj();
	if ((ret_code = getCellAndPosition(input)) == -1)
	{
		GlobalLogger::GetLogger()->Log("ERROR with the Number of players entered");
		return ret_code;
	}
	if ((ret_code = getDiceInput(input)) == -1) {
		GlobalLogger::GetLogger()->Log("ERROR with the Dice Input");
		return ret_code;
	}
	
	return ret_code;

}

void gamePlan::DeclareOutput()
{
	for (size_t i = 0; i < allPlayers.size(); i++)
	{
		allPlayers[i]->addBalance(allPlayers[i]->getOwnedhotelCount() * 200);
		//std::cout << "PlayerName:- " << allPlayers[i]->getPlayersId() << "     Balance:- " << allPlayers[i]->getBalance() << std::endl;
	}
	std::sort(allPlayers.begin(), allPlayers.end(), player::compare);
	
	GlobalLogger::GetLogger()->Log("output balance");
	std::cout << "output balance" << std::endl;
	for (size_t i = 0; i < allPlayers.size(); i++)
	{
		std::cout << "PlayerName:- " << allPlayers[i]->getPlayersId() << "     Balance:- " << allPlayers[i]->getBalance()<<std::endl;
	}
	std::cout<<"Winner is "<<allPlayers[0]->getPlayersId() << "     Balance:- " << allPlayers[0]->getBalance() << std::endl;
}

gamePlan::gamePlan()
{
	_numberOfPlayersPlaying = 0;
	_cellMappingObj = new boardCell();
}


gamePlan::~gamePlan()
{
}
