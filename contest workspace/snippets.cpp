// Input an array
vector<int> vec;
int size, x;
cin >> size;
while (size)
{
    size--;
    cin >> x;
    vec.push_back(x);
}

// sort, min, max, accumulate vec
sort(vec.begin(), vec.end());
int minvec = *min_element(vec.begin(), vec.end());
int maxvec = *max_element(vec.begin(), vec.end());
int sumvec = accumulate(vec.begin(), vec.end(), 0);

// prefixSum
void fillPrefixSum(vector<int> &vec, vector<int> &prefixSum)
{
    prefixSum.push_back(vec[0]);
    for (int i = 1; i < vec.size(); i++)
        prefixSum.push_back(prefixSum[i - 1] + vec[i]);
}
