/*
Bradley Gallardo
CS41
Term Project I - Polynomial
Driver File
*/

#include "polyList.h"					//To use polyList.h
#include <iostream>						//To use input/output streams
#include <cstdlib>						//To use system("pause")
#include <Windows.h>					//To use Sleep()
using namespace std;					//To use standard scope


//----------Function Prototypes----------//

void display_info();					//To display infomation of polynomial.cpp
void display_menu(int &, bool);			//To display menu
void poly_addition(bool);				//To add two polynomials
void poly_subtraction(bool);			//To subtract two polynomials
void poly_multiplication(bool);			//To multiply two polynomials
void solve_poly(bool);					//To solve for a nth term



int main() {

	int choice;							//To hold user's menu choice
	bool isIntMode = true;

	//Displays infomation about polynomial list
	display_info();

		do {
			//Displays menu and prompts user
			display_menu(choice, isIntMode);

			//Run desired case based on menu choice
			switch (choice) {
			case 0:							//To quit
				char input;					//To ask user if they are sure

				set_color(BGREEN);
				cout << "*****************************************************************************" << endl << endl;
				cout << "\t Are you sure you want to quit?" << endl;

				set_color(BCYAN);
				cout << "\t  > ";
				cin >> input;
				cout << endl;

				input = toupper(input);		//Uppercase input

				set_color(WHITE);
				//If user wants to quit (Enters 'Y')
				if (input == 'Y') {
					cout << "\t\t Thank you for using Poly Math." << endl << endl
						<< "\t\t This program will automatically close in..." << endl;;

					//Counts down from 5 to 1
					for (int i = 5; i > 0; i--) {
						cout << "\t\t  " << i << " second(s)" << endl;
						Sleep(1000);		//Wait 1 second (1000 milliseconds)
					} // !for (int i = 5; i > 0; i--) 

					cout << "\t\t Now exiting..." << endl;
					Sleep(1000);			//Wait 1 second (1000 milliseconds)
				} // !if (input == 'Y')

				else {
					cout << "\t\t Now returning back to Poly Math..." << endl;
					choice = 1;
					Sleep(2000);			//Wait 2 second (2000 milliseconds)
				} // !else

				break;

			case 1:							//To add

				set_color(BGREEN);
				cout << "*****************************************************************************" << endl;

				//Gets input for two poly list, inserts nodes to lists, adds lists together, and displays result
				poly_addition(isIntMode);
				cout << endl;

				break;

			case 2:							//To subtract

				set_color(BGREEN);
				cout << "*****************************************************************************" << endl;

				//Gets input for two poly list, inserts nodes to lists, subtracts lists, and displays result
				poly_subtraction(isIntMode);
				cout << endl;

				break;

			case 3:							//To multiply

				set_color(BGREEN);
				cout << "*****************************************************************************" << endl;

				//Gets input for two poly list, inserts nodes to lists, multiplies lists, and displays result
				poly_multiplication(isIntMode);
				cout << endl;

				break;
			case 4:							//To solve for x

				set_color(BGREEN);
				cout << "*****************************************************************************" << endl;

				//Gets input for a poly list, inserts nodes to lists, solves for desired term, and displays result
				solve_poly(isIntMode);
				cout << endl;

				break;
			case 5:

				if (isIntMode)
					isIntMode = false;
				else
					isIntMode = true;

				break;
			default:						//Edge Case: Invalid option

				set_color(BGREEN);
				cout << "Invalid choice..." << endl;

				break;
			}

			cout << endl;

		} while (choice != 0);
	system("pause");
}

/*
 _______________________________________________________________________________________________________________________________________
/*											---------Function Defintions----------														*\
\*______________________________________________________________________________________________________________________________________*/

/*-------------------------------------------------------------------------------------------------------------*\
|	Displays infomation about PolyList																			|
|		Parameters - (NULL)																						|
\*-------------------------------------------------------------------------------------------------------------*/
void display_info() { // <0>
	set_color(BGREEN);
	cout << "Welcome to TERM PROJECT I - POLYNOMIAL" << endl << endl

	
	    << "\t This program will test polynomial addition, subtraction, multiplication, " << endl
		<< "\tand solving for a specific term." << endl << endl

		<< "\t Each polynomial node has three components, BASE to hold coefficent, " << endl
		<< "\tPOWER to hold exponent, and NEXT to point to the next node." << endl << endl

		<< "\t\t |head|--> |base, power|--> |base, power|--> \\0" << endl << endl

		<< "\t The first value entered will always be the coefficent and the second value will " << endl
		<< "\talways be the exponenet. Additionally, enter (-9, -9) to end a polynomial list." << endl << endl << endl;

} // <0> display_info()


/*-------------------------------------------------------------------------------------------------------------*\
|	Displays menu and prompts user to choose an option															|
|		Parameters - (int &input --> to hold user's menu choice, bool intMode --> to tell whether to use		|
|		 PolyList as integers or doubles)																		|
\*-------------------------------------------------------------------------------------------------------------*/
void display_menu(int &input, bool intMode) {
	set_color(BGREEN);

	//intMode == true
	if(intMode) {
		cout << "+-------------------------------------------------------------------------------+" << endl;
		cout << "|\t ______        _           _______                _			|" << endl;
		cout << "|\t(_____ \\      | |         (_______)          _   | |			|" << endl;
		cout << "|\t _____) )___  | | _   _    _  _  _  _____  _| |_ | |__			|" << endl;
		cout << "|\t|  ____// _ \\ | || | | |  | ||_|| |(____ |(_   _)|  _ \\			|" << endl;
		cout << "|\t| |    | |_| || || |_| |  | |   | |/ ___ |  | |_ | | | |		|" << endl;
		cout << "|\t|_|     \\___/  \\_)\\__  |  |_|   |_|\\_____|   \\__)|_| |_|		|" << endl;
		cout << "|\t                 (____/							|" << endl;
		cout << "+-------------------------------------------------------------------------------+" << endl;
		cout << "|\t\t _  __  _  _____  ____  ____  ____ _____			|" << endl;
		cout << "|\t\t| ||  \\| ||_   _|| ===|/ (_,`| ===|| () )			|" << endl;
		cout << "|\t\t|_||_|\\__|  |_|  |____|\\____)|____||_|\\_\\			|" << endl;
		cout << "+-------------------------------------------------------------------------------+" << endl;

		cout << "\t 1. Addition + " << endl
			<< "\t 2. Subtraction - " << endl
			<< "\t 3. Multiplication * " << endl
			<< "\t 4. Solve for f(x) " << endl
			<< "\t 5. Switch to double mode " << endl
			<< "\t 0. Quit " << endl;

		set_color(BCYAN);
		cout << "\t  > ";
		cin >> input;
		cout << endl;
	}
	else {
		cout << "+-------------------------------------------------------------------------------+" << endl;
		cout << "|\t ______        _           _______                _			|" << endl;
		cout << "|\t(_____ \\      | |         (_______)          _   | |			|" << endl;
		cout << "|\t _____) )___  | | _   _    _  _  _  _____  _| |_ | |__			|" << endl;
		cout << "|\t|  ____// _ \\ | || | | |  | ||_|| |(____ |(_   _)|  _ \\			|" << endl;
		cout << "|\t| |    | |_| || || |_| |  | |   | |/ ___ |  | |_ | | | |		|" << endl;
		cout << "|\t|_|     \\___/  \\_)\\__  |  |_|   |_|\\_____|   \\__)|_| |_|		|" << endl;
		cout << "|\t                 (____/							|" << endl;
		cout << "+-------------------------------------------------------------------------------+" << endl;
		cout << "|\t\t ____  ____  __ __ _____  _     ____				|" << endl;
		cout << "|\t\t| _) \\/ () \\|  |  || () )| |__ | ===|				|" << endl;
		cout << "|\t\t|____/\\____/ \\___/ |_()_)|____||____|				|" << endl;
		cout << "+-------------------------------------------------------------------------------+" << endl;

		cout << "\t 1. Addition + " << endl
			<< "\t 2. Subtraction - " << endl
			<< "\t 3. Multiplication * " << endl
			<< "\t 4. Solve for f(x) " << endl
			<< "\t 5. Switch to integer mode " << endl
			<< "\t 0. Quit " << endl;

		set_color(BCYAN);
		cout << "\t  > ";
		cin >> input;
		cout << endl;
	}

}


