/*
Bradley Gallardo
CS41
Term Project I - Polynomial
Header File
*/

#ifndef POLYLIST_H													//To use polyList.h
#define POLYLIST_H													//To use polyList.h
#include <iostream>													//To use input/output streams						
#include <cmath>													//To use pow()
using namespace std;												//To use standard scope 

template <class T>
class PolyList {
private:
	struct ListNode {
		ListNode *next;												//To point to next node
		T base;														//To hold base value
		int power;													//To hold nth power of base value
	};
	ListNode *head;													//To point to beginning of list

public:

	//Constructor
	PolyList();

	//Copy Constructor
	PolyList(PolyList &);

	//Destructor
	~PolyList();

	//PolyList operations
	void appendNode(T, int);										//To append node to end of list
	void insertNode(T, int);										//To insert node in order from greatest to least
	void deleteNode(T);												//To delete desired node
	void displayList() const;										//To display entire list
	void simplifyList();											//To simplify list by combining like terms
	T solveFor(T);													//To solve for a specific term

	//Operator overloads
	PolyList *operator=(PolyList &);								//To use polynomial assignment
	PolyList *operator+(PolyList &);								//To use polynomial addition
	PolyList *operator-(PolyList &);								//To use polynomial subtraction
	PolyList *operator*(PolyList &);								//To use polynomial multiplication
	template <class T>
	friend ostream &operator<<(ostream &, PolyList<T> &);			//To use polynomial cout
	template <class T>
	friend istream &operator>>(istream &, PolyList<T> &);			//To use polynomial cin


};
/*-------------------------------------------------------------------------------------------------------------*\
|	Availiable windows console text colors																		|
|		(D = Dark, B = Bright)																					|
\*-------------------------------------------------------------------------------------------------------------*/
enum Colors {
	BLUE = 1, GREEN, CYAN, RED, PURPLE, DYELLOW, WHITE, GREY, BBLUE, BGREEN, BCYAN, BRED, PINK, YELLOW, BWHITE
};											


/*-------------------------------------------------------------------------------------------------------------*\
|	Function prototype of function defined in main() of term_project_I_polynomial.cpp							|
|		Parameters - (Colors c --> to selct desired user's color from Colors enum)								|
\*-------------------------------------------------------------------------------------------------------------*/
void set_color(Colors);

/*
______________________________________________________________________________________________________________________________________
/*											---------Function Defintions----------														*\
\*______________________________________________________________________________________________________________________________________*/


/*-------------------------------------------------------------------------------------------------------------*\
|	Constructor																									|
|		Parameters - (NULL)																						|
\*-------------------------------------------------------------------------------------------------------------*/
template <class T>
PolyList<T>::PolyList() { // <0>

	//Set head of PolyList to NULL (list is empty) 
	head = nullptr; 

} // <0> PolyList()

/*-------------------------------------------------------------------------------------------------------------*\
|	Copy Constructor																							|
|		Parameters - (PolyList rhs --> copies entire PolyList from right hand side to left hand side PolyList)	|																						|
\*-------------------------------------------------------------------------------------------------------------*/
template <class T>
PolyList<T>::PolyList(PolyList &rhs) { // <0>
	ListNode *rhsPtr = nullptr;
	ListNode *lhsPtr = nullptr;
	ListNode *nextNode;

	rhsPtr = rhs.head;

	while (rhsPtr) { // <1>


		nextNode = new ListNode;
		nextNode->base = rhsPtr->base;
		nextNode->power = rhsPtr->power;
		nextNode->next = nullptr;

		if (!head) {
			
			head = nextNode;
			
			lhsPtr = head;

		}
		else {

			lhsPtr->next = nextNode;

			lhsPtr = lhsPtr->next;

		}

		rhsPtr = rhsPtr->next;

	} // <1> while (rhsPtr)


	lhsPtr = nullptr;

} // <0> PolyList()


/*-------------------------------------------------------------------------------------------------------------*\
|	Destructor																									|
|		Parameters - (NULL)																						|
\*-------------------------------------------------------------------------------------------------------------*/
template <class T>
PolyList<T>::~PolyList() { // <0>
	ListNode *nodePtr = nullptr;
	ListNode *nextNode = nullptr;

	//Start at beginning of list
	nodePtr = head;

	//Traverse list until end
	while (nodePtr != nullptr) { // <1>
		
		//Point to node after current node
		nextNode = nodePtr->next;

		//Delete current node
		delete nodePtr;

		//Move to next node to be deleted
		nodePtr = nextNode;

	} // <1> while (nodePtr != nullptr)

} // <0> ~PolyList()


