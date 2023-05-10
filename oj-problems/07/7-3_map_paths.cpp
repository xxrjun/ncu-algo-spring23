#include <iostream>
#include <vector>
using namespace std;

int unique_paths(int m, int n)
{
    // 創建dp表格
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // 初始化第一行第一列
    for (int i = 0; i < m; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        dp[0][i] = 1;
    }

    // 開始iterate
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    // 返回
    return dp[m - 1][n - 1];
}

int main()
{
    int test_cases;
    int m, n;

    cin >> test_cases;
    for (int i = 0; i < test_cases; i++)
    {
        cin >> m >> n;
        cout << unique_paths(m, n) << endl;
    }
}