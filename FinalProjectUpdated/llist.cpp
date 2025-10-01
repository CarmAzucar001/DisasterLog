//CS311 Ho Fall24 Linked List class

//INSTRUCTION:
//Must use the provided HW3P1_help.doc to create llist.cpp
//It helps to first create if-then-else structure to fill in later.
//- Make sure PURPOSE and PARAMETER comments are given in detail
//  You can copy from a Word document to emacs (contrl-right click)
//  Highly recommended to copy HW3P1-help as PURPOSE of each function.
//
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes
//  NEVER delete my comments!!!!
//
//EMACS HINT:
//  cntr-K cuts and cntr-Y pastes. 
//  Esc x replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#: HW3P1 llist
//Your name: Carmelo Azucar
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"llist.h" 

llist::llist()
{
	cout << "... in llist constructor..." << endl;
	Front = NULL; // intialize the front to be NULL
	Rear = NULL; // initalize the rear to point to NULL
	Count = 0; // sets the count to 0
}

llist::~llist()
{
	cout << ".... in llist destructor..." << endl;
	while (!isEmpty()) // WHile the list is not empty call delete front
	{
		el_t temp;
		deleteFront(temp); // will continue to delete everything until the list is empty
	}
}

//PURPOSE: The purpose of this function is to check the front and rear pointers to see if they point at an element. If they point to NULL then the list is empty. This function also checks the counter.
// If the counter has a count of 0 then the list is empty
//PARAMETER:No parameter is needed
bool llist::isEmpty()
{
	if (Front == NULL && Rear == NULL && Count == 0) // will check if the front is NULL and if the Rear is NULL and if the count is 0
	{
		return true; // returns true since nothing is in the list if all these conditions are met
	}
	else // after all the checks returns false if none of the conditions are met
	{
		return false;// returns false suggesting elements are found in the list
	}
} // be sure to check all 3 data members

//PURPOSE:The purpose of this function is to display the elements in the list and will display empty if there is nothing in the list. This will create a new pointer to point to the front 
// and then move through the list while printing the elements as it moves through the list.
//PARAMETER:No parameter is needed
void llist::displayAll()
{
	//Nothing is in the list(Speical CASE)
	if (isEmpty()) //Checks if the list is empty
	{
		cout << "[ empty ]" << endl; // if the list is empty it will print out empty
	}
	else //if the list is not empty start the print for the list
	{
		cout << "[ ";
		Node* P = Front; // New P pointer that will point to the front of the list
		while (P != NULL) // Will continue to move until the P reaches the end or reaches NULL
		{
			cout << P->Elem; //Prints the elements that P holds

			cout << ' ';

			P = P->Next; // Move P through the list 
		}

		cout << "]\n";
	}
}
// be sure to display horizontally in [  ] with
// blanks between elements e.g. [ 1 2 3 4 ]
// You MUST use while (P != NULL) loop or you will not get the credit!



//PURPOSE:The purpose of this function is to first check if the list is empty. If the list is empty then there is only going to be one element in the list for rear and front to point too.
// Otherwise it will first create a new node to store the element we are going to add will making the element hold the element from NewNum. Since we are adding to the rear then p's next value can be set to point to rear
// Then by connecting Rear's next value to P and making P be the new rear we are then able to add elements to the rear
//PARAMETER: The parameter this function uses is able to store the element that is going to be added to the rear of the list
void llist::addRear(el_t NewNum)
{
	Node* p = new Node; // creates a new node p 
	p->Elem = NewNum;// Makes the element of the new node to be the value(NewNum)
	p->Next = NULL; // makes the next value of p point to NULL since we are adding to the rear

	//The element to be added is the first one(Speical CASE)
	if (isEmpty()) // check if the element will be the first one to be added
	{
		Front = p; // will make the front point to the new node p
		Rear = p; //Will make the rear point to the new node p
	}
	else
	{
		Rear->Next = p; // uses the rear pointer to point to the next element which we are adding and in this case will be P since it is our new element to be added
		Rear = p; // makes p be the new rear
		//Rear->Elem = NewNum; // makes the rear element be the new one to be added
		//Rear->Next = NULL; // makes the rear's next value point to NULL suggesting we are reaching beyond the list
	}
	Count++;// increase the count of the list

} // comment the 2 cases

