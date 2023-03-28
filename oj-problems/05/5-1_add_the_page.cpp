#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int sum;
        cin >> sum;
        int pages = ceil((sqrt(1 + 8 * (sum + 1)) - 1) / 2);
        int missing_page = (pages * (pages + 1)) / 2 - sum;
        cout << missing_page << " " << pages << endl;
    }
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <array>

// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;

//     vector<array<long long, 2>> v;
//     long long sum = 0;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> sum;

//         if (sum <= 0)
//         {
//             v.push_back({0, 0});
//             continue;
//         }

//         long long missing_page = 1;
//         long long total_page = 1;
//         long long tmp = total_page;

//         while (tmp < sum)
//         {
//             total_page++;
//             tmp += total_page;
//         }

//         if (tmp == sum)
//         {
//             total_page++;
//             missing_page = total_page;
//         }
//         else
//         {
//             missing_page = tmp - sum;
//         }

//         v.push_back({missing_page, total_page});
//     }

//     int len = v.size();
//     for (int i = 0; i < len - 1; i++)
//     {
//         cout << v[i][0] << " " << v[i][1] << endl;
//     }

//     cout << v[len - 1][0] << " " << v[len - 1][1];
// }
