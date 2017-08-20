/*
Bradley Gallardo
CS41
complex.cpp
Implementation File
*/
#include <iostream>
#include <cmath> //for sqrt() & pow()
#include "complex.h"
#include <Windows.h> //for sleep()

//-------------Main Menu Function-------------//
void Complex::menu() {
	char copyPaste;
	std::cout << color_in(BGREEN, "If you are trying to copy-n-paste the console, enter \'y\'.") << std::endl << "> ";
	std::cin >> copyPaste;

	system("cls"); //clears console

	int choice;
	Complex c1, c2, result, temp1, temp2;
	Colors default = get_default_color(); //finds user's default text color 
	do {
		std::cout << color_in(BCYAN, "****************************************************************************************") << std::endl
			<< "****************************************************************************************" << std::endl
			<< "**"; std::cout << color_in(BRED, "+----------------------------------------------------------------------------------+"); std::cout << color_in(BCYAN, "**") << std::endl
			<< "**"; std::cout << color_in(BRED, "|_______________________________________________________________________           |");  std::cout << color_in(BCYAN, "**") << std::endl
			<< "**"; std::cout << color_in(BRED, "|______/\\\\\\\\____________/\\\\\\\\____________________________________________\\         |");  std::cout << color_in(BCYAN, "**") << std::endl
			<< "**"; std::cout << color_in(BRED, "|\\_____\\/\\\\\\\\\\\\________/\\\\\\\\\\\\____________________________________________\\        |");  std::cout << color_in(BCYAN, "**") << std::endl
			<< "**"; std::cout << color_in(BRED, "| \\_____\\/\\\\\\//\\\\\\____/\\\\\\//\\\\\\____________________________________________\\       |");  std::cout << color_in(BCYAN, "**") << std::endl
			<< "**"; std::cout << color_in(BRED, "|/ \\_____\\/\\\\\\\\///\\\\\\/\\\\\\/_\\/\\\\\\_____/\\\\\\\\\\\\\\\\___/\\\\/\\\\\\\\\\\\____/\\\\\\____/\\\\\\_\\      |");  std::cout << color_in(BCYAN, "**") << std::endl
			<< "**"; std::cout << color_in(BRED, "| / \\_____\\/\\\\\\__\\///\\\\\\/___\\/\\\\\\___/\\\\\\/////\\\\\\_\\/\\\\\\////\\\\\\__\\/\\\\\\___\\/\\\\\\_\\     |");  std::cout << color_in(BCYAN, "**") << std::endl
			<< "**"; std::cout << color_in(BRED, "|/ / \\_____\\/\\\\\\____\\///_____\\/\\\\\\__/\\\\\\\\\\\\\\\\\\\\\\__\\/\\\\\\__\\//\\\\\\_\\/\\\\\\___\\/\\\\\\_\\    |");  std::cout << color_in(BCYAN, "**") << std::endl
			<< "**"; std::cout << color_in(BRED, "| / / \\_____\\/\\\\\\_____________\\/\\\\\\_\\//\\\\///////___\\/\\\\\\___\\/\\\\\\_\\/\\\\\\___\\/\\\\\\_\\   |");  std::cout << color_in(BCYAN, "**") << std::endl
			<< "**"; std::cout << color_in(BRED, "|/ / / \\_____\\/\\\\\\_____________\\/\\\\\\__\\//\\\\\\\\\\\\\\\\\\\\_\\/\\\\\\___\\/\\\\\\_\\//\\\\\\\\\\\\\\\\\\__\\  |");  std::cout << color_in(BCYAN, "**") << std::endl
			<< "**"; std::cout << color_in(BRED, "| / / / \\_____\\///______________\\///____\\//////////__\\///____\\///___\\/////////___\\ |");  std::cout << color_in(BCYAN, "**") << std::endl
			<< "**"; std::cout << color_in(BRED, "|/ / / / \\________________________________________________________________________\\|");  std::cout << color_in(BCYAN, "**") << std::endl
			<< "**"; std::cout << color_in(BRED, "| / / / /__________________________________________________     + Addition 1._____/|");  std::cout << color_in(BCYAN, "**") << std::endl
			<< "**"; std::cout << color_in(BRED, "|/ / / /_____________________________                     - Subtraction 2. ______/ |");  std::cout << color_in(BCYAN, "**") << std::endl
			<< "**"; std::cout << color_in(BRED, "| / / /_______________________                       * Multiplication 3. _______/  |");  std::cout << color_in(BCYAN, "**") << std::endl
			<< "**"; std::cout << color_in(BRED, "|/ / /__________                                         / Division 4. ________/   |");  std::cout << color_in(BCYAN, "**") << std::endl
			<< "**"; std::cout << color_in(BRED, "| / /____________________                            ++ Increment 5. _________/    |");  std::cout << color_in(BCYAN, "**") << std::endl
			<< "**"; std::cout << color_in(BRED, "|/ /______________                                 -- Decrement 6. __________/     |");  std::cout << color_in(BCYAN, "**") << std::endl
			<< "**"; std::cout << color_in(BRED, "| /__________________                             == Equal to 7. ___________/      |");  std::cout << color_in(BCYAN, "**") << std::endl
			<< "**"; std::cout << color_in(BRED, "|/_________________________                 != Not Equal to 8. ____________/       |");  std::cout << color_in(BCYAN, "**") << std::endl
			<< "**"; std::cout << color_in(BRED, "|_______                                   > Greater than 9. _____________/        |");  std::cout << color_in(BCYAN, "**") << std::endl
			<< "**"; std::cout << color_in(BRED, "|______________               >= Greater than or Equal 10. ______________/         |");  std::cout << color_in(BCYAN, "**") << std::endl
			<< "**"; std::cout << color_in(BRED, "|_________                           < 11. Less than 11. _______________/          |");  std::cout << color_in(BCYAN, "**") << std::endl
			<< "**"; std::cout << color_in(BRED, "|_______________________     <= Less than or Equal 12. ________________/           |");  std::cout << color_in(BCYAN, "**") << std::endl
			<< "**"; std::cout << color_in(BRED, "|________                      || Absolute Value 13. _________________/            |");  std::cout << color_in(BCYAN, "**") << std::endl
			<< "**"; std::cout << color_in(BRED, "|___ Quit 0.     ____________________________________________________/             |");  std::cout << color_in(BCYAN, "**") << std::endl
			<< "**"; std::cout << color_in(BRED, "|___________________________________________________________________/              |");  std::cout << color_in(BCYAN, "**") << std::endl
			<< "**"; std::cout << color_in(BRED, "+----------------------------------------------------------------------------------+");  std::cout << color_in(BCYAN, "**") << std::endl
			<< "****************************************************************************************" << std::endl
			<< "****************************************************************************************" << std::endl << std::endl;

		std::cout << color_in(CLASSICWHITE, "Please make a selection") << std::endl;
		std::cout << color_in(GREY, "> ");
		std::cin >> choice;

		switch (choice) { //quit
		case 0:
			std::cout << color_in(CLASSICWHITE, "Program will now exit") << std::endl;
			break;

		case 1: //add
			std::cout << color_in(CLASSICWHITE, "Enter two complex numbers:") << std::endl;
			std::cin >> c1 >> c2;

			result = c1 + c2;
			set_color(YELLOW);
			std::cout << "\t\t(" << c1 << ") + (" << c2 << ") = " << result << std::endl;
			set_color(default);
			break;

		case 2: //subtract
			std::cout << color_in(CLASSICWHITE, "Enter two complex numbers:") << std::endl;
			std::cin >> c1 >> c2;

			result = c1 - c2;
			set_color(YELLOW);
			std::cout << "(" << c1 << ") - (" << c2 << ") = " << result << std::endl;
			set_color(default);
			break;

		case 3: //muliply
			std::cout << color_in(CLASSICWHITE, "Enter two complex numbers:") << std::endl;
			std::cin >> c1 >> c2;

			result = c1 * c2;
			set_color(YELLOW);
			std::cout << "(" << c1 << ") * (" << c2 << ") = " << result << std::endl;
			set_color(default);
			break;

		case 4: //divide
			std::cout << color_in(CLASSICWHITE, "Enter two complex numbers:") << std::endl;
			std::cin >> c1 >> c2;

			result = c1 / c2;
			set_color(YELLOW);
			std::cout << "(" << c1 << ") / (" << c2 << ") = " << result << std::endl;
			set_color(default);
			break;

		case 5: //increment
			std::cout << color_in(CLASSICWHITE, "Enter two complex numbers:") << std::endl;
			std::cin >> c1 >> c2;

			temp1 = c1;
			temp2 = c2;
			++temp1;
			++temp2;
			set_color(YELLOW);
			std::cout << "++(" << c1 << ") = " << temp1 << std::endl;
			std::cout << "++(" << c2 << ") = " << temp2 << std::endl;
			set_color(default);
			break;

		case 6: //decrement
			std::cout << color_in(CLASSICWHITE, "Enter two complex numbers:") << std::endl;
			std::cin >> c1 >> c2;

			temp1 = c1;
			temp2 = c2;
			--temp1;
			--temp2;
			set_color(YELLOW);
			std::cout << "--(" << c1 << ") = " << temp1 << std::endl;
			std::cout << "--(" << c2 << ") = " << temp2 << std::endl;
			set_color(default);
			break;

		case 7: //equal to
			std::cout << color_in(CLASSICWHITE, "Enter two complex numbers:") << std::endl;
			std::cin >> c1 >> c2;

			set_color(YELLOW);
			if (c1 == c2)
				std::cout << "(" << c1 << ") is equal to (" << c2 << ") " << std::endl;
			else
				std::cout << "(" << c1 << ") is not equal to (" << c2 << ") " << std::endl;
			set_color(default);
			break;

		case 8: //not equal to
			std::cout << color_in(CLASSICWHITE, "Enter two complex numbers:") << std::endl;
			std::cin >> c1 >> c2;

			set_color(YELLOW);
			if (c1 != c2)
				std::cout << "(" << c1 << ") is not equal to (" << c2 << ") " << std::endl;
			else
				std::cout << "(" << c1 << ") is equal to (" << c2 << ") " << std::endl;
			set_color(default);
			break;

		case 9: //greater than
			std::cout << color_in(CLASSICWHITE, "Enter two complex numbers:") << std::endl;
			std::cin >> c1 >> c2;

			set_color(YELLOW);
			if (c1 > c2)
				std::cout << "(" << c1 << ") is greater than (" << c2 << ") " << std::endl;
			else
				std::cout << "(" << c1 << ") is not greater than (" << c2 << ") " << std::endl;
			set_color(default);
			break;

		case 10: //greater than or equal
			std::cout << color_in(CLASSICWHITE, "Enter two complex numbers:") << std::endl;
			std::cin >> c1 >> c2;

			set_color(YELLOW);
			if (c1 >= c2)
				std::cout << "(" << c1 << ") is greater than or equal to (" << c2 << ") " << std::endl;
			else
				std::cout << "(" << c1 << ") is not greater than or equal to (" << c2 << ") " << std::endl;
			set_color(default);
			break;

		case 11: //less than
			std::cout << color_in(CLASSICWHITE, "Enter two complex numbers:") << std::endl;
			std::cin >> c1 >> c2;

			set_color(YELLOW);
			if (c1 < c2)
				std::cout << "(" << c1 << ") is less than (" << c2 << ") " << std::endl;
			else
				std::cout << "(" << c1 << ") is not less than (" << c2 << ") " << std::endl;
			set_color(default);
			break;

		case 12: //less than or equal
			std::cout << color_in(CLASSICWHITE, "Enter two complex numbers:") << std::endl;
			std::cin >> c1 >> c2;

			set_color(YELLOW);
			if (c1 <= c2)
				std::cout << "(" << c1 << ") is less than or equal to (" << c2 << ") " << std::endl;
			else
				std::cout << "(" << c1 << ") is not less than or equal to (" << c2 << ") " << std::endl;
			set_color(default);
			break;

		case 13: //absolute value
			std::cout << color_in(CLASSICWHITE, "Enter two complex numbers:") << std::endl;
			std::cin >> c1 >> c2;

			set_color(YELLOW);
			std::cout << "|" << c1 << "| = ";
			cabs(c1);
			std::cout << c1 << std::endl;

			std::cout << "|" << c2 << "| = ";
			cabs(c2);
			std::cout << c2 << std::endl;
			set_color(default);
			break;

		default: //edge cases
			std::cout << color_in(CLASSICWHITE, "Invalid input...please selection a option ") << std::endl;
			std::cout << color_in(GREY, "> ");
			std::cin >> choice;
		}

		if (choice != 0) {

			set_color(BWHITE); //conosle will clear after 5 seconds if the copy paste option is not 'y'
			for (int i = 5; i >= 0; i--) {
				if (i == 5)
					std::cout << "Console will automatically clear in 5 secounds..." << std::endl;
				else if (i == 0)
					std::cout << "\tClearing..." << std::endl;
				else if (i == 1)
					std::cout << "\t" << i << " second" << std::endl;
				else
					std::cout << "\t" << i << " seconds" << std::endl;
				Sleep(1000); //1000 milliseconds = 1 second 
			}
			if (copyPaste == 'y') { //console will pause after countdown, then clear
				std::cin.ignore();
				std::cout << color_in(BGREEN, "Press enter to continue...") << std::endl;
				std::cin.get();
			}
			system("cls");

			set_color(default);
		}
	} while (choice != 0);
}


