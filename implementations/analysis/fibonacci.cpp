/**
 * @file fibonacci.cpp
 * @author xxrjun (github.com/xxrjun)
 * @brief Fibonacci
 * @version 0.1
 * @date 2023-04-09
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>

using namespace std;

/**
 * @brief Fibonacci
 *
 * * Time Complexity: O(2^n)
 * * Space Complexity: O(n)
 *
 * @param n
 * @return int
 */
int fibonacci(int n)
{
    if (n == 1 || n == 2)
        return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;
    cin >> n;

    cout << fibonacci(n) << endl;
}

/*

Input:
10

Output:
89


Input:
20

Output:
10946


Input:
30

Output:
1346269


Input:
40

Output:
165580141

*/