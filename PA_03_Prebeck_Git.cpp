//************************************************************
// Author:      Blake Prebeck
// Class:       ITCS 2530
// Assignment:  Week 03 - Programming Assignment #3
// Professor:   Koss
// Due Date:    11/07/21
//************************************************************

// 1) Input item name (string)
// 2) Input fragile (y/n)
// 3) Input order total (double)
// 4) Input destination (usa/can/aus)
// 5) Selection structure(s) for costs
// 6) Output Item, shipping cost, destination, total costs.

    //Headers
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <fstream>
using namespace std;

    //Constants
const double SHIP_FRAGILE = 2.00;
const double SHIP_FREE = 0.00;

const double SHIP_USA_1 = 6.00;
const double SHIP_USA_2 = 9.00;
const double SHIP_USA_3 = 12.00;

const double SHIP_CAN_1 = 8.00;
const double SHIP_CAN_2 = 12.00;
const double SHIP_CAN_3 = 15.00;

const double SHIP_AUS_1 = 10.00;
const double SHIP_AUS_2 = 14.00;
const double SHIP_AUS_3 = 17.00;


int main()
{
        //Variables
    ofstream outData;

    string itemName;
    string orderDestination;
    string itemFragile;

    double orderTotal = 0.00;
    double shippingCost = 0.00;
    double shippingTotal = 0.00;

        //Open output file
    outData.open("Order.txt");
    
        //Banner text
    cout << setfill('.') << setw(50) << "." << endl;
    cout << "ITCS 2530 - Programming Assignment for week #3" << endl;
    cout << setw(50) << "." << endl;
    cout << endl;
    outData << setfill('.') << setw(50) << "." << endl;
    outData << "ITCS 2530 - Programming Assignment for week #3" << endl;
    outData << setw(50) << "." << endl;
    outData << endl;


        //Set fixed decimal place to 2
    cout << fixed << showpoint << setprecision(2);
    outData << fixed << showpoint << setprecision(2);  

        //Input item name
    cout << setw(50) << left;
    cout << "Please enter the item name (no spaces)" << ":";
    outData << setw(50) << left;
    outData << "Please enter the item name (no spaces)" << ":";
    cin >> itemName;
    outData << itemName << endl;
    transform(itemName.begin(), itemName.end(), itemName.begin(), ::toupper);   //Convert lowercase to uppercase

        //Input fragile
    cout << setw(50) << left;
    cout << "Is the item fragile? (y=yes/n=no)" << ":";
    outData << setw(50) << left;
    outData << "Is the item fragile? (y=yes/n=no)" << ":";
    cin >> itemFragile;
    outData << itemFragile << endl;
    transform(itemFragile.begin(), itemFragile.end(), itemFragile.begin(), ::toupper);  //Convert lowercase to uppercase
    if (itemFragile == "Y" || itemFragile == "N");  //Entry validation
    else
    {
        cout << endl << "Invalid entry, exiting";
        outData << endl << "Invalid entry, exiting";
        system("pause");
        return -1;
    }

        //Input order total
    cout << setw(50) << left;
    cout << "Please enter your order total" << ":";
    outData << setw(50) << left;
    outData << "Please enter your order total" << ":";
    cin >> orderTotal;
    outData << orderTotal << endl;

        //Input order destination
    cout << setw(50) << left;
    cout << "Please enter destination. (usa/can/aus)" << ":";
    outData << setw(50) << left;
    outData << "Please enter destination. (usa/can/aus)" << ":";
    cin >> orderDestination;
    outData << orderDestination << endl;
    transform(orderDestination.begin(), orderDestination.end(), orderDestination.begin(), ::toupper);   //Convert lowercase to uppercase
    if (orderDestination == "USA" || orderDestination == "CAN" || orderDestination == "AUS");   //Entry validation
    else
    {
        cout << endl << "Invalid entry, exiting";
        outData << endl << "Invalid entry, exiting";
        system("pause");
        return -1;
    }   

    cout << endl;
    outData << endl;

        //Selection structure - shipping cost from destination
    if (orderTotal < 50)
    {
        if (orderDestination == "USA")
            shippingCost = SHIP_USA_1;
        else if (orderDestination == "CAN")
            shippingCost = SHIP_CAN_1;
        else 
            shippingCost = SHIP_AUS_1;
    }
    else if (orderTotal >= 50.01 and orderTotal <= 100.00)
    {
        if (orderDestination == "USA")
            shippingCost = SHIP_USA_2;
        else if (orderDestination == "CAN")
            shippingCost = SHIP_CAN_2;
        else
            shippingCost = SHIP_AUS_2;
    }
    else if (orderTotal >= 100.01 and orderTotal <= 150.00)
    {
        if (orderDestination == "USA")
            shippingCost = SHIP_USA_3;
        else if (orderDestination == "CAN")
            shippingCost = SHIP_CAN_3;
        else
            shippingCost = SHIP_AUS_3;
    }
    else
        shippingCost = SHIP_FREE;
 
        //Selection structure - shipping total including fragile
    if (itemFragile == "Y")
        shippingTotal = shippingCost + SHIP_FRAGILE;
    else
        shippingTotal = shippingCost;

        //Output item name
    cout << setw(40) << left;
    cout << "Your item is" << itemName << endl;
    outData << setw(40) << left;
    outData << "Your item is" << itemName << endl;
        
        //Output shipping cost
    cout << setw(40) << left;
    cout << "Your shipping cost is" << "$" << shippingTotal << endl;
    outData << setw(40) << left;
    outData << "Your shipping cost is" << "$" << shippingTotal << endl;

        //Output shipping destination
    cout << setw(40) << left;
    cout << "You are shipping to" << orderDestination << endl;
    outData << setw(40) << left;
    outData << "You are shipping to" << orderDestination << endl;

        //Output total shipping cost
    cout << setw(40) << left;
    cout << "Your total shipping costs are" << "$" << shippingTotal + orderTotal << endl << endl;
    outData << setw(40) << left;
    outData << "Your total shipping costs are" << "$" << shippingTotal + orderTotal << endl << endl;

        //Output goodbye
    cout << setfill('-') << setw(40) << "-" << "Thank You!" << endl;
    outData << setfill('-') << setw(40) << "-" << "Thank You!" << endl;

        //Close file
    outData.close();

    return 0;
}
