#include <iostream>
using namespace std;

class Distance
{
private:
	int meters = 0;

public:
	void DisplayData()
	{
		cout << "Meter value: " << meters << endl;
	}
	//declaring these as friend so that they can access meters variable of this class.
	friend void addfive(Distance &d);
	friend void addten(Distance &d);

	//making whole class friend so that all of its functions can access meters variable of this class.
	friend class addfif;
};

//Note: pass by argument has been
//done because I want to change value of meter(see the 2nd use of call by ref in notes).

class add1 //a particular function is friend.
{
public:
	friend void addten(Distance &d);
	{
		d.meters = d.meters + 10;
	}
};

// void addten(Distance &d) //I don't need to use scope resolution for add1's function
// {						//(friend funtion's scope is wide). Just looks like global function(O yeah! its actually a global function made freind to 2 classes)
// 	d.meters = d.meters + 10;
// }

//declaring whole class as friend.
class addfif
{
public:
	void addfifteen(Distance &d) //don't need to mention friend here.
	{
		d.meters = d.meters + 15;
	}
};

//a global function.
void addfive(Distance &d) //if I don't call by ref it will create  a local d or d1 and operate on it.
{						  //thus d1's one won't be affected. 2nd application of call by ref.
	d.meters = d.meters + 5;
}

int main()
{
	Distance d1;
	d1.DisplayData();

	addfive(d1); //non class function
	d1.DisplayData();

	/*
	Distance x;
	x.addfive(d1); //non class function
	 error: 'class add' has no member named 'addfive'
	 why? making friend doesn't mean its a part(scope is better term to use) of that class.
	*/

	addten(d1); //class function
	d1.DisplayData();

	addfif y;
	y.addfifteen(d1);
	d1.DisplayData();

	return 0;
}