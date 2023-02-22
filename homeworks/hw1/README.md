# Homework 1

### 題目 1:

A. 使用虛擬碼(pseudo code)寫一個演算法，輸入一個整數 n(n>2)並並判斷 n 是否為質數(prime)(Write an algorithm using the pseudo code to input an integer n and output (decide) if n is a prime.)

#### 解題想法:

- 輸入: 大於 2 整數 n；輸出: n 是否為質數
- 終止條件:
  - n 在有限的循環(i < n)下被整除
  - 有限循環檢查完了
- 質數代表只能被 1 與自身整除。
- 1 不是質數，題目也說輸入是大於 2 的整數，故不需考慮例外狀況。
- 先判斷此數是否為偶數且不為 2 (能被 2 整除)，若為偶數直接回傳 false，因為偶數除了 2 以外都不是質數；若不為偶數，則進行 Iteration 並只需要檢查奇數，可以減少迴圈次數。
- **(Optional)** 因為一個數的最大因數不會超過該數的平方根，故迴圈只需判斷到輸入 n 的平方根 sqrt(n)，可以減少迴圈次數，但如果數字太大也可能導致計算平方根需要大量的計算。

#### Pseudo Code:

```
Algorithm isPrime(n)
Input: Integer, n (n > 2)
Output: Boolean, if n is a prime

 1. if n mod 2 = 0
 2.    return false
 3.
 4. i ← 3
 5.    while i <= floor(sqrt(n)) do
 6.    if n mod i = 0
 7.        return false
 8.    i ← i + 2
 9.
10. return true
```

#### Implementation (C++)

```cpp
#include <iostream>
#include <unordered_set>

using namespace std;

bool isHappyNumber(int n)
{
	unordered_set<int> seen;

	while (true)
	{
		int new_num = 0;
		while (n)
		{
			int digit = n % 10;
			n /= 10;

			new_num += digit * digit;
		}

		if (new_num == 1)
			return true;

		if (seen.count(new_num) != 0)
			return false;

		seen.insert(new_num);
		n = new_num
	}
}

int main()
{
	int n = 0;

	while (cin >> n)
	{
		if (isHappyNumber(n))
			cout << n << " is a happy number!" << endl;
		else
			cout << n << " is not a happy number!" << endl;
	}

	return 0;
}
```

<div align="right"><a href="#homework-1">BACK TO TOP</a></div>

### 題目 2:

F. 使用虛擬碼(pseudo code)寫 一個演算法，輸入一個整數 n(n>0)並判斷 n 是否為快樂數(happy number) (Write an algorithm to input an integer n and output (decide) if n is a happy number.)
註: 快樂數有以下的特性：在給定的進位制下，該數字所有數位(digits)的平方和，得到的新數再次求所有數位的平方和，如此重複進行，最終結果必為 1。例 如，以十進位為例：
28 → 2^2+8^2= 68 → 6^2+8^2=100 → 1^2+0^2+0^2=1，因此 28 是快樂數

#### 解題想法:

- 輸入:大於 0 的整數 n；輸出: n 是否為快樂數
- 終止條件:
  - 出現循環，也就是出現了已經出現過的數字，此數不為快樂數，輸出 false。
  - 暫存數字等於 1，此數為快樂數，輸出 true。
- 一個暫存數字 num 每次取其個位數字平方並將 num / 10，將所有數字加總看是不是 1，或是已經出現過了(用 set 紀錄已經出現過的數字)。

#### Pseudo Code:

```
Algorithm isHappyNumber(n)
Input: Integer, n (n > 0)
Output: Boolean, if n is a happy number

 1. seen ← empty set
 2.
 3. while true
 4.     new_num ← 0
 5.
 6.     while n != 0
 7.        digit ← n mod 10
 8.        n ← floor(n / 10)
 9.
10.        new_num ← new_num + digit * digit
11.
12.     // 出現 1，為快樂數
13.     if new_num = 1
14.         return true
15.
16.     // 出現循環，不為快樂數
17.     if new_num in seen
18.             return false
19.
20.     // 將出現過的數字加入seen
21.     insert new_num in seen
22.
23.     n ← new_num
```

#### Implementation (C++)

```cpp
#include <iostream>
#include <unordered_set>

using namespace std;

bool isHappyNumber(int n)
{
	unordered_set<int> seen;

	while (true)
	{
		int new_num = 0;
		while (n)
		{
			int digit = n % 10;
			n /= 10;

			new_num += digit * digit;
		}

		if (new_num == 1)
			return true;

		if (seen.count(new_num) != 0)
			return false;

		seen.insert(new_num);
		n = new_num;
	}
}

int main()
{
	int n = 0;

	while (cin >> n)
	{
		if (isHappyNumber(n))
			cout << n << " is a happy number!" << endl;
		else
			cout << n << " is not a happy number!" << endl;
	}

	return 0;
}
```

<div align="right"><a href="#homework-1">BACK TO TOP</a></div>
```
