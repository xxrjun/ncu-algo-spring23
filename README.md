# NCU CE Algorithms in Spring 2023

> 這學期 27 學分有專題又有資工資管兩門演算法，不成功便成仁
>
> 變 29 學分了

- [NCU CE Algorithms in Spring 2023](#ncu-ce-algorithms-in-spring-2023)
  - [Implementations of Algorithms](#implementations-of-algorithms)
    - [Analysis](#analysis)
    - [Divide and Conquer](#divide-and-conquer)
    - [Dynamic Programming](#dynamic-programming)
  - [Homeworks(hand-writing)](#homeworkshand-writing)
  - [Online Judge Problems(Using C++)](#online-judge-problemsusing-c)
  - [Epilogue](#epilogue)

## Implementations of Algorithms

### Analysis

| Algorithm            | Code                                                 | Time Complexity                                     | Space Complexity |
| -------------------- | ---------------------------------------------------- | --------------------------------------------------- | ---------------- |
| Fibonacci            | [C++](./implementations/analysis/fibonacci.cpp)      | _O(2 ^ n)_                                          | O(n)             |
| Bubble Sort          | [C++](./implementations/analysis/bubble-sort.cpp)    | B: _O(n ^ 2)_<br />A: _O(n ^ 2)_<br />W: _O(n ^ 2)_ | _O(1)_, inplace  |
| Improved Bubble Sort | [C++](./implementations/analysis/bubble-sort.cpp)    | B: _O(n)_<br />A: _O(n ^ 2)_<br />W: _O(n ^ 2)_     | _O(2)_           |
| Insertion Sort       | [C++](./implementations/analysis/insertion-sort.cpp) | B: _O(n)_<br />A: _O(n ^ 2)_<br />W: _O(n ^ 2)_     | _O(1)_, inplace  |

### Divide and Conquer

| Algorithm                          | Code                     | Time Complexity                                     | Space Complexity |
| ---------------------------------- | ------------------------ | --------------------------------------------------- | ---------------- |
| Merge Sort                         | [C++](./implementations) | B: _O(nlogn)_<br />A: _O(nlogn)_<br />W: _O(nlogn)_ |                  |
| Quick Sort                         | [C++](./implementations) | B: _O(nlogn)_<br />A: _O(nlogn)_<br />W: _O(n ^ 2)_ |                  |
| Maximum Contiguous Subsequence Sum | [C++](./implementations) |                                                     |                  |
| Closest Pair of 2D Points          | [C++](./implementations) |                                                     |                  |

### Dynamic Programming

| Algorithm                          | Code                                        | Time Complexity | Space Complexity |
| ---------------------------------- | ------------------------------------------- | --------------- | ---------------- |
| KnapSack                           | [C++](./implementations/dp/DP-KnapSack.cpp) | _O(n \* W)_     | -                |
| Longest Common Subsequence         | [C++](./implementations/dp/DP-LCS.cpp)      | _O(n \* m)_     | -                |
| Maximum Contiguous Subsequence Sum | [C++](./implementations/dp/DP-MCSS.cpp)     | _O(n)_          | -                |

## Homeworks(hand-writing)

| #HW                                                  | Date     | Score |
| ---------------------------------------------------- | -------- | ----- |
| [HW1 A & F](./homeworks/hw1/)                        | 23/03/07 | 100   |
| [HW2 D & 論文心得](./homeworks/hw2/)                 | 23/03/14 | 100   |
| [HW3 B & D](./homeworks/hw3/)                        | 23/03/21 | 100   |
| [HW4 4-1B & 4-2G](./homeworks/hw4/HW4_109403019.pdf) | 23/03/28 |       |

## Online Judge Problems(Using C++)

> 佛系解題沒在管排名，不過還是做個紀錄

Team59

| #Problem                                                                    | Date                                  | Status |
| --------------------------------------------------------------------------- | ------------------------------------- | ------ |
| [1-1 Odd Sum](./oj-problems/01/1-1_odd_sum.cpp)                             | 23/03/01                              | Yes    |
| [1-2 Happy Number](./oj-problems/01/1-2_happy_number.cpp)                   | 23/03/01                              | Yes    |
| [1-3 Odd Sum](./oj-problems/01/1-1_odd_sum.cpp)                             | 23/03/01                              | Yes    |
| 第一周成績: **Rank 18/137** : Time 624                                      |                                       |        |
| [2-1 Odd Sum without prime](./oj-problems/02/2-1_odd_sum_without_prime.cpp) | 23/03/07                              | Yes    |
| [2-2 GCD](./oj-problems/02/2-2_GCD.cpp)                                     | 23/03/07                              | Yes    |
| [2-3 Perfect number](./oj-problems/02/2-3_perfect_number.cpp)               | 23/03/07                              | Yes    |
| 第二周成績: **Rank 13/137** : Time 206                                      |                                       |        |
| [3-1 Bubble sort](./oj-problems/03/3-1_bubble.cpp)                          | 23/03/14                              | Yes    |
| [3-2 Fibonacci](./oj-problems/03/3-2_fibonacci.cpp)                         | 23/03/14                              | Yes    |
| [3-3 All in All](./oj-problems/03/3-3_all_int_all.cpp)                      | 23/03/14                              | Yes    |
| 第三周成績: **Rank 3/137** : Time 68                                        |                                       |        |
| [4-1 Age Sort](./oj-problems/04/4-1_age_sort.cpp)                           | 23/03/22                              | Yes    |
| [4-2 Reverse and Add](./oj-problems/04/4-2_reverse_and_add.cpp)             | 23/03/22                              | Yes    |
| [4-3 Number Sort](./oj-problems/04/4-3_number_sort.cpp)                     | 23/03/22                              | Yes    |
| 第四周成績: **Rank 2/137** : Time 101                                       | [Done](./oj-problems/src/04-0321.png) |        |
| [5-1 Add the Page](./oj-problems/05/5-1_add_the_page.cpp)                   |                                       | Yes    |
| [5-2 Divisors](./oj-problems/05/5-2_divisors.cpp)                           | 23/03/28                              | Yes    |
| [5-3 Ugly Number](./oj-problems/05/5-3_ugly_number.cpp)                     | 23/03/28                              | Yes    |
| 第四周成績: **Rank 2/137** : Time 101                                       | [Done](./oj-problems/src/04-0321.png) |        |

## Implementations of Algorithms

### Sorting

### Divide and Conquer

### Dynamic Programming

| Algorithm                          | Code                                     | Analysis                   |
| ---------------------------------- | ---------------------------------------- | -------------------------- |
| KnapSack                           | [C++](./implementations/DP-KnapSack.cpp) | Time Complexity: O(nW)     |
| Longest Common Subsequence         | [C++](./implementations/DP-LCS.cpp)      | Time Complexity: O(n \* m) |
| Maximum Contiguous Subsequence Sum | [C++](./implementations/DP-MCSS.cpp)     | Time Complexity: O(n)      |

## Epilogue
