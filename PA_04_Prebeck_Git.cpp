//************************************************************
// Author:      Blake Prebeck
// Class:       ITCS 2530
// Assignment:  Week 04 - Programming Assignment #4
// Professor:   Koss
// Due Date:    11/14/21
//************************************************************

// Description: This program counts the number of vowels in a file.

// Requirements:
// 1) User must specify the name of the file(from the command line) to analyze when the program is run.  If not an error should be generated.
// 2) Use constants where appropriate.
// 3) Use I/O(stream) manipulators to format the output so that it is identical to the example below.
// 4) Pass the name of the file to read in from the command line.


	//Headers
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


int main(int argc, char* argv[])
{
	// The executable name and at least one argument?
	if (argc < 2)
	{
		std::cout << "Error with input agrs.." << std::endl;
		return 1;
	}

	// For debugging purposes only
	for (int i = 0; i < argc; i++)
	{
		std::cout << i << ":" << argv[i] << std::endl;
	}

	//Check if file is opened
	std::ifstream inFile;
	inFile.open(argv[1]);
	if (!inFile)
	{
		std::cout << "Error with file name.." << std::endl;
		return 1;
	}

	//Variables
	char c = ' ';

	int vowelA = 0;
	int vowelE = 0;
	int vowelI = 0;
	int vowelO = 0;
	int vowelU = 0;

	int vowelTotal = 0;

	int letterB = 0;
	int letterC = 0;
	int letterD = 0;

	//Banner text
	cout << setfill('*') << setw(60) << "*" << endl;
	cout << setw(47) << "Welcome to my Letter Count Program" << setw(13) << '*' << endl;
	cout << setw(60) << "*" << endl;
	cout << endl;

	//Output the name of the first command line argument
	cout << "Analyzing file " << "'" << argv[0] << "'..." << endl << endl;

	//Loop to count vowels
	while (!inFile.eof() && inFile >> c)
	{
		if (c == 'A' || c == 'a')
		{
			vowelA++;
			vowelTotal++;
		}
		else if (c == 'E' || c == 'e')
		{
			vowelE++;
			vowelTotal++;
		}
		else if (c == 'I' || c == 'i')
		{
			vowelI++;
			vowelTotal++;
		}
		else if (c == 'O' || c == 'o')
		{
			vowelO++;
			vowelTotal++;
		}
		else if (c == 'U' || c == 'u')
		{
			vowelU++;
			vowelTotal++;
		}
		else if (c == 'B' || c == 'b')
		{
			letterB++;
		}
		else if (c == 'C' || c == 'c')
		{
			letterC++;
		}
		else if (c == 'D' || c == 'd')
		{
			letterD++;
		}
		else
			continue;
	}

	//Set fill
	cout << setfill('.');

	//Output vowel count
	cout << "The number of A's:  " << setw(40) << "." << vowelA << endl;
	cout << "The number of E's:  " << setw(40) << "." << vowelE << endl;
	cout << "The number of I's:  " << setw(40) << "." << vowelI << endl;
	cout << "The number of O's:  " << setw(40) << "." << vowelO << endl;
	cout << "The number of U's:  " << setw(40) << "." << vowelU << endl;
	cout << "The vowel count is: " << setw(40) << "." << vowelTotal << endl;
	cout << "The number of B's:  " << setw(40) << "." << letterB << endl;
	cout << "The number of C's:  " << setw(40) << "." << letterC << endl;
	cout << "The number of D's:  " << setw(40) << "." << letterD << endl;

	//Close file
	inFile.close();

	system("pause");
	return 0;
}