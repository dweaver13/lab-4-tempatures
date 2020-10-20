/*
Dale Weaver
C++ Fall 2020
Due: October 19th 2020
Lab 4 Temperature Output
this lab will display certain tempatures from a 24 hour period and take that number, divide by 3
and display that amount of * to the right
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void calc(); //second function. It makes it easier to find errors instead of one big main funtion

int main()
{
	cout << "\n Here are the tempetures for 24 hours.\n Each '*' represents 3 degrees.\n"; // displays title as well what each star means
	cout << setw(8) << "-30" << setw(8) << "0" << setw(10) << "30" << setw(10) << "60" << setw(10) << "90" << setw(10) << "120" << setw(10) << "150" << endl; // displays # of stars on top of the screen
	calc(); // calls the calculation function
	return 0;
}

void calc()
{
	ifstream inFile; //calls file that has temps
	string fileName; //allows file name to be a string
	float tempature; //used for tempatures taken from file
	string starOut; //used for displaying stars to screen
	// opens file and puts all the numbers into the variable 'tempature'
	inFile.open("VariousTemps.dat"); 
	inFile >> tempature;
	
	while (inFile >> tempature)
	{
		tempature = ceil(tempature); // rounds any numbers up

		starOut = ""; //resets string after every tempature
		//makes sure that the tempature is valid
		if (tempature < -30 && tempature > 120)
		{
			inFile >> tempature;
			continue;
		}
		else
		{
			cout << tempature << ":"; //displays tempature on left side as well :
		}

		//takes tempature and divides by 3 then allots the correct amount of stars
		for (int i = 1; i <= (abs(tempature) / 3); ++i)
		{
			starOut.append("*"); //appoints stars
		}

		// prints the tempature as well as the stars 
		if (tempature == -30)
		{
			cout << setw(11) << starOut << "|"; //puts | on right side of stars
		}
		else if (tempature > -30 && tempature <= -10) //-30 to -10
		{
			cout << setw(11) << starOut << "|";//puts | on right side of stars
		}
		else if (tempature > -10 && tempature < 0) //-10 to 0
		{
			cout << setw(12) << starOut << "|";//puts | on right side of stars
		}
		else if (tempature >= 0 && tempature < 10) //0 to 10
		{
			cout << setw(14) << "|" << starOut;//puts | on left side of stars
		}
		else if (tempature >= 10 && tempature < 100) //10 to 100
		{
			cout << setw(13) << "|" << starOut;//puts | on left side of stars
		}
		else if (tempature >= 100 && tempature <= 120) //100 to 120
		{
			cout << setw(12) << "|" << starOut;//puts | on left side of stars
		}
		else if (tempature > 120) //any tempature about 120 is left out
		{
			continue;
		}
		cout << endl; // ends line
	}
}