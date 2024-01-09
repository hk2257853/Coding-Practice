#include <iostream>
using namespace std;

class base
{
public:
	void display()
	{
		cout << "\nBase class display :";
	}
	virtual void show() // base class virtual function
	{
		cout << "\nBase class show : ";
	}
};

class derived : public base
{
public:
	void display()
	{
		cout << "\nDerived class display : ";
	}
	void show() // override // override keyword is optional in c++
	{
		cout << "\nDerived class show : ";
	}
};

int main()
{
	base b;
	derived d;

	b.show();	 // calls base class show
	d.show();	 // calls derived class show

	// late binding (run time polymorphism)
	base *bptr; // base class pointer
	cout << "\n bptr points to Base\n";
	bptr = &b;

	bptr->display(); // calls base class display
	bptr->show();	 // calls base class show

	cout << "\n\n-------------------------------\n";

	cout << "\n bptr points to Derived\n";
	bptr = &d;

	bptr->display(); // calls base class display (function overriding - base class function is called). 
					 // The bptr is point to derived class, so derived values/funtions should come. But that's not happening so we use late binding.
	bptr->show();	 // calls derived class show (using virtual function)

	return 0;
}

/*
extra:
a Vtable (virtual table) is a data structure used for implementing polymorphism
a table of function pointers
This pointer helps the program determine which function to call when you use a virtual function through a base class pointer or reference.
*/