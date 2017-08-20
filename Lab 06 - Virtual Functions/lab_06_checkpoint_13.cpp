#include <iostream>
class First
{
protected:
	int a;
public:
	First(int x = 1)
	{
		a = x;
	}
	void twist()
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
	void twist()
	{
		b *= 10; 
	}
};

int main()
{
	First object1;
	Second object2;
	std::cout << object1.getVal() << std::endl;
	std::cout << object2.getVal() << std::endl;

	std::cout << "Press any key to continue..." << std::endl;
	std::cin.get();
	return 0;
}
/*
2
2
Press any key to continue...

	Object1 is initialized to the class First and is set to 1 (by the constructor). When object1 is 
displayed using getVal() it also calls twist(), which multiplies the 1 by 2. Object1 will thus show 2.
Object2 is initialized to the class Second and is set to 5. Second inherits First so when object2 is
displayed using getVal() it uses twist() from Second but still returns a. So the display is 2 2.
*/