#include "iostream"
using namespace std;
#include "vector"
#include "algorithm"
#include "climits"
#include "set"

// can be improved with hashmap n all
// I do silly mistakes (missing a variable, ++/--, wrong formuale - like for disk scheduling etc)

void print_frame(vector<int> frame, bool hit)
{
    for (int i = 0; i < frame.size(); i++)
    {
        cout << frame[i] << " ";
    }
    if(hit) cout << "hit";
    else cout << "miss";
    cout << endl;
}

void lru(vector<int> vec, int framesize)
{
    vector<int> frame;
    for (int i = 0; i < vec.size(); i++)
    {
        if (frame.size() < framesize) 
        {
            frame.push_back(vec[i]);
            print_frame(frame, false);
        }
        else
        {            
            // check if hit or miss
            bool hit = false;
            for (int j = 0; j < framesize; j++)
            {
                if(vec[i] == frame[j]) hit = true;
            }
            
            if(hit) print_frame(frame, hit);
            else
            {
                // lru main logic
                set<int> s;
                int kind;
                for (int j = i - 1; j >= 0; j--) // wrote == in place of --, took 30min to fix!
                {
                    for (int k = 0; k < framesize; k++)
                    {
                        bool found = s.find(vec[j]) != s.end();
                        if(vec[j] == frame[k] && !found) 
                        {
                            s.insert(vec[j]);
                            kind = k;
                        }
                    }                               
                }
                frame[kind] = vec[i];
                print_frame(frame, hit); 
            }            
        }                
    }
    
    
}

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);

    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    int framesize;
    cin >> framesize;

    lru(vec, framesize);
    
}
