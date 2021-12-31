//command line arguments
#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
int main(int argc, char *argv[])
{
	int number[9]={11,22,33,44,55,66,77,88,99};
	
	ofstream fout1,fout2;    // Name of program: 11 o e.cpp
	
	fout1.open(argv[1]); 		//ODD FILE
	fout2.open(argv[2]);		//EVEN FILE
	
	for(int i=0;i<9;i++)
	{
		if(number[i]%2==0)
			fout2<<number[i]<<" ";   // even number
		else
			fout1<<number[i]<<" ";   // odd number
	}
	fout1.close();
	fout2.close();
	
	ifstream fin;
	char ch;
	
	for(int i=1;i<argc;i++)  // i=1,2
	{
		fin.open(argv[i]);
			cout<<"Contents of "<<argv[i]<<"\n";
			do
			{
				fin.get(ch);
				cout<<ch;
				
			}while(fin);
			cout<<"\n";
			fin.close();
	}
	return 0;
}
