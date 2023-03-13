// sort. take a gap of m. get it done.

class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
        long long ans = INT_MAX;
        sort(a.begin(), a.end());
        for(long long i = 0; i + m - 1 < n; i++)
        {
            ans = min(ans, a[i + m - 1] - a[i]); // i + m - 1 not i! This error was difficult to detect! had to see soln
        }
        return ans;
    }
};