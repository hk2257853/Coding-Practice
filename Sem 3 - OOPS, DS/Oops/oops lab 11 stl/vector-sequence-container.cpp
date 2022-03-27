// Vector Sequence Container
#include <iostream>
#include <conio.h>
#include <vector>
using namespace std;
void display(vector<int> &); // display function prototype
int main()
{
	vector<int> v; // integer vector created

	cout << "\nInitial size() = " << v.size();		   // gives no of elements
	cout << "\nInitial capacity() = " << v.capacity(); // capacity returns no elements that vector can store b4 that vector needs to dynamically resize itself to accommodate more elements

	v.push_back(10); // pushing the element at back of vector
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	cout << "\nAfter push_back() size() = " << v.size();
	cout << "\nAfter push_back() capacity() = " << v.capacity();

	cout << "\nDisplay vector elements after push_back() :";
	display(v);

	cout << "\nFrist element of vector = " << v.front();
	cout << "\nLast element of vector = " << v.back();

	// Inserting elements in vector using iterator
	vector<int>::iterator itr = v.begin(); // here itr is pointing to 0th element of v
	itr = itr + 5;						   // itr made to point 4th element;
	v.insert(itr, 60);					   // insert 40 as 4th element of v

	cout << "\nDisplay vector elements after insertion :";
	display(v);

	// pop_back() function to delete last element
	v.pop_back();

	cout << "\nDisplay vector elements after pop_back() :";
	display(v);

	// erase(delete) vector elements
	v.erase(v.begin() + 2, v.begin() + 4); // erase(2,4) = deletes 30 & 40 but not 50

	cout << "\nDisplay vector elements after erase() :";
	display(v);

	// resizing vector
	v.resize(10);
	cout << "\nAfter resize() vector size = " << v.size();

	// using clear function
	v.clear();

	cout << "\nAfter clear() function :";
	display(v);

	cout << "\nIs vector empty = " << v.empty();

	getch();
	return 0;
}
void display(vector<int> &v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << " " << v.at(i); // at() prints vector element at each reference index
	}
}
