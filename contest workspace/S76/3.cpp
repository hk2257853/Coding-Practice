#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include<numeric>
using ll = long long;

// don't assume! thought repetitions ain't allowed. But no where mentioned like that!!!!!!!!!!

int main() 
{
	int t;
	cin >> t;
	while(t)
	{
	    t--;
	    int size;
        cin >> size;

        cout << "1 2 ";
        size -= 2;
        int count = 5;
        while (size)
        {
            if(size == 1) 
            {
                cout << "4";
                size--;
            }
            else 
            {
                cout << count << " -" << count << " ";
                count++;
                size -= 2;
            }
        }
        
        cout << endl;

	}
	return 0;
}
