/*
Bradley Gallardo
CS41
complex.cpp
Implementation File
*/
#include <iostream>
#include <cmath>
#include <fstream>
#include "complex.h"

Complex::Complex() { //Default Constructor
	real = imaginary = 0; //sets complex values to zero
}

Complex::Complex(double r, double i) { //Standard Constructor
	real = r; //sets complex values to parameters values
	imaginary = i; 
}

Complex::Complex(const Complex &obj) { //Copy Constructor
	real = obj.real; //copies complex values from a another complex number  
	imaginary = obj.imaginary;
}

void Complex::setReal(const double &r) { //sets real to parameter
	real = r;
}

void Complex::setImaginary(const double &i) { //sets imaginary to parameter
	imaginary = i;
}

double Complex::getReal() { //returns real number
	return real;
}

double Complex::getImaginary() { //returns imaginary number
	return imaginary;
}

Complex Complex::operator=(const Complex &right) { //Assignment Overload
	real = right.real; 
	imaginary = right.imaginary;

	return *this;
}

std::ostream &operator << (std::ostream &oStream, const Complex &obj) { //Insertion Overload
	if (obj.imaginary < 0)
		oStream << obj.real << " - " << fabs(obj.imaginary) << "i ";
	else 
		oStream << obj.real << " + " << obj.imaginary << "i ";

	return oStream;
}

std::istream &operator >> (std::istream &iStream, Complex &obj) { //Extraction Overload
	std::cout << "Enter a value for a real part" << std::endl << "> ";
	iStream >> obj.real;

	std::cout << "Enter a value for a complex part" << std::endl << "> ";
	iStream >> obj.imaginary;

	return iStream;
}

std::ofstream &operator << (std::ofstream &ofSteam, const Complex &obj) { //File Insertion Overload
	if (obj.imaginary < 0)
		ofSteam << obj.real << " - " << fabs(obj.imaginary) << "i ";
	else
		ofSteam << obj.real << " + " << obj.imaginary << "i ";

	return ofSteam;
}

void Complex::outputConstructors(const Complex &obj1, const Complex &obj2, const Complex &obj3, std::ofstream &ofile) { //Copies constructor values and outputs to "results.txt"
	ofile << "--------Constructors--------" << std::endl;
	ofile << "c1 = " << obj1 << std::endl
		  << "c2 = " << obj2 << std::endl
		  << "c3 = " << obj3 << std::endl << std::endl;

}

void Complex::outputExtraction(const Complex &obj, std::ofstream &ofile) { //Copies extraction value and outputs to "results.txt"
	ofile << "--------Extraction Operator--------" << std::endl;
	ofile << "c1 = " << obj << std::endl << std::endl;
}

void Complex::outputAssignment(const Complex &obj1, const Complex &obj2, const Complex &obj3, std::ofstream &ofile) { //Copies assignment values and outputs to "results.txt"
	ofile << "--------Assignment Operator--------" << std::endl;
	ofile << "c1 = " << obj1 << std::endl
		  << "c2 = " << obj2 << std::endl << std::endl;
}

void fileCheck(const std::ofstream &ofile) { //Checks if file was created
	if (ofile.fail()) {
		std::cout << "File was failed to be created!!!\a" << std::endl;

		system("pause");
		exit(0);
	}
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