/*-------------------------------------------------------------------------------------------------------------*\
|	Gets input for two PolyList, inserts nodes to each lists, adds lists together, and displays result			|
|		Parameters - (bool intMode --> to tell whether to use PolyList as integers or doubles)					|
\*-------------------------------------------------------------------------------------------------------------*/
void poly_addition(bool intMode) {
	if (intMode) {
		PolyList<int> augendPoly,			//To hold first poly list
			addendPoly,						//To hold second poly list
			*sum = nullptr;					//To point to a poly list of sum of first and second list

		cout << "Polynomial: Addition" << endl << endl;

		//Set nodes for first poly list
		set_color(GREEN);
		cout << "\t Augend List" << endl;
		cin >> augendPoly;


		//Set nodes for second poly list
		set_color(GREEN);
		cout << "\t Addend List" << endl;
		cin >> addendPoly;


		//Simplify both lists (combine like terms)
		augendPoly.simplifyList();
		addendPoly.simplifyList();

		//Display first list
		set_color(WHITE);
		cout << "\t\t\t   ";
		cout << augendPoly << endl;

		//Display second list
		cout << "\t\t\t + ";
		cout << addendPoly << endl;

		cout << "\t\t\t--------------------------" << endl;

		//Add first and second list
		sum = augendPoly + addendPoly;

		//Simplify sum list (combine like terms)
		sum->simplifyList();

		//Display sum list
		cout << "\t\t\t   ";
		sum->displayList();
		cout << endl;

		set_color(BGREEN);
	}

	else {
		PolyList<double> augendPoly,		//To hold first poly list
			addendPoly,						//To hold second poly list
			*sum = nullptr;					//To point to a poly list of sum of first and second list

		cout << "Polynomial: Addition" << endl << endl;

		//Set nodes for first poly list
		set_color(GREEN);
		cout << "\t Augend List" << endl;
		cin >> augendPoly;


		//Set nodes for second poly list
		set_color(GREEN);
		cout << "\t Addend List" << endl;
		cin >> addendPoly;


		//Simplify both lists (combine like terms)
		augendPoly.simplifyList();
		addendPoly.simplifyList();

		//Display first list
		set_color(WHITE);
		cout << "\t\t\t   ";
		cout << augendPoly << endl;

		//Display second list
		cout << "\t\t\t + ";
		cout << addendPoly << endl;

		cout << "\t\t\t--------------------------" << endl;

		//Add first and second list
		sum = augendPoly + addendPoly;

		//Simplify sum list (combine like terms)
		sum->simplifyList();

		//Display sum list
		cout << "\t\t\t   ";
		sum->displayList();
		cout << endl;

		set_color(BGREEN);
	}
}


/*-------------------------------------------------------------------------------------------------------------*\
|	Gets input for two PolyList, inserts nodes to each lists, subtracts lists together, and displays result		|
|		Parameters - (bool intMode --> to tell whether to use PolyList as integers or doubles)					|
\*-------------------------------------------------------------------------------------------------------------*/
void poly_subtraction(bool intMode) {

	if(intMode) {
		PolyList<int> minuendPoly,			//To hold user's first poly list
			subtrahendPoly,					//To hold user's second poly list
			*difference = nullptr;			//To point to a poly list of difference of first and second lists

		cout << "Polynomial: Subtraction" << endl << endl;

		//Set nodes for first poly list
		set_color(GREEN);
		cout << "\t Minuend List" << endl;
		cin >> minuendPoly;

		//Set nodes for second poly list
		set_color(GREEN);
		cout << "\t Subtrahend List" << endl;
		cin >> subtrahendPoly;

		//Simplify both lists (combine like terms)
		minuendPoly.simplifyList();
		subtrahendPoly.simplifyList();

		//Display first list
		set_color(WHITE);
		cout << "\t\t\t   ";
		cout << minuendPoly << endl;

		//Display second list
		cout << "\t\t        -( ";
		cout << subtrahendPoly << ") " << endl;
		cout << "\t\t\t--------------------------" << endl;

		//Subtract first and second list
		difference = minuendPoly - subtrahendPoly;

		//Simplify difference list (combine like terms)
		difference->simplifyList();

		//Display sum list
		cout << "\t\t\t   ";
		difference->displayList();
		cout << endl;

		set_color(BGREEN);
	}
	else {

		PolyList<double> minuendPoly,		//To hold user's first poly list
			subtrahendPoly,					//To hold user's second poly list
			*difference = nullptr;			//To point to a poly list of difference of first and second lists

		cout << "Polynomial: Subtraction" << endl << endl;

		//Set nodes for first poly list
		set_color(GREEN);
		cout << "\t Minuend List" << endl;
		cin >> minuendPoly;

		//Set nodes for second poly list
		set_color(GREEN);
		cout << "\t Subtrahend List" << endl;
		cin >> subtrahendPoly;

		//Simplify both lists (combine like terms)
		minuendPoly.simplifyList();
		subtrahendPoly.simplifyList();

		//Display first list
		set_color(WHITE);
		cout << "\t\t\t   ";
		cout << minuendPoly << endl;

		//Display second list
		cout << "\t\t        -( ";
		cout << subtrahendPoly << ") " << endl;
		cout << "\t\t\t--------------------------" << endl;

		//Subtract first and second list
		difference = minuendPoly - subtrahendPoly;

		//Simplify difference list (combine like terms)
		difference->simplifyList();

		//Display sum list
		cout << "\t\t\t   ";
		difference->displayList();
		cout << endl;

		set_color(BGREEN);
	}
}


