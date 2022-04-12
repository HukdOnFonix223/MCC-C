////////////////////////////////////////////////////////////////////////////////
// Authors:     Group #3 - Blake Prebeck, Jacob Zabel, Sophia Nava Gavaldon
// Class:       ITCS 2530
// Assignment:  Final Project
// Professor:   Koss
// Due Date:    12/18/21
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
const int PEOPLE = 10;
const int MAX_CHAR = 30;
ifstream inFile;
ofstream outFile;

////////////////////////////////////////
//Global Structures
////////////////////////////////////////
struct santaStruct
{
	string name;
	char idea[MAX_CHAR];
};
santaStruct santa[PEOPLE];


////////////////////////////////////////
//Prototypes
////////////////////////////////////////

//Jacob's
// declare functions
bool GetSantaInfo(santaStruct santa[]);
void GetGiftIdea(santaStruct santa[]);


//Blake's
void BannerText();
char MenuSwitch(char& menuSelection, santaStruct santa[], string secretSantas[PEOPLE], int PEOPLE, int MAX_CHAR);
void PairSecretSantas(santaStruct santa[], string secretSantas[PEOPLE], int PEOPLE);
void SecretSantaConsole(santaStruct santa[], string secretSantas[PEOPLE], int PEOPLE, int MAX_CHAR);    //Blake & Sophia

//Sophia's
void SecretSantaFile(santaStruct santa[], string secretSantas[PEOPLE], int PEOPLE, int MAX_CHAR);

////////////////////////////////////////
//Main - Blake, Jacob, Sophia
////////////////////////////////////////
int main()
{
	//Variables
	char menuSelection = ' ';

	//Arrays
	string secretSantas[PEOPLE];

	//Functions
	while (menuSelection != 'Q' && menuSelection != 'q')
	{
		BannerText();
		MenuSwitch(menuSelection, santa, secretSantas, PEOPLE, MAX_CHAR);
	}

	return 0;
}


////////////////////////////////////////
// Functions
////////////////////////////////////////

//Function to display welcome banner - Blake
void BannerText()
{
	//Welcome Banner
	cout << setfill('*') << setw(60) << "*" << endl;
	cout << setw(47) << "Welcome To Our Secret Santa Program!" << setw(13) << '*' << endl;
	cout << setw(60) << "*" << endl;
	cout << endl;

	//Menu Text
	cout << "Ho! Ho! Ho! Merry Christmas!" << endl << endl;
	cout << "Please follow the instructions below to create your Secret Santa roster!" << endl << endl;
	cout << "To show program Usage, enter: 'U'" << endl;
	cout << "To input Gifts, enter: 'G'" << endl;
	cout << "To output Secret Santa roster, enter: 'S'" << endl;
	cout << "To save the Secret Santa roster to a file, enter: 'F'" << endl;
	cout << "To quit the program, enter: 'Q'" << endl;
	cout << endl;
}


//Function for Menu Switch - Blake
char MenuSwitch(char& menuSelection, santaStruct santa[], string secretSantas[PEOPLE], int PEOPLE, int MAX_CHAR)
{
	cout << "Please enter selection:  ";
	cin >> menuSelection;
	switch (menuSelection)
	{
		//Call Output to [F]ile Function()
	case 'F':
	case 'f':
		system("cls");
		SecretSantaFile(santa, secretSantas, PEOPLE, MAX_CHAR);
		system("pause");
		system("cls");
		break;

		//Call [G]ift Entry Function()
	case 'G':
	case 'g':
		system("cls");
		GetSantaInfo(santa);
		GetGiftIdea(santa);
		PairSecretSantas(santa, secretSantas, PEOPLE);
		system("cls");
		break;

		//[R]eset Console
	case 'R':
	case 'r':
		system("cls");
		break;

		//Output [S]ecret Santa Roster
	case 'S':
	case 's':
		system("cls");
		SecretSantaConsole(santa, secretSantas, PEOPLE, MAX_CHAR);
		cout << endl << "Merry Christmas!" << endl;
		system("pause");
		system("cls");
		break;

		//[Q]uit Program
	case 'Q':
	case 'q':
		system("cls");
		cout << endl << "Merry Christmas!" << endl;
		return menuSelection;
		break;

		//Default Reset Console
	default:
		system("cls");
		break;
	}
}


//Function to reverse arrays for Secret Santas - Blake
void PairSecretSantas(santaStruct santa[], string secretSantas[PEOPLE], int PEOPLE)
{
	for (int i = 0; i < PEOPLE; i++)
	{
		secretSantas[PEOPLE - (i + 1)] = santa[i].name;
	}
}


//Function to output pairs and gifts to console - Blake & Sophia
void SecretSantaConsole(santaStruct santa[], string secretSantas[PEOPLE], int PEOPLE, int MAX_CHAR)
{
	//Column headings
	cout << setfill(' ') << endl;
	cout << setw(MAX_CHAR) << left << "RECIPIENT" << setw(MAX_CHAR) << "SECRET SANTA" << setw(MAX_CHAR) << "GIFT" << endl;

	//Output for Recipient's name
	for (int i = 0; i < PEOPLE; i++)
	{
		cout << setw(MAX_CHAR) << left << santa[i].name;

		//Output for Secret Santa's name
		cout << setw(MAX_CHAR) << left << secretSantas[i];

		//Output for Gift
		for (int col = 0; col < MAX_CHAR; col++)
		{
			cout << santa[i].idea[col];
		}
		cout << endl;
	}
}


//Function to open file name and store people into arrays - Jacob
bool GetSantaInfo(santaStruct santa[])
{

	string FILE_NAME;//to store file name
	cout << "Please enter the file where the names of the people are stored (Include the file extention): "; cin >> FILE_NAME;

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
	for (int row = 0; row < PEOPLE; row++)
	{
		inFile >> santa[row].name;
	}

	return true;
}

//Function to enter gifts into array - Jacob
void GetGiftIdea(santaStruct santa[])
{
	int i = 0;
	while (i < PEOPLE)
	{
		cout << "What is the gift " << santa[i].name << " wants: "; cin >> santa[i].idea;
		i++;
	}
}


//Function to output pairs and gifts to file - Sophia
void SecretSantaFile(santaStruct santa[], string secretSantas[PEOPLE], int PEOPLE, int MAX_CHAR)
{

	//Open output file
	outFile.open("Roster.txt");

	//Column headings
	outFile << setfill(' ') << endl;
	outFile << setw(MAX_CHAR) << left << "RECIPIENT" << setw(MAX_CHAR) << "SECRET SANTA" << setw(MAX_CHAR) << "GIFT" << endl;

	//Output for Recipient's name
	for (int i = 0; i < PEOPLE; i++)
	{
		outFile << setw(MAX_CHAR) << left << santa[i].name;

		//Output for Secret Santa's name
		outFile << setw(MAX_CHAR) << left << secretSantas[i];

		//Output for Gift
		for (int col = 0; col < MAX_CHAR; col++)
		{
			outFile << santa[i].idea[col];
		}
		outFile << endl;
	}
	cout << "Output to file is successful." << endl;
}
