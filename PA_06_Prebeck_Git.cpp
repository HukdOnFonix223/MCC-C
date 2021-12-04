//************************************************************
// Author:      Blake Prebeck
// Class:       ITCS 2530
// Assignment:  Week 06 - Programming Assignment #6
// Professor:   Koss
// Due Date:    12/05/21
//************************************************************

// Description:	Program calculates a bowling league's average bowling scores.
//				Outputs bowlers names, scores and averages.		


//Headers
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;


//Global Constants
string FILE_NAME = "BowlingScores.txt";
const int ARRAY_SIZE = 10;
const int ARRAY_COL = 5;

//Global Variables
ifstream inFile;


//Prototypes
void BannerText();
void GetBowlingData(string FILE_NAME, string bowlerName[], int bowlerScore[][ARRAY_COL], int ARRAY_SIZE, int ARRAY_COL);
void GetAverageScore(string bowlerName[], int bowlerScore[][ARRAY_COL], double bowlerAvg[], int ARRAY_SIZE, int ARRAY_COL);
void PrettyPrintResults(string bowlerName[], int bowlerScore[][ARRAY_COL], double bowlerAvg[], int ARRAY_SIZE, int ARRAY_COL);

//Main Function
int main()
{
	//Variables
	string bowlerName[ARRAY_SIZE];
	int bowlerScore[ARRAY_SIZE][ARRAY_COL];
	double bowlerAvg[ARRAY_SIZE];

	//Display Welcome Banner
	BannerText();

	//Open File
	inFile.open(FILE_NAME);

	//Check if file is opened
	if (!inFile)
	{
		cout << "Cannot open file:  " << FILE_NAME << endl;
		system("pause");
		return 1;
	}
	else
		cout << FILE_NAME << " has successfully opened." << endl;

	//Open File & Retrieve Bowler Data and store in Arrays
	GetBowlingData(FILE_NAME, bowlerName, bowlerScore, ARRAY_SIZE, ARRAY_COL);

	//Calculate Averages and store in Array
	GetAverageScore(bowlerName, bowlerScore, bowlerAvg, ARRAY_SIZE, ARRAY_COL);

	//Print Bowler Name, Scores and Averages
	PrettyPrintResults(bowlerName, bowlerScore, bowlerAvg, ARRAY_SIZE, ARRAY_COL);

	return 0;
}

//Function to display welcome banner
void BannerText()
{
	cout << setfill('*') << setw(60) << "*" << endl;
	cout << setw(47) << "Welcome To My Bowling Score Program" << setw(13) << '*' << endl;
	cout << setw(60) << "*" << endl;
	cout << endl;
}

//Function to read data from file and input into arrays
void GetBowlingData(string FILE_NAME, string bowlerName[], int bowlerScore[][ARRAY_COL], int ARRAY_SIZE, int ARRAY_COL)
{


	//Input data into arrays
	for (int row = 0; row < ARRAY_SIZE; row++)
	{
		inFile >> bowlerName[row];

		for (int col = 0; col < ARRAY_COL; col++)
		{
			inFile >> bowlerScore[row][col];
		}
	}
}

//Function to average bowler's scores
void GetAverageScore(string bowlerName[], int bowlerScore[][ARRAY_COL], double bowlerAvg[], int ARRAY_SIZE, int ARRAY_COL)
{
	for (int row = 0; row < ARRAY_SIZE; row++)
	{
		int sum = 0;

		//Calculate sum for each row
		for (int col = 0; col < ARRAY_COL; col++)
		{
			sum = sum + bowlerScore[row][col];
		}

		//Calculate average for each row
		bowlerAvg[row] = sum / ARRAY_COL;
	}
}

//Function to output bowler names, scores and averages
void PrettyPrintResults(string bowlerName[], int bowlerScore[][ARRAY_COL], double bowlerAvg[], int ARRAY_SIZE, int ARRAY_COL)
{
	//Output Column Names
	cout << setfill(' ') << endl;
	cout << setw(15) << left << "NAME" << setw(25) << "SCORES" << setw(20) << "AVERAGE" << endl;

	//Output bowler's name
	for (int row = 0; row < ARRAY_SIZE; row++)
	{
		cout << setw(15) << left << bowlerName[row];

		//Output bowler's scores
		for (int col = 0; col < ARRAY_COL; col++)
		{
			cout << setw(4) << left << bowlerScore[row][col] << " ";
		}

		//Output bowler's averages
		cout << setw(4) << left << bowlerAvg[row];
		cout << endl;
	}
}