//PURPOSE: THe purpose of this function is to add an element to the front by creating a new node and having it store the element we want to add. We first check if its empty which will make the front and rear point to the new element
// .Afterwards we make p's next element connect to the front and then make p the new front element. This allows us to add to the front of the list 
//PARAMETER: The parameter used stores the element that we are going to add to the front of the list 
void llist::addFront(el_t NewNum)
{
	//similar check to add rear
	Node* p = new Node; // creates a new node p 
	p->Elem = NewNum;// Makes the element of the new node to be the value(NewNum)

	//The element to be added is the first one(Speical CASE)
	if (isEmpty()) // check if the element will be the first one to be added
	{
		Front = p; // will make the front point to the new node p
		Rear = p; //Will make the rear point to the new node p
	}
	else // Other elements are already in the list
	{
		p->Next = Front; //connect the p's next element with teh front so it adds to the front of the list
		Front = p; // make p the new front element
	}


	Count++;// increase the count of the list
} // comment the 2 cases

//PURPOSE: The purpose of this function is to first check if the list is empty and if its empty it will throw an underflow exception. Afterwards it will check to see if the element we are deleting is the 
// only element in the list. If the element is the only one in the list it will make the Front and Rear point back to NULL. If the first 2 conditions are not met then it will take the value of the front and store it in 
// old num while also creating a new pointer that points to front's next element. Then it will delete front while making P the new front
//PARAMETER: The paramter uses pass by reference to store the front element into OldNum
void llist::deleteFront(el_t& OldNum)
{
	//Exception case
	if (isEmpty()) // checks if the list is empty
	{
		throw Underflow();// if the list is empty then throw an exception
	}
	//Special CASE: The list will be empty after deleting
	else if (Front == Rear) // We can either check count or in this case we check if the front or rear point to the same position suggesting there is only one item in the list
	{
		OldNum = Front->Elem; // Old Num will store the old value that the front pointer had
		delete Front; // Deleting the front pointer
		Front = NULL; // Since nothing is in the list after deleting the front needs to point to NULL
		Rear = NULL; // Since nothing is in the list after deleting the front needs to point to NULL
	}
	//Regular CASE:Deleting Normally
	else
	{
		OldNum = Front->Elem; // Old Num will store the old value that the front pointer had
		Node* p = Front->Next; //new pointer that will point to fronts next 
		delete Front; // deleting the front element
		Front = p; // Making p the new front element after deleting
	}

	Count--; // Decrement the Count
} // comment the 3 cases

//PURPOSE:The purpose of this function is to first check if the list is empty and if its empty it will throw an underflow exception. Afterwards it will check to see if the element we are deleting is the 
// only element in the list. If the element is the only one in the list it will make the Front and Rear point back to NULL.
// Afterwards we will make a pointer to move through the list and stop before we reach rear so we get the value before and then we 
// store the element into OldNum. After storing we delete the rear and ensure everything connects with each other and the last value's next is set back to null
// This function is similar to the delete front.
//PARAMETER:The parameter is used in order to store the value we are deleting and it uses pass by reference 
void llist::deleteRear(el_t& OldNum)
{
	//Exception case
	if (isEmpty()) // checks if the list is empty
	{
		throw Underflow();// if the list is empty then throw an exception
	}
	//Special CASE: The list will be empty after deleting
	else if (Front == Rear) // We can either check count or in this case we check if the front or rear point to the same position suggesting there is only one item in the list
	{
		OldNum = Rear->Elem; // Old Num will store the old value that the front pointer had
		delete Rear; // Deleting the front pointer
		Front = NULL; // Since nothing is in the list after deleting the front needs to point to NULL
		Rear = NULL; // Since nothing is in the list after deleting the front needs to point to NULL
	}
	else
	{
		Node* p = Front; // stores p as Front
		while (p->Next != Rear) // move p until it reaches the value before the rear
		{
			p = p->Next; // move through the list
		}
		OldNum = Rear->Elem;//Store the rear element
		delete Rear; // delete the rear element
		Rear = p; // make p the new rear pointer
		Rear->Next = NULL; // ensures the next value after rear is set to NULL
	}

	Count--; //decrement list
} // comment the 3 cases


// Utility Function to move a local pointer to the Jth node
void llist::moveTo(int J, Node*& temp)
{  // Note that case1 client does not test this. But it is needed
   // for case 2 so make it work perfectly.  
  // moves temp J-1 times to go to the Jth node (>=1 and <= Count is assumed)   
  // for ( int K = ... ) temp = temp->Next;

	if (J < 1 || J > Count) // J needs to stay between 1 and the count 
	{
		throw OutOfRange(); //if not in the range it will throw an exception
	}
	temp = Front; //make the temp pointer be the front

	for (int K = 1; K < J; K++) //Since we start at the front we need to start K at 1
	{
		temp = temp->Next; //move temp through the list
	}


}




/* --- harder ones for case 2 and 3 follow -- */


