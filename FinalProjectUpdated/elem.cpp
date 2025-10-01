// CS311 Ho Fall24 - el_t for HW8 Hash Table
// Element type of a list node is defined here
// el_t can be changed by the client to fit its needs
// Edit ** parts
//  NEVER delete my comments!!
//----------------------------------------------------

#include "elem.h"
#include "slist.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

el_t::el_t() // initalize all the information to empty strings and empty int
{
	code = 0;
	date = "";
	disaster_type = "";
	disaster_location = "";
	disaster_name = "";
	disaster_power = 0;
	disaster_occurance_by_power_in_year = 0;
	key = 0;
	Skey = "";

}

el_t::el_t(int c, string d, string dt, string dl, string dn, int dp, int dop, int k,string sk) // initalize
{
	code = c;
	date = d;
	disaster_type = dt;
	disaster_location = dl;
	disaster_name = dn;
	disaster_power = dp;
	disaster_occurance_by_power_in_year = dop;
	key = k;
	Skey = sk;
}

// ONLY the key part should be available to the user of this class
int el_t::getkey()
{
	return key;
}

// ONLY the key part should be available to the user of this class 
void el_t::setkey(int akey)
{
	key = akey;
}

int el_t::getDisasterPower() // will return the given disaster power
{
	return disaster_power;
}

string el_t::getDisasterType() // return the disaster type
{
	return disaster_type;
}

int el_t::getYear() // turn the date into an int and return the int year
{
	return stoi(date.substr(date.length() - 4));
}

// overload == for search based on the key part only
bool el_t::operator==(el_t OtherOne)
{
	if (this->key == OtherOne.key) return true; else return false;
}

// based on the key part only
bool el_t::operator!=(el_t OtherOne)
{
	if (this->key != OtherOne.key) return true; else return false;
}

bool el_t::operator<(el_t otherone) // this function will be used as a comparison if it is needed later on
{
	int dateYear = stoi(date.substr(date.length() - 4));
	if(dateYear < otherone.getYear())
	{
		return true;
	}
	return false;
}

// overload cout 
ostream& operator<<(ostream& os, const el_t& E)
{
	os << E.date << ',' << E.disaster_type << ',' << E.disaster_location << ',' << E.disaster_name << E.disaster_power << ',' << E.disaster_occurance_by_power_in_year << ',' <<endl; // display other parts of E in a nice way
	return os; // this overload will show the information that we want to display and will ignore the rest
}
// if you make it come out just like the input file, Saving to a file will
// be easier!


//this function is only used to display the search menu
void el_t::SearchMenu(vector<el_t> VE)
{

	el_t e;
	bool  SearchEnd;
	SearchEnd = false;
	int  SearchMenuChoice;
	int year;
	string type;
	do
	{
		cout << " Search Menu:" << endl;
		cout << "1. Search by disaster type" << endl;
		cout << "2. Search by year" << endl;
		cout << "3.End Program" << endl;
		cout << "Which option would you like to do?" << endl;
		cin >> SearchMenuChoice;
		switch (SearchMenuChoice)
		{
		case 1:
			cout << "We are now Searching by type:" << endl;

			cout << "Enter the type you want to search for:(wind/ground/water/eruption)" << endl;
			cin >> type;
			e.SearchByString(VE,type); // depending on what we are searching for we are going to call the correct search

	//		e.outputFile("SearchType.txt",VE);
			//call  coutearchType
			break;
		case 2:
			cout << "Now  searching by the year:" << endl;
			//call  coutearchYear
			cout << "Enter the year" << endl; // prompts the user to enter a year first and passes it into the function
			cin >> year;
			e.SearchByYear(VE, year);
			break;
		case 3:
			cout << " Now ending" << endl;
			SearchEnd = true;
			break;
		default:
			cout << "Incorrect option please try again" << endl;
			break;

		}
	} while (SearchEnd != false);
}

// this menu will only show the sort menu 
void el_t::SortMenu(vector<el_t> VE)
{
	bool SortEnd = false; 
	int SortMenuChoice;
	do
	{ // shows the possible options
		cout << "Sort Menu:" << endl;
		cout << "1.Sort by the highest power(Bubble Sort)" << endl;
		cout << "2.Sort by the recent disasters" << endl;
		cout << "3.End Program" << endl;
		cout << "Which option would you like to do?" << endl;
		cin >> SortMenuChoice;
		switch (SortMenuChoice)
		{
		case 1:
			cout << "We are now sorting by highest power" << endl;
			sortByHighestPower(VE);
			for (int i = 0; i < VE.size(); i++)
			{
				cout << VE[i] << endl;
			}
			break;
		case 2:
			cout << "Now sorting by the recent disasters" << endl;
			sortByRecentDisaster(VE);
			for (int x = 0; x < VE.size(); x++)
			{
				cout << VE[x] << endl;
			}
			break;
		case 3:
			cout << " Now ending" << endl;
			SortEnd = true;
			break;
		default:
			cout << "Incorrect option please try again" << endl;
			break;
		}
	} while (SortEnd != false);
}

