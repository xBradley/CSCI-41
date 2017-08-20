#include <iostream>
#include <cstdlib>
#include "IntBinaryTree.h"
using namespace std;

//-----Function Prototypes-----//
void assignment_test();
void copy_test();
char repeat();

int main(){
	char again;

	do
	{
	cout << "*****************************************************************************" << endl << endl;

	assignment_test();

	copy_test();

	again = repeat();

	} while (again == 'Y');

	cout << endl;
	system("pause");
}

//-----Function Definititons-----//

//Makes a binary tree and uses a assignement operator to copy 
void assignment_test(){
	IntBinaryTree main,		//Main-Tree 
		sub;				//Sub-Tree
	int input;				//To hold user's integers 

	//Adds three nodes to main tree
	cout << "Assignemnt Operator Overload" << endl;
	cout << "\tEnter an integer to add to Main-Tree" << endl;
	for (int i = 0; i < 3; i++){
		cout << "\t\tNumber " << i + 1 << ": ";
		cin >> input;

		main.insertNode(input);
	}
	
	//Display main tree
	cout << endl << "\t\t\tMain-Tree (in-order)" << endl;
	main.displayInOrder();
	cout << endl;

	//Assign main tree to sub tree
	sub = main;

	//Display sub tree
	cout << "\t\t\tSub-Tree (in-order)" << endl;
	sub.displayInOrder();
	cout << endl;
}

//Makes a binary tree and uses a copy constructor to copy
void copy_test(){
	IntBinaryTree main;		//Main-Tree 
	int input;				//To hold user's integers 

	//Adds three nodes to main tree
	cout << "Copy Constructor" << endl;
	cout << "\tEnter an integer to add to Main-Tree" << endl;
	for (int i = 0; i < 3; i++){
		cout << "\t\tNumber " << i + 1 << ": ";
		cin >> input;

		main.insertNode(input);
	}

	//Display main tree
	cout << endl << "\t\t\tMain-Tree (in-order)" << endl;
	main.displayInOrder();
	cout << endl;

	//Copy main tree to sub tree
	IntBinaryTree sub(main);

	//Display sub tree
	cout << "\t\t\tSub-Tree (in-order)" << endl;
	sub.displayInOrder();
	cout << endl;
}

//Promts user if they want to run the program again
char repeat() {
	char input; //To hold user's answer

	cout << endl << "Do you want try this again?"
		<< endl << " > ";
	cin >> input;

	if (isalpha(input))						//Edge Case: only alphas
		input = toupper(input);				//Edge Case: only uppercases

											//Validation loop --input may only be either 'Y' or 'N'--
	while (input != 'Y' && input != 'N') {

		std::cout << "\tPlease enter either Y or N" << std::endl << "\t > ";
		std::cin >> input;

		if (isalpha(input))					//Edge Case: only alphas
			input = toupper(input);			//Edge Case: only uppercases

		if (input == 'Y' || input == 'N') {	//If input is 'Y' or 'N', return input
			cout << endl << endl;
			return input;
		}
	}

	cout << endl << endl;
	return input;
}

//-----Test Cases-----//
/*
*****************************************************************************

Assignemnt Operator Overload
        Enter an integer to add to Main-Tree
                Number 1: 5
                Number 2: 10
                Number 3: 15

                        Main-Tree (in-order)
                        5
                        10
                        15

                        Sub-Tree (in-order)
                        5
                        10
                        15

Copy Constructor
        Enter an integer to add to Main-Tree
                Number 1: 90
                Number 2: 23
                Number 3: 3

                        Main-Tree (in-order)
                        3
                        23
                        90

                        Sub-Tree (in-order)
                        3
                        23
                        90


Do you want try this again?
 > y


*****************************************************************************

Assignemnt Operator Overload
        Enter an integer to add to Main-Tree
                Number 1: 90
                Number 2: 23
                Number 3: 0

                        Main-Tree (in-order)
                        0
                        23
                        90

                        Sub-Tree (in-order)
                        0
                        23
                        90

Copy Constructor
        Enter an integer to add to Main-Tree
                Number 1: 29
                Number 2: 3
                Number 3: 1

                        Main-Tree (in-order)
                        1
                        3
                        29

                        Sub-Tree (in-order)
                        1
                        3
                        29


Do you want try this again?
 > y


*****************************************************************************

Assignemnt Operator Overload
        Enter an integer to add to Main-Tree
                Number 1: 1
                Number 2: 2
                Number 3: 3

                        Main-Tree (in-order)
                        1
                        2
                        3

                        Sub-Tree (in-order)
                        1
                        2
                        3

Copy Constructor
        Enter an integer to add to Main-Tree
                Number 1: 4
                Number 2: 5
                Number 3: 6

                        Main-Tree (in-order)
                        4
                        5
                        6

                        Sub-Tree (in-order)
                        4
                        5
                        6


Do you want try this again?
 > n



Press any key to continue . . .
*/