//-------------Assignment Function Overload-------------//
Complex Complex::operator=(const Complex &right) { //Assignment
	real = right.real; 
	imaginary = right.imaginary;

	return *this;
}


//-------------Arithmetic Function Overloads-------------//
Complex Complex::operator+(const Complex &obj) { //Addition
	Complex sum;

	sum.real = real + obj.real;
	sum.imaginary = imaginary + obj.imaginary;

	return sum;
}

Complex Complex::operator-(const Complex &obj) { //Subtraction
	Complex difference;

	difference.real = real - obj.real;
	difference.imaginary = imaginary - obj.imaginary;

	return difference;
}

Complex Complex::operator*(const Complex &obj) { //Multiplication
	Complex product;

	product.real = (real * obj.real) - (imaginary * obj.imaginary);
	product.imaginary = (real * obj.imaginary) + (imaginary * obj.real);

	return product;
}

Complex Complex::operator/(const Complex &obj) { //Division
	Complex quotient;

	quotient.real = ((real * obj.real) - (imaginary * obj.imaginary)) / (pow(obj.real, 2.0) + pow(obj.imaginary, 2.0));
	quotient.imaginary = ((imaginary * obj.real) - (real * obj.imaginary)) / (pow(obj.real, 2.0) + pow(obj.imaginary, 2.0));

	return quotient;
}