//PURPOSE:The purpose of this function is to first check the conditions to ensure it is in range of the linked list.If its not in range then it will throw an OUT OF RANGE Exception.
// After checking the exception it will begin to check if the index we are looking for is either in the rear or in the front of the list,depending on which condition it is the correct call will be made
// After checking the front and rear it will do the regular case in order to delete in the middle.
//PARAMETER: The parameter of this function is used in order to store the old element of the linked list or the element that will be deleted
void llist::deleteIth(int I, el_t& OldNum)
{
	//Node* current = NULL;
	//  Node* previous = NULL;
	  //ERROR CASE
	if (I > Count || I < 1) // if the Index is greater than the count or less than 1 then the element is out of range 
	{
		throw OutOfRange(); // throw an exception to catch out of range 
	}
	Node* current = NULL;
	Node* previous = NULL;

	//SPECIAL CASE
	if (I == 1) // Checks for front element
	{
		deleteFront(OldNum); // Calls delete front in order to delete the element
	}
	else if (I == Count)//checks for rear
	{
		deleteRear(OldNum);
	}
	//REGULAR CASE
	else
	{
		moveTo(I, current);//Move to the index of I
		OldNum = current->Elem;//Have Old Num store the element into old num

		moveTo(I - 1, previous); // Grab the previous value of the list behind I 

		previous->Next = current->Next; // connects the previous node with the next value of current


		delete current;
		Count--;
	}
	//Count--;
} // must use moveTo to move local pointers. Be sure to comment to which node you are moving them. Do not forget to set OldNum.  

//PURPOSE: THe purpose of this function is to find a spot I and insert a new number into the function. This is done by first checking if the index is in the range of the list while also checking if the element to be inserted 
// is in the rear or if its in the front. After checking these areas it will move onto the regular case where it will keep track of the previous and current node while also linking the nodes to the new element to be added
//PARAMETER: The parameters in this function takes the index on where the value will be inserted in the linked list. The second parameter is used in order to store the new value that will be added to the list
void llist::insertIth(int I, el_t newNum)
{
	//Node* current = previous->next;
	//Node* previous = NULL;
	  //ERROR CASE
	//cout << "Test " << I  << " " << "Count " << Count << endl; 
	if (I< 1 || I > Count + 1) // if the Index is greater than the count or less than 1 then the element is out of range 
	{
		throw OutOfRange(); // throw an exception to catch out of range 
	}
	//SPECIAL CASE
	//	cout << "SPecial Case" << endl;
	if (I == 1) // Checks for front element
	{
		addFront(newNum); // Calls delete front in order to delete the element
		//Count++;
	}
	else if (I == Count + 1)//checks for rear
	{
		addRear(newNum);
		//Count++;
	}
	//REGULAR CASE
	else {
		//moveTo(I,current);//Move to the index of I

		Node* NewElem = new Node;
		NewElem->Elem = newNum; // new node to store the new element to be added
		Node* previous = NULL;
		Node* current = NULL;

		moveTo(I - 1, previous); // Stores the previous value of I
		moveTo(I, current);

		previous->Next = NewElem;
		NewElem->Next = current;
		Count++;
	}
	//Count++;
} // must use moveTo to move local pointers. Be sure to comment to which node you are moving them.

//PURPOSE: THe purpose of this function is too take a linked list and create a copy of the list, this helps create  a deep copy of the list This is done by first initalizing the data memebers.
// After the initaliziation it would first check if the list is empty and will return nothing since there is nothing to copy in the list. After the check it will create a 
// new node to point to the front of the original list and then moves through the list while adding the newly added elements to *this effectively creating a new list
//PARAMETER: The purpose of this function is to pass a list to be copied and is considered to be the copy constructor of the function
llist::llist(const llist& Original)
{
	//Initalize the data members
	this->Front = NULL;
	this->Rear = NULL;
	this->Count = 0;

	if (Original.Count == 0)// check if the list to copy from is empty
	{
		return;
	}


	Node* p = Original.Front;//Make the pointer p point to the original linked list front

	while (p != NULL)
	{
		this->addRear(p->Elem); // take elements from the original list and add it to this
		p = p->Next; // moves P through the list
	}


}// use my code

//PURPOSE:The purpose of this function is to overload the = sign in order to allow L1 = L2 which will create a copy of the function L1.This will make the OtherOne have the same
// data to the original list
//PARAMETER: This parameter takes the OtherOne list and creates a copy using the original list and sending it to the otherOne list. This overload function helps us to use 
// L1 = L2 without causing any issies in the program. This parameter can be used as an overload function
llist& llist::operator=(const llist& OtherOne)
{
	el_t x;
	if (this != &OtherOne) // checks if the lists are not equal to each other
	{
		while (!this->isEmpty()) //clears the list
		{
			this->deleteRear(x);
		}

		Node* p = OtherOne.Front;//Make the pointer p point to the original linked list front

		while (p != NULL)
		{
			this->addRear(p->Elem); // take elements from the original list and add it to this
			p = p->Next; // moves P through the list
		}
	}

	return *this;
} // use my code