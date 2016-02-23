/*This program allows the user to play the classic game of plinko with either one chip, multiple chips 
in one slot, or multiple chips in every slot.

+-------------------------------------------------------------------------------------------------------------------------------------------------------------+
|                                                                      TEST CASES                                                                             |
+-------------------------------------+-------------------------------------------------------+---------------------------------------------------------------+
|              INPUT                  |                   EXPECTED OUTPUT                     |                              OUTPUT                           |
+-------------------------------------+-------------------------------------------------------+---------------------------------------------------------------+
| option: 1; slot: 9                  | "INVALID SLOT", return to menu.                       | "INVALID SLOT", return to menu.                               |
+-------------------------------------+-------------------------------------------------------+---------------------------------------------------------------+
| option: 1; slot: 5                  | Chip will fall 12 times & report its path. Program    | PATH: [5.0 5.5 5.0 4.5 4.0 4.5 4.0 3.5 4.0 4.5 4.0 4.5 4.0]   |
|                                     | will report winnigns based on final position.         | WINNINGS: $10000.00                                           |
+-------------------------------------+-------------------------------------------------------+---------------------------------------------------------------+
| option: 3; chips: 50                | Program will print the total and average winnings for | SLOT 0: TOTAL WINNINGS: $28400.00 AVERAGE WINNINGS: $568.00   |
|                                     | all 9 of the slots.                                   | SLOT 1: TOTAL WINNINGS: $22600.00 AVERAGE WINNINGS: $452.00   | 
|                                     |                                                       | SLOT 2: TOTAL WINNINGS: $58300.00 AVERAGE WINNINGS: $1166.00  |      
|                                     |                                                       | SLOT 3: TOTAL WINNINGS: $78100.00 AVERAGE WINNINGS: $1562.00  |  
|                                     |                                                       | SLOT 4: TOTAL WINNINGS: $172500.00 AVERAGE WINNINGS: $3450.00 |     
|                                     |                                                       | SLOT 5: TOTAL WINNINGS: $90100.00 AVERAGE WINNINGS: $1802.00  |   
|                                     |                                                       | SLOT 6: TOTAL WINNINGS: $79400.00 AVERAGE WINNINGS: $1588.00  |   
|                                     |                                                       | SLOT 7: TOTAL WINNINGS: $62200.00 AVERAGE WINNINGS: $1244.00  |    
|                                     |                                                       | SLOT 8: TOTAL WINNINGS: $43300.00 AVERAGE WINNIGNS: $866.00   |
+-------------------------------------+-------------------------------------------------------+---------------------------------------------------------------+
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

const double LEFT = -.5, RIGHT = .5;


int getPrizeMoney(int endposition)
{
	double prize=0;
	int prize1 = 100, prize2 = 500, prize3 = 1000, prize4 = 0, prize5 = 10000;

	switch (endposition)
	{
	case 0: prize = prize1; break;
	case 1: prize = prize2; break;
	case 2: prize = prize3; break;
	case 3: prize = prize4; break;
	case 4: prize = prize5; break;
	case 5: prize = prize4; break;
	case 6: prize = prize3; break;
	case 7: prize = prize2; break;
	case 8: prize = prize1; break;
	}
	return prize;
}

double oneChipFalling(double position, int option)
{
	double move, prize;

	if ((position >= 0) && (position <= 8))
	{
		//Only prints path if option 1 (single chip) is selected
		if (option == 1) { cout << "PATH: [" << setprecision(1) << fixed << position; }
		
		//MOVE CHIP DOWN BOARD
		for (int row = 0; row < 12; row++)
		{
			//CHIP FALLS LEFT OR RIGHT
			if (rand() % 2 == 1)
			{ move = RIGHT; }
			else { move = LEFT; }

			//STOP FROM MOVING OFF BOARD
			if (position == 0)
			{ move = RIGHT; }
			else if (position == 8)
			{ move = LEFT; }

			//DETERMINE AND REPORT PATH TAKEN
			
			position += move;
			if (option == 1) { cout << " " << position; }
		}
		prize = getPrizeMoney(position);

		if (option == 1) { cout << "]" << "\nWINNINGS: $" << setprecision(2) << fixed << prize; }

		return prize;
	}
	else
	{ 
		cout << "INVALID SLOT";
		return 1;
	}
}

int multChipsFalling(int numChips, double position, int option)
{
	int i, endposition;
	double move, totalPrize = 0;

	i = numChips;
	
	if ((position >= 0) && (position <= 8))
	{
		while (i > 0)
		{
			{
					totalPrize += oneChipFalling(position, option);
			}
			i--;
		}
	
		cout << "\nTOTAL WINNINGS: $" << totalPrize;
		double avgPrize = totalPrize / numChips;
		cout << "\nAVERAGE WINNINGS: $" << setprecision(2) << fixed << avgPrize;
		return 0;
	}
	else
	{
		cout << "INVALID SLOT";
		return 1;
	}
}

int main()
{
	double totalPrize = 0, prize, position;
	int option, end, numChips;
	srand(time(0));

	cout << "\t /$$$$$$$  /$$       /$$$$$$ /$$   /$$ /$$   /$$  /$$$$$$\n";
	cout << "\t| $$__  $$| $$      |_  $$_/| $$$ | $$| $$  /$$/ /$$__  $$\n";
	cout << "\t| $$   \\$$| $$        | $$  | $$$$| $$| $$ /$$/ | $$    $$\n";
	cout << "\t| $$$$$$$/| $$        | $$  | $$ $$ $$| $$$$$/  | $$  | $$\n";
	cout << "\t| $$____/ | $$        | $$  | $$  $$$$| $$  $$  | $$  | $$\n";
	cout << "\t| $$      | $$        | $$  | $$\\  $$$| $$\\  $$ | $$  | $$\n";
	cout << "\t| $$      | $$$$$$$$ /$$$$$$| $$ \\  $$| $$ \\  $$|  $$$$$$/\n";
	cout << "\t|__/      |________/|______/|__/  \\__/|__/  \\__/ \\______/\n";

	do
	{
		cout << "\n\n\nMENU\n" << "   1 - Drop a single chip into one slot\n" << "   2 - Drop multiple chips into one slot\n"
			<< "   3 - Drop multiple chips in every slot\n" << "   4 - Quit the program\n" << "Select an option: ";
		cin >> option; 
		if (cin.fail())
		{ 
			cout << "INVALID MENU OPTION"; 
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else
		{
			//OPTION 1--SINGLE CHIP
			if (option == 1)
			{
				cout << "\nSINGLE CHIP" << "\n   Where would you like to start the chip? (Slots 0-8): ";
				cin >> position;
				if (cin.fail()) 
				{ 
					cout << "INVALID SLOT"; 
					cin.clear();
					cin.ignore(1000, '\n');
				}
				else { oneChipFalling(position, option); }
			}

			//OPTION 2--MULT CHIPS
			if (option == 2)
			{
				cout << "\nMULTIPLE CHIPS, ONE SLOT" << "\n   How many chips?: ";
				cin >> numChips;
				if (cin.fail())
				{ 
					cout << "INVALID NUMBER OF CHIPS";
					cin.clear();
					cin.ignore(1000, '\n');
				}
				else if (numChips > 0)
				{
					cout << "   Where would you like to start the chips? (Slots 0-8): ";
					cin >> position;
					if (cin.fail()) 
					{ 
						cout << "INVALID SLOT";
						cin.clear();
						cin.ignore(1000, '\n');
					}
					else { multChipsFalling(numChips, position, option); }
				}
				else { cout << "INVALID NUMBER OF CHIPS"; }
			}

			//OPTION 3--MULT CHIPS EVERY SLOT
			if (option == 3)
			{
				cout << "\nMULTIPLE CHIPS, ALL SLOTS" << "\n   How many chips?: ";
				cin >> numChips;
				if (cin.fail())
				{ 
					cout << "INVALID NUMBER OF CHIPS"; 
					cin.clear();
					cin.ignore(1000, '\n');
				}

				else if (numChips > 0)
				{
					int i = numChips, j = 0; //j is the number of slots 

					if (i > 0)
					{
						while (j <= 8)
						{
							cout << "\nSLOT " << j << ":";
							multChipsFalling(i, j, option);
							j++;
						}
						i--;
					}
				}
				else { cout << "INVALID NUMBER OF CHIPS"; }
			}
		}
	} while (option != 4);

	//OPTION 4--QUIT
	cout << "\nGOODBYE!\n";

	system("pause");
	return 0;
}