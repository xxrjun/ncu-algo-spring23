#include <iostream>
#include <vector>
#include <array>

using namespace std;

bool isOddNum(int n)
{
    if (n % 2 == 0)
        return false;

    return true;
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

        // let a to be an odd num
        if (!isOddNum(a))
            a++;

        // let b to be an odd num
        if (!isOddNum(b))
            b--;

        // Get how many odds number between the range, which is 2n - 2
        int total_odds = (b - a) / 2 + 1;

        int odds_sum = (a + b) / 2 * total_odds;

        res.push_back(odds_sum);
    }

    // Output
    for (int i = 0; i < T; i++)
    {
        cout << "Case " << i + 1 << ": " << res[i] << endl;
    }
}