#include "Residential.h"


Residential::Residential(string tag, bool rental, int value, bool occupied, string address) 
:Property(tag, rental, value, address)
{
	this->occupied = occupied;
	double owed;
}


Residential::~Residential()
{
}

//PRINTS INFORMATION FOR RESIDENTIAL PROPTERY
string Residential::toString()
{
	stringstream ss;
	string occustring;

	if (occupied == true)
	{ occustring = "OCCUPIED"; }
	else
	{ occustring = "NOT OCCUPIED"; }

	ss << Property::toString();
	ss << " " << occustring;

	return ss.str();
}

//CALCULATES TAX OWED ON RESIDENTITAL PROPERTY
double Residential::calcTax()
{
	double rate, owed;

	if (occupied == true)
	{ rate = .006; }
	else
	{ rate = .009; }

	owed = (value*rate);

	return owed;
}

//REPORTS THE TAX OWED FOR RESIDENTIAL PROPERTY
void Residential::reportTax()
{
	double owed = calcTax();
	cout << "Taxes due for the property at: " << address << endl;
	cout << "   Property ID: " << id << endl;
	cout << "   This property has an estimated value of: $" << value << endl;
	cout << "   Taxes due on this property are: $" << owed << endl << endl;
}