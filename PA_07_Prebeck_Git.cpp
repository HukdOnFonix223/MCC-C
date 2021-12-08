////////////////////////////////////////////////////////////////////////////////
// Author:      Blake Prebeck
// Class:       ITCS 2530
// Assignment:  Week 07 - Programming Assignment #7
// Professor:   Koss
// Due Date:    12/12/21
////////////////////////////////////////////////////////////////////////////////
// Description:	Program calculates a bowling league's average bowling scores.
//				Outputs bowlers names, scores and averages.		
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////
//Headers
////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;


////////////////////////////////////////
//Global Constants
////////////////////////////////////////
string FILE_NAME = "BowlingScores.txt";
const int ARRAY_SIZE = 10;
const int ARRAY_COL = 5;


////////////////////////////////////////
//Structures
////////////////////////////////////////
struct bowlerStructure
{
	string name = " ";
	int scores[ARRAY_COL] = { 0 };
	int average = 0;
};


////////////////////////////////////////
//Global Variables
////////////////////////////////////////
ifstream inFile;
bowlerStructure bowlers[ARRAY_SIZE];


////////////////////////////////////////
//Prototypes
////////////////////////////////////////
void BannerText();
bool GetBowlingData(bowlerStructure bowlers[], string FILE_NAME, int ARRAY_SIZE, int ARRAY_COL);
void GetAverageScore(bowlerStructure bowlers[], int ARRAY_SIZE, int ARRAY_COL);
void PrettyPrintResults(bowlerStructure bowlers[], int ARRAY_SIZE, int ARRAY_COL);


////////////////////////////////////////
//Main Function
////////////////////////////////////////
int main()
{
	//Display Welcome Banner
	BannerText();

	//Open File & Retrieve Bowler Data and store in Arrays
	if (GetBowlingData(bowlers, FILE_NAME, ARRAY_SIZE, ARRAY_COL) != false)
	{
		//Calculate Averages and store in Array
		GetAverageScore(bowlers, ARRAY_SIZE, ARRAY_COL);

		//Print Bowler Name, Scores and Averages
		PrettyPrintResults(bowlers, ARRAY_SIZE, ARRAY_COL);
	}
	return 0;
}


////////////////////////////////////////
//Function Definitions
////////////////////////////////////////

//Function to display welcome banner
void BannerText()
{
	cout << setfill('*') << setw(60) << "*" << endl;
	cout << setw(47) << "Welcome To My Bowling Score Program" << setw(13) << '*' << endl;
	cout << setw(60) << "*" << endl;
	cout << endl;
}


//Function to read data from file and input into arrays
bool GetBowlingData(bowlerStructure bowlers[], string FILE_NAME, int ARRAY_SIZE, int ARRAY_COL)
{
	//Open File
	inFile.open(FILE_NAME);

	//Check if file is opened
	if (!inFile)
	{
		cout << "Cannot open file:  " << FILE_NAME << endl;
		system("pause");
		return false;
	}
	else
		cout << FILE_NAME << " has successfully opened." << endl;

	//Input data into arrays
	for (int row = 0; row < ARRAY_SIZE; row++)
	{
		inFile >> bowlers[row].name;

		for (int col = 0; col < ARRAY_COL; col++)
		{
			inFile >> bowlers[row].scores[col];
		}
	}

	return true;
}


//Function to average bowler's scores
void GetAverageScore(bowlerStructure bowlers[], int ARRAY_SIZE, int ARRAY_COL)
{
	for (int row = 0; row < ARRAY_SIZE; row++)
	{
		int sum = 0;

		//Calculate sum for each row
		for (int col = 0; col < ARRAY_COL; col++)
		{
			sum = sum + bowlers[row].scores[col];
		}

		//Calculate average for each row
		bowlers[row].average = sum / ARRAY_COL;
	}
}


//Function to output bowler names, scores and averages
void PrettyPrintResults(bowlerStructure bowlers[], int ARRAY_SIZE, int ARRAY_COL)
{
	//Output Column Names
	cout << setfill(' ') << endl;
	cout << setw(15) << left << "NAME" << setw(25) << "SCORES" << setw(20) << "AVERAGE" << endl;

	//Output bowler's name
	for (int row = 0; row < ARRAY_SIZE; row++)
	{
		cout << setw(15) << left << bowlers[row].name;

		//Output bowler's scores
		for (int col = 0; col < ARRAY_COL; col++)
		{
			cout << setw(4) << left << bowlers[row].scores[col] << " ";
		}

		//Output bowler's averages
		cout << setw(4) << left << bowlers[row].average;
		cout << endl;
	}
}