/*
TEST CASES:
====================================================
|| GUESTS | LARGE | MED | SMALL | TIP % | TOTAL $ ||
||========|=======|=====|=======|=======|=========||
||       2|      0|    0|      2|     50|      $22||
||--------|-------|-----|-------|-------|---------||
||      15|      2|    0|      1|     20|      $44||
||--------|-------|-----|-------|-------|---------||
||      87|     12|    1|      0|     17|     $220||
====================================================
*/

#include <iostream>, <cmath>, <iomanip>
using namespace std;

int main()
{
	/*
	PART 1
	This part of the program will calculate how many pizzas of each size are needed to feed a group of the given size.
	*/

	int guests, large, med, small;
	const int PER_LARGE = 7, PER_MED = 3, PER_SMALL = 1;
	cout << "How many guests?: ";
	cin >> guests;

	large = guests / PER_LARGE; 
	med = (guests - (large * PER_LARGE)) / PER_MED; 
	small = (guests - (large * PER_LARGE) - (med * PER_MED));

	cout << "\nNumber of large pizzas: " << large << "\nNumber of medium pizzas: " << med << "\nNumber of small pizzas: " << small;

	/*
	PART 2
	This part of the program will calculate the total area of the pizzas, and the total area per guest
	*/

	const double PI = 3.14159, RADIUS_LARGE = 10, RADIUS_MED = 8, RADIUS_SMALL = 6;
	double area_total, area_per;

	area_total = large * PI * pow(RADIUS_LARGE, 2) + med * PI * pow(RADIUS_MED, 2) + small * PI * pow(RADIUS_SMALL, 2); //area of a circle = pi*r^2
	area_per = area_total / guests;
		cout << "\n\nTotal area of pizzas: " << area_total << " square inches."
		<< "\nArea of pizza per guest: " << area_per << " square inches.";
	
	/*
	PART 3
	This part of the program will calculate a tip and total price based on the given tip percentage.
	*/

	const double PRICE_LARGE = 14.68, PRICE_MED = 11.48, PRICE_SMALL = 7.28;
	double price_pizzas, tip;
	int price_total;

	cout << "\n\nWhat percent would you like to tip?: ";
	cin >> tip;

	price_pizzas = PRICE_LARGE * large + PRICE_MED * med + PRICE_SMALL * small;
	price_total = price_pizzas + price_pizzas * (tip / 100) + 0.5;

	cout << "\nBill total (to the nearest dollar): " << "$" << price_total;
	
	system("pause");
	return 0;
}