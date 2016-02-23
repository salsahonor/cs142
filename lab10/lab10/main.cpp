#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "Commercial.h"
#include "Property.h"
#include "Residential.h"
using namespace std;

int main()
{
	vector<Property*> allProperties;
	string file;

	cout << "File Name: ";
	cin >> file;

	ifstream input;
	input.open(file.c_str());

	//CONTINUES UNTIL END OF DOCUMENT
	while (!input.eof())
	{
		string tag, rental, occupied, discount, address;
		bool brental, bdiscount, boccupied;
		int value;
		double rate;

		string line;
		getline(input, line);
		stringstream ss;
		ss << line;

		if (ss >> tag) //can't just use ss.fail(), this works instead
		{
			//CHECKS FOR VALID INPUT FOR EACH PIECE OF RESIDENTIAL PROPERTY INFO
			if (tag == "Residential")
			{
				if (ss >> rental)
				{
					//boolean values default to 1 if value is >1, so read in as string
					if (rental == "1" || rental == "0")
					{
						//change to boolean
						if (rental == "1")
						{ brental = true; }
						else
						{ brental = false; }

						if (ss >> value)
						{
							if (value >= 0)
							{
								if (ss >> occupied)
								{
									if (occupied == "1" || occupied == "0")
									{
										if (occupied == "1")
										{ boccupied = true; }
										else
										{ boccupied = false; }

										getline(ss, address);
										Property* res = new Residential(tag, brental, value, boccupied, address);
										allProperties.push_back(res);
									}
									else
									{ cout << "Ignoring bad RESIDENTIAL in input file: " << ss.str() << endl; }
								}
							}
						}
					}
					else
					{ cout << "Ignoring bad RESIDENTIAL in input file: " << ss.str() << endl; }
				}
				//IF ANY OF THE ABOVE FAILED:
				if (ss.fail())
				{ cout << "Ignoring bad RESIDENTIAL in input file: " << line << endl; }
			}

			//CHECKS FOR VALID INPUT FOR EACH PIECE OF COMMERCIAL PROPERTY INFO
			else if (tag == "Commercial")
			{
				if (ss >> rental)
				{
					//boolean values default to 1 if value is >1, so read in as string
					if (rental == "1" || rental == "0")
					{
						//change to boolean
						if (rental == "1")
						{ brental = true; }
						else
						{ brental = false; }

						if (ss >> value)
						{
							if (value >= 0)
							{
								if (ss >> discount)
								{
									//boolean values default to 1 if value is >1, so read in as string
									if (discount == "1" || discount == "0")
									{
										//change to boolean
										if (discount == "1")
										{ bdiscount = true; }
										else
										{ bdiscount = false; }

										if (ss >> rate)
										{
											if (rate >= 0 && rate <= 1)
											{
												getline(ss, address);
												Property* com = new Commercial(tag, brental, value, bdiscount, rate, address);
												allProperties.push_back(com);
											}
										}
									}
									else
									{ cout << "Ignoring bad COMMERCIAL in input file: " << ss.str() << endl; }
								}
							}
						}
					}
					else
					{ cout << "Ignoring bad COMMERCIAL in input file: " << ss.str() << endl; }
				}
				//IF ANY OF THE ABOVE FAILED:
				if (ss.fail())
				{ cout << "Ignoring bad COMMERCIAL in input file: " << line << endl; }
			}
			//"TAG" READ ERROR
			else
			{ cout << "Ignoring unknown property type: " << line << endl; }
		}
	}

	//PRINT VALID PROPERTIES
	cout << "\nAll valid properties:\n";
	for (int j = 0; j < allProperties.size(); j++)
	{
		cout << allProperties[j]->toString() << endl;
	}

	//PRINT TAX REPORT
	cout << "\nNOW PRINTING TAX REPORT:\n";
	for (int k = 0; k < allProperties.size(); k++)
	{
		allProperties[k]->reportTax();
	}

	system("pause");
	return 0;
}