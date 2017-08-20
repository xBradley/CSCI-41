#include <iostream.>
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