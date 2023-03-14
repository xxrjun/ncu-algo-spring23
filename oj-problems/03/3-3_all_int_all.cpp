#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isSubstring(string s, string t)
{
    int n = s.length();
    int m = t.length();
    int count = 0;

    for (int i = 0; i < m; i++)
    {
        if (s[count] == t[i])
            count++;

        if (count == n)
            return true;
    }

    return false;
}

int main()
{
    int N = 0;
    cin >> N;

    vector<vector<string>> v;
    string s1;
    string s2;
    for (int i = 0; i < N; i++)
    {
        v.push_back({});
        cin >> s1;
        cin >> s2;
        v[i].push_back(s1);
        v[i].push_back(s2);
    }

    for (int i = 0; i < N; i++)
    {
        if (isSubstring(v[i][0], v[i][1]))
            cout << "Yes";
        else
            cout << "No";

        cout << endl;
    }
}