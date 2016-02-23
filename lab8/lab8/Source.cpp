/*
TEST CASES
	1. Test: to see if quit function works.
	   Input: 8
	   Output: program ends
	   Result: program behaved as expected, quit for option 8.
	2. Test: to see if "Buy a Car" function works.
	   Input: 3, A, green, 45
	   Output: "Car bought successfully."
	   Result: Selecting 1 (Show Current Inventory) reveals that the car was indeed added to the vector.
	3. Test: to see if "Load File" function works.
	   Input: 6, cars1.txt
	   Output: "Inventory updated successfully."
	   Result: Selecting 1 (Show Current Inventory) and 2 (Show Current Balance) reveals that the contents
			   were indeed added to the vector correctly.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include "Car.h"
using namespace std;

const int NOTFOUND = -1;

int find(vector<Car> cars, string name)
{
	for (int i = 0; i < cars.size(); i++)
	{
		if (cars[i].getName() == name)
		{
			return i;
		}
	}
	return NOTFOUND;
}

void print(vector<Car> cars) //OPTION 1
{
	for (int i = 0; i < cars.size(); i++)
	{
		string car = cars[i].toString();
		cout << "\n" << setprecision(2) << fixed << car;
	}
}

void buyCar(vector<Car> &cars, string name, string color, double price, double &balance)
{
	Car newcar = Car(name, color, price);
	cars.push_back(newcar);
	balance -= price;
	cout << "Car bought successfully.";
}

void sellCar(vector<Car> &cars, string name, double &balance)
{
	int found = find(cars, name);
	if (found != NOTFOUND)
	{
		double price = cars[found].getPrice();
		balance += price;

		cars[found] = cars[cars.size() - 1];
		cars.pop_back();

		cout << "Car sold successfully.";
	}
	else
	{
		cout << "CAR NOT FOUND";
	}
}

void paintCar(vector<Car> &cars, string name)
{
	int found = find(cars, name);
	string newcolor;

	if (found != NOTFOUND)
	{
		cout << "What color would you like to paint " << name << "?: ";
		cin >> newcolor;
		cars[found].paint(newcolor);
		cout << "Car successfully painted " << newcolor << ". $1000 added to the price of " << name << ".";
	}
	else
	{
		cout << "CAR NOT FOUND";
	}
}

void loadCars(vector<Car> &cars, double &balance)
{
	string file;
	double addbal;

	cout << "File Name: ";
	cin >> file;
	ifstream input;
	input.open(file.c_str());

	input >> addbal;
	balance += addbal;

	while (!input.eof())
	{
		string name, color;
		double price;

		input >> name >> color >> price;

		if (!input.fail())
		{
			Car newcar = Car(name, color, price);
			cars.push_back(newcar);
		}
	}

	cout << "Inventory updated successfully.";
	input.close();
}

void saveCars(vector<Car> cars, double balance)
{
	string file;

	cout << "File Name: ";
	cin >> file;
	
	ofstream outfile(file);

	outfile << balance << "\n";

	for (int i = 0; i < cars.size(); i++)
	{
		outfile << cars[i].getName() << " " << cars[i].getColor() << " " << cars[i].getPrice() << "\n";
	}

	cout << "Inventory exported successfully.";
	outfile.close();
}

int main()
{
	vector<Car> cars;
	int option;
	string name, color;
	double price, balance;

	balance = 10000;

	do
	{
		cout << "MENU:\n";
		cout << "   1 - Show Current Inventory\n";
		cout << "   2 - Show Current Balance\n";
		cout << "   3 - Buy a Car\n";
		cout << "   4 - Sell a Car\n";
		cout << "   5 - Paint a Car\n";
		cout << "   6 - Load File\n";
		cout << "   7 - Save File\n";
		cout << "   8 - Quit\n";
		cout << "Select an option: ";

		cin >> option;
		
		int found;
		
		switch (option)
		{
		case 1: //SHOW CURRENT INVENTORY
			print(cars);
			cout << "\n\n";
			break;

		case 2: //SHOW CURRENT BALANCE
			cout << "$" << setprecision(2) << fixed << balance;
			cout << "\n\n";
			break;

		case 3: //BUY A CAR
			cout << "Name: ";
			cin >> name;
			cout << "Color: ";
			cin >> color;
			cout << "Price: $";
			cin >> price;

			found = find(cars, name);

			if ((price <= balance) && (found == NOTFOUND))
			{
				buyCar(cars, name, color, price, balance);
			}
			else
			{
				cout << "INSUFFICIENT FUNDS OR CAR ALREADY EXISTS";
			}
			cout << "\n\n";
			break;

		case 4: //SELL A CAR
			cout << "Name: ";
			cin >> name;
			sellCar(cars, name, balance);
			cout << "\n\n";
			break;

		case 5: //PAINT A CAR
			cout << "Name: ";
			cin >> name;
			paintCar(cars, name);
			cout << "\n\n";
			break;

		case 6: //LOAD FILE
			loadCars(cars, balance);
			cout << "\n\n";
			break;
		case 7: //SAVE FILE
			saveCars(cars, balance);
			cout << "\n\n";
			break;
		}
	} while (option != 8);

	system("pause");
	return 0;
}