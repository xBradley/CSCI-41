/*
Bradley Gallardo
CS41
C-String Manipulation
Uppercase each character, counts characters, vowels, consonants, and digits
*/
#include <iostream>
#include <string>

//----------Function Prototypes-------------
void string_to_array(char*&, unsigned int&);
void uppercase(char*, unsigned int);
void count_things(char*, unsigned int, unsigned int&, unsigned int&, unsigned int&, unsigned int&);
void display_numbers(unsigned int, unsigned int, unsigned int, unsigned int);
char repeat(char);

int main() {
	char again = 'Y';
	do {
	unsigned int size, digits = 0, characters = 0, vowels = 0, consonants = 0;
	char *ptr = NULL;
	
	
		std::cout << "***********************************************************" << std::endl;

		string_to_array(ptr, size);

		uppercase(ptr, size);

		count_things(ptr, size, digits, characters, vowels, consonants);

		display_numbers(characters, vowels, consonants, digits);

		again = repeat(again);
		std::cin.ignore();
		
		delete []  ptr;


	} while (again == 'Y' || again != 'N');
}

//-------------Functions---------------
void string_to_array(char *&ptr, unsigned int& size) { 
/*
+-------------------------------+
| Grabs each char in a string   |
| and places it into a dynamic  |  
|		 char array             |
+-------------------------------+
*/
	std::string input;

	std::cout << "Enter a sentence" << std::endl << "> ";
	std::getline(std::cin, input);
	
	size = input.size(); //sentence length is size of char array

	ptr = new char[size + 1]; //dynamic char array (+1 for /0)

	for (unsigned int i = 0; i < size; i++) //assigns each char in input to char array
		ptr[i] = input[i];
} 

void uppercase(char *ptr, unsigned int size) { 
/*
+-------------------------------+
|   Uppercases each indivdual   |
|            letter             |
+-------------------------------+
*/
	std::cout << std::endl << "\tUppercase: ";
	for (unsigned int i = 0; i < size; i++) {
		
		ptr[i] = toupper(ptr[i]);

		std::cout << ptr[i];
	}
}

void count_things(char *ptr, unsigned int size, unsigned int& digits, unsigned int& characters, unsigned int& vowels, unsigned int& consonants) { 
/*
+-------------------------------+
|   Counts characters, digits,  |
|     vowels, & consonants      |
+-------------------------------+
*/
	for (int i = 0; i < size; i++) {
		if (isdigit(ptr[i])) { //if char is a digit (+1 for digits and characters)
			digits++;
			characters++;
		}
		else if (isalpha(ptr[i])) { //if char is a alpha
			if (ptr[i] == 'A' || ptr[i] == 'E' || ptr[i] == 'I' ||
				ptr[i] == 'O' || ptr[i] == 'U') { //and if char is a vowel (+1 for vowels and characters)
				vowels++;
				characters++;
			} else { //if not a vowel, char is a consonant (+1 for consonants and characters)
				consonants++;
				characters++;
			}
				
		}
	}
}

void display_numbers(unsigned int characters, unsigned int vowels, unsigned int consonants, unsigned int digits) {
/*
+-------------------------------+
|   Displays results of chars,  |
|  vowels, consonants, & digits |
+-------------------------------+
*/
	std::cout << std::endl << "\tThere are " << characters << " characters!" << std::endl;
	std::cout << "\tThere are " << vowels << " vowels!" << std::endl;
	std::cout << "\tThere are " << consonants << " consonants!" << std::endl;
	std::cout << "\tThere are " << digits << " digits!" << std::endl;
}

char repeat(char again) {
/*
+-------------------------------+
| Ask if user whats to repeat   |
|       the code again          |
+-------------------------------+
*/
	std::cout << std::endl << "Do you want try this again?" << std::endl << "> ";
	std::cin >> again;

	again = toupper(again); //uppercases input
	
	while (again != 'Y' && again != 'N') { //checks if user input is not 'Y' or 'N' (edge cases)
		{
			std::cout << "Please enter a either Y or N" << std::endl << "> ";
			std::cin >> again;

			again = toupper(again);

			return again; //loops until user input is either yes or no
		}
		return again; //return if user input is yes or no
	}
}
/*
***********************************************************
Enter a sentence
> Hello my name is bradley gallardo

        Uppercase: HELLO MY NAME IS BRADLEY GALLARDO
        There are 28 characters!
        There are 10 vowels!
        There are 18 consonants!
        There are 0 digits!

Do you want try this again?
> a
Please enter a either Y or N
> y
***********************************************************
Enter a sentence
> I was born July 31th 1996

        Uppercase: I WAS BORN JULY 31TH 1996
        There are 20 characters!
        There are 4 vowels!
        There are 10 consonants!
        There are 6 digits!

Do you want try this again?
> y
***********************************************************
Enter a sentence
> Today is 2/3/2017

        Uppercase: TODAY IS 2/3/2017
        There are 13 characters!
        There are 3 vowels!
        There are 4 consonants!
        There are 6 digits!

Do you want try this again?
> n
Press any key to continue . . .
*/