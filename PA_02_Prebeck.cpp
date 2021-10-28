//************************************************************
// Author:      Blake Prebeck
// Class:       ITCS 2530
// Assignment:  Week 02 - Programming Assignment
// Professor:   Koss
// Due Date:    10/31/21
//************************************************************
// Decomposition:
// #1) Print input statement for kg of cheese produced.
// #2) Calculate containers, cost and profit.
// #3) Output containers, cost and profit.
//************************************************************
// Description: Given an amount of cheese in kg, program 
// will output required containers, cost and profit.
//************************************************************


    //headers
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

    //constants
double CHZ_CONTAINER = 2.76;
double CHZ_COST = 4.12;
double CHZ_PROFIT = 1.45;

int main()
{
        //declare variables
    int chzProduced = 0;
    int chzContainerTotal = 0;
    double chzProfitTotal = 0;
    double chzCostTotal = 0;

            //Banner text
    cout << setfill('*') << setw(80) << "*" << endl;
    cout << setw(51) << "It Ain\'t Easy Being Cheesey" << setw(29) << '*' << endl;
    cout << setw(80) << "*" << endl;
    cout << endl;

        //Input
    cout << "Please enter the total number of kilograms of cheese produced :  ";
    cin >> chzProduced;
    cout << endl;

        //Calculations
    chzContainerTotal = round(chzProduced / CHZ_CONTAINER);
    chzCostTotal = chzContainerTotal * CHZ_COST;
    chzProfitTotal = chzContainerTotal * CHZ_PROFIT;
        
        //Output containers
    cout << setfill(' ') << setw(65) << left;
    cout << "The number of containers to hold the cheese is:  " << right << setw(15) << chzContainerTotal << endl;

        //Output cost
    cout << setfill(' ') << setw(65) << left;
    cout << "The cost of producing " + to_string(chzContainerTotal) + " container(s) of cheese is:  "
        << right << setw(9) << '$' << setprecision(2) << fixed << chzCostTotal << endl;

        //Output profit
    cout << setfill(' ') << setw(65) << left;
    cout << "The profit from producing " + to_string(chzContainerTotal) + " container(s) of cheese is:  " 
        << right << setw(9) << '$' << setprecision(2) << fixed << chzProfitTotal << endl;


    return 0;
}