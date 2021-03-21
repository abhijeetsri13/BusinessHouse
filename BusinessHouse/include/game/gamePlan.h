#include<vector>
#include"..\game\Dice.h"
#include"..\player\player.h"
#include"boardCell.h"



#pragma once
class gamePlan
{
	std::vector<player*> allPlayers;
	Dice Obj;
	boardCell *_cellMappingObj;
	std::vector<int> _diceVal;


	int createCellObj(std::vector<std::string>);
	int getNumberofPlayers(std::istream& input);
	void createPlayerObj();
	int getCellAndPosition(std::istream& input);
	int _numberOfPlayersPlaying;
	int getDiceInput(std::istream& input);
public:
	boardCell * getcellMapping() { return _cellMappingObj; }
	int Play();
	int Initialize(std::istream& input);
	void DeclareOutput();
	gamePlan();
	~gamePlan();
};

