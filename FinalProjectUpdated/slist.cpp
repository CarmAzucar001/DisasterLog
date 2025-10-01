
// Complete all functions with their comments
// NEVER delete my comments!!
// ====================================================
//HW#: HW3P1 slist  inheriting from llist
//Your name: Carmelo Azucar
//Complier:  g++
//File type: slist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"slist.h" 
//#include "llist.h"

//  Make sure llist constructor and destructors have couts in them


// do not change this one
slist::slist()
{
    cout << "slist constructor:" << endl;

}

// positions always start at 1
// don't forget to return the position (>=1) or 0 if not found

//Purpose: The purpose of the function is to first check if the list is empty in order to return a message if nothing is in the list. 
// After the check we set a pointer to the front of the list while starting the position at 1. After the initalization we create a loop
// to move through the list and as we move we check to see if we can find the element based on the pointer and key.
//Parameter: The parameter holds the key for what element or value we are searching for

int slist::search(el_t key)
{
    if (isEmpty()) //first checks if the list is empty and then throw an underflow if its empty using the llist function
    {
        throw Underflow();
    }

    Node* p = Front;// starts p at the front

    int position = 1;//position starts at 1

    while (p != NULL) // go until p reaches the end
    {

        if (p->Elem == key) // if the element in p matches the key then return the position it was found
        {
            return position;
        }

        p = p->Next;//moves p to the next value
        position++; //increment the position counter
    }
    return 0; //return 0 if nothing is found
}




// don't forget to throw OutOfRange for bad pos 
// You must use moveTo to go to the pos
//Purpose:The Purpose of this function is to throw an underflow if the list is empty and an out of range if the element is out of the list range
// After completing the checks we will create a new pointer which will be moved somewhere into the list by the moveTO function and then we replace the
//of p with the new element that we are adding.
//Parameter: The parameter of this function uses the element which will be replaced by the function while also using pos to store the 
//position we are storing from.

void slist::replace(el_t element, int pos)
{
    if (isEmpty()) // check if the list is empty
    {
        throw Underflow(); //throw an underflow if nothing is in the list
    }

    if (pos < 1 || pos > Count + 1) // if the pos is out of range throw outofrange
    {
        throw OutOfRange(); // throw out of range for bad positions
    }
    else
    {
        Node* p;//new node pointer
        moveTo(pos, p); // use the public move to function in order to move p to the pos stored in pos
        p->Elem = element;//the element p is pointing to will be replaced by the new element
    }

}


//Purpose: The purpose of this function is to check if two different lists are equal to each other. In this case we can check the count
//first and if the count doesn't match then the list are not the same. After checking the count we use a loop in order to move through both lists
//As we move through the list we check the elements of each list and return false once one an element is wrong
//Parameter: THe paramter of thiss list uses pass by reference in order to pass a list that we will compare into the list
bool slist::operator==(const slist& OtherOne)
{
    // if not the same length, return false immediately
    // if the same lengths,//check each node to see if the elements are the same
    if (this->Count != OtherOne.Count) // checks the first list with the second list in order to make sure there equal
    {
        return false;//if not make it false
    }

    Node* FirstList = this->Front; // uses the first list to set a pointer to the front of the list
    Node* SecondList = OtherOne.Front; // the second list will also point to the front of the second list

    while (FirstList != NULL)// until the list reaches the end
    {

        if (FirstList->Elem != SecondList->Elem) // compare the elements between each list 
        {
            return false;//return false once an element is wrong
        }

        //Move through both counters
        FirstList = FirstList->Next;
        SecondList = SecondList->Next;
    }
    return true;
}
