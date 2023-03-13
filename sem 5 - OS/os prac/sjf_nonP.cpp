#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"
#include "climits"
#include "set"

// there were few silly mistakes in my logic + silly mistakes while coding

int globalTime = 0;

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

void sjf(vector<int> &AT, vector<int> &BT, int n)
{
    vector<int> WT(n), CT(n), TAT(n), seq(n);

    // put in arrival... each globalTime need to sort wrt burst globalTime...
    // when cpu free, choose the least BT. If I sort code will become difficult. For now better go with easiest.  
    int count = 0;  
    while(count < n)
    {
        // 1st assumed no AT. Helped me to make progress
        int minBtInd = getmin(AT, BT, n);
        if(minBtInd == -1) continue;
        count++;
        seq.push_back(minBtInd);
        globalTime += BT[minBtInd];
        BT[minBtInd] = -1;
        CT[minBtInd] = globalTime;
    }

    vector<pair<int, int>> ganttChart;
    for (int i = 0; i < n; i++)
    {
        ganttChart.push_back({CT[i], i});
    }
    
    sort(ganttChart.begin(), ganttChart.end());

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < ganttChart[i].first; j++)
        {
            cout << "_";
        }
        cout << "P" << ganttChart[i].second;        
    }

    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << ganttChart[i].first << " ";
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

    sjf(AT, BT, n);

}

