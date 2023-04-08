/**
 * @file DP-MCSS.cpp
 * @author your name (you@domain.com)
 * @brief Maximum Contiguous Subsequence Sum, MCSS 最大連續子序列可空與非空版本
 * @version 0.1
 * @date 2023-04-08
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief MCSS 不可空版本
 *
 * * Time Complexity: O(n)
 * * Space Complexity: O(n), for table m
 *
 * @param seq 序列
 * @param n 序列長度
 * @return int 最大連續子序列和
 */
int MCSS1(int seq[], int n)
{
    /* 長度為 0 回傳 0*/
    if (n == 0)
        return 0;

    /* 若序列全為負數則回傳最大的值 */
    bool allNegative = true;
    int maxInNegative = seq[0];
    for (int i = 0; i < n && allNegative; i++)
    {
        maxInNegative = max(maxInNegative, seq[i]);

        if (seq[i] >= 0)
            allNegative = false;
    }

    if (allNegative)
        return maxInNegative;

    /* DP! */
    int m[n];      // 紀錄表格
    m[0] = seq[0]; // 初始化
    int MCSS = seq[0];
    for (int i = 1; i < n; i++)
    {
        m[i] = max(m[i - 1] + seq[i], seq[i]); // (將當前的加上去, 只取當前)
        MCSS = max(MCSS, m[i]);
    }

    return MCSS;
}

/**
 * @brief MCSS 不可空版本改良版
 *
 * * Time Complexity: O(n)
 * * Space Complexity: O(1), without table m
 *
 * @param seq
 * @param n
 * @return int
 */
int MCSS2(int seq[], int n)
{
    /* 長度為 0 回傳 0*/
    if (n == 0)
        return 0;

    /* 若序列全為負數則回傳最大的值 O(n)*/
    bool allNegative = true;
    int maxInNegative = seq[0];
    for (int i = 0; i < n && allNegative; i++)
    {
        maxInNegative = max(maxInNegative, seq[i]);

        if (seq[i] >= 0)
            allNegative = false;
    }

    if (allNegative)
        return maxInNegative;

    /* DP! O(n)*/
    int m = seq[0]; // 紀錄當前最大連續子序列和
    int MCSS = m;
    for (int i = 1; i < n; i++)
    {
        m = max(m + seq[i], seq[i]); // (將當前的加上去, 只取當前)
        MCSS = max(MCSS, m);
    }

    return MCSS;
}

/**
 * @brief MCSS 可空版本
 *
 * * Time Complexity: O(n)
 * * Space Complexity: O(1)
 *
 * @param seq
 * @param n
 * @return int
 */
int MCSS3(int seq[], int n)
{
    /* 長度為 0 回傳 0*/
    if (n == 0)
        return 0;

    /* 若序列全為負數則回傳最大的值 O(n)*/
    bool allNegative = true;
    for (int i = 0; i < n && allNegative; i++)
    {
        if (seq[i] >= 0)
            allNegative = false;
    }

    if (allNegative)
        return 0;

    /* DP! O(n)*/
    int m = 0; // 紀錄當前最大連續子序列和
    int MCSS = m;
    for (int i = 0; i < n; i++)
    {
        m = max(m + seq[i], seq[i]); // (將當前的加上去, 只取當前)
        MCSS = max(MCSS, m);
    }

    return MCSS;
}

int main()
{
    /* 輸入序列之長度 */
    int n;
    cin >> n;

    /* 輸入序列資料 */
    int seq[n];
    for (int i = 0; i < n; i++)
        cin >> seq[i];

    /* 輸出序列 */
    cout << "=============================" << endl;
    cout << "Sequence: ";
    for (int i = 0; i < n; i++)
        cout << seq[i] << " ";
    cout << endl;

    /* Call MCSS Function */
    int MCSS = MCSS1(seq, n);
    cout << "MCSS1(cannot be empty version): " << MCSS << endl;

    MCSS = MCSS2(seq, n);
    cout << "MCSS2(cannot be empty version, improve space complexity): " << MCSS << endl;

    MCSS = MCSS3(seq, n);
    cout << "MCSS3(can be empty version): " << MCSS << endl;
}

/*

Input:
8
-2 11 -4 13 -5 -2 1 2

Output:
=============================
Sequence: -2 11 -4 13 -5 -2 1 2
MCSS1(cannot be empty version): 20
MCSS2(cannot be empty version, improve space complexity): 20
MCSS3(can be empty version): 20


Input:
8
-2 -11 -4 -13 -5 -2 -1 -2

Output:
=============================
Sequence: -2 -11 -4 -13 -5 -2 -1 -2
MCSS1(cannot be empty version): -1
MCSS2(cannot be empty version, improve space complexity): -1
MCSS3(can be empty version): 0


*/