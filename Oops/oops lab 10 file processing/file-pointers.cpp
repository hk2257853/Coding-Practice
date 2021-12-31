//using file pointers
#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
int main()
{
	/*ifstream fin;
	fin.open("input.txt");
	int p = fin.tellg();
	cout<<"\nget pointer pointing at :"<<p;
	
	cout<<"\n--------------------------------\n";
	
	fin.seekg(3);   // get pointer moved to location 3 in file
	p = fin.tellg();
	cout<<"\nget pointer now pointing at :"<<p;
	char name[10];
	fin>>name;
	cout<<"\ncontent read by get pointer after moving at loc 3 :"<<name;
	
	cout<<"\n--------------------------------\n";
	
	fin.seekg(0);   // get pointer taken back to loc 0 in file
	fin>>name;
	cout<<"\ncontent read after taking get pointer back to 0th location :"<<name;
	
	fin.close();
	
	cout<<"\n--------------------------------\n";*/

	
	ofstream fout;
	fout.open("input.txt");
	fout<<"computer";
	int q = fout.tellp();
	cout<<"\n\nput pointer pointing now at location : "<<q;
	
	cout<<"\n--------------------------------\n";
	
	fout<<"engineering";
	q = fout.tellp();
	cout<<"\n\nput pointer after writing engineering at : "<<q;
	
	
	fout.seekp(8,ios::beg);  // move put pointer to 8th loc from beg
	fout<<" sci ";
	fout.close();
	
	fout.open("input.txt",ios::app);
	fout<<" course ";
	fout.close();

	return 0;
}
	