/*-------------------------------------------------------------------------------------------------------------*\
|	Gets input for two PolyList, inserts nodes to each lists, multiplies lists together, and displays result	|
|		Parameters - (bool intMode --> to tell whether to use PolyList as integers or doubles)					|
\*-------------------------------------------------------------------------------------------------------------*/
void poly_multiplication(bool intMode) {

	if (intMode) {
		PolyList<int> multiplicandPoly,		//To hold user's first poly list			
			multiplierPoly,					//To hold user's second poly list
			*product = nullptr;				//To point to a poly list of prodecut of first and second lists

		cout << "Polynomial: Multiplication" << endl << endl;

		//Set nodes for first poly list
		set_color(GREEN);
		cout << "\t Multiplicand List" << endl;
		cin >> multiplicandPoly;

		//Set nodes for second poly list
		set_color(GREEN);
		cout << "\t Multiplier List" << endl;
		cin >> multiplierPoly;

		//Simplify both lists (combine like terms)
		multiplicandPoly.simplifyList();
		multiplierPoly.simplifyList();

		//Display first list
		set_color(WHITE);
		cout << "\t\t\t   ( ";
		cout << multiplicandPoly << ") * ( ";

		//Display second list
		cout << multiplierPoly << ") = ";

		//Multiply first and second list
		product = multiplicandPoly * multiplierPoly;

		//Simplify product list (combine like terms)
		product->simplifyList();

		//Display sum list
		cout << endl << "\t\t\t      ";
		product->displayList();
		cout << endl;

		set_color(BGREEN);
	}
	else {

		PolyList<double> multiplicandPoly,		//To hold user's first poly list			
			multiplierPoly,					//To hold user's second poly list
			*product = nullptr;				//To point to a poly list of prodecut of first and second lists

		cout << "Polynomial: Multiplication" << endl << endl;

		//Set nodes for first poly list
		set_color(GREEN);
		cout << "\t Multiplicand List" << endl;
		cin >> multiplicandPoly;

		//Set nodes for second poly list
		set_color(GREEN);
		cout << "\t Multiplier List" << endl;
		cin >> multiplierPoly;

		//Simplify both lists (combine like terms)
		multiplicandPoly.simplifyList();
		multiplierPoly.simplifyList();

		//Display first list
		set_color(WHITE);
		cout << "\t\t\t   ( ";
		cout << multiplicandPoly << ") * ( ";

		//Display second list
		cout << multiplierPoly << ") = ";

		//Multiply first and second list
		product = multiplicandPoly * multiplierPoly;

		//Simplify product list (combine like terms)
		product->simplifyList();

		//Display sum list
		cout << endl << "\t\t\t      ";
		product->displayList();
		cout << endl;

		set_color(BGREEN);
	}
}


/*-------------------------------------------------------------------------------------------------------------*\
|	Gets input for a PolyList, inserts nodes to list, solves PolyList for desired term, and displays result		|
|		Parameters - (bool intMode --> to tell whether to use PolyList as integers or doubles)					|
\*-------------------------------------------------------------------------------------------------------------*/
void solve_poly(bool intMode) {
	
	if (intMode) {
		PolyList<int> fxPoly;				//To hold user's poly list [f(x)]	
		int	nth,							//To hold user's term to solve for
			result;							//To hold result of solving for nth term

		cout << "Polynomial: Solve For X" << endl << endl;

		//Set nodes for f(x) poly list
		set_color(GREEN);
		cout << "\t f(x) List" << endl;
		cin >> fxPoly;

		//Simplify poly list (combine like terms)
		fxPoly.simplifyList();

		//Prompt user to enter term to solve for
		set_color(GREEN);
		cout << "\t\t Enter a value to solve for." << endl;

		set_color(CYAN);
		cout << "\t\t  > ";
		cin >> nth;

		//Display poly list
		set_color(WHITE);
		cout << endl << "\t\t\t   f(x) = ";
		cout << fxPoly << endl;

		//Solve for nth term
		result = fxPoly.solveFor(nth);

		//Display results
		cout << "\t\t\t   f(" << nth << ") = " << result << endl << endl;

		set_color(BGREEN);
	}
	else {
		PolyList<double> fxPoly;				//To hold user's poly list [f(x)]	
		double	nth,							//To hold user's term to solve for
			result;							//To hold result of solving for nth term

		cout << "Polynomial: Solve For X" << endl << endl;

		//Set nodes for f(x) poly list
		set_color(GREEN);
		cout << "\t f(x) List" << endl;
		cin >> fxPoly;

		//Simplify poly list (combine like terms)
		fxPoly.simplifyList();

		//Prompt user to enter term to solve for
		set_color(GREEN);
		cout << "\t\t Enter a value to solve for." << endl;

		set_color(CYAN);
		cout << "\t\t  > ";
		cin >> nth;

		//Display poly list
		set_color(WHITE);
		cout << endl << "\t\t\t   f(x) = ";
		cout << fxPoly << endl;

		//Solve for nth term
		result = fxPoly.solveFor(nth);

		//Display results
		cout << "\t\t\t   f(" << nth << ") = " << result << endl << endl;

		set_color(BGREEN);
	}
}


/*-------------------------------------------------------------------------------------------------------------*\
|	Set color of post-text																						|
\*-------------------------------------------------------------------------------------------------------------*/
void set_color(Colors c) {

	//set console color
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);

}


/*
 _______________________________________________________________________________________________________________________________________
/*											----------Test Cases----------																*\
\*______________________________________________________________________________________________________________________________________*/

