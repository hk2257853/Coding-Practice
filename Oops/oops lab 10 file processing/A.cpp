#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream fout;
    // open():to open multiple files

    fout.open("file1.txt");
    fout << "1\n";
    fout << "2\n";
    fout << "3\n";
    fout << "4\n";
    fout << "5\n";
    fout.close();

    fout.open("file2.txt");
    fout << "9\n";
    fout << "8\n";
    fout << "7\n";
    fout.close();

    int n = 30;
    char line[n];

    ifstream fin;
    fout.open("file3.txt");
    fin.open("Country");
    while (fin)
    {
        fin.getline(line, n);
        fout << line << endl;
    }
    fin.close();

    fin.open("Capital");
    while (fin)
    {
        fin.getline(line, n);
        fout << line << endl;
    }
    fin.close();
    fout.close();

    return 0;
}
