#include <iostream>
#include <math.h>

using namespace std;

void merge(int seq[], int left, int mid, int right)
{
    int n1 = mid - left + 1; // 左序列長度
    int n2 = right - mid;    // 右序列長度

    // 輔助排序的序列
    int L[n1];
    int R[n2];

    /* 填滿輔助排序之序列 */
    for (int i = 0; i < n1; i++)
    {
        L[i] = seq[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = seq[mid + 1 + i];
    }

    /* 將排序好的輔助陣列依順序填入主序列 */
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < n1 + n2; i++)
    {
        if (p1 < n1 && L[p1] <= R[p2])
            seq[left + i] = L[p1++];
        else
            seq[left + i] = R[p2++];
    }
}

/**
 * @brief Merge Sort
 *
 * * Time Complexity:
 * * * Best: O(nlogn)
 * * * Worst: O(nlogn)
 * * * Average: O(nlogn)
 *
 * * Space Complexity: O(n)
 *
 * @param seq
 * @param left
 * @param right
 */
void mergeSort(int seq[], int left, int right)
{
    if (left >= right) // 元素只剩下一個，終止條件
        return;

    int mid = floor((left + right) / 2);

    /* Divide*/
    mergeSort(seq, left, mid);      // 分割左半
    mergeSort(seq, mid + 1, right); // 分割右半

    // 顯示要合併的序列
    cout << "=======" << endl
         << "Merging: ";
    for (int i = left; i <= right; i++)
        cout << seq[i] << " ";
    cout << endl;

    /* Merge */
    merge(seq, left, mid, right); // 排序合併

    // 顯示合併後的序列
    cout << "After merge: ";
    for (int i = left; i <= right; i++)
        cout << seq[i] << " ";
    cout << endl
         << "=======" << endl;
}

int main()
{
    int n;
    cin >> n;

    int seq1[n];
    for (int i = 0; i < n; i++)
        cin >> seq1[i];

    mergeSort(seq1, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << seq1[i] << " ";
    cout << endl;
}

/*

Input:
10
5 2 4 7 1 3 2 6 9 8

1 2 2 3 4 5 6 7 8 9


*/