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
	int getVal()
	{
		return a;
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
	int getVal()
	{
		return b;
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
1
5
Press any key to continue...

This is the output becuase object1 is initilized as class First. So the 
constructor sets object1 to 1. Object2 is initilized as class Second. The 
constructor then sets object2 to 5. Both uses getVal() to cout their values.
*/