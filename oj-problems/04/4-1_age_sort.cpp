#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v;
    while (n != 0)
    {
        v.clear();
        int input = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> input;
            v.push_back(input);
        }

        sort(v.begin(), v.end());

        for (int i = 0; i < n - 1; i++)
        {
            cout << v[i] << " ";
        }
        cout << v[n - 1] << endl;

        cin >> n;
    }
}