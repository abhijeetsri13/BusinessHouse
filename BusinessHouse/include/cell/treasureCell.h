#pragma once
#include "cell.h"
class treasureCell :public cell
{
public:
	int updateBalance(player *obj);
	treasureCell();
	~treasureCell();
};

