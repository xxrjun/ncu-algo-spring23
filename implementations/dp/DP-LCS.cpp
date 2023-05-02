/**
 * @file lcs-dp.cpp
 * @author xxrjun (github.com/xxrjun)
 * @brief
 * @version 0.1
 * @date 2023-04-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string X, Y;

    cin >> X >> Y;

    int m = X.length();
    int n = Y.length();

    /* 填滿棋盤最上排及最下排 */
    int c[m + 1][n + 1];
    string b[m + 1][n + 1]; // this is for tracking

    for (int i = 0; i <= m; i++)
        c[i][0] = 0;

    for (int i = 0; i <= n; i++)
        c[0][i] = 0;

    /* 執行 LCS Algorithm in DP -> Time Complexity: O(m * n)*/
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            if (X.at(i - 1) == Y.at(j - 1)) /* 相同，填入左上角的數字 + 1 */
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = "same";
            }
            else /* 不相同，填上或左比較大的那個數字 */
            {
                if (c[i][j - 1] > c[i - 1][j])
                {
                    c[i][j] = c[i][j - 1];
                    b[i][j] = "up";
                }
                else
                {
                    c[i][j] = c[i - 1][j];
                    b[i][j] = "left";
                }
            }
        }
    }

    /* 看一下棋盤結果 */
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
            cout << c[i][j] << " ";
        cout << endl;
    }

    /* 使用負責 tracking 的 b 輸出最大共同子序列 */
    vector<string> lcsString;
    int i = m, j = n;
    while (c[i][j] != 0)
    {
        if (b[i][j] == "same")
        {
            string token(1, X.at(i - 1));
            lcsString.push_back(token);
            i--;
            j--;
        }
        else if (b[i][j] == "up")
            j--;
        else if (b[i][j] == "left")
            i--;
    }
    reverse(lcsString.begin(), lcsString.end());

    for (auto &token : lcsString)
        cout << token;
    cout << endl;
}
