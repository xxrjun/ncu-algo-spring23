#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<vector<int>> powerSet(set<int> s);

int main()
{

    /*
        Getting input set
    */
    set<int> s;
    bool exit = false;
    int input = 0;
    while (!exit)
    {
        cin >> input;

        if (input == -1)
        {
            exit = true;
            break;
        }

        if (!s.count(input))
            s.insert(input);
    }

    /*
        Getting power set
    */
    vector<vector<int>> ps = powerSet(s);

    /*
        Printing power set
    */
    for (int i = 0; i < ps.size(); i++)
    {
        cout << "{";
        for (int j = 0; j < ps[i].size(); j++)
        {
            cout << ps[i][j];
            if (j != ps[i].size() - 1)
                cout << ", ";
        }
        cout << "}" << endl;
    }
}

vector<vector<int>> powerSet(set<int> s)
{
    vector<vector<int>> res = {{}};

    // For every element in the set
    for (int element : s)
    {
        int n = res.size();

        // Add element to all subsets
        for (int j = 0; j < n; j++)
        {
            // Copy the subset
            res.push_back(res[j]);

            // Add element to the subset
            res.back().push_back(element);
        }
    }

    return res;
}
