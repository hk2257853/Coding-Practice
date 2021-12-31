//understanding reading-writing class object
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;
class inventory
{
		char name[10];
		int code;
		float cost;
	public:
		void readdata(void);
		void writedata(void);
};
void inventory::readdata(void)
{
	cout<<"\nEnter name : "; cin>>name;
	cout<<"\nEnter code : "; cin>>code;
	cout<<"\nEnter cost : "; cin>>cost;
}
void inventory::writedata(void)
{
	cout<<"\nName : "<<name;
	cout<<"\nCode : "<<code;
	cout<<"\nCost : "<<cost;
}
int main()
{
	inventory item[3];   // array of object
	fstream fobj;   // handles both i/p o/p simultaneously
	fobj.open("stock.txt",ios::in|ios::out);
	for(int i=1;i<=2;i++)
	{
		item[i].readdata();
		fobj.write((char *) & item[i], sizeof(item[i]));
	}
	
	fobj.seekg(0);
	
	for(int i=1;i<=2;i++)
	{
		fobj.read((char *) & item[i], sizeof(item[i]));
		item[i].writedata();
		cout<<"\n---------------------";
	}
	fobj.close();
	
	return 0;
}
