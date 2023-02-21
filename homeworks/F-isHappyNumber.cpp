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