//#include "..\..\pch.h"
#include "..\..\include\game\Dice.h"
#include<random>

int Dice::RollDice()
{
	int temp = rand() % ((12 - 1) + 1) + 1;
	return temp;
}

Dice::Dice()
{
}


Dice::~Dice()
{
}
