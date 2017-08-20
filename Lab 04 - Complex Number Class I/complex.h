/*
Bradley Gallardo
CS41
complex.h
Header File 
*/
#include <iostream>
#include <fstream>
#ifndef COMPLEX_H
#define COMPLEX_H

class Complex;
std::ostream &operator << (std::ostream &, const Complex &);
std::istream &operator >> (std::istream &, Complex &);
std::ofstream &operator << (std::ofstream &, const Complex &);

class Complex {
private:
	double real, imaginary;
public:
	//-------------Constructors-------------//
	Complex(); //Default
	Complex(double, double); //Standard
	Complex(const Complex &); //Copy

	//-------------Mutators-------------//
	void setReal(const double &); 
	void setImaginary(const double &);

	//-------------Accessors-------------//
	double getReal();
	double getImaginary();
	static void outputConstructors(const Complex &, const Complex &, const Complex &, std::ofstream &);
	static void outputExtraction(const Complex &, std::ofstream &);
	static void outputAssignment(const Complex &, const Complex &, const Complex &, std::ofstream &);
	

	//-------------Operator Overloads-------------//
	Complex operator=(const Complex &); //Assignment Operator
	friend std::ostream &operator << (std::ostream &oStream, const Complex &obj); //Insertion Operator
	friend std::istream &operator >> (std::istream &iStream, Complex &num); //Extraction Operator
	friend std::ofstream &operator << (std::ofstream &ofSteam, const Complex &obj); //File Insertion Operator
};
//-------------Non-Member Functions-------------//
void fileCheck(const std::ofstream &);
char repeat();
#endif