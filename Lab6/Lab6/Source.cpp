#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int DIMENSION = 20;

void print(double hotPlate[DIMENSION][DIMENSION])
{
	for (int row = 0; row < DIMENSION; row++)
	{
		for (int col = 0; col < DIMENSION; col++)
		{
			cout << hotPlate[row][col] << " ";
		}
		cout << endl << endl;
	}
}

void initializeHotPlate(double hotPlate[DIMENSION][DIMENSION])
{
	//INITIALIZE hotPlate
	for (int row = 0; row < DIMENSION; row++)
	{
		for (int col = 0; col < DIMENSION; col++)
		{
			hotPlate[row][col] = 0; //initializes the location (row, col) with 0
		}
	}

	//PLACE THE HUNDREDS
	int hundredsRow1 = 0, hundredsRow2 = 19, start100s = 1, end100s = 18, hundred = 100;
	for (int pos = start100s; pos <= end100s; pos++)
	{
		hotPlate[hundredsRow1][pos] = hundred; //fills cells (0, 1) thru (0, 19) with 100
		hotPlate[hundredsRow2][pos] = hundred; //fills cells (19, 1) thru (19, 18) with 100
	}
}

void commenceHotPlate(double hotPlate[DIMENSION][DIMENSION], int iteration)
{
	double dummyPlate[DIMENSION][DIMENSION];
	double num1, num2, num3, num4, avg;
	const double maxChange = .1;
	const int START = 1, FIN = 18, SM_DIMENSION = 18; //the size of the changing array is 18x18 (not 20x20)
	int count = 0;

	//FIND AND PLACE AVG VALUES IN dummyPlate
	for (int row = START; row <= FIN; row++)
	{
		for (int col = START; col <= FIN; col++)
		{
			num1 = hotPlate[row][col-1]; //cell to the left
			num2 = hotPlate[row+1][col]; //cell above
			num3 = hotPlate[row][col+1]; //cell to the right
			num4 = hotPlate[row-1][col]; //cell below
			avg = (num1 + num2 + num3 + num4) / 4; //take the average of the four cells
			
			dummyPlate[row][col] = avg; //assign the average to the cell in dummyHotPlate

			if (abs((dummyPlate[row][col] - hotPlate[row][col])) <= maxChange)
			{
				count++;
			}
		}	
	}
	iteration++;
	
	//GIVE hotPlate THE AVG VALUES
	for (int row = START; row <= FIN; row++)
	{
		for (int col = START; col <= FIN; col++)
		{
			hotPlate[row][col] = dummyPlate[row][col];
		}
	}

	//PRINT THE FIRST ITERATION
	if (iteration == 1)
	{
		print(hotPlate);
	}

	//CONTINUE UNTIL CHANGE < .1 IN EVERY CELL
	if (count < (SM_DIMENSION*SM_DIMENSION))
	{
		commenceHotPlate(hotPlate, iteration);
	}
}

void exportHotPlate(double hotPlate[DIMENSION][DIMENSION])
{
	ofstream outFile("lab6output.csv");
	
	for (int row = 0; row < DIMENSION; row++)
	{
		for (int col = 0; col < DIMENSION; col++)
		{
			outFile << hotPlate[row][col] << ",";
		}
		outFile << endl;
	}
	outFile.close();
}

int main()
{
	double hotPlate[DIMENSION][DIMENSION];

	initializeHotPlate(hotPlate);

	print(hotPlate);

	int iteration = 0;
	commenceHotPlate(hotPlate, iteration);

	exportHotPlate(hotPlate);

	system("pause");
	return 0;
}