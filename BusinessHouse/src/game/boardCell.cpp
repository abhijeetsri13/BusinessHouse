//#include "..\..\pch.h"
#include "..\..\include\game\boardCell.h"
#include"..\..\include\cell\cell.h"



int boardCell::getPlayersPosition(const player * obj, Node *& prevNode)
{
	if (obj != nullptr)
	{
		prevNode = players_positionmap.at(obj->getPlayersId());
	}
	else
		return -1;
	return 0;
}

int boardCell::updatePlayersPosition(player *& playerObj, Node *& newNode)
{
	std::map<std::string, Node*>::iterator it = players_positionmap.find(playerObj->getPlayersId());
	if (it != players_positionmap.end())
		it->second = newNode;
	else
		return -1;
	return 0;
}

int boardCell::MovePlayer(player *playerObj, const int diceMove)
{
	Node *prevNode = nullptr;
	getPlayersPosition(playerObj, prevNode);
	if (prevNode != nullptr) {
		Node *newNode = getNthNode(prevNode, diceMove);
		newNode->data->updateBalance(playerObj);
		return updatePlayersPosition(playerObj, newNode);
	}
	else
		return -1;
}

struct Node *boardCell::addToEmpty(struct Node *last, cell *&data)
{
	if (last != nullptr)
		return last;

	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	if (temp != nullptr)
	{
		temp->data = data;
		last = temp;

		_start = last->next = last;
	}
	
	return last;
}

struct Node *boardCell::addEnd(struct Node *last, cell *&data)
{
	if (last == nullptr)
		return addToEmpty(last, data);

	struct Node *temp =
		(struct Node *)malloc(sizeof(struct Node));
	if (temp != NULL)
	{
		temp->data = data;
		temp->next = last->next;
		last->next = temp;
		last = temp;
	}
	return last;
}

void boardCell::InitializeMap(std::vector<player*> allPlayers)
{
	for (size_t i = 0; i < allPlayers.size(); i++)
		players_positionmap.insert(std::make_pair(allPlayers[i]->getPlayersId(), _start));
}

struct Node* boardCell::getNthNode(struct Node *curent, int n)
{
	struct Node *temp = curent;
	while (n--)
		temp = temp->next;
	
	return temp;
}




void boardCell::addCell(cell *& data)
{
	_last = addEnd(_last, data);
}

boardCell::boardCell()
{
	_start = nullptr;
	_last = nullptr;
}


boardCell::~boardCell()
{
}
