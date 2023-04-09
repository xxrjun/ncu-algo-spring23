/**
 * @file bubble-sort.cpp
 * @author xxrjun (github.com/xxrjun)
 * @brief Bubble Sort
 * @version 0.1
 * @date 2023-04-09
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>

using namespace std;

/**
 * @brief Bubble Sort
 *
 * * Time Complexity:
 *  * * Best: O(n)
 *  * * Worst: O(n^2)
 *  * * Average: O(n^2)
 *
 * * Space Complexity: O(1)
 *
 * @param seq
 * @param n
 * @return int
 */
int bubbleSort(int seq[], int n)
{
    cout << "Original Bubble Sort:" << endl;

    for (int i = 0; i < n - 1; i++)
    {
        cout << "Pass " << i + 1 << ": ";
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (seq[j] > seq[j + 1])
                swap(seq[j], seq[j + 1]);
        }
        for (int i = 0; i < n; i++)
            cout << seq[i] << " ";
        cout << endl;
    }
}

/**
 * @brief Improved Bubble Sort
 *
 * * Time Complexity:
 * * * Best: O(n)
 * * * Worst: O(n^2)
 * * * Average: O(n^2)
 *
 * * Space Complexity: O(2)
 *
 * @param seq
 * @param n
 */
void improvedBubbleSort(int seq[], int n)
{
    bool hasSwap = true;
    cout << "Improved Bubble Sort:" << endl;

    for (int i = 0; i < n - 1 && hasSwap; i++)
    {
        cout << "Pass " << i + 1 << ": ";
        hasSwap = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (seq[j] > seq[j + 1])
            {
                swap(seq[j], seq[j + 1]);
                hasSwap = true;
            }
        }
        for (int i = 0; i < n; i++)
            cout << seq[i] << " ";
        cout << endl;
    }
}

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
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

    /* Original Bubble Sort  */
    bubbleSort(seq1, n);

    for (int i = 0; i < n; i++)
        cout << seq1[i] << " ";
    cout << endl
         << endl;

    /* Original Bubble Sort  */
    improvedBubbleSort(seq2, n);

    for (int i = 0; i < n; i++)
        cout << seq2[i] << " ";
    cout << endl;
}

/*

Input:
10
5 4 3 2 1 6 7 8 9 10

Output:
1 2 3 4 5 6 7 8 9 10

Input:
10
10 9 8 7 6 5 4 3 2 1

Output:
1 2 3 4 5 6 7 8 9 10

*/
