#pragma once
#include <string>
using namespace std;

const int STARTWINS = 0, STARTLOSSES = 0, STARTDRAWS = 0;

class Player
{
public:
	Player(string n);
	~Player();

	string getName();
	int getWin();
	int getLoss();
	int getDraw();
	int getRPSthrow();
	double getWinRecord();

	void addWin();
	void addLoss();
	void addDraw();

	string toString();

private:
	string name;
	int wins, losses, draws;
};

