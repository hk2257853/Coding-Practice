#include <iostream>
#include <conio.h>
#include <string>
using namespace std;
int main()
{
	string s1("good morning");
	string s2("good morning goa");

	int r = s1.compare(s2);
	cout << "\nresult : " << r;
	cout << "\n----------------------------------";
	if (s1 == s2)
		cout << "\nsame";
	else if (s1 > s2)
		cout << "\ns1 greater:";
	else
		cout << "\ns2 greater:";
	cout << "\n----------------------------------";
	int p = s1.compare(0, 11, s2, 0, 15);
	cout << " \n p = " << p;
	cout << "\n----------------------------------";
	cout << "\n substring of s1 = " << s1.substr(0, 4);

	string f1("first");
	string f2("second");

	cout << "\n f1 = " << f1 << " f2 = " << f2;
	f1.swap(f2);
	cout << "\n f1 = " << f1 << " f2 = " << f2;
	cout << "\n----------------------------------";
	string s3("se computer");

	cout << "\n string concatination: " << s1 + " " + f1;
	return 0;
}
