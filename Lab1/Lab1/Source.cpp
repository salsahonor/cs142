// The purpose of this program is to display 7 items of BYU trivia under "Questions" and "Answers"
// columns primarily using escape sequences.
#include <iostream>
using namespace std;

int main()
{
	cout << "\t" << "\t" << "\t" << "\t" << "Basic BYU Trivia" << "\n"
		<< "\n" << "\t" << "\t" << "Questions" << "\t" << "\t" << "\t" << "\t" << "Answers" << "\n"
		<< "\n" << "What was the original name of BYU?" << "\t" << "\t" << "Brigham Young Academy"
		<< "\n" << "When was BYA established?" << "\t" << "\t" << "\t" << "1875"
		<< "\n" << "Who was the first \"permanent\" principal of BYA?" << "\t" << "Karl Maeser"
		<< "\n" << "When did BYA become BYU?" << "\t" << "\t" << "\t" << "1903"
		<< "\n" << "To what sports conference do we belong?" << "\t" << "\t" << "Independent (Football)"
		<< "\n" << "When did BYU win the national football title?" << "\t" << "1984"
		<< "\n" << "Who won the Heisman Trophy in 1990?" << "\t" << "\t" << "Ty Detmer";
	system("pause");
	return 0;
}