Complex Complex::operator++() { //Pre-incremenet
	++real;
	++imaginary;

	return *this;
}

Complex Complex::operator--() { //pre-decrement
	--real;
	--imaginary;

	return *this;
}


//-------------Comparison Function Overloads-------------//
bool Complex::operator==(const Complex &obj) { //Equal to
	bool result;

	if (real == obj.real && imaginary == obj.imaginary)
		result = true;
	else
		result = false;

	return result;
}

bool Complex::operator!=(const Complex &obj) { //Not equal to
	bool result;

	if (real != obj.real || imaginary != obj.imaginary)
		result = true;
	else
		result = false;

	return result;
}

bool Complex::operator>(const Complex &obj) { //Greater than
	bool result;

	if (real > obj.real)
		result = true;
	else if (real == obj.real && imaginary > obj.imaginary)
		result = true;
	else
		result = false;

	return result;
}

bool Complex::operator<(const Complex &obj) { //Less than
	bool result;

	if (real < obj.real)
		result = true;
	else if (real == obj.real && imaginary < obj.imaginary)
		result = true;
	else
		result = false;

	return result;
}

bool Complex::operator>=(const Complex &obj) { //Greater than or equal to
	bool result;

	if (real > obj.real)
		result = true;
	else if (real == obj.real && imaginary >= obj.imaginary)
		result = true;
	else
		result = false;

	return result;
}

