#include <iostream>
#include <vector>
#include <array>
#include <cmath>

using namespace std;

// get nth ugly number in O(n)

int getNthUglyNumber(int k)
{
    if (k == 0)
        return 0;

    int uglyNumbers[k];
    uglyNumbers[0] = 1;
    int nextUglyNumber = 1;

    int i2 = 0, i3 = 0, i5 = 0;
    int nextMultipleOf2 = 2;
    int nextMultipleOf3 = 3;
    int nextMultipleOf5 = 5;

    for (int i = 1; i < k; i++)
    {
        nextUglyNumber = min(nextMultipleOf2, min(nextMultipleOf3, nextMultipleOf5));
        uglyNumbers[i] = nextUglyNumber;

        if (nextUglyNumber == nextMultipleOf2)
        {
            i2++;
            nextMultipleOf2 = uglyNumbers[i2] * 2;
        }

        if (nextUglyNumber == nextMultipleOf3)
        {
            i3++;
            nextMultipleOf3 = uglyNumbers[i3] * 3;
        }

        if (nextUglyNumber == nextMultipleOf5)
        {
            i5++;
            nextMultipleOf5 = uglyNumbers[i5] * 5;
        }
    }

    return nextUglyNumber;
}

int main()
{
    int k;
    cin >> k;

    vector<int> v;

    int input = 0;
    while (k--)
    {
        cin >> input;
        v.push_back(getNthUglyNumber(input));
    }

    int len = v.size();
    for (int i = 0; i < len; i++)
    {
        cout << v[i] << endl;
    }
}