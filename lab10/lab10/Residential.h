#pragma once
#include "Property.h"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class Residential :
	public Property
{
private:
	bool occupied;
public:
	Residential(string tag, bool rental, int value, bool occupied, string address);
	~Residential();
	virtual string toString();
	virtual double calcTax();
	virtual void reportTax();
};

