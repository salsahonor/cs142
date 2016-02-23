/*
TEST CASES:
	1. Test: to see if program rejects/reprompts at invalid input in the tournament
	   Input: Q (instead of 1 or 2)
	   Output: "Invalid Response (Q) Select again: "
	   Result: program behaved as expected, rejected invalid input and reprompted
	2. Test: to see if program actually shuffles the vector
	   Input: 4 (the shuffle option)
	   Output: "The vector shuffled successfully."
	   Result: printing the vector determiens that it did indeed shuffle.
	3. Test: to see if program quits properly
	   Input: 6 (the quit option)
	   Output: program terminates
	   Result: program does indeed quit properly
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

int const FAILED = -1, SHUFFLES = 47;

//CHECKS FOR VALID INPUT (EITHER 1 OR 2)
string entryCheck(string selection)
{
	if ((selection != "1") && (selection != "2"))
	{
		cout << "Invalid Response (" << selection << ")\nSelect again: ";
		cin >> selection;
		entryCheck(selection);
	}
	return selection;
}

//CHECKS FOR POWER OF TWO
bool powerCheck(vector<string> restaurants)
{
	bool isapower = false;
	int size;

	size = restaurants.size();

	while (((size % 2) == 0) && size > 1)
	{
		size = size/2;
	}

	if (size == 1)
	{
		isapower = true;
	}
	return isapower;
}

//FINDS A RESTAURANT IN THE VECTOR
int find(vector<string> restaurants, string restaurantToFind)
{
	for (int i = 0; i < restaurants.size(); i++)
	{
		if (restaurants[i] == restaurantToFind)
		{
			return i;
		}
	}
	return FAILED;
}

//PRINTS THE VECTOR
void displayAllRestaurants(vector<string> restaurants) 
{
	int count = 1;
	string last;
	cout << " \n";

	for (int j = 0; j < restaurants.size()-1; j++)
	{
		cout << restaurants[j] << ", ";
	}

	cout << restaurants[restaurants.size() - 1] << "\n\n";
}

//ADDS A RESTAURANT TO THE VECTOR
void addARestaurant(vector<string>& restaurants)
{
	string newrestaurant;
	
	cout << "Enter a restaurant to add: ";
	cin.sync();
	getline(cin, newrestaurant);

	int found = find(restaurants, newrestaurant);

	if (found == FAILED)
	{
		restaurants.push_back(newrestaurant);
		cout << newrestaurant << " was added to the vector.\n\n";
	}
	else
	{
		cout << newrestaurant << " is already in the vector.\n\n";
	}
}

//REMOVES A RESTAURANT FROM THE VECTOR
void removeARestaurant(vector<string>& restaurants)
{
	string removerestaurant;

	cout << "Enter a restaurant to remove: ";
	cin.sync();
	getline(cin, removerestaurant);
	
	int found = find(restaurants, removerestaurant);
	
	if (found == FAILED)
	{
		cout << removerestaurant << " is not in the vector.\n\n";
	}
	else
	{
		restaurants[found] = restaurants[restaurants.size()-1]; //puts the restaurant in the last index position in the index postion of the "found" restaurant
		restaurants.pop_back(); //deletes the last index position from the vector
		cout << removerestaurant << " was removed from the vector.\n\n";
	}
}

//SHUFFLES THE VECTOR
void shuffleRestaurants(vector<string>& restaurants)
{
	for (int i = 0; i < SHUFFLES; i++)
	{
		int pos1 = rand() % restaurants.size(), pos2 = rand() % restaurants.size();
		string temp = restaurants[pos1];
		restaurants[pos1] = restaurants[pos2];
		restaurants[pos2] = temp;
	}
	cout << "The vector shuffled successfully.\n\n";
}

//PITS RESTAURANTS AGAINST EACH OTHER IN A VICIOUS BATTLE 
void dukeItOut(vector<string> restaurants)
{
	vector<string> losers;
	string restaurant1, restaurant2, selection;
	double numrounds = log2(restaurants.size());

	for (int round = 1; round <= numrounds; round++)
	{
		//recalculates the number of matches dependant on how many entries are left in the restaurants vector
		int nummatches = (restaurants.size() / 2), pos = 1;

		for (int match = 1; match <= nummatches; match++)
		{
			cout << "Round " << round << "/" << numrounds << ", ";
			cout << "Match " << match << "/" << nummatches << " --- ";
			cout << "1: " << restaurants[pos] << " or 2: " << restaurants[pos-1] << "? ";
			cin >> selection;
			selection = entryCheck(selection);

			if (selection == "1")
			{
				losers.push_back(restaurants[pos]);
			}
			else if (selection == "2")
			{
				losers.push_back(restaurants[pos-1]);
			}
			pos += 2;
		}
		
		//removes all the "loser" entries from the restaurants vector
		for (int i = 0; i < losers.size(); i++)
		{
			string loser = losers[i];
			int found = find(restaurants, loser);

			if (found != FAILED)
			{
				restaurants.erase(restaurants.begin() + found);
			}
		}
	}
	cout << "\n" << restaurants[0] << " is the winner!\n\n";
}

int main()
{
	srand(time(0));

	vector<string> restaurants;
	restaurants.push_back("Olive Garden");
	restaurants.push_back("Brick Oven");
	restaurants.push_back("Zupa's");
	restaurants.push_back("Wendy's");
	restaurants.push_back("Pizza Pie Cafe");
	restaurants.push_back("Subway");
	restaurants.push_back("Waffle Love");
	restaurants.push_back("P.F. Chang's");
	int option;

	do
	{
		cout << "   1 - Display All Restaurants\n   2 - Add A Restaurant\n   3 - Remove A Restaurant\n"
			<< "   4 - Shuffle The Vector\n   5 - Begin The Tournament\n   6 - Quit The Program\n" << "Select an option: ";
		cin >> option;
		

		//OPTION 1--DISPLAY ALL RESTAURANTS
		if (option == 1) 
		{
			displayAllRestaurants(restaurants);
		}
		//OPTION 2--ADD A RESTAURANT
		else if (option == 2) 
		{
			addARestaurant(restaurants);
		}
		//OPTION 3--REMOVE A RESTAURANT
		else if (option == 3) 
		{
			removeARestaurant(restaurants);
		}
		//OPTION 4--SHUFFLE THE VECTOR
		else if (option == 4) 
		{
			shuffleRestaurants(restaurants);
		}
		//OPTION 5--BEGIN THE TOURNAMENT
		else if (option == 5) 
		{
			bool cont = powerCheck(restaurants);
			if (cont == true)
			{
				cout << "\n";
				dukeItOut(restaurants);
				option = 6;
			}
			else
			{
				cout << "Insufficient number of entries in the vector. Must be a power of two.\n";
				cout << "The vector currently contains " << restaurants.size() << " entries.\n\n";
			}
			
		}
		else if (option != 6)
		{
			cout << "INVALID MENU OPTION\n\n";
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
			}
		}
	} while (option != 6);

	system("pause");
	return 0;
}