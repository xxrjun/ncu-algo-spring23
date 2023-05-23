#include <iostream>
#include <vector>
#include <limits.h>
#include <cmath>

using namespace std;

int minAvgDifferenceIndex(vector<int> v)
{

    int vSize = v.size();
    if (vSize == 1 || vSize == 0)
        return 0;

    double prefixSum = v[0];
    double postfixSum = 0;

    // get postfixSum first
    for (int i = 1; i < vSize; i++)
    {
        postfixSum += v[i];
    }

    int minAvgDiff = abs(floor(prefixSum / 1) - floor(postfixSum / (vSize - 0 - 1)));
    int resIndex = 0;
    for (int i = 1; i < vSize; i++)
    {
        prefixSum += v[i];

        postfixSum -= v[i];

        int divisor2 = (vSize - i - 1) == 0 ? 1 : (vSize - i - 1);
        int curAvgDiff = abs(floor(prefixSum / (i + 1)) - floor(postfixSum / divisor2));

        if (curAvgDiff < minAvgDiff)
        {
            minAvgDiff = curAvgDiff;
            resIndex = i;
        }
    }

    return resIndex;
}

int main()
{
    int k;
    cin >> k;

    int n;
    int cur;
    vector<int> nums;
    for (int i = 0; i < k; i++)
    {
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> cur;
            nums.push_back(cur);
        }

        if (i != k - 1)
        {
            cout << minAvgDifferenceIndex(nums) << endl;
        }
        else
        {
            cout << minAvgDifferenceIndex(nums);
        }

        nums.clear();
    }
}