#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <string>

using namespace std;

long long reverse(long long n)
{
    string m = to_string(n);
    reverse(m.begin(), m.end());
    return stoi(m);
}

bool is_palindrome(long long n)
{
    // cout << to_string(n) << " " << reverse((n)) << endl;
    return to_string(n) == to_string(reverse((n)));
}

int main()
{
    int N;
    cin >> N;

    vector<long long> v;

    int input = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        v.push_back(input);
    }

    vector<pair<long long, long long>> res(N);
    int n = 0;
    long long count = 0;
    for (int i = 0; i < N; i++)
    {
        n = v[i];
        count = 0;
        n += reverse(n);
        count++;

        while (!is_palindrome(n) && count < 4294967295)
        {
            n += reverse(n);
            count++;
        }

        cout << count << " " << n << endl;
    }
}