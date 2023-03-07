#include <iostream>
#include <vector>
using namespace std;

bool isPerfect(int n)
{
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
            sum += i;
    }

    return (n == sum);
}

int main()
{
    int T = 0;
    cin >> T;

    vector<int> res;
    int count = 0;
    for (int i = 0; i < T; i++)
    {
        int n = 0;
        cin >> n;

        if (isPerfect(n))
        {
            res.push_back(n);
            count++;
        }
    }

    // Output
    for (int i = 0; i < count; i++)
        cout << res[i] << " ";

    cout << endl;
}