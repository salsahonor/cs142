/*This program allows the user to play the classic game of plinko with either one or multiple chips.

+-----------------------------------------------------------------------------------------------------------+
|                                                TEST CASES                                                 |
+---------------------------------------------+-------------------------------------------------------------+
|                    INPUT                    |                            OUTPUT                           |
+---------------------------------------------+-------------------------------------------------------------+
| option: 1; slot: 9                          | INVALID SLOT                                                |
+---------------------------------------------+-------------------------------------------------------------+
| option: 1; slot: 5                          | PATH: [5.0 4.5 4.0 3.5 3.0 2.5 2.0 1.5 1.0 0.5 0.0 0.5 0.0] |
|                                             | WINNINGS: $100.00                                           |
+---------------------------------------------+-------------------------------------------------------------+
| option: 2; chips: 50; slot: 8               | TOTAL WINNINGS: $5900.00                                    |
|                                             | AVERAGE WINNINGS: $118.00                                   |
+---------------------------------------------+-------------------------------------------------------------+
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0));
	double totalPrize=0, prize, position, move;
	int option, positionrestart, end, prize1 = 100, prize2 = 500, prize3 = 1000, prize4 = 0, prize5 = 10000;
	const double LEFT = -.5, RIGHT = .5;

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
			<< "   3 - Quit the program\n" << "Select an option: ";
		cin >> option;

		//ONE CHIP
		if (option == 1)
		{
			cout << "\nSINGLE CHIP" << "\n   Where would you like to start the chip? (Slots 0-8): ";
			cin >> position;

			if ((position >= 0) && (position <= 8)) 
			{
				cout << "PATH: [" << setprecision(1) << fixed << position;
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
					position += move; //position = position + move;
					cout << " " << position;
				}

				//DETERMINE AND REPORT WINNINGS
				end = position;
				switch (end)
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
				cout << "]" << "\nWINNINGS: $" << setprecision(2) << fixed << prize;
			}
			else
			{ cout << "INVALID SLOT"; }
		}

		//MULTIPLE CHIPS
		else if (option == 2) 
		{
			int numChips, i;
			cout << "\nMULTIPLE CHIPS" << "\n   How many chips?: ";
			cin >> numChips;
			i = numChips;
			if (numChips <= 0)
			{
				cout << "INVALID NUMBER OF CHIPS";
				i = 0;
			}

			if (numChips > 0)
			{
				cout << "   Where would you like to start the chips? (Slots 0-8): ";
				cin >> position;
				positionrestart = position;
				if ((position < 0) || (position > 8))
				{
					cout << "INVALID SLOT";
					i = 0;
				}
			}

			while (i > 0)
			{
				{
					if ((position >= 0) && (position <= 8))
					{
						//MOVE CHIP DOWN BOARD
						position = positionrestart;
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

							//DETERMINE PATH TAKEN
							position += move;
						}

						//DETERMINE AND REPORT WINNINGS
						end = position;
						switch (end)
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
						totalPrize += prize; 
					}
				}
				i--;
			}
			if ((numChips > 0) && ((position >= 0) && (position <= 8)))
			{
				cout << "TOTAL WINNINGS: $" << setprecision(2) << fixed << totalPrize;
				double avgPrize = totalPrize / numChips;
				cout << "\nAVERAGE WINNINGS: $" << avgPrize;
				totalPrize = 0;
			}
		}
		else if (option != 3)
		{ cout << "INVALID OPTION"; }
	} while (option != 3);
	
	//OPTION 3
	cout << "\nGOODBYE!\n";

	system("pause");
	return 0;
}