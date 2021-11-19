//************************************************************
// Author:      Blake Prebeck
// Class:       ITCS 2530
// Assignment:  Week 05 - Programming Assignment #5
// Professor:   Koss
// Due Date:    11/21/21
//************************************************************

// Description: This program simulates a surf shop selling surfboards.
// 1) Buy any surfboard in any size and in any quanity.
// 2) At any time show the total number of surfboards of each size sold.
// 3) At any time show the total money made.


//Headers
#include <iostream>
#include <iomanip>
using namespace std;


//Function Prototypes
void ShowUsage();
void MakePurchase(int& iTotalSmall, int& iTotalMedium, int& iTotalLarge, int& iTotalXXXS);
void DisplayPurchase(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, int iTotalXXXS);
void DisplayTotal(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, int iTotalXXXS);

void ShowBanner();
char InputFunction();
void MenuSwitch(char x, int& iTotalSmall, int& iTotalMedium, int& iTotalLarge, int& iTotalXXXS);

//Constants
const double SMALLBOARD = 175.00;
const double MEDIUMBOARD = 190.00;
const double LARGEBOARD = 200.00;
const double XXXSBOARD = 50.00;



int main()
{
    //Variables
    char input1 = ' ';
    int iTotalSmall = 0;
    int iTotalMedium = 0;
    int iTotalLarge = 0;
    int iTotalXXXS = 0;

    //Call ShowBanner()
    ShowBanner();

    //Call ShowUsage()
    ShowUsage();

    do
    {
        //Call InputFunction() and assign user input to variable
        input1 = InputFunction();

        //Call MenuSwitch()
        MenuSwitch(input1, iTotalSmall, iTotalMedium, iTotalLarge, iTotalXXXS);

    } while (input1 != 'Q' and input1 != 'q');

    system("pause");
    return 0;
}


//////////////////////////////
//Function Definitions
//////////////////////////////

//Show Banner Function
void ShowBanner()
{
    //Banner text
    cout << setfill('*') << setw(60) << "*" << endl;
    cout << setw(5) << "*" << " Welcome to my Johnny Utah's PointBreak Surf Shop " << setw(5) << "*" << endl;
    cout << setw(60) << "*" << endl;
    cout << endl;
}


//Show Usage Menu Function
void ShowUsage()
{
    //Menu Text
    cout << "To show program usage 'S'" << endl;
    cout << "To purchase a surfboard press 'P'" << endl;
    cout << "To display current purchases press 'C'" << endl;
    cout << "To display total amount due press 'T'" << endl;
    cout << "To quit the program press'Q'" << endl;
    cout << endl;
}


//User Input Function
char InputFunction()
{
    //Variables
    char menuSelection = ' ';

    cout << "Please enter selection:  ";
    cin >> menuSelection;
    cout << endl;
    return menuSelection;

}


//Make Purchase Function
void MakePurchase(int& iTotalSmall, int& iTotalMedium, int& iTotalLarge, int& iTotalXXXS)
{
    //Variables
    int num1 = 0;
    char char1 = ' ';

    cout << "Please enter the quantity and type (S=small, M=medium, L=large, X=XXXSmall) of surfboard you would like to purchase:";
    cin >> num1 >> char1;
    cout << endl;

    //Tracking Sales
    if (char1 == 'S' || char1 == 's')
        iTotalSmall = iTotalSmall + num1;
    else if (char1 == 'M' || char1 == 'm')
        iTotalMedium = iTotalMedium + num1;
    else if (char1 == 'L' || char1 == 'l')
        iTotalLarge = iTotalLarge + num1;
    else if (char1 == 'X' || char1 == 'x')
        iTotalXXXS = iTotalXXXS + num1;
    else
        cout << "Invalid entry" << endl;
}


//Display Purchase Function
void DisplayPurchase(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int iTotalXXXS)
{
    if (iTotalSmall > 0)
        cout << "The total number of small surfboards is " << iTotalSmall << endl;

    if (iTotalMedium > 0)
        cout << "The total number of medium surfboards is " << iTotalMedium << endl;

    if (iTotalLarge > 0)
        cout << "The total number of large surfboards is " << iTotalLarge << endl;

    if (iTotalXXXS > 0)
        cout << "The total number of XXXSmall surfboards is " << iTotalXXXS << endl;

    if (iTotalSmall == 0 && iTotalMedium == 0 && iTotalLarge == 0 && iTotalXXXS == 0)
        cout << "No purchases made yet" << endl;

    cout << endl;
}


//Display Total Function
void DisplayTotal(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int iTotalXXXS)
{
    //Set fixed decimal place to 2
    cout << fixed << showpoint << setprecision(2);

    if (iTotalSmall > 0)
        cout << "The total number of small surfboards is " << iTotalSmall << " at a total of $" << iTotalSmall * SMALLBOARD << endl;

    if (iTotalMedium > 0)
        cout << "The total number of medium surfboards is " << iTotalMedium << " at a total of $" << iTotalMedium * MEDIUMBOARD << endl;

    if (iTotalLarge > 0)
        cout << "The total number of large surfboards is " << iTotalLarge << " at a total of $" << iTotalLarge * LARGEBOARD << endl;

    if (iTotalXXXS > 0)
        cout << "The total number of XXXSmall surfboards is " << iTotalXXXS << " at a total of $" << iTotalXXXS * XXXSBOARD << endl;

    if (iTotalSmall == 0 && iTotalMedium == 0 && iTotalLarge == 0 && iTotalXXXS == 0)
        cout << "No purchases made yet" << endl;
    else
        cout << "Amount due:  $" << (iTotalSmall * SMALLBOARD) + (iTotalMedium * MEDIUMBOARD) + (iTotalLarge * LARGEBOARD) + (iTotalXXXS *XXXSBOARD) << endl;

    cout << endl;
}


//Menu Switch Statement Function
void MenuSwitch(char x, int& iTotalSmall, int& iTotalMedium, int& iTotalLarge, int& iTotalXXXS)
{
    switch (x)
    {
    case 'S':
    case 's':
        //Clear Console
        system("cls");
        //Call ShowBanner()
        ShowBanner();
        //Call ShowUsage()
        ShowUsage();
        break;

    case 'P':
    case 'p':
        //Call MakePurchase()
        MakePurchase(iTotalSmall, iTotalMedium, iTotalLarge, iTotalXXXS);
        break;

    case 'C':
    case 'c':
        //Call DisplayPurchase()
        DisplayPurchase(iTotalSmall, iTotalMedium, iTotalLarge, iTotalXXXS);
        break;

    case 'T':
    case 't':
        //Call DisplayTotal()
        DisplayTotal(iTotalSmall, iTotalMedium, iTotalLarge, iTotalXXXS);
        break;

    case 'Q':
    case 'q':
        cout << "Thank you" << endl;
        break;
    }
}