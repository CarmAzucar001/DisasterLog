#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "BST.h"
#include "elem.h"


using namespace std;

// This client tests all kinds of cases.
// But the input data is hard coded.
// For BST to be useful, the data should come from a file. 
int main()
{
	vector<el_t> VE; // create a vector to hold the el_t
	el_t e; 
	string filename = "DisasterLog.txt"; /// stores the file name

	int option; // will store the user
	bool f = false; // will turn to true once we want to end the program

	e.inputFile(filename, VE); // will open the file and put the infomration in the vector

	do
	{

		//shows the menu options
		cout << "Menu:" << endl;
		cout << "1.Display the file" << endl;
		cout << "2.Search" << endl;
		cout << "3.Sort" << endl;
		cout << "4.End Program" << endl;

		// will take the user input for the function use
		cout << "What would you like to do:" << endl;
		cin >> option;

		//switch statement to easily access the options and calls the correct function
		switch (option)
		{
		case 1:
			cout << "Now displaying the file:" << endl; // go through the loop and display everything 
			for (int i = 0; i < VE.size(); i++)
			{

				cout << VE[i] << endl;
			}

			break;
		case 2:
			e.SearchMenu(VE); // will only need to call this function which will show a menu and provide options
			break;
		case 3:
			e.SortMenu(VE);// will only need to call this function which will show a menu and provide options
			break;
		case 4:
			cout << "Ending the program" << endl;
			f = true; // if we want to end the program it will switch to true and break out the loop
			break;
		default:
			cout << "Option is not avilable try again" << endl;
		}

	} while (f != false);



  
	return 0;
}// end of program