//Test 1 - Integer
/*
Welcome to TERM PROJECT I - POLYNOMIAL

         This program will test polynomial addition, subtraction, multiplication,
        and solving for a specific term.

         Each polynomial node has three components, BASE to hold coefficent,
        POWER to hold exponent, and NEXT to point to the next node.

                 |head|--> |base, power|--> |base, power|--> \0

         The first value entered will always be the coefficent and the second value will
        always be the exponenet. Additionally, enter (-9, -9) to end a polynomial list.


+-------------------------------------------------------------------------------+
|        ______        _           _______                _                     |
|       (_____ \      | |         (_______)          _   | |                    |
|        _____) )___  | | _   _    _  _  _  _____  _| |_ | |__                  |
|       |  ____// _ \ | || | | |  | ||_|| |(____ |(_   _)|  _ \                 |
|       | |    | |_| || || |_| |  | |   | |/ ___ |  | |_ | | | |                |
|       |_|     \___/  \_)\__  |  |_|   |_|\_____|   \__)|_| |_|                |
|                        (____/                                                 |
+-------------------------------------------------------------------------------+
|                _  __  _  _____  ____  ____  ____ _____                        |
|               | ||  \| ||_   _|| ===|/ (_,`| ===|| () )                       |
|               |_||_|\__|  |_|  |____|\____)|____||_|\_\                       |
+-------------------------------------------------------------------------------+
         1. Addition +
         2. Subtraction -
         3. Multiplication *
         4. Solve for f(x)
         5. Switch to double mode
         0. Quit
          > 1

*****************************************************************************
Polynomial: Addition

         Augend List
                 Please enter two numbers seperated by a space.
                  > -2 2

                 Please enter two numbers seperated by a space.
                  > 3 2

                 Please enter two numbers seperated by a space.
                  > 8 1

                 Please enter two numbers seperated by a space.
                  > -9 -9


         Addend List
                 Please enter two numbers seperated by a space.
                  > 5 2

                 Please enter two numbers seperated by a space.
                  > 4 1

                 Please enter two numbers seperated by a space.
                  > 9 0

                 Please enter two numbers seperated by a space.
                  > -9 -9


                           1x^2 + 8x^1
                         + 5x^2 + 4x^1 + 9x^0
                        --------------------------
                           6x^2 + 12x^1 + 9x^0


+-------------------------------------------------------------------------------+
|        ______        _           _______                _                     |
|       (_____ \      | |         (_______)          _   | |                    |
|        _____) )___  | | _   _    _  _  _  _____  _| |_ | |__                  |
|       |  ____// _ \ | || | | |  | ||_|| |(____ |(_   _)|  _ \                 |
|       | |    | |_| || || |_| |  | |   | |/ ___ |  | |_ | | | |                |
|       |_|     \___/  \_)\__  |  |_|   |_|\_____|   \__)|_| |_|                |
|                        (____/                                                 |
+-------------------------------------------------------------------------------+
|                _  __  _  _____  ____  ____  ____ _____                        |
|               | ||  \| ||_   _|| ===|/ (_,`| ===|| () )                       |
|               |_||_|\__|  |_|  |____|\____)|____||_|\_\                       |
+-------------------------------------------------------------------------------+
         1. Addition +
         2. Subtraction -
         3. Multiplication *
         4. Solve for f(x)
         5. Switch to double mode
         0. Quit
          > 2

*****************************************************************************
Polynomial: Subtraction

         Minuend List
                 Please enter two numbers seperated by a space.
                  > 2 3

                 Please enter two numbers seperated by a space.
                  > 4 2

                 Please enter two numbers seperated by a space.
                  > -1 2

                 Please enter two numbers seperated by a space.
                  > -9 -9


         Subtrahend List
                 Please enter two numbers seperated by a space.
                  > 8 1

                 Please enter two numbers seperated by a space.
                  > 9 2

                 Please enter two numbers seperated by a space.
                  > -9 -9


                           2x^3 + 3x^2
                        -( 9x^2 + 8x^1 )
                        --------------------------
                           2x^3 - 6x^2 - 8x^1


+-------------------------------------------------------------------------------+
|        ______        _           _______                _                     |
|       (_____ \      | |         (_______)          _   | |                    |
|        _____) )___  | | _   _    _  _  _  _____  _| |_ | |__                  |
|       |  ____// _ \ | || | | |  | ||_|| |(____ |(_   _)|  _ \                 |
|       | |    | |_| || || |_| |  | |   | |/ ___ |  | |_ | | | |                |
|       |_|     \___/  \_)\__  |  |_|   |_|\_____|   \__)|_| |_|                |
|                        (____/                                                 |
+-------------------------------------------------------------------------------+
|                _  __  _  _____  ____  ____  ____ _____                        |
|               | ||  \| ||_   _|| ===|/ (_,`| ===|| () )                       |
|               |_||_|\__|  |_|  |____|\____)|____||_|\_\                       |
+-------------------------------------------------------------------------------+
         1. Addition +
         2. Subtraction -
         3. Multiplication *
         4. Solve for f(x)
         5. Switch to double mode
         0. Quit
          > 3

*****************************************************************************
Polynomial: Multiplication

         Multiplicand List
                 Please enter two numbers seperated by a space.
                  > 2 2

                 Please enter two numbers seperated by a space.
                  > 1 1

                 Please enter two numbers seperated by a space.
                  > -9 -9


         Multiplier List
                 Please enter two numbers seperated by a space.
                  > -2 2

                 Please enter two numbers seperated by a space.
                  > -1 1

                 Please enter two numbers seperated by a space.
                  > -9 -9


                           ( 2x^2 + 1x^1 ) * ( -2x^2 - 1x^1 ) =
                              -4x^4 - 4x^3 - 1x^2


+-------------------------------------------------------------------------------+
|        ______        _           _______                _                     |
|       (_____ \      | |         (_______)          _   | |                    |
|        _____) )___  | | _   _    _  _  _  _____  _| |_ | |__                  |
|       |  ____// _ \ | || | | |  | ||_|| |(____ |(_   _)|  _ \                 |
|       | |    | |_| || || |_| |  | |   | |/ ___ |  | |_ | | | |                |
|       |_|     \___/  \_)\__  |  |_|   |_|\_____|   \__)|_| |_|                |
|                        (____/                                                 |
+-------------------------------------------------------------------------------+
|                _  __  _  _____  ____  ____  ____ _____                        |
|               | ||  \| ||_   _|| ===|/ (_,`| ===|| () )                       |
|               |_||_|\__|  |_|  |____|\____)|____||_|\_\                       |
+-------------------------------------------------------------------------------+
         1. Addition +
         2. Subtraction -
         3. Multiplication *
         4. Solve for f(x)
         5. Switch to double mode
         0. Quit
          > 4

*****************************************************************************
Polynomial: Solve For X

         f(x) List
                 Please enter two numbers seperated by a space.
                  > 2 2

                 Please enter two numbers seperated by a space.
                  > 1 1

                 Please enter two numbers seperated by a space.
                  > 4 0

                 Please enter two numbers seperated by a space.
                  > -9 -9


                 Enter a value to solve for.
                  > 2

                           f(x) = 2x^2 + 1x^1 + 4x^0
                           f(2) = 14



+-------------------------------------------------------------------------------+
|        ______        _           _______                _                     |
|       (_____ \      | |         (_______)          _   | |                    |
|        _____) )___  | | _   _    _  _  _  _____  _| |_ | |__                  |
|       |  ____// _ \ | || | | |  | ||_|| |(____ |(_   _)|  _ \                 |
|       | |    | |_| || || |_| |  | |   | |/ ___ |  | |_ | | | |                |
|       |_|     \___/  \_)\__  |  |_|   |_|\_____|   \__)|_| |_|                |
|                        (____/                                                 |
+-------------------------------------------------------------------------------+
|                _  __  _  _____  ____  ____  ____ _____                        |
|               | ||  \| ||_   _|| ===|/ (_,`| ===|| () )                       |
|               |_||_|\__|  |_|  |____|\____)|____||_|\_\                       |
+-------------------------------------------------------------------------------+
         1. Addition +
         2. Subtraction -
         3. Multiplication *
         4. Solve for f(x)
         5. Switch to double mode
         0. Quit
          > 0

*****************************************************************************

         Are you sure you want to quit?
          > y

                 Thank you for using Poly Math.

                 This program will automatically close in...
                  5 second(s)
                  4 second(s)
                  3 second(s)
                  2 second(s)
                  1 second(s)
                 Now exiting...

Press any key to continue . . .
*/

