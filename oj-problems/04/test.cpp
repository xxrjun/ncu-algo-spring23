#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct StringWithDegree
{
    string str;
    int degree;
    int index;
};

bool compare(const StringWithDegree &a, const StringWithDegree &b)
{
    if (a.degree == b.degree)
    {
        return a.index < b.index;
    }
    return a.degree < b.degree;
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n, m;
        cin >> n >> m;

        vector<StringWithDegree> strings(m);
        for (int j = 0; j < m; j++)
        {
            string str;
            cin >> str;

            int degree = 0;
            for (int k = 0; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    if (str[k] > str[l])
                    {
                        degree++;
                    }
                }
            }

            strings[j] = {str, degree, j};
        }

        sort(strings.begin(), strings.end(), compare);

        for (int j = 0; j < m; j++)
        {
            cout << strings[j].str << endl;
        }

        if (i < t - 1)
        {
            cout << endl;
        }
    }

    return 0;
}