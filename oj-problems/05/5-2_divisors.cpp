#include <iostream>
#include <vector>
#include <array>
#include <cmath>

using namespace std;

// count divisors in O(sqrt(n))
int countDivisors(int n)
{
    if (n == 0)
        return 0;

    int count = 2;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (n / i == i)
                count++;
            else
                count += 2;
        }
    }

    return count;
}

int main()
{
    int n;
    cin >> n;

    vector<array<int, 4>> v;

    int l = 0, u = 0, p = 0, d = 0;
    while (n--)
    {

        l = 0, u = 0, p = 0, d = 0;

        cin >> l >> u;

        for (int i = l; i <= u; i++)
        {
            int tmpDivisors = countDivisors(i);
            if (tmpDivisors > d)
            {
                p = i;
                d = tmpDivisors;
            }
        }

        v.push_back({l, u, p, d});
    }

    int len = v.size();
    for (int i = 0; i < len; i++)
    {
        cout << "Between " << v[i][0] << " and " << v[i][1] << ", " << v[i][2] << " has a maximum of " << v[i][3] << " divisors." << endl;
    }
}