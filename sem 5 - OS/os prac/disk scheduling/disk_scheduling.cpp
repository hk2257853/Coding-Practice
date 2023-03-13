#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"
#include "climits"

void print_ans(vector<int> seq, int cost)
{
    for (int i = 0; i < seq.size(); i++)
    {
        cout << seq[i] << " ";
    }
    cout << endl;
    cout << "cost: " << cost << endl;
}

void sstf(vector<int> disk, int head, int start, int end)
{
    int n = disk.size();
    vector<int> seq, isvisited(n, 0);
    int cost = 0;
    seq.push_back(head);
    int currenthead = head;

    while (seq.size() <= n)
    {            
        int min = INT_MAX, ind = 0;
        // get least index
        for (int i = 0; i < n; i++)
        {
            if(!isvisited[i] && abs(disk[i] - currenthead) < min)
            {
                min = disk[i] - currenthead;            
                ind = i;
            }
        }
        isvisited[ind] = 1;
        seq.push_back(disk[ind]);

        cost += abs(currenthead - disk[ind]);
        currenthead = disk[ind];
    }
    
    print_ans(seq, cost);
    

}

// fcfs just c

void look_right(vector<int> disk, int head, int start, int end)
{
    vector<int> seq;
    int cost = 0;
    sort(disk.begin(), disk.end());
    // no use of getting head index ig...
    seq.push_back(head);

    for (int i = 0; i < disk.size(); i++)
    {
        if(disk[i] > head)
        {
            seq.push_back(disk[i]);
        }
    }

    for (int i = disk.size() - 1; i >= 0; i--)
    {
        if (disk[i] < head)
        {
            seq.push_back(disk[i]);
        }        
    }

    // here I can do direct
    int n = disk.size();
    cost = (disk[n - 1] - head) + (disk[n - 1] - disk[0]);
    
    print_ans(seq, cost);


}

int main()
{
    int n;
    cin >> n;
    
    vector<int> disk(n);
    for (int i = 0; i < n; i++)
    {
        cin >> disk[i];
    }

    int head, start, end;
    cout << "Enter head start & end" << endl;
    cin >> head >> start >> end;    
    look_right(disk, head, start, end);
    sstf(disk, head, start, end);

}