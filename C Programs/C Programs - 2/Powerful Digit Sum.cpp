#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void multiply(vector <int> &multiple, int n, int &last_digit)
{
    int carry = 0;
    for(int i = 0; i <= last_digit ; i++)
    {
        const int BASE = 10;

        int product = multiple[i]*n + carry;
        int replace = product%BASE;
        carry = product/BASE;

        multiple[i] = replace;

        if(i == last_digit && carry != 0)
            last_digit++;
    }
}

int main()
{
    int n = 101;

    int max_digit_sum = 0, ans, ans_power;
    for(int a = 1; a <= n; a++)
    {
        const int MAX_DIGITS = 500;
        vector <int> multiple(MAX_DIGITS, 0);
        int last_digit = 1;
        multiple[0] = 1;

        for(int power = 1; power <= n; power++)
        {
            multiply(multiple, a, last_digit);

            int digit_sum = 0;
            for(int i = 0; i < multiple.size(); i++)
                digit_sum += multiple[i];

            if(digit_sum > max_digit_sum) ans = a, ans_power = power;

            max_digit_sum = max(max_digit_sum, digit_sum);
        }
    }

    printf("Maximum digit sum is %d^%d = %d\n", ans, ans_power, max_digit_sum);
    return 0;
}

