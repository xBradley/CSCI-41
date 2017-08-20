#include <iostream>
using namespace std;
class Base
{
protected:
	int baseVar;
public:
	Base(int val = 2)
	{
		baseVar = val;
	}
	int getVar()
	{
		return baseVar;
	}
};
class Derived : public Base
{
private:
	int derivedVar;
public:
	Derived(int val = 100)
	{
		derivedVar = val;
	}
	int getVar()
	{
		return derivedVar;
	}
};
int main()
{
	Base *optr = nullptr;
	Derived object;
	optr = &object;
	cout << optr->getVar() << endl;

	cout << "Press any key to continue..." << endl;
	cin.get();
	return 0;
}

/*
2
Press any key to continue...

	Optr is null pointer of class Base. Object is initialized to class Derived and is set to 100. 
Since object is a from class Derived it inherits class Base, they shar base class. So when optr is 
assigned to the address of object. Optr has the value of 2, since that is the inherited class. Optr
then displays 2. If a Dervived pointer was created and assigned to object. It would display 100
since that is value of the dervived variable.
*/