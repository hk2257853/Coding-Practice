#include <iostream>
using namespace std;

class calc
{
private:
	int a, b, c, sum;

public:
	void dosum(int a, int b)
	{
		sum = a + b;
		cout << "Sum is:" << sum << "\n";
	}

	void dosum(int a, int b, int c)
	{
		sum = a + b + c;
		cout << "Sum is:" << sum << "\n";
	}
};

int main()
{
	calc cal;

	cal.dosum(1, 2);
	cal.dosum(1, 2, 7);

	return 0;
}
