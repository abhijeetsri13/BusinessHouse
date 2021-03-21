#include <string>
#include <vector>
#pragma once
class player
{
	std::string playerId;
	int playerBalance;
	int hotelcount;
	//hotelCell;
public:
	//std::vector<hotelCell*> hotel_list;
	void addhotel() { hotelcount++; }
	int getOwnedhotelCount() { return hotelcount; }
	std::string getPlayersId() const { return playerId; }
	int getBalance() const { return playerBalance; }
	int reduceBalance(int num);
	int addBalance(int num);
	static bool compare(const player* lhs, const player * rhs);
	bool operator>(const player * rhs);
	player();
	player(std::string &playerName, int &playerBalance);
	~player();
};

