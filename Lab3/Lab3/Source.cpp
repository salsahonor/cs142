/*
TEST CASES:
*==========================================================================================================*
||                          PART 1 (INPUT)                               ||        PART 2 (OUTPUT)        ||
||=======================================================================||===============================||
||MILES|GAS PRICE|COST HYB|HYB MPG|RESALE HYB|COST NON|NON MPG|RESALE NON||HYB GAL|HYB TOT|NON GAL|NON TOT||
||=====|=========|========|=======|==========|========|=======|==========||=======|=======|=======|=======||
||10000|     2.50|   32000|     75|     24000|   15000|     25|     11250||666.667|9666.67|   2000|   5750||
||=====|=========|========|=======|==========|========|=======|==========||=======|=======|=======|=======||
|| 8000|     4.25|   29000|     80|     25000|   13000|     30|     10000||    500|   6125|1333.33|9666.67||
||=====|=========|========|=======|==========|========|=======|==========||=======|=======|=======|=======||
||  975|     3.39|   30000|    100|     26000|   18000|     32|     15000||  48.75|4165.26|152.344|3516.45||
*==========================================================================================================*
*/

#include <iostream>
#include <string>
using namespace std;

//this function checks if the input is pos/neg. If neg, it presents an error and presents the last prompt
double num;
string prompt;
double check_num(double num, string prompt)
{
	if (num <= 0)
	{
		cout << "Only positive #'s are valid" << "\n" << prompt;
		cin >> num;
		check_num(num, prompt);
		return num;
	}
	return num;
}

int main()
{
	/* PART 1
	This part prompts the user for several inputs related to their car, verifying that the submitted
	numbers are all positive. */
	string miles_p = "Estimated miles driven per year: ", gas_p = "Estimated price of a gallon of gas during the 5 years of ownership: $";
	string cost_hyb_p = "Initial cost of a hybrid car: $", efficiency_hyb_p = "Efficiency of the hybrid car in MPG: ";
	string resale_hyb_p = "Estimated resale value for a hybrid after 5 years: $", cost_non_p = "Initial cost of a non-hybrid car: $";
	string efficiency_non_p = "Efficiency of the non-hybrid car in MPG: ", resale_non_p = "The estimated resale value for a non-hybrid car after 5 years: $";
	int miles, cost_hybrid, resale_hybrid, cost_non, resale_non;
	double gas_price, efficiency_hybrid, efficiency_non;

	cout << miles_p;
	cin >> miles;
	miles = check_num(miles, miles_p);

	cout << gas_p;
	cin >> gas_price;
	gas_price = check_num(gas_price, gas_p);

	cout << "\n" << cost_hyb_p;
	cin >> cost_hybrid;
	cost_hybrid = check_num(cost_hybrid, cost_hyb_p);

	cout << efficiency_hyb_p;
	cin >> efficiency_hybrid;
	efficiency_hybrid = check_num(efficiency_hybrid, efficiency_hyb_p);

	cout << resale_hyb_p;
	cin >> resale_hybrid;
	resale_hybrid = check_num(resale_hybrid, resale_hyb_p);

	cout << "\n" << cost_non_p;
	cin >> cost_non;
	cost_non = check_num(cost_non, cost_non_p);

	cout << efficiency_non_p;
	cin >> efficiency_non;
	efficiency_non = check_num(efficiency_non, efficiency_non_p);

	cout << resale_non_p;
	cin >> resale_non;
	resale_non = check_num(resale_non, resale_non_p);

	/* PART 2
	This part of the program will output the total cost of owning both cars for  years
	and the total gallons of fuel consumed. */

	double gal_hyb, gal_non, total_hyb, total_non;
	int years = 5;
	string priority;

	gal_hyb = (miles / efficiency_hybrid) * years;
	total_hyb = (gal_hyb*gas_price) + (cost_hybrid - resale_hybrid);
	gal_non = (miles / efficiency_non) * years;
	total_non = (gal_non*gas_price) + (cost_non - resale_non);

	cout << "\nIs your criterion Gas or Total cost?: ";
	cin >> priority;

	if((priority == "Gas" && gal_hyb < gal_non) || (priority == "Total" && total_hyb < total_non))
	{
		cout << "\n\nHybrid Car\n" << "Total gallons of gas: " << gal_hyb << "\nTotal cost of owning: $" << total_hyb;
		cout << "\n\nNon-Hybrid Car\n" << "Total gallons of gas: " << gal_non << "\nTotal cost of owning: $" << total_non;
	}
	else if ((priority == "Gas" && gal_non < gal_hyb) || (priority == "Total" && total_non < total_hyb))
	{
		cout << "\n\nNon-Hybrid Car\n" << "Total gallons of gas: " << gal_non << "\nTotal cost of owning: $" << total_non;
		cout << "\n\nHybrid Car\n" << "Total gallons of gas: " << gal_hyb << "\nTotal cost of owning: $" << total_hyb;
	}

	system("pause");
	return 0;
}