/*
Bradley Gallardo
CS41 
Lab 07 Template Functions
Allocates a desired vector type and finds max and min elements
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <string>

//----------Function Prototypes----------//
void set_string(std::vector<std::string> &);
char repeat();
template <class T>
void set_random(std::vector<T> &);
template <class T>
void display(const std::vector<T> &);
template <class T>
void find_min(const std::vector<T> &, int &);
template <class T>
void find_max(const std::vector<T> &, int &);

int main() {
	std::vector<int> intVec;
	std::vector<double> doubleVec;
	std::vector<std::string> stringVec;
	std::string input;
	int min, max;
	char again;
	srand(time(NULL));

	do {
		//Choose data type
			std::cout << "Enter either string, int, or double to choose the data type" << std::endl << "> ";
			std::cin >> input;

			if (input == "string") {

				//prompt user to add words to vector
				set_string(stringVec);

				//display vector
				display(stringVec);

				//find min
				find_min(stringVec, min);
				std::cout << std::endl << "\t" << stringVec[min] << " is the min value at index " << min << std::endl;

				//find max
				find_max(stringVec, max);
				std::cout << "\t" << stringVec[max] << " is the max value at index " << max << std::endl << std::endl;

			}
			else if (input == "double") {
				//set random doubles
				set_random(doubleVec);

				//display vector
				display(doubleVec);

				//find min
				find_min(doubleVec, min);
				std::cout << std::endl << "\t" << doubleVec[min] << " is the min value at index " << min << std::endl;

				//find max
				find_max(doubleVec, max);
				std::cout << "\t" << doubleVec[max] << " is the max value at index " << max << std::endl << std::endl;
			}
			else if (input == "int") {
				//set random ints
				set_random(intVec);

				//display vector
				display(intVec);

				//find min
				find_min(intVec, min);
				std::cout << std::endl << "\t" << intVec[min] << " is the min value at index " << min << std::endl;

				//find max
				find_max(intVec, max);
				std::cout << "\t" << intVec[max] << " is the max value at index " << max << std::endl << std::endl;
			}
			//prompt user to repeat main
		again = repeat();

	} while (again == 'Y' || again != 'N');
	system("pause");
}

void set_string(std::vector<std::string> &vec) {
	std::string words;		//To hold user's words
	std::cout << "\tEnter 10 words" << std::endl;

	//get input
	for (int i = 1; i <= 10; i++) {
		std::cout << "\t\t" << i << ": ";
		std::cin >> words;

		//add input to vector
		vec.push_back(words);
	}
	std::cout << std::endl;
}

char repeat() { //Repeats main

	char input;
	std::cout << std::endl << "Do you want try this again?" << std::endl << "> ";
	std::cin >> input;

	input = toupper(input); //uppercases input

	if (input == 'Y')
		std::cout << "******************************************************" << std::endl << std::endl;

	while (input != 'Y' && input != 'N') { //checks if user input is not 'Y' or 'N' (edge cases)
		{
			std::cout << "Please enter a either Y or N" << std::endl << "> ";
			std::cin >> input;

			input = toupper(input);

			std::cout << "******************************************************" << std::endl << std::endl;

			return input; //loops until user input is either yes or no
		}
		return input; //return if user input is yes or no
	}
}

//sets random numbers in a vector
template <class T> 
void set_random(std::vector<T> &vec) {
	for (int i = 0; i < 10; i++)
		vec.push_back(1 * rand() / 100.0);
}

//displays vector
template <class T>
void display(const std::vector<T> &vec) {
	std::cout << "\t";
	for (int i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";

		//display 10 numbers per line
		if (i == 9)
			std::cout << std::endl;
	}
}

//finds min element
template <class T>
void find_min(const std::vector<T> &vec, int &minEle) {
	minEle = 0;			
	T minVal = vec[0];

	//scan through vector
	for (int i = 1; i < vec.size(); i++) {
		if (minVal > vec[i]) {
			minVal = vec[i];
			minEle = i;
		}
	}
}

//finds max element
template <class T>
void find_max(const std::vector<T> &vec, int &maxEle) {
	maxEle = 0;
	T maxVal = vec[0];

	//scan through vector
	for (int i = 1; i < vec.size(); i++) {
		if (maxVal < vec[i]) {
			maxVal = vec[i];
			maxEle = i;
		}
	}
}

/*
Enter either string, int, or double to choose the data type
> int
        250 312 266 177 62 3 307 130 173 131

        3 is the min value at index 5
        312 is the max value at index 1


Do you want try this again?
> y
******************************************************

Enter either string, int, or double to choose the data type
> double
        39.87 24.42 322.71 45.27 312.22 132.14 233.9 85.51 95.08 121.14

        24.42 is the min value at index 1
        322.71 is the max value at index 2


Do you want try this again?
> y
******************************************************

Enter either string, int, or double to choose the data type
> string
        Enter 10 words
                1: billy
                2: west
                3: futurama
                4: brad
                5: bryan
                6: fry
                7: leela
                8: farnsworth
                9: bender
                10: interplanetary

        billy west futurama brad bryan fry leela farnsworth bender interplanetary

        bender is the min value at index 8
        west is the max value at index 1


Do you want try this again?
> n
Press any key to continue . . .




Enter either string, int, or double to choose the data type
> double
        255.16 185.13 313.37 135.61 327.48 101.38 280.79 81.98 19.04 290.09

        19.04 is the min value at index 8
        327.48 is the max value at index 4


Do you want try this again?
> y
******************************************************

Enter either string, int, or double to choose the data type
> string
        Enter 10 words
                1: bacon
                2: admiral
                3: chocolate
                4: hermes
                5: conrad
                6: captain
                7: new
                8: hard
                9: you
                10: sigh

        bacon admiral chocolate hermes conrad captain new hard you sigh

        admiral is the min value at index 1
        you is the max value at index 8


Do you want try this again?
> y
******************************************************

Enter either string, int, or double to choose the data type
> int
        166 84 285 266 19 118 6 240 291 2

        2 is the min value at index 9
        291 is the max value at index 8


Do you want try this again?
> n
Press any key to continue . . .
*/