/*-------------------------------------------------------------------------------------------------------------*\
|	Allocate new node, traverse to end of list, and then append node											|
|		Parameters - (T coefficient --> used as base of PolyList, int exponent --> used as power of PolyList)	| 
\*-------------------------------------------------------------------------------------------------------------*/
template <class T>
void PolyList<T>::appendNode(T coeff, int exp) { // <0>
	ListNode *newNode;												//To point to a new node
	ListNode *nodePtr = nullptr;									//To traverse list

	//Allocate a new node and store its base and power
	newNode = new ListNode;
	newNode->base = coeff;
	newNode->power = exp;
	newNode->next = nullptr;

	//If list is empty
	if (!head)														
		head = newNode;

	//List is not empty
	else { // <1>
		//Start at beginning of list
		nodePtr = head;												

		//Traverse to end of list
		while (nodePtr->next)
			nodePtr = nodePtr->next;

		//Append node to end of list
		nodePtr->next = newNode;		

	} // <1> else (list is not empty)

} // <0> appendNode()


/*-------------------------------------------------------------------------------------------------------------*\
|	Allocate new node, traverse list until end or power that is less than new node, and add node before it		|
|		Parameters - (T coefficient --> used as base of PolyList, int exponent --> used as power of PolyList)	|
\*-------------------------------------------------------------------------------------------------------------*/
template <class T>
void PolyList<T>::insertNode(T coeff, int exp) { // <0>
	ListNode *newNode;												//To point to a new node
	ListNode *nodePtr = nullptr;									//To traverse list
	ListNode *prevNode = nullptr;									//To point to the previous node while traverse list

	//Allocate a new node and store its base and power
	newNode = new ListNode;
	newNode->base = coeff;
	newNode->power = exp;
	newNode->next = nullptr;

	//If list is empty
	if (!head)														
		head = newNode;

	//If list is not empty
	else { // <1>

		//Start at beginning of list
		nodePtr = head;												

		//Traverse list until end or power that is less than exponent
		while (nodePtr != nullptr && nodePtr->power > exp) {
			prevNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		//If inserting before first node
		if (prevNode == nullptr) {
			head = newNode;
			newNode->next = nodePtr;
		}
		//Else insert after previous node
		else {
			prevNode->next = newNode;
			newNode->next = nodePtr;
		}

	} // <1> else (list is not empty)

} // <0> insertNode()


/*-------------------------------------------------------------------------------------------------------------*\
|	Search for desired node, move pointers to skip desired node, and then delete node							|
|		Parameters - (T search --> coefficent value to find on a polyList node and delete)						|
\*-------------------------------------------------------------------------------------------------------------*/
template <class T>
void PolyList<T>::deleteNode(T search) { // <0>
	ListNode *nodePtr<T> = nullptr;									//To traverse list
	ListNode *prevNode<T> = nullptr;								//To point to the previous node while traverse list

	//If list is empty, do nothing
	if (!head)
		return;

	//If desired node is the first node
	if (head->base == search) {
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}

	//Desired node is not the first node
	else { // <1>
		//Start at beginning of list
		nodePtr = head;												
			
		//Traverse through list until end or search is found
		while (nodePtr != nullptr && nodePtr->base != search) {
			prevNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		//Move pointers and delete node
		if (nodePtr) {
			prevNode->next = nodePtr->next;
			delete nodePtr;
		}

	} // <1> else (Desired node is not the first node)

} // <0> deleteNode()


/*-------------------------------------------------------------------------------------------------------------*\
|	Traverse list and display each node																			|
|		Parameters - (NULL)																						|
\*-------------------------------------------------------------------------------------------------------------*/
template <class T>
void PolyList<T>::displayList() const { // <0>
	ListNode *nodePtr = nullptr;									//To traverse through list

	//Start at beginning of list
	nodePtr = head;													

	//Traverse until end of list
	while (nodePtr) { // <1>

		//If displaying first node
		if (nodePtr == head) {

			//If first value is negative
			if (nodePtr->base < 0)
				cout << "-" << abs(nodePtr->base) << "x^" << nodePtr->power << " ";
			//If first value is positive
			else
				cout << nodePtr->base << "x^" << nodePtr->power << " ";

		}

		//Displaying rest of list
		else {
			//If value is negative
			if (nodePtr->base < 0)
				cout << "- " << abs(nodePtr->base) << "x^" << nodePtr->power << " ";
			//If value is positive
			else
				cout << "+ " << nodePtr->base << "x^" << nodePtr->power << " ";

		}

		//Switch to next node
		nodePtr = nodePtr->next;

	} // <1> while (nodePtr)

} // <0> displayList()


/*-------------------------------------------------------------------------------------------------------------*\
|	Traverse list and combine like terms (nodes with the power)													|
|		Parameters - (NULL)																						|
\*-------------------------------------------------------------------------------------------------------------*/
template <class T>
void PolyList<T>::simplifyList() { // <0>
	ListNode *nodePtr = nullptr;									//To traverse through list
	ListNode *cursor = nullptr;										//To compare with nodePtr
	ListNode *prevNode = nullptr;									//To point to previous node
	ListNode *newNode;												//To point to a new node

	//Allocate a new node and move pointers
	newNode = new ListNode;
	cursor = head;
	nodePtr = cursor->next;

	while (cursor != nullptr) { // <1>

		while (nodePtr != nullptr) { // <2>

			//If there are nodes with the same power (like terms)
			if (nodePtr->power == cursor->power) { // <3>

				//If there are no more nodes with the same power,
				// then alloacte a new node
				if (newNode->power != cursor->power)
					newNode = new ListNode;

				//If there are still other nodes with the same power (like terms),
				// then combine like terms
				newNode->base = cursor->base + nodePtr->base;
				newNode->power = cursor->power;
				newNode->next = nodePtr->next;

				//To make sure newNode doesn't get deleted
				if (cursor != newNode)
					delete cursor;

				//Delete term that was added to new node
				delete nodePtr;

				//If first node is moving pointers
				if (prevNode == nullptr)
					head = newNode;
				else
					prevNode->next = newNode;

				//Set cursor to new node
				cursor = newNode;

			} // <3> if (nodePtr->power == cursor->power)

			//If comparing nodes are not like terms
			else {
				//Move along to next nodes
				prevNode = cursor;
				cursor = cursor->next;
			}

			//Move to node after cursor
			nodePtr = cursor->next;

		} // <2> while (nodePtr != nullptr)

		cursor = nullptr;

	} // <1> while (cursor != nullptr)

	prevNode = nullptr;

} // <0> simplifyList()


/*-------------------------------------------------------------------------------------------------------------*\
|	Evaluates polyList for a nth term and returns that value													|
|		Parameters - (T nth --> a value used to solve PolyList by)												|
\*-------------------------------------------------------------------------------------------------------------*/
template <class T>
T PolyList<T>::solveFor(T nth) { // <0>
	T total;														//To hold value solved for by nth term
	ListNode *nodePtr;												//To traverse through list
	ListNode *newNode;												//To point to a new node
	PolyList *newList;												//To point to a new list

	//Allocate new node and new list
	newNode = new ListNode;
	newList = new PolyList;

	//Start nodePtr at head
	nodePtr = head;

	while (nodePtr != nullptr) { // <1>

		//Find value for evaluating for each node
		total = pow(nth, nodePtr->power) * nodePtr->base;

		//Set info to newNode
		newNode->base = total;
		newNode->power = 0;
		newNode->next = nullptr;

		//Append newNode to newList
		newList->appendNode(newNode->base, newNode->power);

		//Move to next node
		nodePtr = nodePtr->next;

	} // <1> while (nodePtr != nullptr)

	//Start nodePtr at head of newList 
	nodePtr = newList->head;
	total = 0;

	//Accumulate total
	while (nodePtr != nullptr) {
		total += nodePtr->base;

		nodePtr = nodePtr->next;
	}

	//Return total of solving for nth term
	return total;

} // <0> solveFor() 


/*-------------------------------------------------------------------------------------------------------------*\
|	Assignment Operator= Overload																				|
|		Parameters - (PolyList rhs --> a PolyList on the right hand side of operator=, to be copied to left		|
|		 hand side PolyList)																					|
\*-------------------------------------------------------------------------------------------------------------*/
template <class T>
PolyList<T> *PolyList<T>::operator=(PolyList &rhs) {
	ListNode *rhsPtr = nullptr;
	ListNode *lhsPtr = nullptr;
	ListNode *nextNode;

	rhsPtr = rhs.head;

	if (head) {
		this->~PolyList();
		head = nullptr;
	}

	while (rhsPtr) { // <1>

		nextNode = new ListNode;
		nextNode->base = rhsPtr->base;
		nextNode->power = rhsPtr->power;
		nextNode->next = nullptr;

		if (!head) {

			head = nextNode;

			lhsPtr = head;

		}
		else {

			lhsPtr->next = nextNode;

			lhsPtr = lhsPtr->next;

		}

		rhsPtr = rhsPtr->next;

	} // <1> while (rhsPtr)


	lhsPtr = nullptr;

	return this;
}


/*-------------------------------------------------------------------------------------------------------------*\
|	Addition Operator+ Overload																					|
|		Parameters - (PolyList rhs --> a PolyList on the right hand side of operator+, to add with left hand	|
|		 side PolyList)																							|
\*-------------------------------------------------------------------------------------------------------------*/
template <class T>
PolyList<T> *PolyList<T>::operator+(PolyList &rhs) {
	ListNode *lhsPtr = nullptr;										//To traverse through left hand side list
	ListNode *rhsPtr = nullptr;										//To traverse through right hand side list
	ListNode *tempNode = nullptr;									//To point to temp node
	ListNode *newNode = nullptr;									//To point to a new node
	PolyList *newList = nullptr;									//To point to a new list

	//Allocate a new node, a temp node, and a new list 
	newNode = new ListNode;
	tempNode = new ListNode;
	newList = new PolyList;

	//Start pointers at head of lists
	lhsPtr = head;
	rhsPtr = rhs.head;

	//Loop until both pointers are null
	while (lhsPtr != nullptr && rhsPtr != nullptr) { // <1>

		//If lhs' power and rhs' power are the same (they are like terms)
		if (lhsPtr->power == rhsPtr->power) { // <2>

			//Set newNode base to sum of lhs and rhs
			newNode->base = lhsPtr->base + rhsPtr->base;
			//Set newNode power to lhs power
			newNode->power = lhsPtr->power;
			newNode->next = nullptr;

			//If at the end of both lists
			if (lhsPtr->next == nullptr && rhsPtr->next == nullptr) {
				//Set both pointers to nullptr
				lhsPtr = nullptr;
				rhsPtr = nullptr;
			}

			//If lhs is at the end of list 
			// and rhs is not at the end of list
			else if (lhsPtr->next == nullptr && rhsPtr->next != nullptr) {

				//Set rhsPtr to next node
				rhsPtr = rhsPtr->next;

				//Make a temp node to add
				tempNode->base = 0;
				tempNode->power = rhsPtr->power;
				tempNode->next = nullptr;

				//Set lhsPtr to temp node
				lhsPtr = tempNode;

			}

			//If rhs is at the end of list 
			// and lhs is not at the end of list
			else if (rhsPtr->next == nullptr && lhsPtr->next != nullptr) {
				//Set lhsPtr to next node
				lhsPtr = lhsPtr->next;

				//Make a temp node to add
				tempNode->base = 0;
				tempNode->power = lhsPtr->power;
				tempNode->next = nullptr;

				//Set rhsPtr to temp node
				rhsPtr = tempNode;
			}

			//If there rhsPtr and lhsPtr are not like terms
			else {
				rhsPtr = rhsPtr->next;
				lhsPtr = lhsPtr->next;
			}

		} // <2> if (lhsPtr->power == rhsPtr->power)

		//If lhs' power is greater than rhs' power
		else if (lhsPtr->power > rhsPtr->power) { // <3>

			//Set newNode as lhsPtr
			newNode->base = lhsPtr->base;
			newNode->power = lhsPtr->power;
			newNode->next = nullptr;

			//If lhsPtr is at end of list
			if (lhsPtr->next == nullptr) {
				//Make a temp node to add
				tempNode->base = 0;
				tempNode->power = rhsPtr->power;
				tempNode->next = nullptr;

				//Set lhsPtr to temp node
				lhsPtr = tempNode;
			}
			else
				lhsPtr = lhsPtr->next;

		} // <3> else if (lhsPtr->power > rhsPtr->power)

		//If lhs' power is less than rhs' power
		else if (lhsPtr->power < rhsPtr->power) { // <4>

			//Set newNode as rhsPtr
			newNode->base = rhsPtr->base;
			newNode->power = rhsPtr->power;
			newNode->next = nullptr;

			//If rhsPtr is at end of list
			if (rhsPtr->next == nullptr) {
				//Make a temp node to add
				tempNode->base = 0;
				tempNode->power = lhsPtr->power;
				tempNode->next = nullptr;

				//Set rhsPtr to temp node
				rhsPtr = tempNode;

			}
			else
				rhsPtr = rhsPtr->next;

		} // <4> else if (lhsPtr->power < rhsPtr->power)

		else
			cout << "I dont know how to add this..." << endl;

		//Insert newNode to newList
		newList->insertNode(newNode->base, newNode->power);

	} // <1> while (lhsPtr != nullptr && rhsPtr != nullptr)

	//Return newList with sum of lhs and rhs lists 
	return newList;

} // <0> operator+()


/*-------------------------------------------------------------------------------------------------------------*\
|	Subtraction Operator- Overload																				|
|		Parameters - (PolyList rhs --> a PolyList on the right hand side of operator-, to subtract with left	|
|		hand side polyList)																						|
\*-------------------------------------------------------------------------------------------------------------*/
template <class T>
PolyList<T> *PolyList<T>::operator-(PolyList &rhs) { // <0>
	ListNode *lhsPtr = nullptr;										//To traverse through left hand side list
	ListNode *rhsPtr = nullptr;										//To traverse through right hand side list
	ListNode *tempNode = nullptr;									//To point to temp node
	ListNode *newNode = nullptr;									//To point to a new node
	PolyList *newList = nullptr;									//To point to a new list

	//Allocate a new node, a temp node, and a new list
	newNode = new ListNode;
	tempNode = new ListNode;
	newList = new PolyList;

	//Start pointers at head of lists
	lhsPtr = head;
	rhsPtr = rhs.head;

	//Loop until both pointers are null
	while (lhsPtr != nullptr && rhsPtr != nullptr) { // <1>

		//If lhs' power and rhs' power are the same (there are like terms)
		if (lhsPtr->power == rhsPtr->power) { // <2>

			//Set newNode base to difference of lhs and rhs
			newNode->base = lhsPtr->base + (-1 * rhsPtr->base);
			//Set newNode power to lhs power
			newNode->power = lhsPtr->power;
			newNode->next = nullptr;

			//If at the end of both lists
			if (lhsPtr->next == nullptr && rhsPtr->next == nullptr) {
				//Set both pointers to nullptr
				lhsPtr = nullptr;
				rhsPtr = nullptr;
			} 

			//If lhs is at the end of list 
			// and rhs is not at the end of list
			else if (lhsPtr->next == nullptr && rhsPtr->next != nullptr) {

				//Set rhsPtr to next node
				rhsPtr = rhsPtr->next;

				//Make a temp node to subtract
				tempNode->base = 0;
				tempNode->power = rhsPtr->power;
				tempNode->next = nullptr;

				//Set lhsPtr to temp node
				lhsPtr = tempNode;
			}

			//If rhs is at the end of list 
			// and lhs is not at the end of list
			else if (rhsPtr->next == nullptr && lhsPtr->next != nullptr) {
				//Set lhsPtr to next node
				lhsPtr = lhsPtr->next;

				//Make a temp node to subtract
				tempNode->base = 0;
				tempNode->power = lhsPtr->power;
				tempNode->next = nullptr;

				//Set rhsPtr to temp node
				rhsPtr = tempNode;
			}

			//If there rhsPtr and lhsPtr are not like terms
			else {
				rhsPtr = rhsPtr->next;
				lhsPtr = lhsPtr->next;
			}

		} // <2> if (lhsPtr->power == rhsPtr->power)

		//If lhs' power is greater than rhs' power
		else if (lhsPtr->power > rhsPtr->power) { // <3>
			//Set newNode as lhsPtr
			newNode->base = lhsPtr->base;
			newNode->power = lhsPtr->power;
			newNode->next = nullptr;

			//If lhsPtr is at end of list
			if (lhsPtr->next == nullptr) {
				//Make a temp node to subtract
				tempNode->base = 0;
				tempNode->power = rhsPtr->power;
				tempNode->next = nullptr;

				//Set lhsPtr to temp node
				lhsPtr = tempNode;
			}
			else
				lhsPtr = lhsPtr->next;

		} // <3> else if (lhsPtr->power > rhsPtr->power)

		//If lhs' power is less than rhs' power
		else if (lhsPtr->power < rhsPtr->power) { // <4>
			//Set newNode as rhsPtr
			newNode->base = rhsPtr->base;
			newNode->power = rhsPtr->power;
			newNode->next = nullptr;

			//If rhsPtr is at end of list
			if (rhsPtr->next == nullptr) {
				//Make a temp node to subtract
				tempNode->base = 0;
				tempNode->power = lhsPtr->power;
				tempNode->next = nullptr;

				//Set rhsPtr to temp node
				rhsPtr = tempNode;
			} // !else if (lhsPtr->power < rhsPtr->power)
			else
				rhsPtr = rhsPtr->next;

		} // <4> else if (lhsPtr->power < rhsPtr->power)

		else
			cout << "I dont know how to add this..." << endl;

		//Insert newNode to newList
		newList->insertNode(newNode->base, newNode->power);

	} // <1> while (lhsPtr != nullptr && rhsPtr != nullptr)

	//Return newList with difference of lhs and rhs lists 
	return newList;

} // <0> operator-()


/*-------------------------------------------------------------------------------------------------------------*\
|	Multiplication Operator* Overload																			|
|		Parameters - (PolyList rhs --> a PolyList on the right hand side of operator*, to multiply with	left	|  
|		 hand side polyList)																					|
\*-------------------------------------------------------------------------------------------------------------*/
template <class T>
PolyList<T> *PolyList<T>::operator*(PolyList &rhs) { // <0>
	ListNode *lhsPtr = nullptr;										//To traverse through left hand side list
	ListNode *rhsPtr = nullptr;										//To traverse through right hand side list
	ListNode *newNode;												//To point to a new node
	PolyList *newList;												//To point to a new list

	//Allocate a new node and a new list,
	newNode = new ListNode;
	newList = new PolyList;

	//Start at head of lhsPtr
	lhsPtr = head;

	//Loop until end of lhs list
	while (lhsPtr != nullptr) { // <1>

		//Start at head of rhsPtr
		rhsPtr = rhs.head;

		//Loop until end of rhs list
		while (rhsPtr != nullptr) { // <2>

			//Set product of bases to newNode
			newNode->base = lhsPtr->base * rhsPtr->base;
			//Set addition of powers to newNode
			newNode->power = lhsPtr->power + rhsPtr->power;
			newNode->next = nullptr;

			//Insert node
			newList->insertNode(newNode->base, newNode->power);

			//Set rhsPtr to next node
			rhsPtr = rhsPtr->next;

		} // <2> while (rhsPtr != nullptr)

		//Set lhsPtr to next node
		lhsPtr = lhsPtr->next;

	} // <1> while (lhsPtr != nullptr)

	//Return newList with product of lhs and rhs lists
	return newList;

} // <0> operator*() 


/*-------------------------------------------------------------------------------------------------------------*\
|	Insertion Operator<< Overload																				|
|		Parameters - (ostream operator<< --> to insert console, PolyList<T> rhs --> a polyList on the right		|
|		 hand side of operator<< to be displayed)																|
\*-------------------------------------------------------------------------------------------------------------*/
template <class T>
ostream &operator<<(ostream &stream, PolyList<T> &rhs) { // <0>
	
	//Display list
	rhs.displayList();
	
	//Returning stream allows for multiple couts 
	return stream;

} // <0> operator<<()


/*-------------------------------------------------------------------------------------------------------------*\
|	Extraction Operator>> Overload																				|
|		Parameters - (istream stream --> to extract user's input, PolyList<T> rhs --> a polyList on the right	|
|		 hand side of operator>> to hold user's coefficient and exponent in a node)								|
\*-------------------------------------------------------------------------------------------------------------*/
template <class T>
istream &operator>>(istream &stream, PolyList<T> &rhs) { // <0>
	T coeff;														//To hold user's coefficent
	int exp;														//To hold user's exponenet

	do {
		//Prompt user for coefficent and exponent until user enters (-9 -9)
		set_color(GREEN);
		cout << "\t\t Please enter two numbers seperated by a space." << endl;

		set_color(CYAN);
		cout << "\t\t  > ";
		cin >> coeff >> exp;
		cout << endl;

		//Insert node if coeff and exp are not equal to -9 and -9, respectively
		if (coeff != -9 && exp != -9)
			rhs.insertNode(coeff, exp);

	} while (coeff != -9 && exp != -9);
	cout << endl;

	//Returning stream allows for chains of cins ( e.g. cin >> a >> b; )
	return stream;

} // <0> operator>>() 


#endif // <POLYLIST_H>
