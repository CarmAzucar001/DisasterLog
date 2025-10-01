// CS311 Ho Fall24 slist.h
// HW3P2 Instruction: Inherit everything publicly from llist
// Put only the following in class slist.h 
//    inheriting everything from llist.h
//
// Then create slist.cpp with only the following functions
// Complete all ** parts 
//=================================================
// HW#: HW3P2 slist
// Name: Carmelo Azucar
// File: header file slist.h
//=================================================

#include "llist.h"  // for includes
#include <iostream>

class slist :public llist //inheritance from the llist file in order to use the function
{

public:

    slist();   // constructor. cout "in slist constructor".
    // Make it do nothing else.
    // Experiment and see what happens.
    // Taking this out completely would not work.
    // But note that there is no destructor.
    // PLEASE DO NOT delete the couts in slist and llist
    // constructors and destructors for HW6!!!!!

    int search(el_t e);
    //e is the place holder for the element e that we are searching for
    // search through the list to see if any node contains the key.
    // If so, return its position (>=1). Otherwise, return 0.

    void replace(el_t e, int index);
    //e is the element we are going to replace and index is the we are going to replace from 
    // go to the Ith node (if I is between 1 and Count) and 
    // replace the element there with the new element. 
    // If I was an illegal value, throw OutOfRange 

    bool operator==(const slist& l);
    //l will represent the other list that we are going to overload from
    // checks to see of the two lists look the same


};
