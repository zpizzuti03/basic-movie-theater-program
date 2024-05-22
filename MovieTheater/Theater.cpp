/*
Author Name: Zach Pizzuti
Course#: CSE 110
Lab Title: Theater Seating
Project Description: This program is a program used by theaters to sell tickets
Project Due Date: 12/5/21

*/

#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>

using namespace std;

const int ROWS = 15;        //to hold the amount of rows
const int SEATS = 30;       //to hold the amount of seats in a row

void startingSeats (string[][SEATS], int, int);     //could also be used to reset layout
void displaySeating (string[][SEATS], int, int);
void ticketValue (double[], int);
void displayTicketPrice (double[], int);
void ticketPurchase(string[][SEATS], int, int);
void viewTicketSales(string[][SEATS], double[], int, int);
int displayMenu(int);

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

    string layout[ROWS][SEATS]; //To hold the characters representing seats
    double prices[ROWS];        //To hold to prices of each seat in each row
    int choice = 0;             //To hold the menu choice option

    //fill the rows and seats with their default values
    startingSeats(layout, ROWS, SEATS);

    //Obtain the prices of the tickets for each row
    ticketValue(prices, ROWS);

    cout << endl << endl << endl;
    cout << fixed << setprecision(2);

    //Menu will loop until exit choice is chosen
    do
    {
    //Clear the screen
    system("CLS");

    //Display the menu and get user input for choice
    choice = displayMenu(choice);

       switch(choice)
    {
    case 1:     //View Available Seats
        {
            system("CLS");

            displaySeating(layout, ROWS, SEATS);

            system ("pause");

            break;
        }
    case 2:     //View Seating Prices
        {
            system("CLS");

            displayTicketPrice(prices, ROWS);

            system ("pause");

            break;
        }
    case 3:     //View Ticket Sales
        {
            system("CLS");

            viewTicketSales(layout, prices, ROWS, SEATS);

            break;
        }
    case 4:     //Purchase a Ticket
        {
            system("CLS");

            ticketPurchase(layout, ROWS, SEATS);

            break;
        }
    case 5:     //Exit the list
        {
            cout << endl << "Program ending, Thank You for using C++ Theater!" << endl;

            return 0;

        break;

        }
    }
    }
    while(choice !=5);
}

//********************************************
//The startingSeats function's purpose is to *
//store the starting values of each seat     *
//********************************************
void startingSeats(string layout[][SEATS], const int ROWS, const int SEATS)
{
    int rowCounter = 0, seatCounter = 0;

    for (rowCounter == 0; rowCounter < ROWS; rowCounter++)
    {
        seatCounter = 0;
        for(seatCounter == 0; seatCounter < SEATS; seatCounter++)
        {
            layout[rowCounter][seatCounter] = '#';
        }
    }
}

//**************************************************
//The displaySeating function's purpose is         *
//to display the seating arrangements when called  *
//**************************************************
void displaySeating(string layout[][SEATS], const int ROWS, const int SEATS)
{
        int rowCounter = 0, seatCounter = 0;

        cout << endl << "Open seats are represented by '#'s and bought seats '*'s." << endl << endl;
        cout << "123456789012345678901234567890" << endl;
    for (rowCounter == 0; rowCounter < ROWS; rowCounter++)
    {
        cout << endl;
        seatCounter = 0;
        for(seatCounter == 0; seatCounter < SEATS; seatCounter++)
        {
            cout << layout[rowCounter][seatCounter];
        }
    }
    cout << endl << endl;
}

//***************************************
//The ticketValue function's purpose is *
//to get the value of each row's ticket *
//price by user input                   *
//***************************************
void ticketValue(double prices[], const int ROWS)
{
    int tvCounter = 0;

    for(tvCounter == 0; tvCounter < ROWS; tvCounter++)
    {
        //Get input for the ticket price
        cout << "Please enter the price of the tickets in row " << tvCounter + 1 << ": ";
        cin >> prices[tvCounter];
        //Input Validation
        while(prices[tvCounter] <= 0)
        {
            cout << "Please enter a value greater than zero for the price: ";
            cin >> prices[tvCounter];
        }
    }
}

