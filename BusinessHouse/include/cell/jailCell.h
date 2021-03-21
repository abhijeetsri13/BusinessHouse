#pragma once
#include "cell.h"
class jailCell :
	public cell
{
public:
	int updateBalance(player *obj);
	jailCell();
	~jailCell();
};

