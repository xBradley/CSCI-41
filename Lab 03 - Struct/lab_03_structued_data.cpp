/*
Bradley Gallardo
CS41
Course Grade
Gets student information and calculates grade
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>

struct StudentInfo {
	std::string name;
	std::string IDnum;
	double testScores[3];
	double average = 0;
	char grade;
};

void setStudents(StudentInfo*&, unsigned int&);
void setStudentInfo(StudentInfo*, unsigned int);
void getGrade(StudentInfo*, unsigned int);
void outputStudentReport(StudentInfo*, unsigned int, std::ofstream&);
char repeat();

int main() {
	std::ofstream outputFile("student_report.txt");
	char again = 'Y';

	if (outputFile.fail()) { //if file fails to open the program will close
		std::cout << "Output file failed to open..." << std::endl;

		system("pause");
		exit(0);
	} 

	do {
		StudentInfo *studentPtr = NULL;
		unsigned int size;

		setStudents(studentPtr, size); //create structure array

		setStudentInfo(studentPtr, size); //get student info

		getGrade(studentPtr, size); //get grade

		outputStudentReport(studentPtr, size, outputFile); //output student info

		again = repeat(); //ask if repeat

	} while (again == 'Y' || again != 'N');

	outputFile.close();

	system("pause");
	return 0;
}

/*
+---------setStudent------------+
| Gets size and makes array of  |
|           students            |
+-------------------------------+
*/
void setStudents(StudentInfo* &ptr, unsigned int &size){

	std::cout << "How many students will be entered?" << std::endl << "> "; //gets size for structure array
	std::cin >> size; 

	while (!std::cin) { //check if size is an int
		std::cout << "Please enter a number!" << std::endl << "> "; 
		std::cin.clear();
		std::cin.ignore();
		
		std::cin >> size;
	}
	ptr = new StudentInfo[size]; //allocate memory for structure array
}

/*
+-------setStudentInfo----------+
|  Ask if user whats to repeat  |
|       the code again          |
+-------------------------------+
*/
void setStudentInfo(StudentInfo *ptr, unsigned int size) {
	for (int i = 0; i < size; i++) {
		std::cin.ignore();

		std::cout << "STUDENT " << i + 1 << ":" << std::endl; 
		std::cout << "\tEnter student name" << std::endl << "\t\t\t> "; //get each student's name
		std::getline(std::cin, ptr[i].name);

		std::cout << "\tEnter student ID" << std::endl << "\t\t\t> "; //get each student's ID number
		std:getline(std::cin, ptr[i].IDnum);

		std::cout << "\tEnter 3 test scores" << std::endl;
		for (int index = 0; index < 3; index++) { //get each student's 3 test scores
			std::cout << "\t\tTest Score " << index + 1 << std::endl << "\t\t\t> ";
			std::cin >> ptr[i].testScores[index];

			while (!std::cin) { //checks if input is a number
				std::cout << "\tPlease enter a valid test scores!" << std::endl << "\t\t\t> ";
				std::cin.clear();
				std::cin.ignore();

				std::cin >> ptr[i].testScores[index];
			}
			ptr[i].average += ptr[i].testScores[index]; //accumulater for each student 
		}
		ptr[i].average /= 3.0; //calculates average
	}
}

/*
+-----------getGrade------------+
|  Checks average to calculate  |
|             grade             |
+-------------------------------+
*/
void getGrade(StudentInfo *ptr, unsigned int size){
	for (int i = 0; i < size; i++){ //check average and assigns proper grade
		if (ptr[i].average >= 90.0) ptr[i].grade = 'A';
		else if (ptr[i].average >= 80.0) ptr[i].grade = 'B';
		else if (ptr[i].average >= 70.0) ptr[i].grade = 'C';
		else if (ptr[i].average >= 60.0) ptr[i].grade = 'D';
		else if (ptr[i].average >= 50.0) ptr[i].grade = 'F';
		else
			std::cout << "getGrade function has failed..." << std::endl;
	}
}

