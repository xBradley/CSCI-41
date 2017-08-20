

#include <iostream>
#include <cstdlib>
#include "NumberList.h"
using namespace std;

int main() {

	NumberList linkedList;
	int input; //user input
	int i; //counter 

		cout << "***********************************************************************" << endl << endl;

		i = 0;
		cout << "Appending" << endl << endl;
		//get input
		while (i < 3) {
				cout << "\tEnter an integer" << endl
					 << "\t > ";
			cin >> input;

			//append each int 
			linkedList.appendNode(input);
			i++;
		}
		//display list
		cout << endl << "\t\t";
		linkedList.displayList();
		cout << endl << endl;

		
		i = 0;
		cout << "Inserting" << endl << endl;
		//get input
		while ( i < 3) {
				cout << "\tEnter an integer" << endl
					 << "\t > ";
			cin >> input;

			//insert each int
			linkedList.insertNode(input);
			i++;
		}
		//display list
		cout << endl << "\t\t";
		linkedList.displayList();
		cout << endl << endl;

		i = 0;
		cout << "Deleting" << endl << endl;
		//get input
		while ( i < 3) {
				cout << "\tEnter an integer" << endl
					 << "\t > ";
			cin >> input;

			//delete desired node
			linkedList.deleteNode(input);
			i++;
		}
		//display list
		cout << endl << "\t\t";
		linkedList.displayList();
		cout << endl << endl;

	system("pause");
}

/*
***********************************************************************

Appending

        Enter an integer
         > 1
        Enter an integer
         > 3
        Enter an integer
         > 5

                1 3 5

Inserting

        Enter an integer
         > 2
        Enter an integer
         > 4
        Enter an integer
         > 6

                1 2 3 4 5 6

Deleting

        Enter an integer
         > 1
        Enter an integer
         > 2
        Enter an integer
         > 3

                4 5 6

Press any key to continue . . .

***********************************************************************

Appending

        Enter an integer
         > 5
        Enter an integer
         > 10
        Enter an integer
         > 15

                5 10 15

Inserting

        Enter an integer
         > 7
        Enter an integer
         > 1
        Enter an integer
         > 90

                1 5 7 10 15 90

Deleting

        Enter an integer
         > 90
        Enter an integer
         > 1
        Enter an integer
         > 10

                5 7 15

Press any key to continue . . .

***********************************************************************

Appending

        Enter an integer
         > 0
        Enter an integer
         > 3
        Enter an integer
         > 10

                0 3 10

Inserting

        Enter an integer
         > 2
        Enter an integer
         > 8
        Enter an integer
         > 7

                0 2 3 7 8 10

Deleting

        Enter an integer
         > 1
        Enter an integer
         > 10000
        Enter an integer
         > 8

                0 2 3 7 10

Press any key to continue . . .
*/