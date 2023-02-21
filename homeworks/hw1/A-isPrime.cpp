#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int n)
{
  if (n % 2 == 0)
    return false;

  int i = 3;
  while (i < floor(sqrt(n)))
  {
    if (n % i == 0)
      return false;
    i += 2;
  }

  return true;
}

int main()
{
  int n;
  cin >> n;

  if (isPrime(n))
    cout << n << " is a prime number" << endl;
  else
    cout << n << " is not a prime number" << endl;

  return 0;
}