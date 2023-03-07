#include <iostream>
#include <cmath>
#include <array>
#include <vector>

using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}
bool isOdd(int n)
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
        if (!isOdd(a))
            a++;

        // let b to be an odd num
        if (!isOdd(b))
            b--;

        int odds_sum = 0;
        for (int j = a; j <= b; j += 2)
        {
            if (!isPrime(j))
                odds_sum += j;
        }

        res.push_back(odds_sum);
    }

    // Output
    for (int i = 0; i < T; i++)
    {
        cout << res[i] << endl;
    }
}
