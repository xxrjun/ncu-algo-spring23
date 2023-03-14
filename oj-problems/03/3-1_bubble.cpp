#include <iostream>
#include <vector>

using namespace std;

int calculateSwapTimes(vector<int> v)
{
    int count = 0;
    int len = v.size();
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
                count++;
            }
        }
    }

    return count;
}

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    int N = 0;
    cin >> N;

    vector<vector<int>> v;
    vector<int> res;
    int L = 0;
    for (int i = 0; i < N; i++)
    {
        v.push_back({});
        cin >> L;
        int input = 0;
        for (int j = 0; j < L; j++)
        {
            cin >> input;
            v[i].push_back(input);
        }
    }

    for (int i = 0; i < N; i++)
        res.push_back(calculateSwapTimes(v[i]));

    for (int i = 0; i < N; i++)
        cout << "Optimal swapping takes " << res[i] << " swaps." << endl;
}