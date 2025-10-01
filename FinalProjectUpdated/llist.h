//CS311 Ho Fall24 llist.h
//INSTRUCTION:
//Llist class - header file template 
//You must complete the ** parts and then complete llist.cpp
//Don't forget PURPOSE and PARAMETERS 

// =======================================================
// HW#: HW3P1 llist
// Your name: Carmelo Azucar
// Compiler:  g++ 
// File type: headher file  llist.h
//=======================================================

// alias el_t : element type definition
#include "elem.h"

//a list node is defined here as a struct Node for now
struct Node
{
    el_t Elem;   // elem is the element stored
    Node* Next;  // next is the pointer to the next node

};
//---------------------------------------------------------

class llist
{

protected:
    Node* Front;       // pointer to the front node
    Node* Rear;        // pointer to the rear node
    int  Count;        // counter for the number of nodes

    // untility function to move to a specified node position
    void moveTo(int, Node*&);

public:

    // Exception handling classes 
    class Underflow {};
    class OutOfRange {};  // thrown when the specified Node is out of range

    llist();     // constructor to create a list object
    ~llist();     // destructor to destroy all nodes

    //PURPOSE: This function will be used to check if the list is empty using count,rear,and front as different conditions while returning either true if the list is empty or false if elements are in the list
    //PARAMETER:None is needed
    bool isEmpty();

    //PURPOSE:The purpose of this function is to show all the elements that are in the list
    //PARAMETER: No parameter is needed
    void displayAll();

    //PURPOSE:The purpose of this function is take the element you want to enter being in 'e' and then adding it to the front of the list while making it the new front element
    //PARAMETER: The function passes an element 'e' that will be added to the front of the list
    void addFront(el_t e);

    //PURPOSE: The purpose of this function is to take the element 'e', which is the element to be added, and add it to the rear of the list while making the element the new rear
   //PARAMETER: This functions passes the element 'e' in order to add it to the rear of the list
    void addRear(el_t e);

    //PURPOSE: THe purpose of this function is to check the front element and delete the element that is in the front while updating the front element.
    //Will throw UNDERFLOW if the list is empty and there will be a special case when there is only one element in the list
    //PARAMETER: The parameter uses pass by reference in order to store the element to be deleted and will proceed to delete and update the list  
    void deleteFront(el_t& e);


    //PURPOSE:The purpose if this function is to check the rear element and delete the element found in the rear of the list while also updating to a new rear.
    // Will throw UNDERFLOW if the list is empty while also having a special case when there is only one element in the list
    //PARAMETER:The paramers uses pass by reference in order to the element to be deleted in 'e' and then will delete and update the list
    void deleteRear(el_t& e);

    //End of Case 1
    //---------------------------------------

    //Part of Case 2 

    //PURPOSE: The purpose of this function is to go to an index i and delete the element from the index by storing the index into the Old Num parameter. WHile having the I start at 1
    // This should throw on out of range error once the I reaches the outside the list. This function will have a special case when the count is 1 or when I is 1 it will call deletefront function.
    // The regular case will update the count once the element is deleted.
    //PARAMETER: The parameter stores an index I where the function will go and delete from that certain position. The second parameter uses pass by refrenceto store the element that will be
    //deleted and storing it in 'OldNum' while also updating the list
    void deleteIth(int I, el_t& OldNum);  // calls moveTo

    //PURPOSE: The purpose of this function is to go to index I and insert at that position.Should THROW an Out of range exception if it is beyond the list. There will be another special case 
    // where there is only one value being added to the list. IN the end of the function the count should be updated since we are adding a value to the list.
    //PARAMETER: This parameter stores the index I where the function will go to the index and then insert in that postition. The second parameter will store the new value to be entered
    //and will update the list since a new element has been added
    void insertIth(int I, el_t newNum);   // calls moveTo

    //PURPOSE: The purpose of this function is to take a linked list and make a copy of that list. THis is the copy constructor for the linked list and it creates a deep copy of the linked list.
   //PARAMETER: The parameter uses pass by reference in order to pass a linked list to be copied 
   //Copy Constructor to allow pass by value and return by value of a llist
    llist(const llist& l);

    //PURPOSE:The purpose of this function is to overload the = sign in order to make a linked list have the same data as the original data.
   //PARAMETER: The parameter takes the other linked list in order to overload the function in order to allow proper copying. This will also allow us to use L1 = L2 without any issues.
   //Overloading of = (returns a reference to a llist)
    llist& operator=(const llist& OtherOne);


};
