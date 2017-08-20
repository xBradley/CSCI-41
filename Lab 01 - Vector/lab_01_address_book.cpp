#include <iostream>
#include <conio.h>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

void enter_data(vector<string>&, vector<string>&);
void display_address(vector<string>, vector<string>);
void sort_name_address(vector<string>&, vector<string>&);

int main(void)
{
	vector<string>names;
	vector<string>addresses;

	enter_data(names, addresses);

	display_address(names, addresses);

	sort_name_address(names, addresses);

	display_address(names, addresses);


	cout << endl << "Press any key to continue..." << endl;
	_getch();

	return 0;
}

void enter_data(vector<string>& names, vector<string>& addresses) //get names and addresses and put them into a two seperate vectors 
{
	string name;
	string address;
	int size = 0;

	cout << "How many names would you like to add to the address book" << endl << "> ";
	cin >> size;

	while (!cin)
	{
		cout << endl << "Please enter a number..." << endl << "> "; //if size is not an int, ask again
		cin.clear();
		cin.ignore();
		cin >> size;
	}


	for (int i = 0; i < size; i++)
	{
		if (i == 0)
			cin.ignore();

		cout << endl << i + 1 << ". Enter the name" << endl << "> ";
		getline(cin, name);

		names.push_back(name);

		cout << endl << "\tEnter the address" << endl << "\t> ";
		getline(cin, address);

		addresses.push_back(address);

	}
	cout << endl;
}

void display_address(vector<string> names, vector<string> addresses) //displays addresses and names
{
	int longestName = names[0].size(); 

	for (int i = 1; i < names.size(); i++) //scan name vector to find the longest name
	{
		if (names[i].size() > longestName)
			longestName = names[i].size();
	}

	cout << left << setw(longestName + 6) << "\tNames" << "Addresses" << endl
		 << "_______________________________________" << endl;

	for (int index = 0; index < names.size(); index++)
	{
		cout << index + 1 << ".\t" << left << setw(longestName + 5) << names[index] << addresses[index] << endl;
	}
	cout << endl;
}

void sort_name_address(vector<string>& names, vector<string>& addresses) //sorts names in a;phabetcal order with the same address 
{
	int startScan, maxIndex;
	string tempNames;
	string maxValue;

	for (startScan = 0; startScan < (names.size() - 1); startScan++)
	{
		maxIndex = startScan;
		maxValue = names[startScan];
		tempNames = addresses[startScan];
		for (int index = (startScan + 1); index < names.size(); index++)
		{
			if (names[index] < maxValue)
			{
				maxValue = names[index];
				tempNames = addresses[index];
				maxIndex = index;
			}
		}
		names[maxIndex] = names[startScan];
		addresses[maxIndex] = addresses[startScan];
		names[startScan] = maxValue;
		addresses[startScan] = tempNames;
	}
}


/*
How many names would you like to add to the address book
> 4

1. Enter the name
> Bradley Gallardo

        Enter the address
        > 1234 King Street

2. Enter the name
> Bryan Gallardo

        Enter the address
        > 234 G Ave, Parlier, California

3. Enter the name
> Sandra Barrios

        Enter the address
        > 345 Apt B. Fresno, California

4. Enter the name
> Micheal Hernandez

        Enter the address
        > 563 Dennis Drive Sanger, California

        Names                 Addresses
_______________________________________
1.      Bradley Gallardo      1234 King Street
2.      Bryan Gallardo        234 G Ave, Parlier, California
3.      Sandra Barrios        345 Apt B. Fresno, California
4.      Micheal Hernandez     563 Dennis Drive Sanger, California

        Names                 Addresses
_______________________________________
1.      Bradley Gallardo      1234 King Street
2.      Bryan Gallardo        234 G Ave, Parlier, California
3.      Micheal Hernandez     563 Dennis Drive Sanger, California
4.      Sandra Barrios        345 Apt B. Fresno, California


Press any key to continue...



How many names would you like to add to the address book
> 2

1. Enter the name
> Nick Cage

        Enter the address
        > 896 Apple St. Selma, California

2. Enter the name
> Mac Johnson

        Enter the address
        > 1166 Nike Ave. Fresno, California

        Names           Addresses
_______________________________________
1.      Nick Cage       896 Apple St. Selma, California
2.      Mac Johnson     1166 Nike Ave. Fresno, California

        Names           Addresses
_______________________________________
1.      Mac Johnson     1166 Nike Ave. Fresno, California
2.      Nick Cage       896 Apple St. Selma, California


Press any key to continue...



How many names would you like to add to the address book
> a

Please enter a number...
> b

Please enter a number...
> 5

1. Enter the name
> Dee Harrison

        Enter the address
        > 254 Blue Street Burbank, Canada

2. Enter the name
> Raul Garcia

        Enter the address
        > 123 Windows Ave. Parlier, Texas

3. Enter the name
> Jacob Padilla

        Enter the address
        > 423 Bigger Street Parlier, California

4. Enter the name
> Jesus Guzman

        Enter the address
        > 345 Rasberry Drive Sanger, California

5. Enter the name
> Samantha Gallardo

        Enter the address
        > 235 Google St. Parlier, Nevada

        Names                 Addresses
_______________________________________
1.      Dee Harrison          254 Blue Street Burbank, Canada
2.      Raul Garcia           123 Windows Ave. Parlier, Texas
3.      Jacob Padilla         423 Bigger Street Parlier, California
4.      Jesus Guzman          345 Rasberry Drive Sanger, California
5.      Samantha Gallardo     235 Google St. Parlier, Nevada

        Names                 Addresses
_______________________________________
1.      Dee Harrison          254 Blue Street Burbank, Canada
2.      Jacob Padilla         423 Bigger Street Parlier, California
3.      Jesus Guzman          345 Rasberry Drive Sanger, California
4.      Raul Garcia           123 Windows Ave. Parlier, Texas
5.      Samantha Gallardo     235 Google St. Parlier, Nevada


Press any key to continue...

*/