bool Complex::operator<=(const Complex &obj) { //Less than or equal to
	bool result;

	if (real < obj.real)
		result = true;
	else if (real == obj.real && imaginary <= obj.imaginary)
		result = true;
	else
		result = false;

	return result;
}


//-------------Input/Output Function Overloads-------------//
std::ostream &operator << (std::ostream &oStream, const Complex &obj) { //Insertion
	
	if (obj.imaginary < 0)
		oStream << obj.real << " - " << std::fabs(obj.imaginary) << "i";
	else 
		oStream << obj.real << " + " << obj.imaginary << "i";

	return oStream;
}

std::istream &operator >> (std::istream &iStream, Complex &obj) { //Extraction
	std::cout << color_in(CLASSICWHITE, "\tEnter a complex number (seperated by a space)") << std::endl;
	std::cout << color_in(GREY, "\t> ");
	iStream >> obj.real >> obj.imaginary;

	return iStream;
}


//-------------Absolute Value Function Overload-------------//
Complex Complex::cabs(Complex &obj) { //Complex Absolute
	obj.real = sqrt(pow(obj.real, 2));
	obj.imaginary = sqrt(pow(obj.imaginary, 2));

	return obj;
}


//-------------Console Colors Functions-------------//
Colors get_default_color() {
	unsigned short userColor;
	_CONSOLE_SCREEN_BUFFER_INFO info; //struct of <wincon.h> object wAttribute contains text color

	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info)) //gets user's current text color value
		userColor = info.wAttributes; 

	for (int i = BLUE; i <= BWHITE;) { //finds value of color
		if (userColor != i)
			i++;
		else
			return static_cast<Colors>(i); //returns user's default text color settings 
	}
}

void set_color(Colors c) { //sets color of everything after
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c); 
}

char* color_in(Colors c, char* message = "") { //can be used in a cout to change color
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);

	return message;
}