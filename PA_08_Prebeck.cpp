////////////////////////////////////////////////////////////////////////////////
// Author:      Blake Prebeck
// Class:       ITCS 2530
// Assignment:  Week 08 - Programming Assignment #8
// Professor:   Koss
// Due Date:    12/18/21
////////////////////////////////////////////////////////////////////////////////
// Description:	Program calculates a bowling league's average bowling scores.
//				Outputs bowlers names, scores and averages.  
//				Utilizes arrays, structures and classes.		
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
const int ARRAY_SIZE = 10;
const int ARRAY_COL = 4;


////////////////////////////////////////
//Classes
////////////////////////////////////////
class BowlingClass 
{
	public:
		//Constructor
		BowlingClass(string y)
		{
			setFileName(y);
		};


		////////////////////
		//Public Functions
		////////////////////
		
		//Function to display welcome banner
		void BannerText()
		{
			cout << setfill('*') << setw(60) << "*" << endl;
			cout << setw(47) << "Welcome To My Bowling Score Program" << setw(13) << '*' << endl;
			cout << setw(60) << "*" << endl;
			cout << endl;
		}


		//Function to set name of file
		void setFileName(string x)
		{
			sFileName = x;
		}


		//Function to read data from file and input into arrays
		bool GetBowlingData()
		{
			//Open File
			inFile.open(sFileName);

			//Check if file is opened
			if (!inFile)
			{
				cout << "Cannot open file:  " << sFileName << endl;
				system("pause");
				return false;
			}
			else
				cout << sFileName << " has successfully opened." << endl;

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
		void GetAverageScore()
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
		void PrettyPrintResults()
		{
			//Output Column Names
			cout << setfill(' ') << endl;
			cout << setw(15) << left << "NAME" << setw(20) << "SCORES" << setw(20) << "AVERAGE" << endl;

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


	private:
		//Private Variables
		string sFileName;
		ifstream inFile;

		//Private Structures
		struct bowlerStructure
		{
			string name = " ";
			int scores[ARRAY_COL] = { 0 };
			int average = 0;
		};	bowlerStructure bowlers[ARRAY_SIZE];
};


////////////////////////////////////////
//Main Function
////////////////////////////////////////
int main()
{
	//Create Class Object and Call Constructor
	BowlingClass BC("BowlingScores.txt");

	//Display Welcome Banner
	BC.BannerText();

	//Open File & Retrieve Bowler Data and Store in Arrays
	if (BC.GetBowlingData() != false)
	{
		//Calculate Averages and Store in Array
		BC.GetAverageScore();

		//Print Bowler Name, Scores and Averages
		BC.PrettyPrintResults();
	}

	return 0;
}