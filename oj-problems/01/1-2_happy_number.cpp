#include <iostream>
#include <set>
#include <vector>

using namespace std;

bool isHappyNumber(int number)
{
    set<int> seen;
    while (true)
    {

        int cur_sum = 0;
        while (number)
        {
            int digit = number % 10;

            cur_sum += digit * digit;

            number /= 10;
        }

        // Result is 1 --> The number is a Happy Number!
        if (cur_sum == 1)
            return true;

        // Result has be seen before --> The number is not a Happy Number!
        if (seen.count(cur_sum))
            return false;

        seen.insert(cur_sum);

        number = cur_sum;
    }
}

int main()
{
    int total_num = 0;
    cin >> total_num;

    vector<int> test_numbers;
    int cur_input = 0;
    for (int i = 0; i < total_num; i++)
    {
        cin >> cur_input;
        test_numbers.push_back(cur_input);
    }

    for (int i = 0; i < total_num; i++)
    {
        if (isHappyNumber(test_numbers[i]))
            cout << "Happy" << endl;
        else
            cout << "Not Happy" << endl;
    }
}