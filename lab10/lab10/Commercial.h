#pragma once
#include "Property.h"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class Commercial : public Property
{
private:
	bool discount;
	double rate;
public:
	Commercial(string tag, bool rental, int value, bool discount, double rate, string address);
	~Commercial();
	virtual string toString();
	virtual double calcTax();
	virtual void reportTax();
};