//*************************************
//displayMenu is a function that      *
//displays the menu and gets the      *
//user's input for choice on the menu *
//*************************************
int displayMenu(int choice)
{
    cout << endl << setw(18) << "C++ Theater" << endl << setw(8) << " =========================" << endl << endl;
    cout << "  1. View Available Seats" << endl;
    cout << "  2. View Seating Prices" << endl;
    cout << "  3. View Ticket Sales" << endl;
    cout << "  4. Purchase a Ticket" << endl;
    cout << "  5. Exit the Program" << endl << endl;
    cout << " Please enter your choice: ";
    cin >> choice;

    while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5)
    {
        cout << "Please enter a choice number from the menu: ";
        cin >> choice;
    }
    return choice;
}

//***************************************************************
//The purpose of the function displayTicketPrice is to display  *
//the price of the tickets that was entered by the user at the  *
//start of the program                                          *
//***************************************************************
void displayTicketPrice (double prices[], const int ROWS)
{
    int counter = 0;

    cout << endl << "These are the prices of the tickets you entered in the beginning of the program." << endl << endl;

    for (counter == 0; counter < ROWS; counter++)
    {
        cout << "Row " << counter + 1 << " price: $" << prices[counter] << endl;
    }
    cout << endl;
}

//********************************************************
//The purpose of the ticketPurchase function is to allow *
//the user to purchase a ticket in a specific seat in a  *
//specific row, and modify the contents of the array to  *
//match it                                               *
//********************************************************
void ticketPurchase(string layout[][SEATS], const int ROWS, const int SEATS)
{
    int counter = 0;
    string YES = "y", NO = "n";
    string input = YES;
    int rowInput, seatInput;

    do
    {
        if (counter != 0)
        {
            cout << endl << "Would you like to purchase another ticket? (y/n): ";
            cin >> input;

        while (input != YES && input != NO)
            {
                cout << "Please enter y or n: ";
                cin >> input;
            }
        }

        if(input == NO)
        {
            continue;
        }
    system("CLS");

    cout << endl << "Welcome to the ticket purchasing window, please enter the row in which you would like to purchase a ticket (1-15): ";
    cin >> rowInput;

    //Input Validation
    while(rowInput <= 0 || rowInput > 15)
    {
        cout << endl << "Please enter a row number 1-15: ";
        cin >> rowInput;
    }

    cout << endl << "Now, select the seat in the row that you would like to purchase (1-30): ";
    cin >> seatInput;

    //Input Validation
    while(seatInput <= 0 || seatInput > 30)
    {
        cout << endl << "Please enter a seat number 1-30: ";
        cin >> seatInput;
    }

    //For the array, subtract 1 to get the correct element
    rowInput = rowInput - 1;
    seatInput = seatInput - 1;

    if(layout[rowInput][seatInput] == "*")
    {
        cout << endl << "Sorry, that seat is already purchased." << endl;
    }
    else
    {
        layout[rowInput][seatInput] = "*";
        cout << endl << "Seat successfully purchased! Thank you!" << endl;
    }

    counter++;
    }
    while(input == YES);
}

//**********************************************************
//The purpose of viewTicketSales is to show the money made *
//from each currently purchased seat and display it to the *
//user along with the total amount.                        *
//**********************************************************
void viewTicketSales(string layout[][SEATS], double prices[], const int ROWS, const int SEATS)
{
    int rowCount = 0, seatCount = 0, counter = 0;
    double rowPrice[ROWS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    double total = 0;
    int fullSeats[ROWS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    cout << endl << "These are the details of all of the tickets sold." << endl << endl;

    //For loop to determine money spent
    for (rowCount == 0; rowCount < ROWS; ++rowCount)
    {
        seatCount = 0;

        for (seatCount == 0; seatCount < SEATS; ++seatCount)
        {
            if (layout[rowCount][seatCount] == "*")
            {
                fullSeats[rowCount] += 1;
            }
        }
        //Find the price of all purchased seats in the row
        rowPrice[rowCount] = static_cast<double>(fullSeats[rowCount]) * (prices[rowCount]);

        total += rowPrice[rowCount];
    }

    //For loop to display the money spent
    for(counter == 0; counter < ROWS; ++counter)
    {
        cout << "Total money from Row " << counter + 1 << ": $" << rowPrice[counter];
        cout << endl << "Seats Sold Row " << counter + 1 << ": " << fullSeats[counter] << endl << endl;
    }

    cout << endl << "Total money made from sales: $" << total << endl << endl;

    system ("pause");
}