// this function will take all the information from the file and put all in a vector
void el_t::inputFile(const string& file, vector<el_t>& info)
{
	ifstream fin(file); // using the provided file open it 
	if (!fin.is_open()) // if we cant open the file send an error
	{
		cout << "The file can not be open" << endl;
		return;
	}

	string fileLine; // used to store the line

	while (getline(fin, fileLine)) // this will keep going until we run out of lines in the file
	{

		int code;
		//** add 2 more pieces of info here
		string date,disaster_type,disaster_location,disaster_name;

		//since variables are working with numbers they will stay as an int 
		int disaster_power;
		int disaster_occurance_by_power_in_year;
		int key = 0;
		string skey = "";

		stringstream SS(fileLine); // we are going to use a string stream to grab the information from the file 

		
		SS >> code >> date >> disaster_type >> disaster_location >> disaster_name >> disaster_power >> disaster_occurance_by_power_in_year;

	
		el_t information(code, date, disaster_type, disaster_location, disaster_name, disaster_power, disaster_occurance_by_power_in_year, key,skey);
		info.push_back(information); // push that information into the el_t object
	}

	fin.close();

}

void el_t::SearchByYear(vector<el_t>& info, int input)
{
	bool f = false; 
	//cout << input;
	cout << "Showing the Found year:" << endl; // used to display the year so it won't repeat
	for (int i = 0; i < info.size(); i++) // this for loop is used to go through the vector
	{
		if (info[i].getYear() == input) // will check each object in the vector and compare it to the user inputted key
		{
			cout << input << ":" << info[i] << endl; // display it if it is found
			
		}
		f = true; // will be used to break the loop
	}
	if (f != false)
	{
		cout << "The year can not be found" << endl;
	}

}

void el_t::SearchByString(vector<el_t>& inf, string& input)
{
	bool f = false;
	cout << "Showing the Found Type:" << endl; // similar to the search by year  
	for (int i = 0; i < inf.size(); i++)// this for loop is used to go through the vector
	{
		if (inf[i].getDisasterType() == input)// will check each object in the vector and compare it to the user inputted key
		{
			cout << inf[i] << ":" << endl; // display it if it is found
		}
		f = true;
	}
	if (f != false) // send an error if we cant find it
	{
		cout << "The year can not be found" << endl;
	}

}


// this will sort using bubble sort for now
void el_t::sortByHighestPower(vector<el_t>& info)
{

	for (int i = 0; i < info.size(); i++) // go through the vector
	{
		for (int j = 0; j < info.size() - 1 - i; j++) // move another variable through the vector
		{
			//compare the power based on what is found
			if (info[j].getDisasterPower() < info[j + 1].getDisasterPower())
			{
				// Swap the two elements if the first one has a smaller disaster power
				el_t temp = info[j];
				info[j] = info[j + 1];
				info[j + 1] = temp;
			}
		}
	}
}

//this function will still use bubble sort and sort by the most recent disaster
void el_t::sortByRecentDisaster(vector<el_t>& info)
{
	for (int i = 0; i < info.size(); i++) // go through the vector
	{
		for (int j = 0; j < info.size() - 1 - i; j++) // move another variable through the vector
		{
			//compare the power based on what is found
			if (info[j].getYear() < info[j + 1].getYear())
			{
				// Swap the two elements if the first one has a smaller disaster power
				el_t temp = info[j];
				info[j] = info[j + 1];
				info[j + 1] = temp;
			}
		}
	}
}

//void el_t::outputFile(const string& file, vector<el_t>& info)
//{ofstream fout(file); // will be used for the output file


	//	if (!fout.is_open()) // if we cant open the file send an error
		//{
		//	cout << "The file can not be open" << endl;return;	}

		//for (int i = 0; i < info.size(); i++)
		//{fout << info[i] << endl;}

	//fout.close();//close the file
//	cout << "The information has been saved" << endl;}
