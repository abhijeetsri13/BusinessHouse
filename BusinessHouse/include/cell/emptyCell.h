#pragma once
#include "cell.h"
class emptyCell :public cell
{
public:
	int updateBalance(player * obj);
	emptyCell();
	~emptyCell();
};