//Test 2 - Integer
/*
Welcome to TERM PROJECT I - POLYNOMIAL

         This program will test polynomial addition, subtraction, multiplication,
        and solving for a specific term.

         Each polynomial node has three components, BASE to hold coefficent,
        POWER to hold exponent, and NEXT to point to the next node.

                 |head|--> |base, power|--> |base, power|--> \0

         The first value entered will always be the coefficent and the second value will
        always be the exponenet. Additionally, enter (-9, -9) to end a polynomial list.


+-------------------------------------------------------------------------------+
|        ______        _           _______                _                     |
|       (_____ \      | |         (_______)          _   | |                    |
|        _____) )___  | | _   _    _  _  _  _____  _| |_ | |__                  |
|       |  ____// _ \ | || | | |  | ||_|| |(____ |(_   _)|  _ \                 |
|       | |    | |_| || || |_| |  | |   | |/ ___ |  | |_ | | | |                |
|       |_|     \___/  \_)\__  |  |_|   |_|\_____|   \__)|_| |_|                |
|                        (____/                                                 |
+-------------------------------------------------------------------------------+
|                _  __  _  _____  ____  ____  ____ _____                        |
|               | ||  \| ||_   _|| ===|/ (_,`| ===|| () )                       |
|               |_||_|\__|  |_|  |____|\____)|____||_|\_\                       |
+-------------------------------------------------------------------------------+
         1. Addition +
         2. Subtraction -
         3. Multiplication *
         4. Solve for f(x)
         5. Switch to double mode
         0. Quit
          > 1

*****************************************************************************
Polynomial: Addition

         Augend List
                 Please enter two numbers seperated by a space.
                  > 5 3

                 Please enter two numbers seperated by a space.
                  > 4 2

                 Please enter two numbers seperated by a space.
                  > 9 1

                 Please enter two numbers seperated by a space.
                  > -9 -9


         Addend List
                 Please enter two numbers seperated by a space.
                  > 4 2

                 Please enter two numbers seperated by a space.
                  > 3 1

                 Please enter two numbers seperated by a space.
                  > 9 0

                 Please enter two numbers seperated by a space.
                  > -9 -9


                           5x^3 + 4x^2 + 9x^1
                         + 4x^2 + 3x^1 + 9x^0
                        --------------------------
                           5x^3 + 8x^2 + 12x^1 + 9x^0


+-------------------------------------------------------------------------------+
|        ______        _           _______                _                     |
|       (_____ \      | |         (_______)          _   | |                    |
|        _____) )___  | | _   _    _  _  _  _____  _| |_ | |__                  |
|       |  ____// _ \ | || | | |  | ||_|| |(____ |(_   _)|  _ \                 |
|       | |    | |_| || || |_| |  | |   | |/ ___ |  | |_ | | | |                |
|       |_|     \___/  \_)\__  |  |_|   |_|\_____|   \__)|_| |_|                |
|                        (____/                                                 |
+-------------------------------------------------------------------------------+
|                _  __  _  _____  ____  ____  ____ _____                        |
|               | ||  \| ||_   _|| ===|/ (_,`| ===|| () )                       |
|               |_||_|\__|  |_|  |____|\____)|____||_|\_\                       |
+-------------------------------------------------------------------------------+
         1. Addition +
         2. Subtraction -
         3. Multiplication *
         4. Solve for f(x)
         5. Switch to double mode
         0. Quit
          > 2

*****************************************************************************
Polynomial: Subtraction

         Minuend List
                 Please enter two numbers seperated by a space.
                  > -3 3

                 Please enter two numbers seperated by a space.
                  > 2 2

                 Please enter two numbers seperated by a space.
                  > 9 1

                 Please enter two numbers seperated by a space.
                  > -9 -9


         Subtrahend List
                 Please enter two numbers seperated by a space.
                  > 4 2

                 Please enter two numbers seperated by a space.
                  > 8 1

                 Please enter two numbers seperated by a space.
                  > -9 -9


                           -3x^3 + 2x^2 + 9x^1
                        -( 4x^2 + 8x^1 )
                        --------------------------
                           -3x^3 - 2x^2 + 1x^1


+-------------------------------------------------------------------------------+
|        ______        _           _______                _                     |
|       (_____ \      | |         (_______)          _   | |                    |
|        _____) )___  | | _   _    _  _  _  _____  _| |_ | |__                  |
|       |  ____// _ \ | || | | |  | ||_|| |(____ |(_   _)|  _ \                 |
|       | |    | |_| || || |_| |  | |   | |/ ___ |  | |_ | | | |                |
|       |_|     \___/  \_)\__  |  |_|   |_|\_____|   \__)|_| |_|                |
|                        (____/                                                 |
+-------------------------------------------------------------------------------+
|                _  __  _  _____  ____  ____  ____ _____                        |
|               | ||  \| ||_   _|| ===|/ (_,`| ===|| () )                       |
|               |_||_|\__|  |_|  |____|\____)|____||_|\_\                       |
+-------------------------------------------------------------------------------+
         1. Addition +
         2. Subtraction -
         3. Multiplication *
         4. Solve for f(x)
         5. Switch to double mode
         0. Quit
          > 3

*****************************************************************************
Polynomial: Multiplication

         Multiplicand List
                 Please enter two numbers seperated by a space.
                  > 7 2

                 Please enter two numbers seperated by a space.
                  > 9 4

                 Please enter two numbers seperated by a space.
                  > -9 -9


         Multiplier List
                 Please enter two numbers seperated by a space.
                  > 1 1

                 Please enter two numbers seperated by a space.
                  > -9 -9


                           ( 9x^4 + 7x^2 ) * ( 1x^1 ) =
                              9x^5 + 7x^3


+-------------------------------------------------------------------------------+
|        ______        _           _______                _                     |
|       (_____ \      | |         (_______)          _   | |                    |
|        _____) )___  | | _   _    _  _  _  _____  _| |_ | |__                  |
|       |  ____// _ \ | || | | |  | ||_|| |(____ |(_   _)|  _ \                 |
|       | |    | |_| || || |_| |  | |   | |/ ___ |  | |_ | | | |                |
|       |_|     \___/  \_)\__  |  |_|   |_|\_____|   \__)|_| |_|                |
|                        (____/                                                 |
+-------------------------------------------------------------------------------+
|                _  __  _  _____  ____  ____  ____ _____                        |
|               | ||  \| ||_   _|| ===|/ (_,`| ===|| () )                       |
|               |_||_|\__|  |_|  |____|\____)|____||_|\_\                       |
+-------------------------------------------------------------------------------+
         1. Addition +
         2. Subtraction -
         3. Multiplication *
         4. Solve for f(x)
         5. Switch to double mode
         0. Quit
          > 4

*****************************************************************************
Polynomial: Solve For X

         f(x) List
                 Please enter two numbers seperated by a space.
                  > 10 2

                 Please enter two numbers seperated by a space.
                  > 6 2

                 Please enter two numbers seperated by a space.
                  > -9 -9


                 Enter a value to solve for.
                  > 10

                           f(x) = 16x^2
                           f(10) = 1600



+-------------------------------------------------------------------------------+
|        ______        _           _______                _                     |
|       (_____ \      | |         (_______)          _   | |                    |
|        _____) )___  | | _   _    _  _  _  _____  _| |_ | |__                  |
|       |  ____// _ \ | || | | |  | ||_|| |(____ |(_   _)|  _ \                 |
|       | |    | |_| || || |_| |  | |   | |/ ___ |  | |_ | | | |                |
|       |_|     \___/  \_)\__  |  |_|   |_|\_____|   \__)|_| |_|                |
|                        (____/                                                 |
+-------------------------------------------------------------------------------+
|                _  __  _  _____  ____  ____  ____ _____                        |
|               | ||  \| ||_   _|| ===|/ (_,`| ===|| () )                       |
|               |_||_|\__|  |_|  |____|\____)|____||_|\_\                       |
+-------------------------------------------------------------------------------+
         1. Addition +
         2. Subtraction -
         3. Multiplication *
         4. Solve for f(x)
         5. Switch to double mode
         0. Quit
          > 0

*****************************************************************************

         Are you sure you want to quit?
          > y

                 Thank you for using Poly Math.

                 This program will automatically close in...
                  5 second(s)
                  4 second(s)
                  3 second(s)
                  2 second(s)
                  1 second(s)
                 Now exiting...

Press any key to continue . . .
*/

