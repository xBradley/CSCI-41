/*
Bradley Gallardo
CS41
Lab 10 Recusrive Functions   
Recursive multiplication and palindrome check
*/

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

//-----FUNCTIONS PROTOTYPES-----//
void find_product();
int multiply(int, int);
void find_palin();
bool palin_Detector(string, int);
char repeat();

int main() {
	char again;
	do {
		cout << "************************************************************************" << endl << endl;
		find_product();

		find_palin();

		again = repeat();

	} while (again == 'Y' && again != 'N');

	system("pause");
}

//-----FUNCTIONS-----//
void find_product() {
	int var1, var2, product;

	cout << "Recursive Multiplication" << endl;

		cout << endl << "\tEnter two numbers (seperated by a space) to multiply" << endl //prompt user
					 << "\t > ";
		cin >> var1 >> var2;

		product = multiply(var1, var2); //calculate product using recursion

		cout << endl << "\t\t" << var1 << " * " << var2 << " = " << product << endl << endl << endl; //display product

}

//multiplies recursively using addition (7 * 3 = 7 + 7 + 7 + 0)
int multiply(int var1, int var2) {

	if (var2 == 0) //base case: var2 reaches 0
		return var2; //returns 0
	else
		return var1 + multiply(var1, var2 - 1); //recursive multiplication
}

void find_palin() {
	string uWord; //user word
	int capacity; //word length
	bool palin = false; //is palindrome

	cout << "Recursive Palindrome Detector" << endl << endl
		<< "\tEnter a word to test if it is a palindrome" << endl //prompt user
		<< "\t > ";
	cin >> uWord;

	capacity = uWord.length(); //capacity is set to uWord length

	palin = palin_Detector(uWord, capacity); //checks if is a palindrome

	cout << endl;

	if (palin == true) //display results
		cout << "\t\t" << uWord << " is a palindrome" << endl << endl;
	else
		cout << "\t\t" << uWord << " is not a palindrome" << endl << endl;
}

//recursivley finds out if a word is a palindrome
bool palin_Detector(string str, int cap) {
	string str2; 

	if (cap == 1 || cap == 0) //base case: word is a single character (e.g. "e") or none are there
		return true;
	else
		if (str.front() == str[cap - 1]) { //if front letter is the same as the last letter make a
			str2 = str.substr(1, cap - 2); //smaller sub string by cutting off the ends 

			return palin_Detector(str2, str2.length()); //recursively check until cap is 1 or 0
		}
}

char repeat() { //Repeats main

	char input;
	std::cout << std::endl << "Do you want try this again?" << std::endl << " > ";
	std::cin >> input;

	input = toupper(input); //uppercases input

	if (input == 'Y')
		cout << endl << endl;

	while (input != 'Y' && input != 'N') { //checks if user input is not 'Y' or 'N' (edge cases)
			
		std::cout << "\tPlease enter either Y or N" << std::endl << "\t > ";
		std::cin >> input;

		input = toupper(input);

		if (input == 'Y' || input == 'N') {
			cout << endl << endl;
			return input; //loops until user input is either yes or no
		}
	}
	return input; //return if user input is yes or no

}


/*-----TEST CASES-----//
************************************************************************

Recursive Multiplication

        Enter two numbers (seperated by a space) to multiply
         > 10 0

                10 * 0 = 0


Recursive Palindrome Detector

        Enter a word to test if it is a palindrome
         > level

                level is a palindrome


Do you want try this again?
 > u
        Please enter either Y or N
         > a
        Please enter either Y or N
         > y

************************************************************************

Recursive Multiplication

        Enter two numbers (seperated by a space) to multiply
         > 1 90

                1 * 90 = 90


Recursive Palindrome Detector

        Enter a word to test if it is a palindrome
         > happy

                happy is not a palindrome


Do you want try this again?
 > y

************************************************************************

Recursive Multiplication

        Enter two numbers (seperated by a space) to multiply
         > 8 9

                8 * 9 = 72


Recursive Palindrome Detector

        Enter a word to test if it is a palindrome
         > noon

                noon is a palindrome


Do you want try this again?
 > n

Press any key to continue . . .
*/