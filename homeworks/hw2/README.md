# Homework 2

- [Homework 2](#homework-2)
    - [題目 1:](#題目-1)
    - [題目 2:](#題目-2)

### 題目 1:

D. 使用虛擬碼(pseudo code)寫一個演算法，以輸入一個具有 n 個元素的集合 S 並輸出 S 的幂集(power set)，你必須分析演算法的時間複雜度。 (Write an algorithm to input a set S of n elements and output the power set of S. You must analyze the time complexity of your algorithm.)

#### 解題過程與想法:

- 何謂 Power set(幂集)?  
   指給定一個集合，包含該集合所有子集的集合(包含空集合)。例如: 集合`{1, 2}` 的幂集為 `{{}, {1}, {2}, {1, 2}}`

- Input: 集合 S，其中包含 n 個元素；Output: S 集合的幂集(Power Set)
- Process:
  - 計算 S 的幂集
- 終止條件:

  - 如果輸入的集合 S 為空，直接回傳一個只包含空集合的幂集合
  - 跑完集合 S 的所有元素，回傳此集合的幂集合

- 視覺化

  - 輸入: `{1, 2, 3, 4}`
  - 輸出:

    ```plaintext
    {}
    {1}
    {2}
    {1, 2}
    {3}
    {1, 3}
    {2, 3}
    {1, 2, 3}
    {4}
    {1, 4}
    {2, 4}
    {1, 2, 4}
    {3, 4}
    {1, 3, 4}
    {2, 3, 4}
    {1, 2, 3, 4}
    ```

- 補: 找 Power set 算是一種 combination 的問題(?

  如給定集合有 n 個元素

  n = 2 時，此集合的幂集合就有 4 個

  ```
  C(2, 0) + C(2, 1) + C(2, 2) = 1 + 2 + 1 = 4
  ```

  n = 3 時，此集合的幂集合就有 8 個

  ```
  C(3, 0) + C(3, 1) + C(3, 2) + C(3, 3) = 1 + 3 + 3 + 1 = 8
  ```

  如果擔心就再多一輪 n = 4 個元素時，此集合的幂集合就有 16 個

  ```
  C(4, 0) + C(4, 1) + C(4, 2) + C(4, 3) + C(4, 4) = 1 + 4 + 6 + 4 + 1 = 16
  ```

#### Pseudo Code:

```cpp
Algorithm powerSet(inputSet)
Input: Set of n elements
Output: Power set of the inputSet

1. // 建立一個只包含空集合的幂集合
2. powerSet = [[]]
3.
4. // 如果輸入的集合為空，直接回傳
5. if inputSet is empty:
6.     return powerSet
7. else:
8.     // 對於輸入之集合的每個元素
9.     for element in inputSet:
10.
11.         // 目前集合的長度
12.         n ← lenght of powerSet
13.
14.         // 對於目前幂集合中的每個子集合
15.         for i = 0 to n - 1:
16.
17.             // 複製該子集合，並將當前元素加入複製的子集合中
18.             subset ← copy of powerSet[i]
19.             add element into subset
20.
21.             // 將此子集合加入到幂集合中
22.             add subset into powerSet
23.
24.     // 別忘記回傳結果
25.     return powerSet
```

#### Implementation (C++)

```cpp
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
```

<div align="right"><a href="#homework-1">BACK TO TOP</a></div>image.png

### 題目 2:

G. 若一演算法 A 的時間複雜度為 `6*2^n = O(2^n)` 可以在 n=10 的時候耗費一小時解決問題 X，而另一個解決問題 X 的演算法 B 的時間複雜度為 `5*n^3 = O(n^3)`， 則請問當 n=10 時演 算法 B 要耗費多少時間完成?

#### 解題想法:

- 演算法 A 的時間複雜度 `6 * 2^n` 帶入 `n = 10` ⇒ `6 * 2 ^ 10 = 6144`
- 演算法 B 的時間複雜度 `5 * n^3` 帶入 `n = 10` ⇒ `5 * 10 ^ 3 = 5000`

不等式 `6144/5000 = 60 min / x min` ⇒ x = 48.828125 minutes

<div align="right"><a href="#homework-1">BACK TO TOP</a></div>
