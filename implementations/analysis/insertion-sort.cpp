#include <iostream>

using namespace std;

/**
 * @brief Insertion Sort
 *
 * * Time Complexity:
 * * * Best: O(n)
 * * * Worst: O(n^2)
 * * * Average: O(n^2)
 *
 * * Space Complexity: O(1)
 *
 * @param seq
 * @param n
 * @return int
 */
int insertionSort(int seq[], int n)
{
    cout << "Insertion Sort:" << endl;

    for (int i = 1; i < n; i++) // 從序列第一個元素開始往前找位置插入
    {
        cout << "Pass " << i << ": ";
        int tmp = seq[i];              // 先把當前元素存起來
        int j = i - 1;                 // 要比較之元素的指標
        while (tmp < seq[j] && j >= 0) // 往前找插入位置，前方為已排序好的陣列
        {
            swap(seq[j], seq[j + 1]);
            j--;
        }

        seq[j + 1] = tmp; // 找到插入位置

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
    for (int i = 0; i < n; i++)
    {
        cin >> seq1[i];
    }

    insertionSort(seq1, n);

    for (int i = 0; i < n; i++)
        cout << seq1[i] << " ";
    cout << endl;
}