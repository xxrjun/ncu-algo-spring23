#include <iostream>
#include <vector>

using namespace std;

int Fibonacci(int n)
{
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main()
{
    int N = 0;
    cin >> N;

    vector<int> v;
    int input;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        v.push_back(input);
    }

    for (int i = 0; i < N; i++)
    {
        cout << Fibonacci(v[i]) << endl;
    }
}