// CS311 Ho  Fall24 - el_t for HW8 Hash Table
// Element type of a list node is defined here
// el_t can be changed by the client to fit its needs
// I use IFNDEF in case this file gets included more than once
// Update based on **
// ---------------------------------------------------------

#ifndef A
#define A

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class el_t
{
private:  // these will change depending
    // on the client needs
    int code;
    //** add 2 more pieces of info here
    string date;
    string disaster_type;
    string disaster_location;
    string disaster_name;

    //since variables are working with numbers they will stay as an int 
    int disaster_power;
    int disaster_occurance_by_power_in_year;

    int key;      // key -- for EC, key has to change to string everywhere!!!
    string Skey;
public:

    el_t();  // to create a blank el_t object
    el_t(int, string, string, string, string, int, int, int,string); // to create an initialized el_t object - useful for the client   ** add more arguments to create the object

    // The following functions are available to
    // the htable class to be able to
    // use different el_t without modifying the code

    int getkey(); // only the key part can be accessed by the user of this class.

    void setkey(int); // only the key part can be accessed by the user of this class.

    // will be used to grab the priavte data memebers when it is needed
    int getDisasterPower();
    string getDisasterType();
    int getYear();




    // In linked list search,
    //    == is used to compare node elements
    // but what does it mean for this client to compare
    // node elements?  
    bool operator==(el_t);  // overload == for search
    bool operator!=(el_t);  // overload != for search
    bool operator<(el_t); // overload function to do the comparison


    // This overloads cout for the el_t object
    // This is a friend function since the receiver object is not el_t
    friend ostream& operator<<(ostream&, const el_t&);


    //Will only show the menu depending on what they do
    void SearchMenu(vector<el_t>);
    void SortMenu(vector<el_t>);

    // will extract the information from the file
    void inputFile(const string& file,vector<el_t>& info);

    //will search based on what the user wants to find
    void SearchByYear(vector<el_t>&, int input);
    void SearchByString(vector<el_t>&, string& input);


    //these functions will be used by the sort menu in order to sort the data
    void sortByHighestPower(vector<el_t>& info);
    void sortByRecentDisaster(vector<el_t>&);


   //void outputFile(const string& file, vector<el_t>& info);
};

#endif
