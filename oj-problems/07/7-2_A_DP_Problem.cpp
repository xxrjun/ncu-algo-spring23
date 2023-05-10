#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <math.h>

using namespace std;

pair<int, int> parse_expression(const string &expr)
{
    int coef = 0, constant = 0;
    string term;

    // 用正負號來判斷是否為項的開頭
    bool negative = false;

    // 逐字元處理式子
    for (char ch : expr)
    {
        // 遇到加減號時，將目前的項加入係數或常數
        if (ch == '+' || ch == '-')
        {
            if (!term.empty())
            {
                if (term.back() == 'x')
                {
                    int num = term.size() == 1 ? 1 : stoi(term.substr(0, term.size() - 1));
                    coef += negative ? -num : num;
                }
                else
                {
                    constant += negative ? -stoi(term) : stoi(term);
                }
                term.clear();
            }

            // 記錄下一項的正負號
            negative = (ch == '-');
        }
        else
        {
            // 非加減號時，將字元加入項中
            term.push_back(ch);
        }
    }

    // 將剩下的項加入係數或常數
    if (!term.empty())
    {
        if (term.back() == 'x')
        {
            int num = term.size() == 1 ? 1 : stoi(term.substr(0, term.size() - 1));
            coef += negative ? -num : num;
        }
        else
        {
            constant += negative ? -stoi(term) : stoi(term);
        }
    }

    return {coef, constant};
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(); //
    string equation;

    while (n--)
    {
        getline(cin, equation);

        // 找到等號位置，分割左右兩邊的式子
        size_t eq_pos = equation.find('=');
        string lhs = equation.substr(0, eq_pos);
        string rhs = equation.substr(eq_pos + 1);

        // 處理左右兩邊的式子，分別計算出係數和常數
        pair<int, int> left_expr = parse_expression(lhs);
        pair<int, int> right_expr = parse_expression(rhs);

        // 計算係數和常數的差值，並判斷是否有解
        int coef_diff = left_expr.first - right_expr.first;
        int const_diff = right_expr.second - left_expr.second;

        if (coef_diff == 0 && const_diff == 0)
            cout << "IDENTITY" << endl;
        else if (coef_diff == 0 && const_diff != 0)
            cout << "IMPOSSIBLE" << endl;
        else
        {
            double s = static_cast<double>(const_diff) / coef_diff;
            cout << static_cast<int>(floor(s)) << endl;
        }
    }

    return 0;
}
