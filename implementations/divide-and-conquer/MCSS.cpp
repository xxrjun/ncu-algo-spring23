#include <iostream>
#include <math.h>
#include <limits.h>

using namespace std;

/**
 * @brief Maximum Contiguous Subsequence Sum (Non-empty version)
 *
 * * Time Complexity: O(nlogn)
 * * Space Complexity: O(logn)
 *
 *
 * @param seq
 * @param left
 * @param right
 * @return int
 */
int MCSS(int seq[], int left, int right)
{

    /* 一個元素就回傳自己了 */
    if (left >= right)
        return seq[left];

    /* Divide & Conquer */
    int mid = left - floor((left - right) / 2);

    /* 左右子問題 */
    int msl = MCSS(seq, left, mid);
    int msr = MCSS(seq, mid + 1, right);

    /* 處理邊界 */
    // 邊界往左側
    int mbl = INT_MIN; // max sum of left bound subsequence
    int tl = 0;
    for (int i = mid; i >= left; i--)
    {
        tl += seq[i];
        mbl = max(mbl, tl);
    }

    // 邊界往右側
    int mbr = INT_MIN; // max sum of right bound subsequence
    int tr = 0;
    for (int i = mid + 1; i <= right; i++)
    {
        tr += seq[i];
        mbr = max(mbr, tr);
    }

    cout << "msl: " << msl << ", msr: " << msr << ", mbl + mbr: " << (mbl + mbr) << endl;

    /* 回傳最大的一個: 左連續子序列最大和、右練續子序列最大和、邊界處連續子序列最大和 */
    return max(msl, max(msr, (mbl + mbr)));
}

/**
 * @brief Maximum Contiguous Subsequence Sum (Empty version)
 *
 * * Time Complexity: O(nlogn)
 * * Space Complexity: O(logn)
 *
 * @param seq
 * @param left
 * @param right
 * @return int
 */
int MCCSE(int seq[], int left, int right)
{
    if (left >= right)
        return max(0, seq[left]); // 可空版本，如果比零小就回傳零

    /* Divide & Conquer */
    int mid = left - floor((left - right) / 2);
    int msl = MCCSE(seq, left, mid);
    int msr = MCCSE(seq, mid + 1, right);

    /* 處理邊界*/
    // 邊界往左側 O(n/2)
    int mbl = 0;
    int tl = 0;
    for (int i = mid; i >= 0; i--)
    {
        tl += seq[i];
        mbl = max(mbl, tl);
    }
    // 邊界往右側 O(n/2)
    int mbr = 0;
    int tr = 0;
    for (int i = mid + 1; i <= right; i++)
    {
        tr += seq[i];
        mbr = max(mbr, tr);
    }

    cout << "msl: " << msl << ", msr: " << msr << ", mbl + mbr: " << (mbl + mbr) << endl;

    /* 回傳最大的一個: 左連續子序列最大和、右練續子序列最大和、邊界處連續子序列最大和 */
    return max(msl, max(msr, (mbl + mbr)));
}

int main()
{
    int n;
    cin >> n;

    int seq1[n];
    int seq2[n];
    for (int i = 0; i < n; i++)
    {
        cin >> seq1[i];
        seq2[i] = seq1[i];
    }

    int res = MCSS(seq1, 0, n - 1);
    cout << "Max Continuous Subsequence Sum(Non-empty): " << res << endl;
    cout << "===================" << endl;

    res = MCCSE(seq2, 0, n - 1);
    cout << "Max Continuous Subsequence Sum(Empty is accepted): " << res << endl;

    return 0;
}
