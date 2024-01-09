#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <numeric>
using ll = long long;
#include <climits>
#include <cmath>

int countBits(int number) {
    int count = 0;

    while (number) {
        // Increment count for each set bit
        count += number & 1;
        
        // Right shift the number to check the next bit
        number >>= 1;
    }

    return count;
}

int findPositionOfSetBit(int n) {
    if (n == 0) {
        // If the number is 0, there is no set bit.
        return -1;
    }

    int position = 0;

    // Find the number of bits in an integer
    int numBits = sizeof(int) * CHAR_BIT;

    // Iterate through each bit of the number from the most significant bit
    for (int i = numBits - 1; i >= 0; --i) {
        if ((n & (1 << i)) != 0) {
            // If the bit is set, return the position
            return i + 1; // Adding 1 to convert from 0-based index to 1-based index
        }
    }

    return position;
}

int main()
{
	int t;
	cin >> t;
	while (t)
	{
		t--;
        int x, y;
        cin >> x >> y;
        y = pow(2, y);
        int ans = 0;
        int rightmostbit = findPositionOfSetBit(y);
        int setbits = countBits(x);

        for (int i = 0; i < x; i++)
        {
            /* code */
        }
        
        cout << abs(rightmostbit-setbits) * 2 << " ";
	}
	return 0;
}
