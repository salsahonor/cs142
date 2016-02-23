#include "Commercial.h"


Commercial::Commercial(string tag, bool rental, int value, bool discount, double rate, string address) 
:Property(tag, rental, value, address)
{
	this->discount = discount;
	this->rate = rate;
}


Commercial::~Commercial()
{
}

//PRINTS INFORMATION FOR COMMERCIAL PROPERTY
string Commercial::toString()
{
	stringstream ss;
	string discstring;

	if (discount == true)
	{ 
		discstring = "DISCOUNT:";
		ss << Property::toString();
		ss << " " << discstring;
		ss << " " << rate * 100 << "%";
	}
	else
	{ 
		discstring = "NO DISCOUNT";
		ss << Property::toString();
		ss << " " << discstring;
	}

	return ss.str();
}

//CALCULATES TAX OWED FOR COMMERCIAL PROPERTY
double Commercial::calcTax()
{
	double rentrate, owed;
	if (rental == true)
	{ rentrate = .012; }
	else
	{ rentrate = .01; }

	owed = value*rentrate;

	if (discount == true)
	{ owed = owed - (owed*rate); }

	return owed;
}

//REPORTS THE TAX OWED FOR COMMERCIAL PROPERTY
void Commercial::reportTax()
{
	double owed = calcTax();
	cout << "Taxes due for the property at: " << address << endl;
	cout << "   Property ID: " << id << endl;
	cout << "   This property has an estimated value of: $" << value << endl;
	cout << "   Taxes due on this property are: $" << owed << endl << endl;
}