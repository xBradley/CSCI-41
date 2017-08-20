#include <iostream>	//To use cout cin
#include <cstdlib>	//To use system("pause")
#include <stack>	//To create stack
#include <deque>	//To create deque
#include <vector>	//To use stack as a vector
#include <string>	//To create string
using namespace std;

//------Function Prototypes------//

void reverse_string();
void is_palindrome();
char repeat();

int main() {
	char again;		//To ask user to repeat program

	do {
		cout << "**********************************************************" << endl << endl;
		
		reverse_string();
		cout << endl;

		is_palindrome();
		cout << endl;

		again = repeat();

		cin.ignore();

	} while (again == 'Y' && again != 'N');

	system("pause");
}

//------Function Definitions------//

//Gets a string from user and reverses the order
void reverse_string() {
	stack< char, vector<char> > cStack; //Character stack using vectors
	string input;						//To hold user's sentence/word

	//Get user Input
	cout << "Reverse" << endl;
	cout << "\tEnter a word or sentence" << endl
		<< "\t > ";
	getline(cin, input);

	cout << endl;

	//Push each character to stack
	for (int i = 0; i < input.length(); i++) {
		cStack.push(input[i]);
	}

	cout << "\t\t";

	//Display character at top of stack, then pop it off
	while (!cStack.empty()) {
		cout << cStack.top();
		cStack.pop();
	}
	cout << endl << endl;
}

//Gets a string from user and checks if it is a palindrome
void is_palindrome() {
	deque<char> cDeque; //Character deque
	string input;		//To hold user's sentence/word
	char front, rear;	//To check if front and rear characters are the same
	bool palin = true;	//To know if is palindrome

	//Get user input
	cout << "Palindrome Test" << endl
		<< "\tEnter a word or sentence" << endl
		<< "\t > ";
	getline(cin, input);

	//Push each character into the rear of the deque
	for (int i = 0; i < input.length(); i++) {
		if (isalpha(input[i]) ) {			//Edge Case: only alphas get pushed 

			input[i] = tolower(input[i]);	//Edge Case: only lower case chars 

			cDeque.push_back(input[i]);
		}
	}

	//Palindrome Test
	while (palin) {
		front = cDeque.front();						//Front is set to first char
		rear = cDeque.back();						//Rear is set to last char

		cDeque.pop_front();							//Front is popped
		cDeque.pop_back();							//Rear is popped

		if (front != rear)							//If front and rear don't match, loop is broken
			palin = false;							// and is not a palindrome

		if (cDeque.size() == 1 || cDeque.empty())	//If only 1 char remains or is empty, loop is broken 
			break;									// and is a palindrome
	}

	if (palin)
		cout << endl << "\t\tThis is a palindrome" << endl;
	else
		cout << endl << "\t\tThis is not a palindrome" << endl;
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



//------Test Cases------//

/*
**********************************************************

Reverse
        Enter a word or sentence
         > racecar

                racecar


Palindrome Test
        Enter a word or sentence
         > Delia, here we, nine were hailed.

                This is a palindrome


Do you want try this again?
 > y


**********************************************************

Reverse
        Enter a word or sentence
         > level

                level


Palindrome Test
        Enter a word or sentence
         > Draw, O Caesar, erase a coward.

                This is a palindrome


Do you want try this again?
 > y


**********************************************************

Reverse
        Enter a word or sentence
         > Happy day

                yad yppaH


Palindrome Test
        Enter a word or sentence
         > I love deques!!!

                This is not a palindrome


Do you want try this again?
 > n


Press any key to continue . . .
*/