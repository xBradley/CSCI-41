/*
Bradley Gallardo
CS41
Lab 09 Sorted Linked List
This program creates a linked list and sorts it from least to greatest 
*/
#include "LinkedList.h"				//To use linked lists
#include <iostream>					//To use input/output streams
#include <cstdlib>					//To usse system("pause")
#include <string>					//To use strings
using namespace std;

int main() {
	LinkedList<int> iList;			//To hold integer list 
	LinkedList<double> dList;		//To hold double list
	LinkedList<string> sList;		//To holld string list

	int iInput;						//To hold user's integer input
	double dInput;					//To hold user's double input
	string sInput;					//To hold user's string input

	int choice;						//To hold user's menu choice

	do {							//1. repeats menu 

		//Prompt menu and get input
		cout << "***************************************************************" << endl << endl;
		cout << "Please select a data type to create a linked list with" << endl
			<< "\t1. Integars" << endl
			<< "\t2. Doubles" << endl
			<< "\t3. Strings" << endl
			<< "\t4. Quit" << endl
			<< "\t > ";
		cin >> choice;

		switch (choice) {			//2. Menu choices
		case 1:						//If integers

			cout << "\t\tEnter five integars" << endl;

			//Get input and append to list
			for (int i = 0; i < 5; i++) {
				cout << "\t\t " << i + 1 << ". ";
				cin >> iInput;

				iList.appendNode(iInput);
			}

			//Display unsorted list
			cout << endl << "\t\t\tUnsorted List" << endl
				<< "\t\t\t  ";
			iList.displayList();
			cout << endl << endl;

			//Sort list
			iList.sortList();

			//Display sorted list
			cout << "\t\t\tSorted List" << endl
				<< "\t\t\t  ";
			iList.displayList();
			cout << endl << endl;

			//Destroy list
			iList.~LinkedList();

			break;

		case 2:						//If doubles

			cout << "\t\tEnter five doubles" << endl;

			//Get input and append to list
			for (int i = 0; i < 5; i++) {
				cout << "\t\t " << i + 1 << ". ";
				cin >> dInput;

				dList.appendNode(dInput);
			}

			//Display unsorted list
			cout << endl << "\t\t\tUnsorted List" << endl
				<< "\t\t\t  ";
			dList.displayList();
			cout << endl << endl;

			//Sort list
			dList.sortList();

			//Display sorted list
			cout << "\t\t\tSorted List" << endl
				<< "\t\t\t  ";
			dList.displayList();
			cout << endl << endl;

			//Destroy list
			dList.~LinkedList();

			break;

		case 3:						//If strings
			cin.ignore();
			cout << "\t\tEnter five strings" << endl;

			//Get input and append to list
			for (int i = 0; i < 5; i++) {
				cout << "\t\t " << i + 1 << ". ";
				getline(cin, sInput);

				sList.appendNode(sInput);
			}

			//Display unsorted list
			cout << endl << "\t\t\tUnsorted List" << endl
				<< "\t\t\t  ";
			sList.displayList();
			cout << endl << endl;

			//Sort list
			sList.sortList();

			//Display sorted list
			cout << "\t\t\tSorted List" << endl
				<< "\t\t\t  ";
			sList.displayList();
			cout << endl << endl;

			//Destroy list
			sList.~LinkedList();

			break;
	
		case 4:						//If quit
			cout << endl << "Now exiting..." << endl;
			break;

		default:					//Edge cases: Invalid input
			cout << "Invalid choice..." << endl;
			break;

		} // !2. switch (choice)

	} while (choice != 4);	// !1. menu

	system("pause");
}

//----------Test Cases----------//
/* 
***************************************************************

Please select a data type to create a linked list with
        1. Integars
        2. Doubles
        3. Strings
         > 1
                Enter five integars
                 1. 5
                 2. 4
                 3. 3
                 4. 2
                 5. 1

                        Unsorted List
                          5, 4, 3, 2, 1,

                        Sorted List
                          1, 2, 3, 4, 5,

***************************************************************

Please select a data type to create a linked list with
        1. Integars
        2. Doubles
        3. Strings
         > 1
                Enter five integars
                 1. 9
                 2. 23
                 3. 2
                 4. 8
                 5. 1

                        Unsorted List
                          9, 23, 2, 8, 1,

                        Sorted List
                          1, 2, 8, 9, 23,

***************************************************************

Please select a data type to create a linked list with
        1. Integars
        2. Doubles
        3. Strings
         > 1
                Enter five integars
                 1. 23
                 2. 0
                 3. 23
                 4. 9
                 5. 100

                        Unsorted List
                          23, 0, 23, 9, 100,

                        Sorted List
                          0, 9, 23, 23, 100,

***************************************************************

Please select a data type to create a linked list with
        1. Integars
        2. Doubles
        3. Strings
         > 2
                Enter five doubles
                 1. 1.2
                 2. 9.3
                 3. 0.34
                 4. 8.7
                 5. 9.01223

                        Unsorted List
                          1.2, 9.3, 0.34, 8.7, 9.01223,

                        Sorted List
                          0.34, 1.2, 8.7, 9.01223, 9.3,

***************************************************************

Please select a data type to create a linked list with
        1. Integars
        2. Doubles
        3. Strings
         > 2
                Enter five doubles
                 1. 8.2
                 2. 0.3
                 3. 78.23
                 4. 8.3
                 5. -1.23

                        Unsorted List
                          8.2, 0.3, 78.23, 8.3, -1.23,

                        Sorted List
                          -1.23, 0.3, 8.2, 8.3, 78.23,

***************************************************************

Please select a data type to create a linked list with
        1. Integars
        2. Doubles
        3. Strings
         > 2
                Enter five doubles
                 1. 9.23
                 2. 1000.23245
                 3. -23.2343
                 4. 0000.2324
                 5. -34

                        Unsorted List
                          9.23, 1000.23, -23.2343, 0.2324, -34,

                        Sorted List
                          -34, -23.2343, 0.2324, 9.23, 1000.23,

***************************************************************

Please select a data type to create a linked list with
        1. Integars
        2. Doubles
        3. Strings
         > 3
                Enter five strings
                 1. sasha
                 2. samantha
                 3. sassy
                 4. pixel
                 5. boots

                        Unsorted List
                          sasha, samantha, sassy, pixel, boots,

                        Sorted List
                          boots, pixel, samantha, sasha, sassy,

***************************************************************

Please select a data type to create a linked list with
        1. Integars
        2. Doubles
        3. Strings
         > 3
                Enter five strings
                 1. bradley gallardo
                 2. bryan gallardo
                 3. sandra barrios
                 4. sal barrios
                 5. evelyn palcios

                        Unsorted List
                          bradley gallardo, bryan gallardo, sandra barrios, sal barrios, evelyn palacios,

                        Sorted List
                          bradley gallardo, bryan gallardo, evelyn palacios, sal barrios, sandra barrios,

***************************************************************

Please select a data type to create a linked list with
        1. Integars
        2. Doubles
        3. Strings
         > 3
                Enter five strings
                 1. philip fry
                 2. turanga leela
                 3. hermes conrad
                 4. hurbert farnsworth
                 5. john zoidberg

                        Unsorted List
                          philip fry, turanga leela, hermes conrad, hurbert farnsworth, john zoidberg,

                        Sorted List
                          hermes conrad, hurbert farnsworth, john zoidberg, philip fry, turanga leela,

***************************************************************

Please select a data type to create a linked list with
        1. Integars
        2. Doubles
        3. Strings
        4. Quit
         > 4

Now exiting...
Press any key to continue . . .
*/