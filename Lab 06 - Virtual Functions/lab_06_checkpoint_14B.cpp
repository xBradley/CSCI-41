#include <iostream>
using namespace std;
class First
{
protected:
	int a;
public:
	First(int x = 1)
	{
		a = x;
	}
	virtual void twist()
	{
		a *= 2;
	}
	int getVal()
	{
		twist(); return a;
	}
};
class Second : public First
{
private:
	int b;
public:
	Second(int y = 5)
	{
		b = y;
	}
	virtual void twist()
	{
		a *= 50;
	}
};
int main()
{
	First object1;
	Second object2;
	cout << object1.getVal() << endl;
	cout << object2.getVal() << endl;

	cin.ignore();
	cout << "Press any ket to continue..." << endl;
	cin.get();
	return 0;
}
/*
2
50
Press any key to continue...

	Object1 is initialized to class First and is set to 1. When object1 uses getVal() to display its
value, twist() is called. Object1 is multiplied by 2 and is set to that value. Object2 is initialized
to class Second and is set to 5. When object2 uses getVal() to display its value, twist() is called
again but since it is a virtual function, it uses the definition in class Second. Twist() multiplies 
value a by 50. Object2 display 50.
*/