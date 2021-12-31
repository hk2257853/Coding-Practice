//updating file:random access
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
	cin>>name;
	cin>>code;
	cin>>cost;
}
void inventory::writedata(void)
{
	cout<<"\n"<<name;
	cout<<"\n"<<code;
	cout<<"\n"<<cost;
}
int main()
{
	inventory item1[10],item2[10],item;   
		
	fstream fobj;   // handles both i/p o/p simultaneously
	fobj.open("store.txt",ios::in|ios::out);

	cout<<"\nEnter Name Code Cost to insert in store.txt file \n";
	for(int i=1;i<=2;i++)
	{
		item1[i].readdata();
		fobj.write((char *) & item1[i], sizeof(item1[i]));
	}
		
	cout<<"\nCURRENT CONTENT OF STORE FILE:\n";
	
	fobj.seekg(0);    // go to start
	
	for(int i=1;i<=2;i++)
	{
		fobj.read((char *) & item2[i], sizeof(item2[i]));
		item2[i].writedata();
		cout<<"\n---------------------";
	}
	
	fobj.clear();  // clearing eof()
	
	cout<<"\nAdd a new item details in store file \n";
	item.readdata();
	
	fobj.write((char *) & item, sizeof(item));
	
	fobj.seekg(0);
	
	cout<<"\nContents after adding new item are as follows \n";
	for(int i=1;i<=3;i++)
	{
		fobj.read((char *) & item2[i], sizeof(item2[i]));
		item2[i].writedata();
		cout<<"\n---------------------\n";
	}
	
	int last=fobj.tellg();
	int n = last / sizeof(item);
	
	cout<<"\nNo of objects in file : "<<n<<"\n";
	cout<<"\nTotal bytes in the file : "<<last<<"\n";
	
	fobj.clear();
	
	cout<<"\nEnter the object number to be updated :\n";
	int objno;  //3
	cin>>objno;
	
	int loc = (objno-1)*sizeof(item);
	cout<<"\nobj loc to be updated is = "<<loc<<"\n";
	
	fobj.seekp(loc);   // jump put pointer to that loc
	
	cout<<"\nEnter new values to update for object-no : "<<objno<<"\n";
	item.readdata();
	fobj.write((char *) & item, sizeof(item));
	
	fobj.seekg(0);
	
	cout<<"\nContents of updated file is as follows : ";
	for(int i=1;i<=3;i++)
	{
		fobj.read((char *) & item2[i], sizeof(item2[i]));
		item2[i].writedata();
		cout<<"\n---------------------\n";
	}
	
	
	return 0;
}
