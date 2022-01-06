#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream outf("ITEM"); //writing mode by dfault so no need to specify
    cout<<"Enter item name";
    string name;
    cin>>name;
    outf<<name<<"\n";
    cout<<"Enter item cost";
    float cost;
    cin>>cost;
    outf.close();

    ifstream inf("ITEM"); //open in read mode
    inf>>name;
    inf>>cost;
    cout<<"\n";
    cout<<"Item name: "<< name<< "\n";
    cout<<"Item cost: "<< cost<< "\n";
    inf.close();

    return 0;

}
