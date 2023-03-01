#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main()
{
    int N = 0;
    cin >> N;

    vector<string> v;
    string str;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        v.push_back(str);
    }

    // Make a map
    map<char, int> m;
    char c = 'A';
    for (int i = 1; c <= 'Z'; c++, i++)
    {
        m[c] = i;
    }

    // Calculate and get the result
    vector<long> res;
    for (int i = 0; i < N; i++)
    {
        long cur_sum = 0;

        string cur_str = v[i];
        int count = cur_str.size() - 1;
        int ptr = 0;
        while (count > 0)
        {

            long t = 26;
            for (int j = 1; j < count; j++)
            {
                t *= 26;
            }

            cur_sum += m[cur_str[ptr++]] * t;
            count--;
        }

        cur_sum += m[cur_str[ptr]];

        res.push_back(cur_sum);
    }

    // Output result
    for (int i = 0; i < N; i++)
    {
        cout << res[i] << endl;
    }
}