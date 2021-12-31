//understanding get() and put()
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;
int main()
{
	char name[20];
	cout<<"\nEnter a string : ";
	cin>>name;  // computer
	
	int len=strlen(name);
	
	ofstream fout;  // fstream obj can handle both i/o o/p simultaneously
	fout.open("getput.txt");
	
	for(int i=0;i<len;i++)
	{
		fout.put(name[i]);
	}
	fout.close();
	
	ifstream fin;
	fin.open("getput.txt");
	
	char c;
	while(fin)
	{
		fin.get(c);
		cout<<c;
	}
	fin.close();
	
	return 0;
}
	
	
	
