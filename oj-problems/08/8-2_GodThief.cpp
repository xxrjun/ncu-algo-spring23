#include <iostream>
#include <vector>

using namespace std;

void printCombination(vector<int> comb)
{
    for (int count = 0; count < comb.size(); count++)
    {
        cout << comb[count];
        if (count != comb.size() - 1)
        {
            cout << " ";
        }
    }
}

int main()
{
    int K;
    cin >> K;

    int T, N;
    int sum = 0;
    vector<int> M;
    vector<int> comb;

    while (K--)
    {
        cin >> T >> N;

        M.resize(N);
        for (int i = 0; i < N; i++)
            cin >> M[i];

        while (M.size())
        {
            sum = 0;
            for (int j = 0; j < M.size(); j++)
            {
                if (sum + M[j] <= T)
                {
                    sum += M[j];
                    comb.push_back(M[j]);
                }

                if (sum == T)
                {
                    printCombination(comb);
                    break;
                }
            }

            if (sum == T)
            {
                break;
            }

            M.erase(M.begin());
            comb.clear();
        }

        if (sum < T || comb.size() == 0)
        {
            cout << "impossible";
        }

        cout << endl;

        M.clear();
        comb.clear();
    }
    return 0;
}