/*
+------outputStudentReport------+
| Outputs student report into   |
|      student_report.txt       |
+-------------------------------+
*/
void outputStudentReport(StudentInfo *ptr, unsigned int size, std::ofstream &ofile) {
	unsigned int longestName, longestID;
	longestName = (ptr[0].name).size(); //sets longest name to first name
	longestID = (ptr[0].IDnum).size(); //sets longest id number to first id number

	for (int i = 1; i < size; i++) {
	
		if (longestName < (ptr[i].name).size()) //finds longest name
			longestName = (ptr[i].name).size(); 

		if (longestID < (ptr[i].IDnum).size()) //finds longest id number
			longestID = (ptr[i].IDnum).size();
	}

	ofile << std::left << std::setw(longestName + 5) << "NAME"
			  << std::setw(longestID + 5) << "ID"
			  << std::setw(10) << "TEST SCORES"
			  << std::right << std::setw(20) << "AVERAGE"
			  << std::setw(10) << "GRADE" << std::endl;

	ofile << "--------------------------------------------------------------------------" << std::endl;

	for (int i = 0; i < size; i++) {
		unsigned int numSpaces = 0;
		ofile << std::left << std::setw(longestName + 5) << ptr[i].name
				  << std::setw(longestID + 5) << ptr[i].IDnum;

		if ((ptr[i].testScores[0]) == 100.0) { //if first test score is 100, no decimal point
			ofile << std::fixed << std::setprecision(0) << std::setw(3) << ptr[i].testScores[0] << "% ";
			numSpaces++; //+1 to spaces needed
		} else //uses decimal point
			ofile << std::fixed << std::setprecision(1) << std::setw(4) << ptr[i].testScores[0] << "% ";

		if ((ptr[i].testScores[1]) == 100.0) { //if second test score is 100, no decimal point
			ofile << std::fixed << std::setprecision(0) << std::setw(3) << ptr[i].testScores[1] << "% ";
			numSpaces++; //+1 to spaces needed
		} else //uses decimal point
			ofile << std::fixed << std::setprecision(1) << std::setw(4) << ptr[i].testScores[1] << "% ";

		if ((ptr[i].testScores[2]) == 100.0) { //if third test score is 100, no decimal point
			ofile << std::fixed << std::setprecision(0) << std::setw(3) << ptr[i].testScores[2] << "% ";
			numSpaces++; //+1 to spaces needed
		} else //uses decimal point
			ofile << std::fixed << std::setprecision(1) << std::setw(4) << ptr[i].testScores[2] << "% ";

		for (int j = 0; j < numSpaces; j++) //add spaces to even out setw
			ofile << ' '; 

		ofile << std::right << std::setw(12) << ptr[i].average << '%';
		ofile << std::setw(10) << ptr[i].grade << std::endl << std::endl;
	}
	std::cout << std::endl << "Student information has been written in \"student_report\".txt" << std::endl;
}

/*
+------------repeat-------------+
| Ask if user whats to repeat   |
|       the main again          |
+-------------------------------+
*/
char repeat() {

	char input;
	std::cout << std::endl << "Do you want try this again?" << std::endl << "> ";
	std::cin >> input;

	input = toupper(input); //uppercases input

	while (input != 'Y' && input != 'N') { //checks if user input is not 'Y' or 'N' (edge cases)
		{
			std::cout << "Please enter a either Y or N" << std::endl << "> ";
			std::cin >> input;

			input = toupper(input);

			return input; //loops until user input is either yes or no
		}
		return input; //return if user input is yes or no
	}
}

/*
How many students will be entered?
> a
Please enter a number!
> 2
STUDENT 1:
        Enter student name
                        > Bradley Gallardo
        Enter student ID
                        > 0698391
        Enter 3 test scores
                Test Score 1
                        > a
        Please enter a valid test scores!
                        > 100
                Test Score 2
                        > 90.3
                Test Score 3
                        > 77.6
STUDENT 2:
        Enter student name
                        > Bryan Gallardo
        Enter student ID
                        > 0986374
        Enter 3 test scores
                Test Score 1
                        > 27.4
                Test Score 2
                        > 89.3
                Test Score 3
                        > 99.3

Student information has been written in "student_report".txt

Do you want try this again?
> j
Please enter a either Y or N
> y
How many students will be entered?
> 1
STUDENT 1:
        Enter student name
                        > Gordan Ramsay
        Enter student ID
                        > 1234567892
        Enter 3 test scores
                Test Score 1
                        > 12
                Test Score 2
                        > 92.3
                Test Score 3
                        > 100

Student information has been written in "student_report".txt

Do you want try this again?
> y
How many students will be entered?
> 4
STUDENT 1:
        Enter student name
                        > Tony Ibarra
        Enter student ID
                        > 213484
        Enter 3 test scores
                Test Score 1
                        > 100
                Test Score 2
                        > 43
                Test Score 3
                        > 100
STUDENT 2:
        Enter student name
                        > Evelyn Palacios
        Enter student ID
                        > 4373842342
        Enter 3 test scores
                Test Score 1
                        > 100
                Test Score 2
                        > 100
                Test Score 3
                        > 100
STUDENT 3:
        Enter student name
                        > Samantha Gallardo
        Enter student ID
                        > 32432
        Enter 3 test scores
                Test Score 1
                        > 89
                Test Score 2
                        > 78.4
                Test Score 3
                        > 100
STUDENT 4:
        Enter student name
                        > Raul Garcia
        Enter student ID
                        > 2437924
        Enter 3 test scores
                Test Score 1
                        > 89.3
                Test Score 2
                        > 30.4
                Test Score 3
                        > 99.9

Student information has been written in "student_report".txt

Do you want try this again?
> n
Press any key to continue . . .
*/