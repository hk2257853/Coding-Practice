#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"
#include "climits"
#include "set"

int globalTime = 0;

// this part can be removed as we r going 1 sec at a time
void incTime(vector<int> &AT, vector<int> &BT, int n)
{
    int minArrival = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if(BT[i] != -1 && AT[i] < minArrival) 
        {
            minArrival = AT[i];
        }
    }
    globalTime = minArrival;
}

int getmin(vector<int> &AT, vector<int> &BT, int n)
{
    int min = INT_MAX, ind = -1;
    for (int i = 0; i < n; i++)
    {
        if(BT[i] != -1 && BT[i] < min && AT[i] <= globalTime) 
        {
            min = BT[i];
            ind = i; // missed this!
        }
    }

    // if ind -1 ie no process available
    if(ind == -1) incTime(AT, BT, n);
    
    return ind;
}

void Psjf(vector<int> &AT, vector<int> &BT, int n)
{
    vector<int> WT(n), CT(n), TAT(n), seq;

    int count = 0;  
    while(count < n)
    {        
        int minBtInd = getmin(AT, BT, n);
        if(minBtInd == -1) continue;
        BT[minBtInd]--;
        globalTime++; // 1 sec at a time
        seq.push_back(minBtInd);
        if(BT[minBtInd] == 0) 
        {
            count++;
            BT[minBtInd] = -1;
            CT[minBtInd] = globalTime;
        }
    }

    vector<pair<int, int>> ganttChart;
    for (int i = 0; i < n; i++)
    {
        ganttChart.push_back({CT[i], i});
    }
    
    sort(ganttChart.begin(), ganttChart.end());
    // TODO: show every sec... this is wrong
    for (int i = 0; i < seq.size(); i++)
    {
        cout << seq[i] + 1;
    }
    
        
}


int main()
{

    int n;
    cin >> n;
    vector<int> AT(n), BT(n);

    for(int i = 0; i < n; i++)
    {
        cin >> BT[i];
        cin >> AT[i];
    }

    Psjf(AT, BT, n);

}

