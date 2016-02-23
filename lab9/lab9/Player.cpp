#include "Player.h"
#include <sstream>
using namespace std;

int const ROCK = 0, PAPER = 1, SCISSORS = 2;

//CONSTRUCTOR
Player::Player(string n)
{
	name = n;
	wins = STARTWINS;
	losses = STARTLOSSES;
	draws = STARTDRAWS;
}

Player::~Player()
{
}

//GETTERS
string Player::getName()
{ return name; }
int Player::getWin()
{ return wins; }
int Player::getLoss()
{ return losses; }
int Player::getDraw()
{ return draws; }

//SETTERS
void Player::addWin()
{ wins++; }
void Player::addLoss()
{ losses++; }
void Player::addDraw()
{ draws++; }

//returns R P or S at random
int Player::getRPSthrow()
{
	int num = rand() % 3;

	if (num == 0)
	{ return ROCK; }
	else if (num == 1)
	{ return PAPER; }
	else if (num == 2)
	{ return SCISSORS; }
}

//returns ratio of "wins/total number of matches"
double Player::getWinRecord()
{
	double record;
	if ((wins + losses + draws) != 0)
	{
		record = wins / (wins + losses + draws+0.0); //wins, losses, draws are int so need "+0.0" to return double
	}
	else
	{
		record = 0;
	}
	return record;
}

//puts all the metadata associated with a Player variable in a string
string Player::toString()
{
	stringstream ss;
	double record = getWinRecord(); 

	ss << "\nName: " << name << endl;
	ss << "Wins: " << wins << endl;
	ss << "Losses: " << losses << endl;
	ss << "Draws: " << draws << endl;
	ss << "Win Record: " << 100*record << "%" << endl;

	return ss.str();
}