//Test 3 - Double
/*
Welcome to TERM PROJECT I - POLYNOMIAL

         This program will test polynomial addition, subtraction, multiplication,
        and solving for a specific term.

         Each polynomial node has three components, BASE to hold coefficent,
        POWER to hold exponent, and NEXT to point to the next node.

                 |head|--> |base, power|--> |base, power|--> \0

         The first value entered will always be the coefficent and the second value will
        always be the exponenet. Additionally, enter (-9, -9) to end a polynomial list.


+-------------------------------------------------------------------------------+
|        ______        _           _______                _                     |
|       (_____ \      | |         (_______)          _   | |                    |
|        _____) )___  | | _   _    _  _  _  _____  _| |_ | |__                  |
|       |  ____// _ \ | || | | |  | ||_|| |(____ |(_   _)|  _ \                 |
|       | |    | |_| || || |_| |  | |   | |/ ___ |  | |_ | | | |                |
|       |_|     \___/  \_)\__  |  |_|   |_|\_____|   \__)|_| |_|                |
|                        (____/                                                 |
+-------------------------------------------------------------------------------+
|                _  __  _  _____  ____  ____  ____ _____                        |
|               | ||  \| ||_   _|| ===|/ (_,`| ===|| () )                       |
|               |_||_|\__|  |_|  |____|\____)|____||_|\_\                       |
+-------------------------------------------------------------------------------+
         1. Addition +
         2. Subtraction -
         3. Multiplication *
         4. Solve for f(x)
         5. Switch to double mode
         0. Quit
          > 5


+-------------------------------------------------------------------------------+
|        ______        _           _______                _                     |
|       (_____ \      | |         (_______)          _   | |                    |
|        _____) )___  | | _   _    _  _  _  _____  _| |_ | |__                  |
|       |  ____// _ \ | || | | |  | ||_|| |(____ |(_   _)|  _ \                 |
|       | |    | |_| || || |_| |  | |   | |/ ___ |  | |_ | | | |                |
|       |_|     \___/  \_)\__  |  |_|   |_|\_____|   \__)|_| |_|                |
|                        (____/                                                 |
+-------------------------------------------------------------------------------+
|                ____  ____  __ __ _____  _     ____                            |
|               | _) \/ () \|  |  || () )| |__ | ===|                           |
|               |____/\____/ \___/ |_()_)|____||____|                           |
+-------------------------------------------------------------------------------+
         1. Addition +
         2. Subtraction -
         3. Multiplication *
         4. Solve for f(x)
         5. Switch to integer mode
         0. Quit
          > 1

*****************************************************************************
Polynomial: Addition

         Augend List
                 Please enter two numbers seperated by a space.
                  > 1.2 2

                 Please enter two numbers seperated by a space.
                  > 3.10 1

                 Please enter two numbers seperated by a space.
                  > 90.23 0

                 Please enter two numbers seperated by a space.
                  > -9 -9


         Addend List
                 Please enter two numbers seperated by a space.
                  > 4.2 2

                 Please enter two numbers seperated by a space.
                  > 9.1 1

                 Please enter two numbers seperated by a space.
                  > -9 -9


                           1.2x^2 + 3.1x^1 + 90.23x^0
                         + 4.2x^2 + 9.1x^1
                        --------------------------
                           5.4x^2 + 12.2x^1 + 90.23x^0


+-------------------------------------------------------------------------------+
|        ______        _           _______                _                     |
|       (_____ \      | |         (_______)          _   | |                    |
|        _____) )___  | | _   _    _  _  _  _____  _| |_ | |__                  |
|       |  ____// _ \ | || | | |  | ||_|| |(____ |(_   _)|  _ \                 |
|       | |    | |_| || || |_| |  | |   | |/ ___ |  | |_ | | | |                |
|       |_|     \___/  \_)\__  |  |_|   |_|\_____|   \__)|_| |_|                |
|                        (____/                                                 |
+-------------------------------------------------------------------------------+
|                ____  ____  __ __ _____  _     ____                            |
|               | _) \/ () \|  |  || () )| |__ | ===|                           |
|               |____/\____/ \___/ |_()_)|____||____|                           |
+-------------------------------------------------------------------------------+
         1. Addition +
         2. Subtraction -
         3. Multiplication *
         4. Solve for f(x)
         5. Switch to integer mode
         0. Quit
          > 2

*****************************************************************************
Polynomial: Subtraction

         Minuend List
                 Please enter two numbers seperated by a space.
                  > -3.2 3

                 Please enter two numbers seperated by a space.
                  > 9.1 1

                 Please enter two numbers seperated by a space.
                  > 17.2 0

                 Please enter two numbers seperated by a space.
                  > -9 -9


         Subtrahend List
                 Please enter two numbers seperated by a space.
                  > 1.1 2

                 Please enter two numbers seperated by a space.
                  > -9 -9


                           -3.2x^3 + 9.1x^1 + 17.2x^0
                        -( 1.1x^2 )
                        --------------------------
                           -3.2x^3 + 1.1x^2 + 9.1x^1 + 17.2x^0


+-------------------------------------------------------------------------------+
|        ______        _           _______                _                     |
|       (_____ \      | |         (_______)          _   | |                    |
|        _____) )___  | | _   _    _  _  _  _____  _| |_ | |__                  |
|       |  ____// _ \ | || | | |  | ||_|| |(____ |(_   _)|  _ \                 |
|       | |    | |_| || || |_| |  | |   | |/ ___ |  | |_ | | | |                |
|       |_|     \___/  \_)\__  |  |_|   |_|\_____|   \__)|_| |_|                |
|                        (____/                                                 |
+-------------------------------------------------------------------------------+
|                ____  ____  __ __ _____  _     ____                            |
|               | _) \/ () \|  |  || () )| |__ | ===|                           |
|               |____/\____/ \___/ |_()_)|____||____|                           |
+-------------------------------------------------------------------------------+
         1. Addition +
         2. Subtraction -
         3. Multiplication *
         4. Solve for f(x)
         5. Switch to integer mode
         0. Quit
          > 3

*****************************************************************************
Polynomial: Multiplication

         Multiplicand List
                 Please enter two numbers seperated by a space.
                  > 1.1 1

                 Please enter two numbers seperated by a space.
                  > 3.1 0

                 Please enter two numbers seperated by a space.
                  > -9 -9


         Multiplier List
                 Please enter two numbers seperated by a space.
                  > 4.20 1

                 Please enter two numbers seperated by a space.
                  > -9 -9


                           ( 1.1x^1 + 3.1x^0 ) * ( 4.2x^1 ) =
                              4.62x^2 + 13.02x^1


+-------------------------------------------------------------------------------+
|        ______        _           _______                _                     |
|       (_____ \      | |         (_______)          _   | |                    |
|        _____) )___  | | _   _    _  _  _  _____  _| |_ | |__                  |
|       |  ____// _ \ | || | | |  | ||_|| |(____ |(_   _)|  _ \                 |
|       | |    | |_| || || |_| |  | |   | |/ ___ |  | |_ | | | |                |
|       |_|     \___/  \_)\__  |  |_|   |_|\_____|   \__)|_| |_|                |
|                        (____/                                                 |
+-------------------------------------------------------------------------------+
|                ____  ____  __ __ _____  _     ____                            |
|               | _) \/ () \|  |  || () )| |__ | ===|                           |
|               |____/\____/ \___/ |_()_)|____||____|                           |
+-------------------------------------------------------------------------------+
         1. Addition +
         2. Subtraction -
         3. Multiplication *
         4. Solve for f(x)
         5. Switch to integer mode
         0. Quit
          > 4

*****************************************************************************
Polynomial: Solve For X

         f(x) List
                 Please enter two numbers seperated by a space.
                  > 2.2 2

                 Please enter two numbers seperated by a space.
                  > 1.1 1

                 Please enter two numbers seperated by a space.
                  > -9 -9


                 Enter a value to solve for.
                  > 4.4 3

                           f(x) = 2.2x^2 + 1.1x^1
                           f(4.4) = 47.432



+-------------------------------------------------------------------------------+
|        ______        _           _______                _                     |
|       (_____ \      | |         (_______)          _   | |                    |
|        _____) )___  | | _   _    _  _  _  _____  _| |_ | |__                  |
|       |  ____// _ \ | || | | |  | ||_|| |(____ |(_   _)|  _ \                 |
|       | |    | |_| || || |_| |  | |   | |/ ___ |  | |_ | | | |                |
|       |_|     \___/  \_)\__  |  |_|   |_|\_____|   \__)|_| |_|                |
|                        (____/                                                 |
+-------------------------------------------------------------------------------+
|                ____  ____  __ __ _____  _     ____                            |
|               | _) \/ () \|  |  || () )| |__ | ===|                           |
|               |____/\____/ \___/ |_()_)|____||____|                           |
+-------------------------------------------------------------------------------+
         1. Addition +
         2. Subtraction -
         3. Multiplication *
         4. Solve for f(x)
         5. Switch to integer mode
         0. Quit
          >
*****************************************************************************
Polynomial: Multiplication

         Multiplicand List
                 Please enter two numbers seperated by a space.
                  >  1.1 1

                 Please enter two numbers seperated by a space.
                  > -9 -9


         Multiplier List
                 Please enter two numbers seperated by a space.
                  > 2.2 1

                 Please enter two numbers seperated by a space.
                  > -9 -9


                           ( 1.1x^1 ) * ( 2.2x^1 ) =
                              2.42x^2


+-------------------------------------------------------------------------------+
|        ______        _           _______                _                     |
|       (_____ \      | |         (_______)          _   | |                    |
|        _____) )___  | | _   _    _  _  _  _____  _| |_ | |__                  |
|       |  ____// _ \ | || | | |  | ||_|| |(____ |(_   _)|  _ \                 |
|       | |    | |_| || || |_| |  | |   | |/ ___ |  | |_ | | | |                |
|       |_|     \___/  \_)\__  |  |_|   |_|\_____|   \__)|_| |_|                |
|                        (____/                                                 |
+-------------------------------------------------------------------------------+
|                ____  ____  __ __ _____  _     ____                            |
|               | _) \/ () \|  |  || () )| |__ | ===|                           |
|               |____/\____/ \___/ |_()_)|____||____|                           |
+-------------------------------------------------------------------------------+
         1. Addition +
         2. Subtraction -
         3. Multiplication *
         4. Solve for f(x)
         5. Switch to integer mode
         0. Quit
          > 0

*****************************************************************************

         Are you sure you want to quit?
          > y

                 Thank you for using Poly Math.

                 This program will automatically close in...
                  5 second(s)
                  4 second(s)
                  3 second(s)
                  2 second(s)
                  1 second(s)
                 Now exiting...

Press any key to continue . . .
*/

