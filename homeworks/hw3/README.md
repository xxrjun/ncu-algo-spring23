# Homework 2

- [Homework 2](#homework-2)
  - [題目 1](#題目-1)
  - [題目 2](#題目-2)

### 題目 1

B.  分析改良氣泡排序演算法最佳、最差與平均時間複雜度

#### 解題過程與想法

- 何為改良氣泡排序演算法？
  - 使用一個變數去儲存此次 pass 是否有 swap ，若判斷沒有 swap 則代表已經排好
- 分析

  - **Best Case: O(n)**
    發生的情形為序列已經順序排好，此時只需要遍歷所有元素一輪即可結束排序，故時間複雜度為 O(n)
  - **Wort Case: O(n^2)**
    發生的情形為序列完全逆序。每回合分別需執行 n - 1、n - 2、...、1 次  
     `(n - 1) + (n - 2) + ... + 1 = n * (n - 1) / 2 = O(n^2)`
  - **Average Case: O(n^2)**
    n 比資料，平均需要比較 (n - 1) / 2 次  
     `n * (n - 1) / 2 = O(n^2)`

  <div align="right"><a href="#homework-1">BACK TO TOP</a></div>image.png

### 題目 2

D.  分析快速排序演算法最佳狀況空間複雜度(best case space complexity)。

#### 解題過程與想法

Quick sort 的最佳狀況是在每次遞迴時，都能夠幾乎平分待排序的序列。因為每次遞迴都會將序列一分為二，因此遞迴呼叫的深度為 `logn`，故 Qucik sort 的最佳狀況空間複雜度為`O(logn)`。

雖然如果每次 pivot 都恰好為序列的中位數時，最佳狀況就會發生，不過查了一下資料說找中位數的代價蠻高的所以通常不會專門去找中為數。

<div align="right"><a href="#homework-1">BACK TO TOP</a></div>
