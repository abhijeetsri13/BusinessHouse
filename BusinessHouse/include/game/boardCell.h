#pragma once
#include"..\cell\cell.h"
#include <cstdlib>
#include"..\player\player.h"

#include <map>
#include<vector>

struct Node
{
	cell *data;
	struct Node *next;
};



class boardCell
{
	struct Node *_last;
	struct Node *_start;
	int getPlayersPosition(const player *obj, Node *&prevNode);
	int updatePlayersPosition(player *&playerObj, Node *&newNode);
public:
	std::map<std::string, Node*> players_positionmap;
	int MovePlayer(player*, const int);
	Node * addToEmpty(Node * last, cell *& data);
	Node * addEnd(Node * last, cell *& data);
	void InitializeMap(std::vector<player*> allPlayers);
	struct Node* getNthNode(struct Node *curent,int n);
	void addCell(cell *&data);
	boardCell();
	~boardCell();
};

