/*
Bradley Gallardo
CS41
complex.h
Header File 
*/
#include <iostream>
#ifndef COMPLEX_H
#define COMPLEX_H

class Complex;
std::ostream &operator << (std::ostream &, const Complex &);
std::istream &operator >> (std::istream &, Complex &);

class Complex {
private:
	double real, imaginary;
public:
	//-------------Assignment Overload-------------//
	Complex operator=(const Complex &); //Assignment

	//-------------Arithmetic Overloads-------------//
	Complex operator+(const Complex &); //Addition
	Complex operator-(const Complex &); //Subtraction
	Complex operator*(const Complex &); //Multiplication
	Complex operator/(const Complex &); //Division
	Complex operator++(); //Pre-increment
	Complex operator--(); //Pre-decrement
	
	//-------------Comparison Overloads-------------//
	bool operator==(const Complex &); //Equal to
	bool operator!=(const Complex &); //Not equal to
	bool operator>(const Complex &); //Greater than
	bool operator<(const Complex &); //Less than
	bool operator>=(const Complex &); //Greater than or equal to
	bool operator<=(const Complex &); //Less than or equal to

	//-------------Input/Output Overloads-------------//
	friend std::ostream &operator << (std::ostream &oStream, const Complex &obj); //Insertion Operator
	friend std::istream &operator >> (std::istream &iStream, Complex &num); //Extraction Operator
	
	//-------------Absolute Value Overload-------------//
	static Complex cabs(Complex &); //Complex Absolute

	//-------------Main Menu-------------//
	static void menu();
};
//-------------Console Colors-------------//
enum Colors { //Availiable windows console colors (D = Dark, B = Bright)
	BLUE = 1, GREEN, CYAN, RED, PURPLE, DYELLOW, CLASSICWHITE, GREY, BBLUE, BGREEN, BCYAN, BRED, PINK, YELLOW, BWHITE
};
void set_color(Colors); //set color of everything after
char* color_in(Colors, char*); //set color of line of text
Colors get_default_color(); //finds user's default console text color
#endif