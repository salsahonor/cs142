/*
TEST CASES
	1. Test: to see if quit function works.
	   Input: 6
	   Output: program ends
	   Result: program behaved as expected--quit for option 6.
	2. Test: to see if "Add a Player" function works.
	   Input: 2, A
	   Output: "A added successfully."
	   Result: Selecting 1 (Show All Players) confirms that A was added to the vector.
	3. Test: to see if "Fight" function works.
	   Input: 2, A, 2, B, 3, A, 3, B, 5
	   Output: "A WINS!"
	   Result: Selecting 1 (Show All Players) confirms that A and B fought and A won.
*/

#include <iostream>
#include "Player.h"
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

const int FAILED = -1;
int const ROCK = 0, PAPER = 1, SCISSORS = 2;

//FIND PLAYER
int find(vector<Player*> players, string n)
{
	for (int i = 0; i < players.size(); i++)
	{
		if (players[i]->getName() == n)
		{
			return i;
		}
	}
	return FAILED;
}

//SHOW PLAYERS
void print(vector<Player*> players)
{
	for (int i = 0; i < players.size(); i++)
	{
		string pstats = players[i]->toString();
		cout << pstats << endl;
	}
}

//ADD NEW PLAYER
void addPlayer(vector<Player*> &players)
{
	string name;
	cout << "Name of Player: ";
	cin.sync();
	getline(cin, name);

	int found = find(players, name);
	if (found == FAILED)
	{
		Player* p = new Player(name);
		players.push_back(p);
		cout << name << " successfully added.\n\n";
	}
	else
	{
		cout << name << " is already a player.\n\n";
	}
}

//ADD TO LINE UP
void addLineUp(vector<Player*> &lineup, vector<Player*> allPlayers)
{
	string name;
	cout << "Who do you want to add to the line up?: ";
	cin.sync();
	getline(cin, name);

	int found = find(allPlayers, name);
	if (found != FAILED)
	{
		Player* p = allPlayers[found];
		lineup.push_back(p);
		cout << name << " successfully added to the line up.\n\n";
	}
	else
	{
		cout << name << " is not a player.\n\n";
	}
}

//FIGHT
void dukeitout(vector<Player*> &lineup)
{
	if (lineup.size() >= 2) //need at least two players in the vector
	{
		int p0throw = lineup[0]->getRPSthrow(), p1throw = lineup[1]->getRPSthrow();
		string p0name = lineup[0]->getName(), p1name = lineup[1]->getName();

		if (lineup[0] == lineup[1]) //if the first two entries are the same, automatic draw
		{
			cout << p0name << " is the only contestant. Automatic DRAW.\n\n";
			lineup[0]->addDraw();
		}
		else
		{
			cout << p0name << " and " << p1name << " are gonna DUKE IT OUT!!\n\n";

			if (p0throw == ROCK)
			{
				cout << p0name << " throws ROCK!\n";
				if (p1throw == ROCK)
				{
					cout << p1name << " throws ROCK!\n\n";
					lineup[0]->addDraw();
					lineup[1]->addDraw();
					cout << p0name << " and " << p1name << " DRAW!\n\n";
				}
				else if (p1throw == PAPER)
				{
					cout << p1name << " throws PAPER!\n\n";
					lineup[0]->addLoss();
					lineup[1]->addWin();
					cout << p1name << " WINS!\n\n";
				}
				else if (p1throw == SCISSORS)
				{
					cout << p1name << " throws SCISSORS!\n\n";
					lineup[0]->addWin();
					lineup[1]->addLoss();
					cout << p0name << " WINS!\n\n";
				}
			}
			else if (p0throw == PAPER)
			{
				cout << p0name << " throws PAPER!\n";
				if (p1throw == ROCK)
				{
					cout << p1name << " throws ROCK!\n\n";
					lineup[0]->addWin();
					lineup[1]->addLoss();
					cout << p0name << " WINS!\n\n";
				}
				else if (p1throw == PAPER)
				{
					cout << p1name << " throws PAPER!\n\n";
					lineup[0]->addDraw();
					lineup[1]->addDraw();
					cout << p0name << " and " << p1name << " DRAW!\n\n";
				}
				else if (p1throw == SCISSORS)
				{
					cout << p1name << " throws SCISSORS!\n\n";
					lineup[0]->addLoss();
					lineup[1]->addWin();
					cout << p1name << " WINS!\n\n";
				}
			}
			else if (p0throw == SCISSORS)
			{
				cout << p0name << " throws SCISSORS!\n";
				if (p1throw == ROCK)
				{
					cout << p1name << " throws ROCK!\n\n";
					lineup[0]->addLoss();
					lineup[1]->addWin();
					cout << p1name << " WINS!\n\n";
				}
				else if (p1throw == PAPER)
				{
					cout << p1name << " throws PAPER!\n\n";
					lineup[0]->addWin();
					lineup[1]->addLoss();
					cout << p0name << " WINS!\n\n";
				}
				else if (p1throw == SCISSORS)
				{
					cout << p1name << " throws SCISSORS!\n\n";
					lineup[0]->addDraw();
					lineup[1]->addDraw();
					cout << p0name << " and " << p1name << " DRAW!\n\n";
				}
			}
		}
		lineup.erase(lineup.begin(), lineup.begin() + 2); //deletes the first two entries from line up vector
	}
	else
	{
		cout << "Not enough players in the line up.\n\n";
	}
}

int main()
{
	srand(time(0));
	vector <Player*> allPlayers;
	vector <Player*> lineUp;
	int option;

	do
	{
		cout << "MENU\n";
		cout << "   1 - Show All Players" << endl;
		cout << "   2 - Add New Player" << endl;
		cout << "   3 - Add to Line Up" << endl;
		cout << "   4 - Show Line Up" << endl;
		cout << "   5 - Fight" << endl;
		cout << "   6 - Quit" << endl;
		cout << "Select an option: ";
		cin >> option;

		switch (option)
		{
		case 1://SHOW PLAYERS
			print(allPlayers);
			break;

		case 2://ADD NEW PLAYER
			addPlayer(allPlayers);
			break;

		case 3://ADD TO LINE UP
			addLineUp(lineUp, allPlayers);
			break;

		case 4://SHOW LINE UP
			print(lineUp);
			break;

		case 5://FIGHT
			dukeitout(lineUp);
			break;
		}
	} while (option != 6);

	return 0;
}