//Test 4 - Double
/*
Welcome to TERM PROJECT I - POLYNOMIAL

         This program will test polynomial addition, subtraction, multiplication,
        and solving for a specific term.

         Each polynomial node has three components, BASE to hold coefficent,
        POWER to hold exponent, and NEXT to point to the next node.

                 |head|--> |base, power|--> |base, power|--> \0

         The first value entered will always be the coefficent and the second value will
        always be the exponenet. Additionally, enter (-9, -9) to end a polynomial list.


+-------------------------------------------------------------------------------+
|        ______        _           _______                _                     |
|       (_____ \      | |         (_______)          _   | |                    |
|        _____) )___  | | _   _    _  _  _  _____  _| |_ | |__                  |
|       |  ____// _ \ | || | | |  | ||_|| |(____ |(_   _)|  _ \                 |
|       | |    | |_| || || |_| |  | |   | |/ ___ |  | |_ | | | |                |
|       |_|     \___/  \_)\__  |  |_|   |_|\_____|   \__)|_| |_|                |
|                        (____/                                                 |
+-------------------------------------------------------------------------------+
|                _  __  _  _____  ____  ____  ____ _____                        |
|               | ||  \| ||_   _|| ===|/ (_,`| ===|| () )                       |
|               |_||_|\__|  |_|  |____|\____)|____||_|\_\                       |
+-------------------------------------------------------------------------------+
         1. Addition +
         2. Subtraction -
         3. Multiplication *
         4. Solve for f(x)
         5. Switch to double mode
         0. Quit
          > 5


+-------------------------------------------------------------------------------+
|        ______        _           _______                _                     |
|       (_____ \      | |         (_______)          _   | |                    |
|        _____) )___  | | _   _    _  _  _  _____  _| |_ | |__                  |
|       |  ____// _ \ | || | | |  | ||_|| |(____ |(_   _)|  _ \                 |
|       | |    | |_| || || |_| |  | |   | |/ ___ |  | |_ | | | |                |
|       |_|     \___/  \_)\__  |  |_|   |_|\_____|   \__)|_| |_|                |
|                        (____/                                                 |
+-------------------------------------------------------------------------------+
|                ____  ____  __ __ _____  _     ____                            |
|               | _) \/ () \|  |  || () )| |__ | ===|                           |
|               |____/\____/ \___/ |_()_)|____||____|                           |
+-------------------------------------------------------------------------------+
         1. Addition +
         2. Subtraction -
         3. Multiplication *
         4. Solve for f(x)
         5. Switch to integer mode
         0. Quit
          > 1

*****************************************************************************
Polynomial: Addition

         Augend List
                 Please enter two numbers seperated by a space.
                  > 10.3 3

                 Please enter two numbers seperated by a space.
                  > 9.2 1

                 Please enter two numbers seperated by a space.
                  > 9.1 0

                 Please enter two numbers seperated by a space.
                  > -9 -9


         Addend List
                 Please enter two numbers seperated by a space.
                  > 2.2 4

                 Please enter two numbers seperated by a space.
                  > -10.2 3

                 Please enter two numbers seperated by a space.
                  > -9 -9


                           10.3x^3 + 9.2x^1 + 9.1x^0
                         + 2.2x^4 - 10.2x^3
                        --------------------------
                           2.2x^4 + 0.1x^3 + 9.2x^1 + 9.1x^0


+-------------------------------------------------------------------------------+
|        ______        _           _______                _                     |
|       (_____ \      | |         (_______)          _   | |                    |
|        _____) )___  | | _   _    _  _  _  _____  _| |_ | |__                  |
|       |  ____// _ \ | || | | |  | ||_|| |(____ |(_   _)|  _ \                 |
|       | |    | |_| || || |_| |  | |   | |/ ___ |  | |_ | | | |                |
|       |_|     \___/  \_)\__  |  |_|   |_|\_____|   \__)|_| |_|                |
|                        (____/                                                 |
+-------------------------------------------------------------------------------+
|                ____  ____  __ __ _____  _     ____                            |
|               | _) \/ () \|  |  || () )| |__ | ===|                           |
|               |____/\____/ \___/ |_()_)|____||____|                           |
+-------------------------------------------------------------------------------+
         1. Addition +
         2. Subtraction -
         3. Multiplication *
         4. Solve for f(x)
         5. Switch to integer mode
         0. Quit
          > 2

*****************************************************************************
Polynomial: Subtraction

         Minuend List
                 Please enter two numbers seperated by a space.
                  > -3.2 3

                 Please enter two numbers seperated by a space.
                  > -9.1 2

                 Please enter two numbers seperated by a space.
                  > -9.7 1

                 Please enter two numbers seperated by a space.
                  > -9 -9


         Subtrahend List
                 Please enter two numbers seperated by a space.
                  > -8.1 3

                 Please enter two numbers seperated by a space.
                  > 19.2 2

                 Please enter two numbers seperated by a space.
                  > -9 -9


                           -3.2x^3 - 9.1x^2 - 9.7x^1
                        -( -8.1x^3 + 19.2x^2 )
                        --------------------------
                           4.9x^3 - 28.3x^2 - 9.7x^1


+-------------------------------------------------------------------------------+
|        ______        _           _______                _                     |
|       (_____ \      | |         (_______)          _   | |                    |
|        _____) )___  | | _   _    _  _  _  _____  _| |_ | |__                  |
|       |  ____// _ \ | || | | |  | ||_|| |(____ |(_   _)|  _ \                 |
|       | |    | |_| || || |_| |  | |   | |/ ___ |  | |_ | | | |                |
|       |_|     \___/  \_)\__  |  |_|   |_|\_____|   \__)|_| |_|                |
|                        (____/                                                 |
+-------------------------------------------------------------------------------+
|                ____  ____  __ __ _____  _     ____                            |
|               | _) \/ () \|  |  || () )| |__ | ===|                           |
|               |____/\____/ \___/ |_()_)|____||____|                           |
+-------------------------------------------------------------------------------+
         1. Addition +
         2. Subtraction -
         3. Multiplication *
         4. Solve for f(x)
         5. Switch to integer mode
         0. Quit
          > 3

*****************************************************************************
Polynomial: Multiplication

         Multiplicand List
                 Please enter two numbers seperated by a space.
                  > -10.1 2

                 Please enter two numbers seperated by a space.
                  > 8.3 1

                 Please enter two numbers seperated by a space.
                  > -9 -9


         Multiplier List
                 Please enter two numbers seperated by a space.
                  > 7.2 2

                 Please enter two numbers seperated by a space.
                  > -9-9


                           ( -10.1x^2 + 8.3x^1 ) * ( 7.2x^2 ) =
                              -72.72x^4 + 59.76x^3


+-------------------------------------------------------------------------------+
|        ______        _           _______                _                     |
|       (_____ \      | |         (_______)          _   | |                    |
|        _____) )___  | | _   _    _  _  _  _____  _| |_ | |__                  |
|       |  ____// _ \ | || | | |  | ||_|| |(____ |(_   _)|  _ \                 |
|       | |    | |_| || || |_| |  | |   | |/ ___ |  | |_ | | | |                |
|       |_|     \___/  \_)\__  |  |_|   |_|\_____|   \__)|_| |_|                |
|                        (____/                                                 |
+-------------------------------------------------------------------------------+
|                ____  ____  __ __ _____  _     ____                            |
|               | _) \/ () \|  |  || () )| |__ | ===|                           |
|               |____/\____/ \___/ |_()_)|____||____|                           |
+-------------------------------------------------------------------------------+
         1. Addition +
         2. Subtraction -
         3. Multiplication *
         4. Solve for f(x)
         5. Switch to integer mode
         0. Quit
          > 4

*****************************************************************************
Polynomial: Solve For X

         f(x) List
                 Please enter two numbers seperated by a space.
                  > 12.2 4

                 Please enter two numbers seperated by a space.
                  > 8.2 9

                 Please enter two numbers seperated by a space.
                  > -9 -9


                 Enter a value to solve for.
                  > 4

                           f(x) = 8.2x^9 + 12.2x^4
                           f(4) = 2.1527e+06



+-------------------------------------------------------------------------------+
|        ______        _           _______                _                     |
|       (_____ \      | |         (_______)          _   | |                    |
|        _____) )___  | | _   _    _  _  _  _____  _| |_ | |__                  |
|       |  ____// _ \ | || | | |  | ||_|| |(____ |(_   _)|  _ \                 |
|       | |    | |_| || || |_| |  | |   | |/ ___ |  | |_ | | | |                |
|       |_|     \___/  \_)\__  |  |_|   |_|\_____|   \__)|_| |_|                |
|                        (____/                                                 |
+-------------------------------------------------------------------------------+
|                ____  ____  __ __ _____  _     ____                            |
|               | _) \/ () \|  |  || () )| |__ | ===|                           |
|               |____/\____/ \___/ |_()_)|____||____|                           |
+-------------------------------------------------------------------------------+
         1. Addition +
         2. Subtraction -
         3. Multiplication *
         4. Solve for f(x)
         5. Switch to integer mode
         0. Quit
          > 0

*****************************************************************************

         Are you sure you want to quit?
          > y

                 Thank you for using Poly Math.

                 This program will automatically close in...
                  5 second(s)
                  4 second(s)
                  3 second(s)
                  2 second(s)
                  1 second(s)
                 Now exiting...

Press any key to continue . . .
*/

