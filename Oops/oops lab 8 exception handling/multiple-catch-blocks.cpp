// Multiple catch statements
#include <iostream>
using namespace std;
void test(int x)
{
	try
	{
		if (x == 1)
			throw x; // throw int
		else if (x == 0)
			throw 'x'; // throw char
		else if (x == -1)
			throw 1.0; // throw double
		cout << "\nEnd of try block:";
	}
	catch (char c)
	{
		cout << "\nCaught a character";
	}
	catch (int m)
	{
		cout << "\nCaught a integer";
	}
	catch (double d)
	{
		cout << "\nCaught a double";
	}
	cout << "\nEnd of catch block:";
}

int main()
{
	cout << "\nTesting multiple catches:";
	cout << "\nX == 1";
	test(1);
	cout << "\nX == 0";
	test(0);
	cout << "\nX == -1";
	test(-1);
	cout << "\nX == 2";
	test(2);

	return 0;
}
