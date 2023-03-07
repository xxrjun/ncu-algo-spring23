#include <iostream>
#include <vector>
#include <array>

using namespace std;

int GCD(int a, int b)
{
    int r = 0;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main()
{
    // Get all input
    int T = 0;
    cin >> T;

    vector<array<int, 2>> v;

    for (int i = 0; i < T; i++)
    {
        int a, b;
        cin >> a >> b;

        v.push_back({a, b});
    }

    // Calculate and get all sums
    vector<int> res;
    for (int i = 0; i < T; i++)
    {
        int a = v[i][0];
        int b = v[i][1];

        res.push_back(GCD(a, b));
    }

    // Output
    for (int i = 0; i < T; i++)
    {
        cout << res[i] << endl;
    }
}