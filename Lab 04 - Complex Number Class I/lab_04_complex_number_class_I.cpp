/*
Bradley Gallardo
CS41
Class Number Class I
Driver File
------------------------------------------------------------
                         Complex                           |
------------------------------------------------------------
- real : double                                            |
- private : double										   |
------------------------------------------------------------
+ Complex() 										       |
+ Complex(double, double)					    		   |
+ Complex(Complex)										   |
+ setReal(double)										   |
+ setImaginary(double)									   |
+ getReal() : double									   |
+ getImaginary() : double								   |
+ operator=(Complex) : Complex							   |
+ operator<<(ostream, Complex) : ostream				   |
+ operator>>(istream, Complex) : istream				   |
+ operator<<(ofstream, Complex) : ofstream				   |
+ outputConstructors(Complex, Complex, Complex, ofstream)  |
+ outputExtraction(Complex, ofstream)					   |
+ outputAssignment(Complex, Complex, Complex, ofstream)	   |
+ fileCheck(ofstream)									   |
+ repeat() : char										   |
------------------------------------------------------------
*/
#include <iostream>
#include <cstdlib>
#include "complex.h"

int main() {
	Complex c1, c2, c3;
	char again;
	std::ofstream outputFile("results.txt");

	fileCheck(outputFile);

	
		c1 = Complex();
		c2 = Complex(2, -4);
		c3 = Complex(c2);

		std::cout << "--------Constuctors--------" << std::endl;
		std::cout << "c1 = " << c1 << std::endl
			<< "c2 = " << c2 << std::endl
			<< "c3 = " << c3 << std::endl << std::endl;

		Complex::outputConstructors(c1, c2, c3, outputFile);

		do {
		std::cout << "--------Extraction Operator--------" << std::endl;
		std::cin >> c1;
		std::cout << "c1 = " << c1 << std::endl << std::endl;

		Complex::outputExtraction(c1, outputFile);

		std::cout << "--------Assignment Operator--------" << std::endl;
		c2 = c1;
		c1 = c3;
		std::cout << "c1 = " << c1 << std::endl
			      << "c2 = " << c2 << std::endl << std::endl;

		Complex::outputAssignment(c1, c2, c3, outputFile);

		again = repeat();

	} while (again == 'Y' || again != 'N');

	outputFile.close();

	system("pause");
	return 0;
}
/*
--------Constuctors--------
c1 = 0 + 0i
c2 = 2 - 4i
c3 = 2 - 4i

--------Extraction Operator--------
Enter a value for a real part
> 3
Enter a value for a complex part
> -2
c1 = 3 - 2i

--------Assignment Operator--------
c1 = 2 - 4i
c2 = 3 - 2i


Do you want try this again?
> j
Please enter a either Y or N
> y
******************************************************

--------Extraction Operator--------
Enter a value for a real part
> -89.3
Enter a value for a complex part
> 100
c1 = -89.3 + 100i

--------Assignment Operator--------
c1 = 2 - 4i
c2 = -89.3 + 100i


Do you want try this again?
> y
******************************************************

--------Extraction Operator--------
Enter a value for a real part
> 4.20
Enter a value for a complex part
> -69
c1 = 4.2 - 69i

--------Assignment Operator--------
c1 = 2 - 4i
c2 = 4.2 - 69i


Do you want try this again?
> n
Press any key to continue . . .
*/