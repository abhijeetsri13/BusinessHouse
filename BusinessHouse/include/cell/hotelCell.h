#pragma once
#include "cell.h"
#include "..\player\player.h"
class hotelCell : public cell
{
	player *_owner;
public:
	int updateBalance(player *obj);
	hotelCell();
	~hotelCell();
};

