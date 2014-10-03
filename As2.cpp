/*
	Programming 1
	Assignment 2
	October 3rd, 2014
	Daniel Perez

	This program calculates the amount of change using the least amount of coins as possible, displays the number of
	each different coin used, and, at the end, displays usage statistics of the calculator.

*/

#include <iostream>
using namespace std;

void main()
{

	int    penniesIn;
	int    pennies;
	int    penniesLeftAfterToonies;
	int    penniesLeftAfterLoonies;
	int    penniesLeftAfterQuarters;
	int    penniesLeftAfterDimes;
	int    penniesLeftAfterNickels;
	int    nickels;
	int    dimes;
	int    quarters;
	int    loonies;
	int    toonies;
	int    calcUses;
	double averagePennies;
	int    totalPennies;
	char   use;
	int    _5To300;
	int    _301To600;
	int    _601To999;

	totalPennies = 0;
	calcUses     = 0;
	_5To300      = 0;
	_301To600    = 0;
	_601To999    = 0;

	cout << "CHANGE CALCULATOR" << endl;
	cout << endl << endl;

	while (true)
	{
		do
		{
			cout << "Do you want to use the calculator Y or N: ";
			cin  >> use;

			use = toupper(use);
		}
		while (use != 'N' && use != 'Y');


		if (use == 'N')
		{
			break;
		}
		
		system("cls");
		

		do
		{
			cout << "Amount of Pennies (5 to 999, 0 to stop): ";
			cin  >> penniesIn;			
		} 
		while ((penniesIn < 5 || penniesIn > 999) && penniesIn != 0);

		if (penniesIn == 0)
		{
			break;
		}
	
		cout << endl;
		
		penniesLeftAfterToonies  = penniesIn % 200;
		toonies                  = penniesIn / 200;

		penniesLeftAfterLoonies  = penniesLeftAfterToonies % 100;
		loonies                  = penniesLeftAfterToonies / 100;
		
		penniesLeftAfterQuarters = penniesLeftAfterLoonies % 25;
		quarters                 = penniesLeftAfterLoonies / 25;
	
		penniesLeftAfterDimes    = penniesLeftAfterQuarters % 10;
		dimes                    = penniesLeftAfterQuarters / 10;

		penniesLeftAfterNickels  = penniesLeftAfterDimes % 5;
		nickels                  = penniesLeftAfterDimes / 5;

		pennies                  = penniesLeftAfterNickels;
	

		cout << "The least amount of coins for 62 pennies is" << endl;

		if (toonies > 0)
		
			cout << toonies  << " toonie(s)" << endl;
		
		if (loonies > 0)

			cout << loonies  << " loonie(s)" << endl;

			
		if (quarters > 0)

			cout << quarters << " quarter(s)" << endl;

				
		if (dimes > 0)

			cout << dimes    << " dime(s)" << endl;

					
		if (nickels > 0)

			cout << nickels  << " nickel(s)" << endl;

						
		if (pennies > 0)

			cout << pennies  << " penny(ies)" << endl;
						
		cout << endl << endl;

		calcUses++;

		totalPennies = totalPennies + penniesIn;

		if (penniesIn > 4 && penniesIn < 301)

			_5To300++;

		else
		{
			if (penniesIn > 300 && penniesIn < 601)

				_301To600++;

			else
			{
				if (penniesIn > 600 && penniesIn < 1000)

					_601To999++;

			}

		}

	}

	if (calcUses > 0)
	{
		system("cls");

		averagePennies = (double)totalPennies / calcUses;

		cout << "----------STATISTICS----------" << endl;
		cout << "The calculator was used " << calcUses << " time(s)" << endl;
		cout << endl;
		cout << "Average # of pennies submitted to the calculator: " << averagePennies << endl;
		cout << endl;

		if (_5To300 > 0)

			cout << "Submitted   5 to 300 pennies " << _5To300 << " time(s)" << endl;

		if (_301To600 > 0)

			cout << "Submitted 301 to 600 pennies " << _301To600 << " time(s)" << endl;

		if (_601To999 > 0)

			cout << "Submitted 601 to 999 pennies " << _601To999 << " time(s)" << endl;

		cout << endl;
	}
}