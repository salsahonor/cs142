#include "Property.h"

//PROPERTY ID (counter)
int Property::nextid = 0;

Property::Property(string tag, bool rental, int value, string address)
{
	this->tag = tag;
	this->rental = rental;
	this->value = value;
	this->address = address;
	id = nextid;
	nextid++;
}


Property::~Property()
{
}

string Property::toString()
{
	stringstream ss;
	string rentstring;

	if (rental == true)
	{ rentstring = "RENTAL"; }
	else
	{ rentstring = "NOT RENTAL"; }

	ss << "PROPERTY ID: " << id;
	ss << " ADDRESS:" << address;
	ss << " " << rentstring;
	ss << " ESTIMATED VALUE: " << value;

	return ss.str();
}
