#include<iostream>
#include<fstream>
using namespace std;

int main(){
	ofstream fout;
   //open():to open multiple files

	fout.open("Country");
    fout<<"USA\n";
    fout<<"SK\n";
    fout<<"UK";
    fout.close();

	fout.open("Capital");
    fout<<"wash\n";
    fout<<"SKC\n";
    fout<<"London\n";
    fout.close();

    int n=30;
    char line[n];

    ifstream fin;

	fin.open("Country");
    cout<<"Content of file\n";
    while(fin)
    {
    fin.getline(line, n);
    cout<<line<<endl;
    }
    fin.close();

    fin.open("Capital");
    cout<<"Content of file 2\n";
    while(fin)
    {
    fin.getline(line, n);
    cout<<line <<endl;
    }
    fin.close();

	return 0;

}

