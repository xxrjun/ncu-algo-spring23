/**
 * @file DP-KnapSack.cpp
 * @author xxrjun (github.com/xxrjun)
 * @brief
 * @version 0.1
 * @date 2023-04-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <vector>
#define MAX 200

using namespace std;

struct item
{
    int value;
    int weight;
    int index;
};

/**
 * @brief KnapSack DP Algorithm
 *
 * Time Complexity: O(n * W)
 *
 * @param valueTable
 * @param items
 * @param n
 * @param Weight
 */
void KnapSack(int (*valueTable)[MAX], const vector<item> items, const int n, const int Weight)
{
    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= Weight; w++)
        {
            if (items[i - 1].weight <= w)
            {
                int itemValue = items[i - 1].value;
                int itemWeight = items[i - 1].weight;

                int stayValue = valueTable[i - 1][w];                         // 不放入新的物品，維持上一列的結果
                int newValue = itemValue + valueTable[i - 1][w - itemWeight]; // 放入新物品，價值與重量皆有變化

                valueTable[i][w] = max(stayValue, newValue);
            }
            else
            {
                valueTable[i][w] = valueTable[i - 1][w];
            }
        }
    }
}

void findIncludedItems(int (*valueTable)[MAX], const vector<item> items, const int n, const int W)
{
    vector<item> includedItems;
    int i = n;
    int j = W;

    while (i > 0 && j > 0)
    {
        if (valueTable[i][j] != valueTable[i - 1][j])
        {
            includedItems.push_back(items[i - 1]);
            j -= items[i - 1].weight;
        }
        i--;
    }

    // Print included items
    cout << "Included items: " << endl;
    for (item it : includedItems)
    {
        cout << "Item index: " << it.index << ", Value: " << it.value << ", Weight: " << it.weight << endl;
    }
}

int main()
{
    /* 輸入共有幾個物品, 最大重量 */
    int n, W;
    cout << "How many items: ";
    cin >> n;
    cout << "Max weight: ";
    cin >> W;

    /* 設定物品value & weight */
    cout << "Setting items... (value, weight)" << endl;
    vector<item> items;
    int v, w;
    item curItem;
    for (int i = 0; i < n; i++)
    {
        cout << "item " << i + 1 << ": ";
        cin >> v >> w;
        curItem.value = v;
        curItem.weight = w;
        curItem.index = i + 1;

        items.push_back(curItem);
    }

    /* 初始化value表格第一列*/
    int(*valueTable)[MAX] = new int[n + 1][MAX];
    for (int i = 0; i < W + 1; i++)
        valueTable[0][i] = 0;

    /* 執行DP KnapSack -> Time Complexity: O(n) */
    KnapSack(valueTable, items, n, W);

    /* 看一下value表格結果 */
    cout << "=======================" << endl;
    cout << "value table: " << endl;
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < W + 1; j++)
        {
            if (valueTable[i][j] < 10)
                cout << " ";
            cout << valueTable[i][j] << " ";
        }
        cout << endl;
    }

    /* 找出最大價值 */
    cout << "=======================" << endl;
    cout << "Max value: " << valueTable[n][W] << endl;

    /* 找出包含的物品 */
    cout << "=======================" << endl;
    findIncludedItems(valueTable, items, n, W);

    return 0;
}

/* Test case 1
4
10
10 5
40 4
30 6
50 3

*/
