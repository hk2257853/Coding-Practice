#include "iostream"
using namespace std;
#include "queue"

int main()
{
    int n;
    cin >> n;
    int globaltime = 0;
    vector<int> AT(n), BT(n), WT(n), CT(n), TAT(n);

    for(int i = 0; i < n; i++)
    {
    cin >> AT[i];
    cin >> BT[i];
    }

    // main algo
    for(int i = 0; i < n; i++)
    {
    if(globaltime < AT[i]) globaltime = AT[i];
    WT[i] = globaltime - AT[i];
    globaltime += BT[i]; // execution
    CT[i] = globaltime;
    TAT[i] = globaltime - AT[i];
    }

    float sumtat = 0, sumwt = 0;
    // print the table
    cout << "Process " << "AT " << "BT " << "CT " << "TAT " << "WT " << endl;
    for(int i = 0; i < n; i++)
    {
    cout << "P" << i << ":      " << AT[i] << " " << BT[i] << "  " << CT[i] << "    " << TAT[i] << "  " << WT[i] << endl;
    sumtat += TAT[i];
    sumwt += WT[i];
    }

    cout << "TAT average: " << sumtat / 4 << endl;
    cout << "WT average: " << sumwt / 4 << endl;

    cout << "Gantt chart: " << endl;
    cout << AT[0];
    for(int i = 0; i < n; i++)
    {
    for(int j = 0; j < CT[i]; j++) cout << "_";
    cout << "P" << i;
    }
    cout << endl;
    cout << AT[0];
    for(int i = 0; i < n; i++)
    {
    for(int j = 0; j < CT[i]; j++) cout << " ";
    cout << " " << CT[i];
    }

}
