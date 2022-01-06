//understanding read() and write() fun {blocks of Binary data}
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;
int main()
{
	float height1[4]={175.5,153.0,167.25,160.70};
	float height2[4];
	
	ofstream fout;
	fout.open("readwrite.txt");
	
	fout.write((char *) & height1,sizeof(height1));
	fout.close();
	
	ifstream fin;
	fin.open("readwrite.txt");
	
	fin.read((char *) & height2,sizeof(height2));
	
	for(int i=1;i<=4;i++)
	{
		cout<<height2[i]<<" ";
	}
	fin.close();
	
	return 0;
}
