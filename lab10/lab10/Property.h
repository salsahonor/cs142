#pragma once
#include <string>
#include <sstream>
using namespace std;

class Property
{
public:
	//variables have to be public to be accessed in child functions
	string tag, address;
	bool rental;
	int value, id;

	Property(string tag, bool rental, int value, string address);
	~Property();

	virtual string toString();
	virtual double calcTax() = 0;
	virtual void reportTax() = 0;

	static int nextid;
};

